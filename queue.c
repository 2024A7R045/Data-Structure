//10/mar/2025
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int queue[SIZE], front = -1, rear = -1;

int isempty()
{
    return (front == -1) ? 1 : 0;
}
int isfull()
{
    return (rear == SIZE - 1) ? 1 : 0;
}
int enqueue(int data)
{
    queue[++rear] = data;
    if (front == -1)
        front = rear;
    printf("element inserted!!!\n");
}
int dequeue()
{
    int data = queue[front];
    if (front == rear)
    {
        front == rear = -1;
    }
    else
    {
        front++;
        return data;
    }
}
int peek()
{
    return queue[front];
}
int dispaly()
{
    printf("queue element are : \n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d", queue[i]);
    }
}

int main()
{
    while (1)
    {
        printf("");
        printf("");
        printf("");
        printf("");
        printf("");
        printf("");
    }
    int choice, data;
    printf("");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        if (isfull())
        {
            printf("Queue is full\n");
        }
        else
        {
            printf("Enter element \n");
            scanf("%d", &data);
            enqueue(data);
        }
        break;
    case 2:
        if (isempty())
        {
            printf("queue inderflow!!!\n");
        }
        else
        {
            printf("%d is dequeue form the queue\n", dequeue());
        }
        break;
    case 3:
        if (isempty())
        {
            printf("queue inderflow!!!\n");
        }
        else
        {
            printf("element form the queue\n", peek());
        }
        break;
        break;
    case 4:
        if (isempty())
        {
            printf("queue inderflow!!!\n");
        }
        else
        {
            display();
        }
        break;
    case 5: 
    exit(0);
        break;
    default:
        printf("invalid choice\n");
    }
}