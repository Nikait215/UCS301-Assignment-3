#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

char stackArray[MAX];
int top = -1;
void push(char ch)
{
    if (top == MAX - 1)
    {
        cout << "Stack Overflow!\n";
        return;
    }

    top++;
    stackArray[top] = ch;
}
char pop()
{
    if (top == -1)
    {
        return '\0';
    }

    char ch = stackArray[top];
    top--;

    return ch;
}

int main()
{
    string str;

    cout << "===== REVERSE STRING USING STACK =====\n";

    cout << "\nEnter a string: ";
    getline(cin, str);

    for (char ch : str)
    {
        push(ch);
    }

    cout << "\nReversed string: ";
    while (top != -1)
    {
        cout << pop();
    }

    cout << endl;

    return 0;
}