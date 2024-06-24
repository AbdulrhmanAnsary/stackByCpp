#include <iostream>
#include <stdexcept>

using namespace std;

struct Node
{
    int data;
    Node *next = nullptr;
};

class StackUnderflowError : public runtime_error
{
  public:
    StackUnderflowError() : runtime_error("StackUnderflowError: The stack is empty") {}
};

class Stack
{
  public:
    Node *top = nullptr;

  public:
    Stack() {}

    ~Stack()
    {
        Node *current = top;

        while (current)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    bool isEmpty()
    {
        if (top)
            return false;
        else
            return true;
    }

    void push(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;

        if (top)
        {
            Node *previous = top;
            top = newNode;
            top->next = previous;
        }
        else
            top = newNode;
    }

    void display()
    {
        Node *temp = top;

        cout << "{";

        while (temp)
        {
            cout << temp->data;
            temp = temp->next;

            if (temp)
            {
                cout << ", ";
            }
        }

        cout << "}\n";
    }

    int pop()
    {
        if (top == nullptr)
            throw StackUnderflowError();
        else
        {
            Node *firstNode = top;
            top = firstNode->next;
            delete firstNode;

            return top->data;
        }
    }

    int peek()
    {
        if (top == nullptr)
            throw StackUnderflowError();
        else
            return top->data;
    }
};

int main(int argc, char *argv[])
{
    Stack nums;

    //nums.push(5);
    //nums.push(10);
    //nums.push(15);
    //nums.push(20);
    //nums.push(25);
    //nums.push(30);
    nums.display();

    try
    {
        cout << "pop = " << nums.pop() << endl;
        cout << "peek = " << nums.peek() << endl;

        nums.display();
    }
    catch (StackUnderflowError &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}