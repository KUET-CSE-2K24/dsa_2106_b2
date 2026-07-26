#include <iostream>
using namespace std;

// Q. Convert Decimal to Binary

int arr[100] = {0};
int top = -1;

int push(int x)
{
    arr[++top] = x;
}

int pop()
{
    arr[top] = 0;
    return arr[top--];
}

void display()
{
    cout << "Array: ";

    for (int i = 0; i <= top; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverse_display()
{

    for (int i = top; i >= 0; i--)
    {
        cout << arr[i];
    }
    cout << endl;
}

int main()
{
    int x = 4;
    int decimal = x;
    while (x > 0)
    {

        int y = x % 2;
        push(y);
        x /= 2;
    }

    cout << "Decimal: " << decimal << "\nBinary: ";
    reverse_display();
    return 0;
}