#include <iostream>
#include <string>
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

bool isMatchingPair(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

int main()
{
    string expression;

    cout << "===== BALANCED PARENTHESES =====\n";

    cout << "\nEnter an expression: ";
    getline(cin, expression);

    bool balanced = true;

    for (char ch : expression)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top == -1)
            {
                balanced = false;
                break;
            }

            char opening = pop();

            if (!isMatchingPair(opening, ch))
            {
                balanced = false;
                break;
            }
        }
    }

    if (top != -1)
    {
        balanced = false;
    }

    if (balanced)
    {
        cout << "\nExpression has balanced parentheses.\n";
    }
    else
    {
        cout << "\nExpression does NOT have balanced parentheses.\n";
    }

    return 0;
}