#include <iostream>
using namespace std;

const int MAX = 100;

int stackArray[MAX];
int top = -1;
bool isEmpty()
{
    return top == -1;
}
bool isFull()
{
    return top == MAX - 1;
}
void push(int value)
{
    if (isFull())
    {
        cout << "Stack Overflow! Stack is full.\n";
        return;
    }

    top++;
    stackArray[top] = value;

    cout << "Element pushed successfully.\n";
}
void pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow! Stack is empty.\n";
        return;
    }

    cout << "Popped element: " << stackArray[top] << endl;
    top--;
}
void peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty. Nothing to peek.\n";
        return;
    }

    cout << "Top element: " << stackArray[top] << endl;
}
void display()
{
    if (isEmpty())
    {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack elements: ";

    for (int i = top; i >= 0; i--)
    {
        cout << stackArray[i] << " ";
    }

    cout << endl;
}

int main()
{
    int choice;
    int value;

    do
    {
        cout << "\n===== STACK USING ARRAY =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Is Empty\n";
        cout << "4. Is Full\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            if (isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Stack is not empty.\n";
            break;

        case 4:
            if (isFull())
                cout << "Stack is full.\n";
            else
                cout << "Stack is not full.\n";
            break;

        case 5:
            display();
            break;

        case 6:
            peek();
            break;

        case 7:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}