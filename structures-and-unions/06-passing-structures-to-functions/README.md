# 06: Passing a single structure: by value vs by pointer

```c
void byValue(Student s)    { s.marks = 0; }    // changes a COPY
void byPointer(Student *s) { s->marks = 0; }   // changes the ORIGINAL
```

| | By value | By pointer |
|---|---|---|
| What is passed | A full copy of the structure | Only an address |
| Can modify the original | No | Yes |
| Cost | Grows with structure size | Fixed (one pointer) |
| Read-only version | Natural | Use `const Student *` |

## Key points

- Prefer a pointer for anything larger than a few bytes.
- A structure containing an array (like `name[20]`) is copied in full when passed by value.
- Returning a small structure by value is fine:

```c
Point makePoint(int x, int y) { Point p = {x, y}; return p; }
```

- Never return a pointer to a local structure. It no longer exists after the function returns.

## Example

[`pass_struct.c`](pass_struct.c)

```
inside byValue: 0.0
Amit: 78.5
Amit: 0.0
Point: (3, 4)
```

`byValue` changed only its own copy, so the first `show` still prints 78.5. `byPointer` changed the original.

Previous: [05 Pointer to array of structures](../05-pointer-to-array-of-structures/) | Next: [07 Padding and alignment](../07-padding-and-alignment/)
