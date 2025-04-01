// 10/02/2025
//Implement a List using Array and develop functions to perform insertion, deletion and linear search
//operations.
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void insert(int *list, int *size)
{

    int value, pos, i; // pos = 1 , idx = 0

    printf("Enter the position: ");
    scanf("%d", &pos);
    printf("enter value : ");
    scanf("%d", &value);
    pos--;
    if (pos < 0 || pos >= *size || pos > MAX_SIZE)
    {
        printf("Invalid position\n");
    }
    // push operation : adding some thing in last
    /*else if( pos == *size){
        list[pos] = value;
        (*size)++;
        printf("element inserted\n");
        }*/
    else
    {
        for (i = *size; i > pos; i--)
        {
            list[i] = list[i - 1];
        }
        list[pos] = value;
        (*size)++;
        printf("element inserted\n");
    }
}
// transversing : displaying the list
void display(int *list, int size)
{
    if (size == 0)
    {
        printf("list is empty\n");
    }
    else
    {
        int i;
        printf("list elements are : \n");
        for (i = 0; i < size; i++)
        {
            printf("%d ", list[i]);
        }
    }
}
void delete(int list, int *size)
{
    int pos, i;
    printf("enter position : \n");
    scanf("%d", &pos);
    pos--;
    if (pos < 0 || pos >= *size)
    {
        printf("invalid position\n");
    }
    else
    {
        for (i = pos; i < *size - 1; i++)
        {
            list[i] = list[i + 1];
        }
        (*size)++;
        printf("element deleted\n");
    }
}
// searching
/*void search(int list, int size, int value)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (list[i] == value)
        {
            printf("element found at position %d\n", i + 1);

        }

    }
}*/
int main()
{
    int list[MAX_SIZE], size;

    printf("enter list size : ");
    scanf("%d", &size);

    printf("enter list elements : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &list[i]);
    }
    while (1)
    {
        printf("1. for insertion \n");
        printf("2. for deletion \n");
        printf("3. for searching \n");
        printf("4. for transversing \n");
        printf("5. for exit \n");
        int choice;
        printf("enter choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(list, &size);
            break;
        case 2:
            delete (list, &size);
            break;
        case 3:
            break;
        case 4:
            display(list, size);
            break;
        case 5:
            break;
        default:
            printf("");
        }
        printf("\n");
        system("pause");
    }
    return 0;
}
