#include <iostream>
using namespace std;

const int MAX = 100;

int main()
{
    int temperature[MAX];
    int result[MAX];
    int stackArray[MAX];

    int top = -1;
    int n;

    cout << "===== DAILY TEMPERATURES =====\n";

    cout << "\nEnter number of days: ";
    cin >> n;

    if (n < 1 || n > MAX)
    {
        cout << "Invalid number of days.\n";
        return 0;
    }

    cout << "Enter temperatures:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> temperature[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (top != -1 &&
               temperature[stackArray[top]] <= temperature[i])
        {
            top--;
        }

        if (top == -1)
        {
            result[i] = 0;
        }
        else
        {
            result[i] = stackArray[top] - i;
        }

        stackArray[++top] = i;
    }

    cout << "\nDays until a warmer temperature:\n";

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}