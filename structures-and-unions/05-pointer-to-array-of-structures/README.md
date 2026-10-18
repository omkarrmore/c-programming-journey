# 05: Pointer to an array of structures, and passing it to functions

The most useful pattern in practice: address books, student records, sensor tables.

## Pointer to the first element

`cls` decays to `Student *`, so a pointer walks the array with normal pointer arithmetic. `p + 1` moves by `sizeof(Student)` bytes, not by 1 byte.

```c
Student *p = cls;          // same as &cls[0]

p->name;                   // cls[0].name
(p + 1)->name;             // cls[1].name
(*(p + 2)).name;           // cls[2].name
```

`arr[i].marks` and `(arr + i)->marks` are the same thing.

## Passing the array to a function

Only a **pointer to the first element** is passed. Nothing is copied, so the function works on the original array. Always pass the element count separately, because the function cannot know the size.

```c
void printStudents(const Student *arr, int n);   // read-only, 'const' blocks writes
void addGrace(Student *arr, int n, float grace); // modifies the caller's data
Student *findTopper(Student *arr, int n);        // returns a pointer INTO the array
```

## Pointer to the whole array (less common)

```c
Student (*pa)[MAX] = &cls;      // pointer to an array of MAX Students
printf("%s\n", (*pa)[2].name);  // Ravi
```

The parentheses matter:

- `Student (*pa)[MAX]` is a **pointer to an array**.
- `Student *pa[MAX]` is an **array of pointers**.

`pa + 1` jumps over the entire array, while `p + 1` jumps over one element. For everyday code, a plain `Student *` plus a count is simpler.

## Dynamic array

```c
Student *list = malloc(n * sizeof(Student));
if (list == NULL) return 1;
addGrace(list, n, 5.0f);       // the same functions work unchanged
free(list);
```

## Key points

- Pass `(pointer, count)`, never just the pointer.
- Use `const Student *` when the function only reads.
- A function may return a pointer into the caller's array. It must **never** return a pointer to its own local variable.
- Every `malloc` needs a matching `free`, and always check for `NULL`.

## Example

[`pointer_to_array.c`](pointer_to_array.c)

```
First:  Amit
Second: Neha
1  Amit     80.5
2  Neha     93.0
3  Ravi     68.0
Topper: Neha (93.0)
Via pointer to array: Ravi
p + 1  moves 28 bytes
pa + 1 moves 84 bytes
10  Dyn1     55.0
11  Dyn2     65.0
```

Previous: [04 Array of structures](../04-array-of-structures/) | Next: [06 Passing structures to functions](../06-passing-structures-to-functions/)
