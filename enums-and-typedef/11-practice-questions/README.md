# 11: Practice questions

Try each one on paper first, then check the answers below.

## Questions

1. What are the values of `A, B, C, D, E` in `enum { A, B = 5, C, D = 2, E };`?
2. Given `#define PTR int *` and `PTR a, b;`, what is `sizeof(b)` on a 64-bit machine?
3. What does `typedef int *P; const P p = &x;` mean? Can you write `*p = 5;` and `p = &y;`?
4. What does `typedef int (*Op)(int, int);` declare?
5. Write a motor state machine with states `IDLE`, `RUNNING`, `FAULT` and events `START`, `STOP`, `ERROR`, `RESET`, using an enum and a `switch`.
6. Write a `typedef`'d `Button` structure with an `id` and an `onPress` callback, then call the callback.
7. What does this print?
   ```c
   enum Color { RED, GREEN, BLUE };
   enum Color c = BLUE;
   printf("%d", c + 1);
   ```
8. Can `enum A { X, Y };` and `enum B { X, Z };` exist in the same scope?
9. Why is it better to leave out `default` in a `switch` over an enum?
10. Why should you not send an `enum` variable directly over UART?

## Answers

1. `A=0, B=5, C=6, D=2, E=3`.
2. `4`. The macro expands to `int * a, b;`, so `a` is a pointer and `b` is a plain `int`.
3. `const P p` makes the **pointer** const: `int *const p`. `*p = 5;` is allowed (the int can change). `p = &y;` is an error (the pointer cannot move).
4. It defines `Op` as a type: a pointer to a function that takes two `int`s and returns `int`.
5. See `motorNext` in [`solutions.c`](solutions.c).
6. See `Button` and `sayPressed` in [`solutions.c`](solutions.c).
7. `3`. `BLUE` is 2, and the enumerator is a plain integer, so `c + 1` is 3.
8. **No.** Enumerator names share the ordinary identifier namespace, so `X` would be defined twice, which is a compile error.
9. With `-Wall`, the compiler then warns when a new enumerator is added and a `case` for it is missing. A `default` branch silences that warning.
10. The size of an enum is implementation-defined and the byte order is not fixed. Convert it to a fixed-width type (for example `uint8_t`) and validate it on the receiving side.

## Solutions output

```
Q1: A=0 B=5 C=6 D=2 E=3
Q2: sizeof(a)=8 sizeof(b)=4
Q5: after START -> 1 (RUNNING=1)
Q5: after ERROR -> 2 (FAULT=2)
Q5: START ignored in FAULT -> 2
Q5: after RESET -> 0 (IDLE=0)
Q6: button 7 pressed
Q7: 3
```

Previous: [10 Common mistakes](../10-common-mistakes/) | Back to [index](../README.md)
