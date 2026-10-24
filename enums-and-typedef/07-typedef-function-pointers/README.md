# 07: typedef for function pointers

The raw syntax for a function pointer is hard to read. A `typedef` makes it clear.

```c
int (*op)(int, int);              // raw: op is a pointer to a function (int, int) -> int

typedef int (*BinaryOp)(int, int);
BinaryOp op;                      // same thing, readable
```

To read it: the name being defined in a typedef is the one inside `(*...)`, so `BinaryOp` is the type "pointer to function taking two ints and returning int".

## Operation table

```c
typedef struct {
    const char *name;
    BinaryOp    fn;
} Operation;

Operation table[] = { {"add", add}, {"sub", sub}, {"mul", mul} };

for (unsigned i = 0; i < sizeof table / sizeof table[0]; i++)
    printf("%s(6, 3) = %d\n", table[i].name, table[i].fn(6, 3));
```

## Callbacks

```c
typedef void (*Callback)(int value);

void check(int value, int threshold, Callback high, Callback low)
{
    if (value > threshold) high(value);
    else                   low(value);
}
```

The caller decides what happens. This is how drivers notify application code (button pressed, timer expired, byte received).

## Key points

- A function name without `()` is its address, so `BinaryOp op = mul;` needs no `&`.
- Call through the pointer with `op(4, 5)`.
- Tables of function pointers replace long `switch` statements (command handlers, menu actions, state handlers).
- Always make sure a function pointer is not `NULL` before calling it, especially for optional callbacks.

## Example

[`function_pointers.c`](function_pointers.c)

```
add(6, 3) = 9
sub(6, 3) = 3
mul(6, 3) = 18
op(4, 5) = 20
  callback: 80 is HIGH
  callback: 20 is low
```

Previous: [06 typedef with pointers and const](../06-typedef-pointers-and-const/) | Next: [08 typedef in embedded code](../08-typedef-in-embedded/)
