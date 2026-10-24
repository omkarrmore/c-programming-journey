#include <stdio.h>

typedef enum { IDLE, RUNNING, FAULT, STATE_COUNT } MotorState;
typedef enum { EV_START, EV_STOP, EV_ERROR, EV_RESET, EVENT_COUNT } MotorEvent;

/* designated array initializers keep names and values in sync */
static const char *stateName[STATE_COUNT] = {
    [IDLE]    = "IDLE",
    [RUNNING] = "RUNNING",
    [FAULT]   = "FAULT"
};

static const char *eventName[EVENT_COUNT] = {
    [EV_START] = "START",
    [EV_STOP]  = "STOP",
    [EV_ERROR] = "ERROR",
    [EV_RESET] = "RESET"
};

/* no 'default' on purpose: -Wall warns if a state is ever left out */
MotorState nextState(MotorState s, MotorEvent e)
{
    switch (s) {
    case IDLE:
        if (e == EV_START) return RUNNING;
        break;
    case RUNNING:
        if (e == EV_STOP)  return IDLE;
        if (e == EV_ERROR) return FAULT;
        break;
    case FAULT:
        if (e == EV_RESET) return IDLE;
        break;
    case STATE_COUNT:
        break;
    }
    return s;                       /* event ignored in this state */
}

int main(void)
{
    MotorEvent script[] = { EV_START, EV_STOP, EV_STOP, EV_START,
                            EV_ERROR, EV_START, EV_RESET };
    MotorState s = IDLE;

    for (unsigned i = 0; i < sizeof script / sizeof script[0]; i++) {
        MotorState n = nextState(s, script[i]);
        printf("%-8s + %-5s -> %s\n", stateName[s], eventName[script[i]], stateName[n]);
        s = n;
    }
    return 0;
}
