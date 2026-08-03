#include <iostream>
using namespace std;

int arr[100] = {0};

int front = 0;
int rear = -1;

int size()
{
    return rear - front + 1;
}

void enqueue(int x)
{
    rear++;
    arr[rear] = x;
}

int dequeue()
{
    return arr[front++];
}

int main()
{

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);

    while (size() > 1)
    {
        dequeue();
        enqueue(dequeue());
    }

    cout << arr[front] << endl;

    return 0;
}