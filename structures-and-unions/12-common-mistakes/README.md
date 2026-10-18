# 12: Common mistakes

| Mistake | Fix |
|---|---|
| `.` on a pointer, or `->` on a variable | Dot for variables, arrow for pointers |
| `s.name = "Amit";` | Arrays are not assignable. Use `strcpy(s.name, "Amit")` or `snprintf` |
| Assuming `sizeof(struct)` equals the sum of its members | Padding exists. Print `sizeof` and use `offsetof` |
| Comparing structures with `==` | Compare members individually |
| `memcmp` on structures with padding | Padding bytes are unspecified. Compare members |
| Passing a large structure by value | Pass `const Student *` |
| Forgetting the element count when passing an array of structures | Pass `(pointer, count)` |
| Returning a pointer to a local structure | Return by value, or pass in a destination pointer |
| `Student *pa[3]` when you meant `Student (*pa)[3]` | The first is an array of pointers, the second a pointer to an array |
| Reading a union member that was not last written, without thinking about byte order | Know the representation, or avoid it |
| No type tag when a union holds more than one kind of value | Use a tagged union |
| Relying on bit-field layout being the same across compilers | Verify per compiler and target |
| `malloc` without checking `NULL`, or without `free` | Always check, always free |
| Writing `*p.name` | Write `p->name` or `(*p).name` |

Previous: [11 Unions in embedded work](../11-unions-in-embedded/) | Next: [13 Practice questions](../13-practice-questions/)
