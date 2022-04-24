#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Stack
{
public:
    stack<int> stack;
};
ostream &operator<<(std::ostream &os, Stack &stack)
{
    if (stack.stack.size() == 0)
        throw "Exception: the stack is empty";
    os << stack.stack.top() << "\n";
    stack.stack.pop();
    return os;
}
istream &operator>>(std::istream &is, Stack &stack)
{
    int newVal;
    is >> newVal;
    stack.stack.push(newVal);
    return is;
}

int main()
{

    Stack stack;
    int count, out;
    cout << "Enter count of elements in stack: ";
    cin >> count;
    try
    {
        if (count <= 0)
            throw "The count of values cannot be equal or less than 0";
        for (int i = 0; i < count; i++)
        {
            cin >> stack;
        }
        cout << "Enter count of values, which you want to see: ";
        cin >> out;
        if (out <= 0)
            throw "The count of values cannot be equal or less than 0";
        for (int i = 0; i < out; i++)
        {
            cout << stack;
        }
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }

    return 0;
}