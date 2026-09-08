#include <iostream>
using namespace std;

const int MAX = 100;

void push(int stack[], int &top, int value)
{
    if (top < MAX - 1)
    {
        stack[++top] = value;
    }
}

int pop(int stack[], int &top)
{
    return stack[top--];
}

int peek(int stack[], int top)
{
    return stack[top];
}

bool isEmpty(int top)
{
    return top == -1;
}

void display(int stack[], int top)
{
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << " ";
    }

    cout << endl;
}

int main()
{
    int stack1[MAX];
    int stack2[MAX];

    int top1 = -1;
    int top2 = -1;

    int n;

    cout << "===== SORT ARRAY USING STACKS =====\n";

    cout << "\nEnter number of elements: ";
    cin >> n;

    if (n < 1 || n > MAX)
    {
        cout << "Invalid size.\n";
        return 0;
    }

    cout << "Enter " << n << " elements:\n";

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        push(stack1, top1, value);
    }
    while (!isEmpty(top1))
    {
        int temp = pop(stack1, top1);

        while (!isEmpty(top2) && peek(stack2, top2) > temp)
        {
            push(stack1, top1, pop(stack2, top2));
        }

        push(stack2, top2, temp);
    }

    cout << "\nSorted array:\n";

    display(stack2, top2);

    return 0;
}