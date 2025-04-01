// WAP to understand Priority Queue
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct
{
    int element;
    int priority;
} PriorityQueue;

PriorityQueue pq[SIZE];
int front = -1, count = -1;

int isEmpty()
{
    return (front == -1) ? 1 : 0;
}

int isFull()
{
    return (count == SIZE - 1) ? 1 : 0;
}

void enqueue(int data, int priority)
{
    if (isEmpty())
    {
        count = count + 1;
        pq[count].element = data;
        pq[count].priority = priority;
        front = count;
    }
    else
    {
        int i;
        for (i = 0; i <= count; i++)
        {
            if (pq[i].priority < priority)
            {
                for (int j = count; j >= i; j--)
                {
                    pq[j+1]=pq[j];
                }
                    pq[i].element = data;
                    pq[i].priority = priority;
                    break;
                
            }
           
        }
        if (i == count + 1)
        {
            pq[i].element = data;
            pq[i].priority = priority;
        }
        count++;
     
    }  
    printf("element inserted !!!\n");
}

int dequeue()
{
    int data = pq[front].element;
    if (front == count)
    {
        front = count = -1;
    }
    else
    {
        front++;
    }
    return data;
}

int peek()
{
    return pq[front].element;
}

void display()
{

    printf("Priority Queue elements are: \n");
    for (int i = front; i <= count; i++)
    {
        printf("%d (Priority: %d)\n", pq[i].element, pq[i].priority);
    }
}

int main()
{
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        int choice, data, priority;
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isFull())
            {
                printf("Priority Queue Overflow !!!\n");
            }
            else
            {
                printf("Enter Element: ");
                scanf("%d", &data);
                printf("Enter Priority: ");
                scanf("%d", &priority);
                enqueue(data, priority);
            }
            break;
        case 2:
            if (isEmpty())
            {
                printf("Priority Queue Underflow !!!\n");
            }
            else
            {
                printf("%d is dequeued (removed) from the priority queue\n", dequeue());
            }
            break;
        case 3:
            if (isEmpty())
            {
                printf("Priority Queue is empty !!!\n");
            }
            else
            {
                printf("Element with highest priority is: %d\n", peek());
            }
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice !!!!!\n");
        }
        printf("\n\n");
        system("pause");
    }
    return 0;
}
