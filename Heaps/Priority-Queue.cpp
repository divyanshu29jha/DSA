#include <bits/stdc++.h>
using namespace std;

int main() {
    // Max-heap (default)
    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(20);

    cout << "Max-Heap: " << maxHeap.top() << endl; // Outputs 20

    // Min-heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(20);

    cout << "Min-Heap: " << minHeap.top() << endl; // Outputs 5

    return 0;
}

/*
Template Parameters:
int: Type of the elements in priority queue (e.g., integers).
vector<int>: The underlying container used to store the integers. It's specified to be a vector of int.
greater<int>: The comparison function to establish a min-heap (where the smallest element has the highest priority).

Key Operations:
push(element): Adds an element to the priority queue. // O(logn)
pop(): Removes the top element (the largest in a max-heap or the smallest in a min-heap).   // O(logn)
top(): Returns the top element.   // O(1)
empty(): Checks if the priority queue is empty.  // O(1)
size(): Returns the number of elements in the queue.   // O(1)
*/


