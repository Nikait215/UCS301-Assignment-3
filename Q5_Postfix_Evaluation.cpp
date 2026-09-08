#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int MAX = 100;

int stackArray[MAX];
int top = -1;

void push(int value)
{
    if (top < MAX - 1)
    {
        stackArray[++top] = value;
    }
}

int pop()
{
    if (top == -1)
    {
        return 0;
    }

    return stackArray[top--];
}

int calculate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;

    case '-':
        return a - b;

    case '*':
        return a * b;

    case '/':
        return a / b;

    case '^':
    {
        int result = 1;

        for (int i = 0; i < b; i++)
        {
            result *= a;
        }

        return result;
    }

    default:
        return 0;
    }
}

int main()
{
    string postfix;

    cout << "===== POSTFIX EXPRESSION EVALUATION =====\n";

    cout << "\nEnter postfix expression: ";
    getline(cin, postfix);

    for (char ch : postfix)
    {
        if (ch == ' ')
        {
            continue;
        }
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/' ||
                 ch == '^')
        {
            int b = pop();
            int a = pop();

            int result = calculate(a, b, ch);

            push(result);
        }
    }

    cout << "\nResult = " << pop() << endl;

    return 0;
}