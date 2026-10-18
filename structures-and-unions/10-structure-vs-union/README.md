# 10: Structure vs union

| | Structure | Union |
|---|---|---|
| Keyword | `struct` | `union` |
| Memory | Sum of all members (plus padding) | Size of the largest member |
| Members valid at once | All | Only the last one written |
| Each member has its own address | Yes | No, all start at the same address |
| Main purpose | Group related data | Save memory, or view the same bytes in different ways |
| Typical use | Records, nodes, packets | Registers, protocol frames, variant data |

**A structure models data. A union reinterprets it.**

## Example

[`compare.c`](compare.c) uses the same three members in both a `struct` and a `union`.

```
sizeof(struct S) = 12
sizeof(union  U) = 4
struct: &s.i == &s.f ? no
union : &u.i == &u.f ? yes
```

Previous: [09 Unions](../09-unions/) | Next: [11 Unions in embedded work](../11-unions-in-embedded/)
