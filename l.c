#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int top1 = -1, top2 = -1;
double operand[100];
char operator[100];

int precedence(char opr) {
    switch (opr) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

void doProcess() {
    if (top1 < 1 || top2 < 0) return;
    double x = operand[top1--];
    double y = operand[top1--];
    char opr = operator[top2--];
    double z;
    switch (opr) {
        case '+': z = y + x; break;
        case '-': z = y - x; break;
        case '*': z = y * x; break;
        case '/': z = (x != 0) ? y / x : 0; break;
        case '^': z = pow(y, x); break;
    }
    operand[++top1] = z;
}

double evalInfixExpression(char *exp) {
    int size = strlen(exp);
    for (int i = 0; i < size; i++) {
        char ch = exp[i];
        if (isdigit(ch) || (ch == '-' && (i == 0 || exp[i - 1] == '('))) {
            double num = 0;
            int sign = (ch == '-') ? -1 : 1;
            if (ch == '-') i++;
            while (isdigit(exp[i]) || exp[i] == '.') {
                if (exp[i] == '.') {
                    i++;
                    double decimalPlace = 0.1;
                    while (isdigit(exp[i])) {
                        num += (exp[i] - '0') * decimalPlace;
                        decimalPlace /= 10;
                        i++;
                    }
                    break;
                }
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            operand[++top1] = num * sign;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (top2 != -1 && precedence(ch) <= precedence(operator[top2])) {
                doProcess();
            }
            operator[++top2] = ch;
        } else if (ch == '(') {
            operator[++top2] = ch;
        } else if (ch == ')') {
            while (top2 >= 0 && operator[top2] != '(') {
                doProcess();
            }
            if (top2 >= 0) top2--;
        }
    }
    while (top2 != -1) {
        doProcess();
    }
    return operand[top1--];
}

double evalPostfixExpression(char *exp) {
    int size = strlen(exp);
    for (int i = 0; i < size; i++) {
        char ch = exp[i];
        if (isdigit(ch)) {
            double num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            operand[++top1] = num;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            if (top1 < 1) continue;
            double x = operand[top1--];
            double y = operand[top1--];
            double z;
            switch (ch) {
                case '+': z = y + x; break;
                case '-': z = y - x; break;
                case '*': z = y * x; break;
                case '/': z = (x != 0) ? y / x : 0; break;
                case '^': z = pow(y, x); break;
            }
            operand[++top1] = z;
        }
    }
    return operand[top1--];
}

double evalPrefixExpression(char *exp) {
    int size = strlen(exp);
    for (int i = size - 1; i >= 0; i--) {
        char ch = exp[i];
        if (isdigit(ch)) {
            double num = 0, place = 1;
            while (i >= 0 && isdigit(exp[i])) {
                num = (exp[i] - '0') * place + num;
                place *= 10;
                i--;
            }
            i++;
            operand[++top1] = num;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            if (top1 < 1) continue;
            double x = operand[top1--];
            double y = operand[top1--];
            double z;
            switch (ch) {
                case '+': z = x + y; break;
                case '-': z = x - y; break;
                case '*': z = x * y; break;
                case '/': z = (y != 0) ? x / y : 0; break;
                case '^': z = pow(x, y); break;
            }
            operand[++top1] = z;
        }
    }
    return operand[top1--];
}

int main() {
    char str[100];
    printf("Enter Infix Expression :");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;
    printf("Result = %.2lf\n", evalInfixExpression(str));

    printf("Enter Postfix Expression :");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;
    printf("Result = %.2lf\n", evalPostfixExpression(str));

    printf("Enter Prefix Expression :");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;
    printf("Result = %.2lf\n", evalPrefixExpression(str));
    
    return 0;
}
