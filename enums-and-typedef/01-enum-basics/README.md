# 01: Enum basics

An enumeration gives names to a set of integer constants.

```c
enum Color { RED, GREEN, BLUE };                        // 0, 1, 2
enum Level { LOW = 10, MEDIUM, HIGH = 50, CRITICAL };   // 10, 11, 50, 51

enum Color c = GREEN;
```

With `typedef` you can drop the `enum` keyword:

```c
typedef enum { OFF, ON } Power;
Power p = ON;
```

## Auto-increment rule

The first enumerator is `0` unless you set it. Every enumerator without an explicit value is **the previous value + 1**.

```c
enum Q { A, B = 5, C, D = 2, E };   // A=0, B=5, C=6, D=2, E=3
```

Values do not have to be unique or in order. Two names can share a value.

## The `COUNT` trick

Add a last entry that is never used as a real value. It automatically equals the number of items, so you can loop over every value or size an array.

```c
typedef enum { DAY_MON, DAY_TUE, DAY_WED, DAY_COUNT } Day;

for (Day d = DAY_MON; d < DAY_COUNT; d++) { ... }
```

## Key points

- Enumerators are plain integer constants. `RED + 1` is just `1`.
- Enumerator names live in the **same namespace as ordinary identifiers**, so two enums in the same scope cannot reuse a name.
- Use `UPPER_CASE` names, often with a shared prefix (`DAY_MON`, `EV_START`), so they do not clash.
- If you need specific bit patterns or register values, assign them explicitly.

## Example

[`enum_basics.c`](enum_basics.c)

```
RED=0 GREEN=1 BLUE=2
LOW=10 MEDIUM=11 HIGH=50 CRITICAL=51
c=1, p=1
c + 1 = 3
day 0
day 1
day 2
```

Next: [02 Enum vs #define](../02-enum-vs-define/)
