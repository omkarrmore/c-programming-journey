#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* enum = the tag, union = the payload, struct = glues them together */
typedef enum { MSG_TEMP, MSG_BUTTON, MSG_TEXT } MsgType;

typedef struct {
    MsgType type;
    union {
        float   temperature;        /* MSG_TEMP   */
        uint8_t button;             /* MSG_BUTTON */
        char    text[8];            /* MSG_TEXT   */
    } payload;
} Message;

static void printMessage(const Message *m)
{
    switch (m->type) {
    case MSG_TEMP:
        printf("TEMP   %.1f C\n", m->payload.temperature);
        break;
    case MSG_BUTTON:
        printf("BUTTON #%u pressed\n", m->payload.button);
        break;
    case MSG_TEXT:
        printf("TEXT   \"%s\"\n", m->payload.text);
        break;
    }
}

int main(void)
{
    Message queue[3];

    queue[0].type = MSG_TEMP;
    queue[0].payload.temperature = 36.6f;

    queue[1].type = MSG_BUTTON;
    queue[1].payload.button = 2;

    queue[2].type = MSG_TEXT;
    strcpy(queue[2].payload.text, "READY");

    for (int i = 0; i < 3; i++)
        printMessage(&queue[i]);

    printf("sizeof(Message) = %zu\n", sizeof(Message));
    return 0;
}
