/*
	Name: Shubham Sarang
	Roll No: 1345
	Unit 4: Queue
	Program: Circular Queue
*/

#include <iostream>
#include <conio.h>
#define MAX 4
using namespace std;

// 2. Queues Template
class CQueue
{
    int A[MAX];
    int front;
    int rear;
    int cnt;

public:
    CQueue()
    {
        front = -1;
        rear = -1;
        cnt = 0;
    }
    void Enqueue(int x);
    void Dequeue();
    void PeekFront();
    void PeekRear();
    void Display();
    int Full();
    int Empty();
}; // 3. Functions
int CQueue ::Full()
{
    if (cnt == MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
} // end of the Full
int CQueue ::Empty()
{
    if (cnt == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
} // end of the Empty
void CQueue ::Enqueue(int x)
{
    if (Full())
    {
        cout << "Queue OverFlow";
        return;
    }
    if (front == -1)
    {
        front++;
    }
    if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    A[rear] = x;
    cnt++;
} // End Of Enqueue
void CQueue ::Dequeue()
{
    if (Empty())
    {
        cout << "Underflow!!";
        return;
    }
    int tmp = A[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    cout << "Dequeued Element is : " << tmp;
    cnt--;
} // end of Dequeue
void CQueue ::Display()
{
    if (Empty())
    {
        cout << "Empty!!";
        return;
    }
    int j = front;
    for (int i = 1; i <= cnt; i++)
    {
        cout << A[j] << " ";
        if (j == MAX - 1)
        {
            j = 0;
        }
        else
        {
            j++;
        }
    }
} // end of the Display
void CQueue ::PeekFront()
{
    if (Empty())
    {
        cout << "Underflow!!";
    }
    else
    {
        cout << "Element at the Front is " << A[front];
    }
} // end of the PeekFront
void CQueue ::PeekRear()
{
    if (Empty())
    {
        cout << "Underflow!!";
    }
    else
    {
        cout << "Element at the Rear is " << A[rear];
    }
} // end of the PeekRear
// 4. Menu
int main()
{
    CQueue c;
    int num, ch;
    while (1)
    {
        system("cls");
        cout << "*** Circular Queue ***" << endl;
        cout << "1. Enqueue Element" << endl;
        cout << "2. Dequeue Element" << endl;
        cout << "3. Peek Front Operation" << endl;
        cout << "4. Peek Rear Operation" << endl;
        cout << "5. Display the Queue" << endl;
        cout << "6. Exit" << endl
             << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter a Value : ";
            cin >> num;
            c.Enqueue(num);
            getch();
            break;
        case 2:
            c.Dequeue();
            getch();
            break;
        case 3:
            c.PeekFront();
            getch();
            break;
        case 4:
            c.PeekRear();
            getch();
            break;
        case 5:
            c.Display();
            getch();
            break;
        case 6:
            exit(1);
        default:
            cout << "Incorrect choice !";
            getch();
            break;
            cout << endl;
        } // end of switch
    }     // end of while
} // end of main
