#include <iostream>

using namespace std;

#define size 5
int stack[size], top = - 1;

void push(int value)
{
    if (top == size -1)
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

int pop()
{
    if (top == -1)
    {
        cout << "Stack underflow" << endl;
    }
    else
    {
        return stack[top--];
    }
}

int peek()
{
    if (top == -1)
    {
        cout << "Stack underflow" << endl;
    }
    else
    {
        return stack[top];
    }
}

void display()
{
    if (top == -1)
    {
        cout << "Stack underflow" << endl;
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
    }
}

int main(int argc, char *argv[])
{
    push(5);
    push(10);
    push(15);
    display();
    
    cout << "pop = " << pop() << endl;
    
    display();
    
    cout << "peek = " << peek() << endl;
      
    display();
    
    return 0;
}