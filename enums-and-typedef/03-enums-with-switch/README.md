# 03: Enums with `switch` (state machines)

Enums and `switch` are a natural pair. This is the standard way to write a state machine in embedded C.

```c
typedef enum { IDLE, RUNNING, FAULT, STATE_COUNT } MotorState;
typedef enum { EV_START, EV_STOP, EV_ERROR, EV_RESET, EVENT_COUNT } MotorEvent;

MotorState nextState(MotorState s, MotorEvent e)
{
    switch (s) {
    case IDLE:    if (e == EV_START) return RUNNING; break;
    case RUNNING: if (e == EV_STOP)  return IDLE;
                  if (e == EV_ERROR) return FAULT;   break;
    case FAULT:   if (e == EV_RESET) return IDLE;    break;
    case STATE_COUNT: break;
    }
    return s;      // event ignored in this state
}
```

## Name tables with designated initializers

```c
static const char *stateName[STATE_COUNT] = {
    [IDLE]    = "IDLE",
    [RUNNING] = "RUNNING",
    [FAULT]   = "FAULT"
};
printf("%s\n", stateName[s]);
```

The `[IDLE] =` form ties each string to its enum value, so reordering the enum cannot silently break the table.

## Key points

- **Leave out `default`** when switching on an enum. With `-Wall`, GCC and Clang then warn (`-Wswitch`) if you add a new enumerator and forget to handle it. A `default` hides that warning.
- Always end each `case` with `break` or `return`, otherwise execution falls through to the next case.
- Handling "no change" explicitly (`return s;`) keeps the machine predictable.
- Using `STATE_COUNT` as the table size lets the compiler catch a table that is too short.

## Example

[`state_machine.c`](state_machine.c)

```
IDLE     + START -> RUNNING
RUNNING  + STOP  -> IDLE
IDLE     + STOP  -> IDLE
IDLE     + START -> RUNNING
RUNNING  + ERROR -> FAULT
FAULT    + START -> FAULT
FAULT    + RESET -> IDLE
```

Notice that `STOP` in `IDLE` and `START` in `FAULT` are ignored.

Previous: [02 Enum vs #define](../02-enum-vs-define/) | Next: [04 Enum size and pitfalls](../04-enum-size-and-pitfalls/)
