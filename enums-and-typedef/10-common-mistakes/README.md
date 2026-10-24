# 10: Common mistakes

## Enums

| Mistake | Fix |
|---|---|
| Assuming enum values start at 1 | They start at 0 unless you assign a value |
| Mis-tracing auto-increment (`A, B = 5, C, D = 2, E`) | Each unassigned name is the previous value + 1: 0, 5, 6, 2, 3 |
| Reusing an enumerator name in two enums in the same scope | Enumerators share one namespace. Use a prefix (`DAY_MON`, `EV_START`) |
| Trusting a value from UART, a file or a sensor as a valid enum | Range-check before casting |
| Adding a `default` to a `switch` on an enum | Leave it out so `-Wall` warns about unhandled values |
| Forgetting `break` in a `case` | Execution falls through to the next case |
| Assuming `sizeof(enum)` is always 4 | It is implementation-defined. Use `uint8_t` for wire formats |
| Using a `COUNT` entry as a real value | It is a counter, not a state |

## typedef and #define

| Mistake | Fix |
|---|---|
| Using `#define PTR int *` and writing `PTR a, b;` | Only `a` is a pointer. Use `typedef int *PTR;` |
| `#define SIZE 2 + 3` | Add parentheses, or use an enum |
| Expecting `const` to behave the same with a typedef'd pointer and a macro | Expand the macro as text first, then read the declaration |
| Hiding pointers inside typedef names without a reason | Keep the `*` visible unless the type is meant to be opaque |
| Forgetting the struct tag in a self-referential typedef | Write `typedef struct Node { struct Node *next; } Node;` |
| Calling a function pointer that is `NULL` | Check before calling optional callbacks |

## Tagged unions

| Mistake | Fix |
|---|---|
| Reading a union member that does not match the tag | Always switch on the tag first |
| Writing the payload but forgetting to set the tag | Set both together, ideally in one helper function |
| Putting a large member in the union and wasting space in every message | The union is as big as its largest member |

Previous: [09 Tagged union revisited](../09-tagged-union-revisited/) | Next: [11 Practice questions](../11-practice-questions/)
