# 02: Accessing members: `.` and `->`

| Operator | Used on | Example |
|---|---|---|
| `.` (dot) | a structure variable | `s1.marks` |
| `->` (arrow) | a pointer to a structure | `p->marks` |

```c
Student s1 = {1, "Amit", 78.5f};
Student *p = &s1;

s1.name;       // variable: dot
p->name;       // pointer: arrow
(*p).name;     // same as p->name
```

## Key points

- `p->name` is shorthand for `(*p).name`.
- The parentheses in `(*p).name` are required because `.` binds tighter than `*`. Without them, `*p.name` means `*(p.name)`.
- Writing through the pointer changes the original: `p->marks += 5.0f;` changes `s1.marks`.

## Example

[`access.c`](access.c)

```
s1.name     = Amit
p->name     = Amit
(*p).name   = Amit
s1.marks    = 83.5
```

Previous: [01 Basics](../01-structures-basics/) | Next: [03 Nested and self-referential](../03-nested-and-self-referential/)
