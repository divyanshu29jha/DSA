#include <bits/stdc++.h>
using namespace std;

class Stack {
    int size;
    int *arr;
    int top;

    public:
        Stack(int s) {
            top = -1;
            size = s;
            arr = new int[size];
        }

        void push(int x) {
            top++;
            arr[top] = x;
        }

        int pop() {
            int x = arr[top];
            top--;
            return x;
        }

        int Top() {
            return arr[top];
        }

        int isEmpty() {
            if (top == -1)  // if(arr.size() == 0)
                return 1;
            return 0;
        }

        int isFull() {
            if (top == size - 1)  // if(arr.size() == capacity-1)
                return 1;
            return 0;
        }

        int Size() {
            return top + 1;
        }
};


int main() {
    Stack s(5);
    s.push(6);
    s.push(3);
    s.push(7);
    cout << "Top of stack is before deleting any element " << s.Top() << endl;
    cout << "Size of stack before deleting any element " << s.Size() << endl;
    cout << "The element deleted is " << s.pop() << endl;
    cout << "Size of stack after deleting an element " << s.Size() << endl;
    cout << "Top of stack after deleting an element " << s.Top() << endl;
    return 0;
}