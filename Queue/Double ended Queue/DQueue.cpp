/*
    Name: Shubham Sarang
    Roll No: 1345
    Unit 4: Queue
    Program: Double Ended Queue
*/

#include <iostream>
#include <conio.h>
using namespace std;

// 1. Node Template
class DEQNode
{
	public:
    	int data;
    	DEQNode *right;
    	DEQNode *left;
};

// 2. Queues Template
class DEQueue
{
    DEQNode *front;
    DEQNode *rear;

public:
    DEQueue()
    {
        front = NULL;
        rear = NULL;
    }
    void EnqueueFront(int x);
    void EnqueueRear(int x);
    void DequeueFront();
    void DequeueRear();
    void PeekFront();
    void PeekRear();
    void Display();
    int Empty();
};

// 3. Functions
int DEQueue ::Empty()
{
    int res = (front == NULL && rear == NULL)? 1 : 0;
    return res;
}
void DEQueue ::EnqueueFront(int x)
{
    DEQNode *t = new DEQNode();
    t->data = x;
    t->right = NULL;
    t->left = NULL;
    if (front == NULL)
    {
        front = t;
        rear = t;
    }
    else
    {
        t->right = front;
        front->left = t;
        front = t;
    }
}
void DEQueue ::EnqueueRear(int x)
{
    DEQNode *t = new DEQNode();
    t->data = x;
    t->right = NULL;
    t->left = NULL;
    if (front == NULL)
    {
        front = t;
        rear = t;
    }
    else
    {
        t->left = rear;
        rear->right = t;
        rear = t;
    }
}
void DEQueue ::DequeueFront()
{
    if (Empty())
    {
        cout << "Queue Underflow" << endl;
        return;
    }
    DEQNode *tmp = front;
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->right;
        front->left = NULL;
    }
    cout << "Dequeued Element from front " << tmp->data;
    delete tmp;
}
void DEQueue ::DequeueRear()
{
    if (Empty())
    {
        cout << "Queue Underflow" << endl;
        return;
    }
    DEQNode *tmp = rear;
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        rear = rear->left;
        rear->right = NULL;
    }
    cout << "Dequeued Element from front " << tmp->data;
    delete tmp;
}
void DEQueue ::Display()
{
    DEQNode *tmp = front;
    if (Empty())
    {
        cout << "Queue Underflow";
        return;
    }
    while(tmp != NULL)
    {
    	cout<<tmp->data<<" ";
    	tmp = tmp->right;
	}
}
void DEQueue ::PeekFront()
{
    if (Empty())
    {
        cout << "Queue Underflow!!";
        return;
    }
    DEQNode *tmp = front;
    cout << "Element at the Front is " << tmp->data;
}
void DEQueue ::PeekRear()
{
    if (Empty())
    {
        cout << "Queue Underflow!!";
        return;
    }
    DEQNode *tmp = rear;
    cout << "Element at the Rear is " << tmp->data;
} // 4. Menu
int main()
{
    DEQueue q;
    int num, ch;
    while (1)
    {
        system("cls");
        cout << "*** Double Ended Queue ***" << endl;
        cout << "1. Enqueue Front Element" << endl;
        cout << "2. Enqueue Rear Element" << endl;
        cout << "3. Dequeue Front Element" << endl;
        cout << "4. Dequeue Rear Element" << endl;
        cout << "5. Peek Front Operation" << endl;
        cout << "6. Peek Rear Operation" << endl;
        cout << "7. Display the Queue" << endl;
        cout << "8. Exit" << endl
             << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter a Value : ";
            cin >> num;
            q.EnqueueFront(num);
            getch();
            break;
        case 2:
            cout << "Enter a Value : ";
            cin >> num;
            q.EnqueueRear(num);
            getch();
            break;
        case 3:
            q.DequeueFront();
            getch();
            break;
        case 4:
            q.DequeueRear();
            getch();
            break;
        case 5:
            q.PeekFront();
            getch();
            break;
        case 6:
            q.PeekRear();
            getch();
            break;
        case 7:
            q.Display();
            getch();
            break;
        case 8:
            exit(1);
        default:
            cout << "Incorrect choice !";
            getch();
            break;
            cout << endl;
        } // end of switch
    }     // end of while
} // end of main
