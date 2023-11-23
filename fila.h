#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct queue
{
    int front;
    int rear;
    int *data;
    int capacity;

} Queue;

bool is_empty(Queue *q)
{
    return q->front == q->rear;
}

bool is_full(Queue *q)
{
    return q->rear == q->capacity;
}

void enqueue(Queue *q, int value)
{
    if (is_full(q))
    {
        printf("QUEUE IS FULL\n");
        return;
    }
    q->data[q->rear] = value;
    q->rear++;
}

int dequeue(Queue *q)
{
    if (is_empty(q))
    {
        printf("QUEUE IS EMPTY\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front++;
    return value;
}

Queue *create_queue(int capacity)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
    q->data = (int *)malloc(capacity * sizeof(int));
    return q;
}
