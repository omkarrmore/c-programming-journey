# 02: Enum vs `#define`

Both can name a constant. They work very differently.

| | `#define` | `enum` |
|---|---|---|
| Handled by | Preprocessor (raw text replacement) | Compiler |
| Has a type | No | Integer constant (the variable has the enum type) |
| Scope | None, from the `#define` to the end of the file | Normal block scope |
| Groups related names | No | Yes |
| Auto-numbering | No | Yes |
| Visible in a debugger | Usually not | Usually yes (by name) |
| Can be non-integer (string, float) | Yes | No, integers only |

## The classic trap: text substitution

```c
#define SIZE_DEF 2 + 3
enum { SIZE_ENUM = 2 + 3 };

SIZE_DEF  * 2    // becomes 2 + 3 * 2  = 8
SIZE_ENUM * 2    // 5 * 2               = 10
```

This is the same habit as macro tracing: **expand macros as literal text first, then parse.** An `enum` never has this problem. (With `#define` the fix is parentheses: `#define SIZE_DEF (2 + 3)`.)

## Scope

```c
{
    enum { LOCAL = 7 };   // only exists inside this block
}
#define LATER 99          // exists everywhere below, no matter the block
```

## When to use which

- Use **`enum`** for a related set of integer values (states, modes, error codes, event types).
- Use **`const`** variables or **`#define`** for single values that are not integers, such as strings and floats.
- Use **`#define`** for conditional compilation (`#ifdef`) and for macros that need text substitution.

## Example

[`enum_vs_define.c`](enum_vs_define.c)

```
SIZE_DEF  * 2 = 8  (2 + 3 * 2)
SIZE_ENUM * 2 = 10
m=1 legacy=1
buf has 4 elements
LOCAL = 7
LATER = 99
```

Previous: [01 Enum basics](../01-enum-basics/) | Next: [03 Enums with switch](../03-enums-with-switch/)
