#include <stdio.h>

/* Q1 */
enum Q1 { A, B = 5, C, D = 2, E };

/* Q2 */
#define PTR int *

/* Q5: motor state machine */
typedef enum { IDLE, RUNNING, FAULT } MotorState;
typedef enum { EV_START, EV_STOP, EV_ERROR, EV_RESET } MotorEvent;

MotorState motorNext(MotorState s, MotorEvent e)
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
    }
    return s;
}

/* Q6: typedef'd struct with a function-pointer member */
typedef struct {
    int id;
    void (*onPress)(int id);
} Button;

static void sayPressed(int id) { printf("button %d pressed\n", id); }

/* Q7 */
enum Color { RED, GREEN, BLUE };

int main(void)
{
    /* Q1 */
    printf("Q1: A=%d B=%d C=%d D=%d E=%d\n", A, B, C, D, E);

    /* Q2 */
    PTR a, b;
    printf("Q2: sizeof(a)=%zu sizeof(b)=%zu\n", sizeof a, sizeof b);
    (void)a; (void)b;

    /* Q5 */
    MotorState s = IDLE;
    s = motorNext(s, EV_START);
    printf("Q5: after START -> %d (RUNNING=%d)\n", s, RUNNING);
    s = motorNext(s, EV_ERROR);
    printf("Q5: after ERROR -> %d (FAULT=%d)\n", s, FAULT);
    s = motorNext(s, EV_START);
    printf("Q5: START ignored in FAULT -> %d\n", s);
    s = motorNext(s, EV_RESET);
    printf("Q5: after RESET -> %d (IDLE=%d)\n", s, IDLE);

    /* Q6 */
    Button btn = {7, sayPressed};
    printf("Q6: ");
    btn.onPress(btn.id);

    /* Q7 */
    enum Color c = BLUE;
    printf("Q7: %d\n", c + 1);
    return 0;
}
