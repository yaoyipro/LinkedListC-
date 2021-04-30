#include <iostream>
#include <stdio.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* first;
public:
    LinkedList() { first = NULL; }
    LinkedList(int A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();

};

LinkedList::LinkedList(int A[], int n)
{
    Node* last, * t;
    int i = 0;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList()
{
    Node* p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::Display()
{
    Node* p = first;

    while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
    cout << endl;
}

int LinkedList::Length()
{
    Node* p = first;
    int len = 0;

    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void LinkedList::Insert(int index, int x)
{
    Node* t, * p = first;

    if (index <0 || index > Length())
        return;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int LinkedList::Delete(int index)
{
    Node* p, * q = NULL;
    int x = -1;

    if (index < 1 || index > Length())
        return -1;
    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = first;
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

int main()
{
    int A[] = { 1,2,3,4,5 };
    LinkedList l(A, 5);

    l.Insert(3, 10);

    l.Display();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
