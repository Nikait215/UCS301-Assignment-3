#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int MAX = 100;

char stackArray[MAX];
int top = -1;

void push(char ch)
{
    if (top < MAX - 1)
    {
        stackArray[++top] = ch;
    }
}

char pop()
{
    if (top == -1)
    {
        return '\0';
    }

    return stackArray[top--];
}

char peek()
{
    if (top == -1)
    {
        return '\0';
    }

    return stackArray[top];
}

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/' ||
           ch == '^';
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

int main()
{
    string infix;
    string postfix = "";

    cout << "===== INFIX TO POSTFIX =====\n";

    cout << "\nEnter an infix expression: ";
    getline(cin, infix);

    for (char ch : infix)
    {

        if (ch == ' ')
        {
            continue;
        }

        if (isalnum(ch))
        {
            postfix += ch;
        }

        else if (ch == '(')
        {
            push(ch);
        }

        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix += pop();
            }

            if (top != -1 && peek() == '(')
            {
                pop();
            }
        }

        else if (isOperator(ch))
        {
            while (top != -1 &&
                   peek() != '(' &&
                   precedence(peek()) >= precedence(ch))
            {
                postfix += pop();
            }

            push(ch);
        }
    }

    while (top != -1)
    {
        postfix += pop();
    }

    cout << "\nPostfix expression: " << postfix << endl;

    return 0;
}