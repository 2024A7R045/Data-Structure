//WAP to understand expression conversion
//lab 5
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int top = -1;
char operator[100];
int precedence(char opr)
{
    //Checking the precedence order of operators (highest operator precedence is assigned highest number)
    switch (opr)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    //For precedence of brackets 
    default:
        return 0;
    }
}
char* convertInfixToPostfix(char *exp)
{
    int size = strlen(exp),top = -1,index = 0;
    char operator[size];
    char *str = (char*)malloc(size+1);
    for (int i = 0; i < size; i++)
    {
        char ch = exp[i];
        if (isdigit(ch) || isalpha(ch))
        {
            str[index++] = ch;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            if (top == -1)
            {
                operator[++top] = ch;
            }
            else
            {
                while (top != -1 && precedence(ch) <= precedence(operator[top]))
                {
                    str[index++] = operator[top--];
                }
                operator[++top] = ch;
            }
        }
        else if (ch == '(')
        {
           operator[++top] = ch;
        }
        else if (ch == ')')
        {
           while (operator[top] != '(')
           {
                str[index++] = operator[top--];
           }
           top--;
        }
    }
    while (top != -1)
    {
        str[index++] = operator[top--];
    }
    str[index] = '\0';
    return str;
}
char* strreverse(char *str)
{
    int size = strlen(str),i,j;
    char *temp = (char*)malloc(size+1);
    for (i = size-1, j = 0; i >= 0; i--,j++)
    {
        temp[j] = str[i];
    }
    temp[j] = '\0';
    return temp;
}
char* convertInfixToPrefix(char *exp)
{
    int size = strlen(exp),top = -1,index = 0;
    char operator[size];
    char *str = (char*)malloc(size+1);
    for (int i = size-1; i >= 0; i--)
    {
        char ch = exp[i];
        if (isdigit(ch) || isalpha(ch))
        {
            str[index++] = ch;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            if (top == -1)
            {
                operator[++top] = ch;
            }
            else
            {
                while (top != -1 && precedence(ch) <= precedence(operator[top]))
                {
                    str[index++] = operator[top--];
                }
                operator[++top] = ch;
            }
        }
        else if (ch == ')')
        {
           operator[++top] = ch;
        }
        else if (ch == '(')
        {
           while (operator[top] != ')')
           {
                str[index++] = operator[top--];
           }
           top--;
        }
    }
    while (top != -1)
    {
        str[index++] = operator[top--];
    }
    str[index] = '\0';
    return strreverse(str);
}
char* convertPostfixToInfix(char *exp)
{
    int size = strlen(exp), top = -1;
    char stack[size][100];
    for (int i = 0; i < size; i++)
    {
        char ch = exp[i];
        if (isalnum(ch))
        {
            char temp[] = {ch , '\0'};
            strcpy(stack[++top] , temp);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            char *s1 = stack[top--];
            char *s2 = stack[top--];  
            char s3[100];
            snprintf(s3, 100, "(%s%c%s)",s2,ch,s1);
            strcpy(stack[++top], s3); 
        }
    }
    char *result = stack[top];
    return result;
}
char* convertPrefixToInfix(char *exp)
{
    int size = strlen(exp), top = -1;
    char stack[size][100];
    for (int i = size-1; i >= 0; i--)
    {
        char ch = exp[i];
        if (isalnum(ch))
        {
            char temp[] = {ch , '\0'};
            strcpy(stack[++top] , temp);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            char *s1 = stack[top--];
            char *s2 = stack[top--];  
            char s3[100];
            snprintf(s3, 100, "(%s%c%s)",s1,ch,s2);
            strcpy(stack[++top], s3); 
        }
    }
    char *result = stack[top];
    return result;
}
int main(){
    char exp[100];
    printf("Enter Infix expression = ");
    gets(exp);
    printf("\nPostfix form of Infix expression %s is = %s \n",exp, convertInfixToPostfix(exp));
    printf("\nPrefix form of Infix expression %s is = %s \n",exp, convertInfixToPrefix(exp));
    printf("\nEnter Postfix expression = ");
    gets(exp);
    printf("\nInfix form of Postfix expression %s is = %s \n",exp, convertPostfixToInfix(exp));
    printf("\nEnter Prefix expression = ");
    gets(exp);
    printf("\nInfix form of Prefix expression %s is = %s \n",exp, convertPrefixToInfix(exp));
    return 0;
}