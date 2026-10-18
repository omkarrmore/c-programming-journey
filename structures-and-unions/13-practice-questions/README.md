# 13: Practice questions

Try each one on paper first, then check the answers below.

## Questions

1. What is the difference between `Student *pa[3]` and `Student (*pa)[3]`?
2. If `p` is a `Student *` and `sizeof(Student)` is 28, by how many bytes does `p + 2` move?
3. Why does `addGrace(cls, MAX, 2.0f)` change the caller's data, while `byValue(cls[0])` does not?
4. Predict `sizeof(struct A)` and `sizeof(struct B)` from [topic 07](../07-padding-and-alignment/) if `int` is 4 bytes, then verify with a program.
5. After `d.f = 3.14f;`, what does `d.i` hold, and why?
6. Write `void sortByMarks(Student *arr, int n)` that sorts the array in place.
7. Write a tagged union that holds either an `int` or a 4-character string, plus a function that prints it correctly.

## Answers

1. `Student *pa[3]` is an **array of 3 pointers** to `Student`. `Student (*pa)[3]` is a **pointer to an array** of 3 `Student`s.
2. `2 * 28 = 56` bytes. Pointer arithmetic scales by the size of the pointed-to type.
3. `addGrace` receives a pointer to the first element, so it works on the original array. `byValue` receives a copy of the structure, so it changes only its own copy.
4. `struct A` is 12 bytes and `struct B` is 8 bytes (reordering removes padding). Verified in [`solutions.c`](solutions.c).
5. It holds the **bit pattern** of the float read as an integer: `0x4048F5C3` (1078523331) on a machine with IEEE-754 floats. The union shares memory, so no conversion happens.
6. See `sortByMarks` in [`solutions.c`](solutions.c): a bubble sort that swaps whole structures through a temporary `Student`.
7. See `Item` and `printItem` in [`solutions.c`](solutions.c): a `kind` tag plus a union of `int` and `char s[5]` (4 characters plus the terminator).

## Solutions output

```
2 Neha  91.0
1 Amit  78.5
3 Ravi  66.0
int: 7
str: ABCD
sizeof(struct A) = 12, sizeof(struct B) = 8
```

Previous: [12 Common mistakes](../12-common-mistakes/) | Back to [index](../README.md)
