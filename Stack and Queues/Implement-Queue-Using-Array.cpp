#include<bits/stdc++.h>
using namespace std;
// You can keep track of extra variable cnt to store current no. of elements in Queue (Stiver article)
// Queue behaves in a circular way, so take % n accordingly.

class Queue {
  int * arr;             // OR int arr[MAX_SIZE];
  int n;      // n is the max no. of elements (size of queue)
  int front;
  int rear;    
  
  public:
    Queue(int size) {
        n = size;   // initialize n in constructor
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        if(front == -1 && rear == -1)
            return true;
        return false;
    }

    bool isFull() {
        if((rear + 1) % n == front)
            return true;
        return false;
    }

    void push(int x){    // Enqueue
        if(isFull()){
            cout << "Queue is full. Cannot push more elements.\n";
            return;
        }

        if(isEmpty()){
            front = 0;
            rear = 0;
        } 
        else{
            rear = (rear + 1) % n;
        }
        arr[rear] = x;
        cout << "The element pushed is " << x << endl;
    }

    int pop(){   // Dequeue
        if (isEmpty()) {
            cout << "Queue is empty. Cannot pop.\n";
            return -1;
        }

        int popped = arr[front];    
        if (front == rear) {    // Edge case when only single element in queue
            front = -1;
            rear = -1;
        } 
        else{
            front = (front + 1) % n;
        }
        return popped;
    }

    int top(){
        if (isEmpty()) {
            cout << "Queue is empty. No top element.\n";
            return -1;
        }
        return arr[front];
    }

    int getSize(){
        return (rear - front + n) % n + 1;
    }

    void printQueue(){
        if (isEmpty()){
            cout << "Queue is empty.\n";
            return;
        }

        int i = front;
        while(i != rear){
            cout << arr[i] << " ";
            i = (i + 1) % n;
        }
        cout << arr[rear] << endl;

        // M-2
        // int size = getSize();
        // int i = front;
        // for (int j=0; j<size; j++){
        //     cout << arr[i] << " ";
        //     i = (i + 1) % n;
        // }
        // cout << endl;
    }
};

int main() {
  Queue q(6);
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  cout << "The peek of the queue before deleting any element : " << q.top() << endl;
  cout << "The size of the queue before deletion : " << q.getSize() << endl;
  cout << "The first element to be deleted :" << q.pop() << endl;
  cout << "The peek of the queue after deleting an element : " << q.top() << endl;
  cout << "The size of the queue after deleting an element : " << q.getSize() << endl;
  cout << "The elements of the queue are : " << endl;
  q.printQueue();

  return 0;
}