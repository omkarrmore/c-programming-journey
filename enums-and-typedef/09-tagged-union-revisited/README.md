# 09: Tagged union revisited

This topic ties the series together: an **enum** (the tag), a **union** (the payload) and a **struct** (the glue) combined with **typedef** so the code stays readable.

A union holds only one member at a time, so something must record which one is valid. That something is the enum.

```c
typedef enum { MSG_TEMP, MSG_BUTTON, MSG_TEXT } MsgType;

typedef struct {
    MsgType type;                 // the tag
    union {
        float   temperature;      // MSG_TEMP
        uint8_t button;           // MSG_BUTTON
        char    text[8];          // MSG_TEXT
    } payload;
} Message;
```

## Using it safely

```c
switch (m->type) {
case MSG_TEMP:   printf("%.1f\n", m->payload.temperature); break;
case MSG_BUTTON: printf("%u\n",   m->payload.button);      break;
case MSG_TEXT:   printf("%s\n",   m->payload.text);        break;
}
```

- **Set the tag whenever you write the payload**, and **read only the member the tag names**.
- Switch on the tag with no `default`, so the compiler warns if you add a message type and forget to handle it.
- Every `Message` has the same size, so you can store different kinds in one array or queue.

## Size

`sizeof(Message)` is the tag (4 bytes) plus the largest union member (the 8-byte `text`), so 12 bytes here, however many message kinds you add (as long as none is larger than 8 bytes).

## Where this pattern appears

- Event queues (button, timer, sensor events in one queue)
- Protocol parsers (different frame types)
- Interpreters and tokenizers (numbers, strings, symbols)

## Example

[`tagged_union.c`](tagged_union.c)

```
TEMP   36.6 C
BUTTON #2 pressed
TEXT   "READY"
sizeof(Message) = 12
```

Previous: [08 typedef in embedded code](../08-typedef-in-embedded/) | Next: [10 Common mistakes](../10-common-mistakes/)
