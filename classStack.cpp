#include <iostream>
#include <stdexcept>

using namespace std;

class StackUnderflowError : public runtime_error
{
  public:
    StackUnderflowError() : runtime_error("StackUnderflowError: The stack is empty") {}
};

class StackOverflowError : public runtime_error
{
  public:
    StackOverflowError() : runtime_error("StackOverflowError: The stack is full") {}
};

#define size 5
class Stack
{
  private:
    int stack[size];
    int top = -1;

  public:
    Stack() {}

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    void handleStackErrors()
    {
        try
        {
            if (isEmpty())
                throw StackUnderflowError();
            else if (top == size -1)
              throw StackOverflowError();
        }
        catch (StackUnderflowError &e)
        {
            cerr << e.what() << endl;
        }
        catch (StackOverflowError &e)
        {
            cerr << e.what() << endl;
        }
    }

    void push(int value)
    {
        if (top == size - 1)
            handleStackErrors();
        else
        {
            top++;
            stack[top] = value;
        }
    }

    void display()
    {
        cout << "{";

        for (int i = top; i >= 0; i--)
        {
            cout << stack[i];

            if (i > 0)
                cout << ", ";
        }

        cout << "}\n";
    }

    int pop()
    {
        if (isEmpty())
            handleStackErrors();
        else
            return stack[top--];
    }

    int peek()
    {
        if (isEmpty())
            handleStackErrors();
        else
            return stack[top];
    }
};

int main(int argc, char *argv[])
{
    Stack nums;

    nums.push(1);
    nums.push(2);
    nums.push(3);
    nums.push(4);
    nums.push(5);
    cout << nums.pop() << endl;
    cout << nums.peek() << endl;
    nums.display();

    return 0;
}