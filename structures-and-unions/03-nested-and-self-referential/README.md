# 03: Nested and self-referential structures

## Nested structures

A structure can contain another structure as a member.

```c
typedef struct { int day, month, year; } Date;

typedef struct {
    int  id;
    char name[20];
    Date joined;
} Employee;

Employee e = {101, "Omkar", {1, 6, 2026}};
printf("%d\n", e.joined.year);     // chain the dots
```

## Self-referential structures

A structure cannot contain **itself**, because its size would be infinite. It can contain a **pointer to its own type**. This is the basis of linked lists, stacks, queues and trees.

```c
typedef struct Node {
    int data;
    struct Node *next;     // 'Node' is not a typedef name yet here, so write 'struct Node'
} Node;
```

## Key points

- Use the struct tag (`struct Node`) inside the definition, because the `typedef` name is not available until the definition ends.
- The last node's `next` is `NULL`, which is how you detect the end.
- With dynamic nodes, allocate each one with `malloc` and release each one with `free`.

## Example

[`nested.c`](nested.c)

```
101 Omkar joined 01-06-2026
10 20 30
```

Previous: [02 Accessing members](../02-accessing-members/) | Next: [04 Array of structures](../04-array-of-structures/)
