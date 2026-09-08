#include <iostream>
using namespace std;

const int MAX = 100;

int main()
{
    int arr[MAX];
    int result[MAX];
    int stackArray[MAX];

    int top = -1;
    int n;

    cout << "===== NEXT GREATER ELEMENT =====\n";

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
        cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (top != -1 && stackArray[top] <= arr[i])
        {
            top--;
        }

        if (top == -1)
        {
            result[i] = -1;
        }
        else
        {
            result[i] = stackArray[top];
        }

        stackArray[++top] = arr[i];
    }

    cout << "\nNext Greater Elements:\n";

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}