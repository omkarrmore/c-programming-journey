# 01: Structures: the basics

An array holds many values of the **same** type. A structure groups values of **different** types under one name.

```c
struct Student {
    int   id;
    char  name[20];
    float marks;
};
struct Student s1;        // needs the 'struct' keyword
```

With `typedef` you can drop the keyword:

```c
typedef struct {
    int   id;
    char  name[20];
    float marks;
} Student;
Student s1;
```

## Initialization

```c
Student a = {1, "Amit", 78.5f};                          // positional, order matters
Student b = {.marks = 91.0f, .id = 2, .name = "Neha"};   // designated, any order
Student c = {0};                                         // everything zeroed
```

## Key points

- A definition only describes a layout. **Memory is allocated when you create a variable.**
- Members sit in memory in the order declared.
- A char array member cannot be assigned with `=`. Use `strcpy` or `snprintf`.
- One structure **can** be assigned to another of the same type with `=`. Every member is copied, including arrays inside it.
- Structures cannot be compared with `==`. Compare members one by one.

## Example

[`basics.c`](basics.c)

```
a: 1 Amit 78.5
b: 2 Neha 91.0
c: 3 Ravi 66.0
d: 1 Copy 78.5
sizeof(Student) = 28
```

`d` started as a copy of `a`; changing its name did not affect `a`.

Next: [02 Accessing members](../02-accessing-members/)
