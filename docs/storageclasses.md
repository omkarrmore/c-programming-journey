# Storage Classes in C

After looking at the C memory map, I started exploring how variables
behave in terms of their scope, lifetime, and linkage.

Storage classes help describe these properties of variables and
functions.

## Main Storage Classes

C commonly discusses these storage classes:

- `auto`
- `static`
- `extern`
- `register`

The important properties to understand are:

| Storage Class     | Scope          | Lifetime / Storage Duration | Linkage  |
| ----------------- | -------------- | --------------------------- | -------- |
| `auto`            | Block          | Block execution             | None     |
| `static` (local)  | Block          | Entire program              | None     |
| `static` (global) | File           | Entire program              | Internal |
|`extern `          | File / Program | Entire program              | External |
| `register`        | Block          | Block execution             | None     |


## 1. auto

Local variables are automatic by default.

```c
void test(void)
{
    int x = 10;
}
```

The above is effectively an automatic variable.

It can also be written explicitly:

```c
void test(void)
{
    auto int x = 10;
}
```

The variable exists while the block/function is executing.

I noticed that auto is rarely written explicitly because ordinary
local variables already have automatic storage duration by default.

---

## 2. static

static behaves differently depending on where it is used.

### Static Local Variable

```c
void counter(void)
{
    static int count = 0;

    count++;

    printf("%d\n", count);
}
```

If the function is called multiple times:

```
counter() → 1
counter() → 2
counter() → 3
```

The important part is that count does not get created again with
a fresh value on every function call.

It retains its value for the entire program execution.

The variable still has local scope, so it can only be accessed inside
the function.

### Static Global Variable

```c
static int value = 10;
```

When static is used with a file-scope variable, it gives the variable
internal linkage.

This means the variable can only be accessed from the same source file.

---

## 3. extern

extern is used when a variable is defined somewhere else.

For example:

**file1.c**
```c
int balance = 5000;
```

**file2.c**
```c
extern int balance;
```

Now file2.c can refer to the variable defined in file1.c.

This becomes useful when working with multiple .c files.

The important idea for me was:

- **Definition** → creates the variable
- **Declaration with extern** → tells the compiler that the variable exists elsewhere

---

## 4. register

register can be used to request that a variable be stored in a
CPU register when possible.

```c
void test(void)
{
    register int i;

    for(i = 0; i < 10; i++)
    {
        printf("%d\n", i);
    }
}
```

However, modern compilers usually make their own decisions about
register allocation and optimization.

So I don't treat register as a command that guarantees a variable
will be stored in a CPU register.

---

## Scope vs Lifetime vs Linkage

One thing that became clearer while studying storage classes is that
these terms are related but not the same.

### Scope

Where can I access the variable?

### Lifetime / Storage Duration

How long does the variable exist?

### Linkage

Can the same variable be accessed from another source file?

For example, a static local variable has:

- **Scope** → inside its block
- **Lifetime** → entire program
- **Linkage** → none

This distinction helped me understand why static is more than just
"keep the value."

---

## Quick Comparison

### auto
- normal local variable
- exists during block execution

### static local
- local scope
- retains value for entire program

### static global
- file scope
- internal linkage

### extern
- refers to a variable defined elsewhere
- useful across source files

### register
- historical request for register storage
- modern compiler decides optimization

---

## What I Understood

The main thing I learned is that storage classes are not simply about
"where a variable is stored."

They help describe how a variable behaves in terms of:

- Scope
- Lifetime / storage duration
- Linkage

This connects the memory concepts I was learning with the way
variables actually behave in a C program.
