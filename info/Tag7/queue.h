#pragma once

struct IntQueue;
typedef struct IntQueue IntQueue;

IntQueue *IntQueue_new(void);
int IntQueue_enqueue(IntQueue *queue, int value);
int IntQueue_dequeue(IntQueue *queue);
void IntQueue_delete(IntQueue *queue);
int IntQueue_empty(IntQueue *queue);
