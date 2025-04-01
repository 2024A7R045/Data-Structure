// WAP to understand Priority Queue
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

// Typedef struct to represent an element in the priority queue
typedef struct {
    int data;      // The actual data value
    int priority;  // The priority associated with the data
} PriorityQueue;

// Array to store priority queue elements
PriorityQueue pq[SIZE];
int size = 0; // Variable to track the number of elements in the priority queue

// Function to check if the priority queue is empty
int isEmpty() {
    return (size == 0) ? 1 : 0;
}

// Function to check if the priority queue is full
int isFull() {
    return (size == SIZE) ? 1 : 0;
}

// Function to insert an element into the priority queue based on priority
void enqueue(int data, int priority) {
    if (isFull()) {
        printf("Priority Queue Overflow !!!\n");
        return;
    }
    int i;
    // Shifting elements to maintain priority order
    for (i = size - 1; i >= 0 && pq[i].priority > priority; i--) {
        pq[i + 1] = pq[i];
    }
    // Insert the new element at the correct position
    pq[i + 1].data = data;
    pq[i + 1].priority = priority;
    size++;
    printf("Element inserted !!!\n");
}

// Function to remove the element with the highest priority (lowest priority value)
int dequeue() {
    if (isEmpty()) {
        printf("Priority Queue Underflow !!!\n");
        return -1;
    }
    return pq[--size].data; // Removing the highest priority element
}

// Function to get the element with the highest priority without removing it
int peek() {
    if (isEmpty()) {
        printf("Priority Queue is empty !!!\n");
        return -1;
    }
    return pq[size - 1].data;
}

// Function to display all elements of the priority queue
void display() {
    if (isEmpty()) {
        printf("Priority Queue is empty !!!\n");
        return;
    }
    printf("Priority Queue elements are: \n");
    for (int i = 0; i < size; i++) {
        printf("%d (Priority: %d)\n", pq[i].data, pq[i].priority);
    }
}

// Main function to provide menu-driven operations for the priority queue
int main() {
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        int choice, data, priority;
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Priority Queue Overflow !!!\n");
                } else {
                    printf("Enter Element: ");
                    scanf("%d", &data);
                    printf("Enter Priority: ");
                    scanf("%d", &priority);
                    enqueue(data, priority);
                }
                break;
            case 2:
                if (isEmpty()) {
                    printf("Priority Queue Underflow !!!\n");
                } else {
                    printf("%d is dequeued (removed) from the priority queue\n", dequeue());
                }
                break;
            case 3:
                if (isEmpty()) {
                    printf("Priority Queue is empty !!!\n");
                } else {
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
