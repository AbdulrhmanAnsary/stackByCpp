#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack
{
  private:
    vector<T> elements;

  public:
    void push(const T &value)
    {
        elements.push_back(value);
    }

    T pop()
    {
        if (elements.empty())
        {
            throw out_of_range("Stack underflow");
        }
        T value = elements.back();
        elements.pop_back();
        return value;
    }

    T peek() const
    {
        if (elements.empty())
        {
            throw out_of_range("Stack underflow");
        }
        return elements.back();
    }

    bool isEmpty() const
    {
        return elements.empty();
    }

    void display() const
    {
        for (auto it = elements.rbegin(); it != elements.rend(); ++it)
        {
            cout << *it << endl;
        }
    }
};

int main()
{
    Stack<int> stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    cout << "Stack contents:" << endl;
    stack.display();

    cout << "Popped element: " << stack.pop() << endl;

    cout << "Stack contents after pop:" << endl;
    stack.display();

    cout << "Peek element: " << stack.peek() << endl;

    cout << "Stack contents after peek:" << endl;
    stack.display();

    return 0;
}