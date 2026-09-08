#include <iostream>
using namespace std;

const int MAX = 100;

int stackArray[MAX];
int top = -1;

void push(int value)
{
    stackArray[++top] = value;
}

int pop()
{
    return stackArray[top--];
}

int peek()
{
    return stackArray[top];
}

bool isEmpty()
{
    return top == -1;
}

int main()
{
    int arr[MAX];
    int result[MAX];
    int n;

    cout << "===== NEAREST SMALLER ELEMENT =====\n";

    cout << "\nEnter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {

        while (!isEmpty() && peek() >= arr[i])
        {
            pop();
        }

        if (isEmpty())
        {
            result[i] = -1;
        }
        else
        {
            result[i] = peek();
        }

        push(arr[i]);
    }

    cout << "\nNearest smaller elements:\n";

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}