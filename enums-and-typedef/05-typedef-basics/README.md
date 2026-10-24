# 05: typedef basics

`typedef` creates a **new name for an existing type**. It does not create a new type.

```c
typedef unsigned int  uint;
typedef unsigned char byte;

uint u = 4000000000u;
byte b = 255;
```

## Structures

```c
typedef struct {
    int x, y;
} Point;

Point p = {3, 4};          // no 'struct' keyword needed
```

For a self-referential structure keep the tag, because the typedef name does not exist yet inside the definition:

```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;
```

## Arrays

```c
typedef int Row[3];
Row r = {1, 2, 3};         // same as: int r[3]
```

## Key points

- Read a `typedef` like a normal declaration: write the declaration of a variable, then put `typedef` in front, and the variable name becomes the type name.
- A typedef is **not text substitution**. The compiler treats it as a real type, which is why it behaves better than `#define` with pointers (next topic).
- Good uses: shorter names, hiding implementation details, and making it easy to change a type in one place.
- Avoid hiding pointers inside a typedef unless the type is meant to be opaque, because `const` and `*` then behave in surprising ways.
- Name types consistently, for example `Point`, `Node`, or with a `_t` suffix (note that POSIX reserves names ending in `_t`).

## Example

[`typedef_basics.c`](typedef_basics.c)

```
u=4000000000 b=255
p=(3, 4)
n1.next->data = 20
r has 3 ints, sizeof(Row)=12
```

Previous: [04 Enum size and pitfalls](../04-enum-size-and-pitfalls/) | Next: [06 typedef with pointers and const](../06-typedef-pointers-and-const/)
