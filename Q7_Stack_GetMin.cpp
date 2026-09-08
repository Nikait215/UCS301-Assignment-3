#include <iostream>
using namespace std;

const int MAX = 100;

int mainStack[MAX];
int minStack[MAX];

int top = -1;
int minTop = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        cout << "Stack Overflow! Stack is full.\n";
        return;
    }

    top++;
    mainStack[top] = value;

    if (minTop == -1 || value <= minStack[minTop])
    {
        minTop++;
        minStack[minTop] = value;
    }

    cout << "Element pushed successfully.\n";
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow! Stack is empty.\n";
        return;
    }

    int value = mainStack[top];

    cout << "Popped element: " << value << endl;

    if (value == minStack[minTop])
    {
        minTop--;
    }

    top--;
}

void getMin()
{
    if (top == -1)
    {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Minimum element: "
         << minStack[minTop] << endl;
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack elements: ";

    for (int i = top; i >= 0; i--)
    {
        cout << mainStack[i] << " ";
    }

    cout << endl;
}

int main()
{
    int choice;
    int value;

    do
    {
        cout << "\n===== STACK WITH GETMIN() =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Get Minimum\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

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
            getMin();
            break;

        case 4:
            display();
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}