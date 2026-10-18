# 04: Array of structures

```c
#define MAX 3

Student cls[MAX] = {
    {1, "Amit", 78.5f},
    {2, "Neha", 91.0f},
    {3, "Ravi", 66.0f}
};

for (int i = 0; i < MAX; i++)
    printf("%d %s\n", cls[i].id, cls[i].name);
```

## Key points

- Access a member with `array[index].member`.
- Elements sit one after another in memory, so `sizeof(cls) == MAX * sizeof(Student)`.
- Like any array, `cls` decays to a pointer to its first element when passed to a function or used in an expression. That is what makes the next topic work.

## Example

[`array_of_structs.c`](array_of_structs.c)

```
1  Amit   78.5
2  Neha   91.0
3  Ravi   66.0
Average = 78.50
sizeof(cls) = 84 (= 3 x 28)
```

Previous: [03 Nested and self-referential](../03-nested-and-self-referential/) | Next: [05 Pointer to array of structures](../05-pointer-to-array-of-structures/)
