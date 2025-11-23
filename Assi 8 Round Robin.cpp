#include <iostream>
using namespace std;

class CircularQueue {
    int front, rear, size;
    int *arr;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;
        if (front == -1)
            front = 0;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int val = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
        return val;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

void roundRobinScheduling(int processes[], int n, int burstTime[], int quantum) {
    int remainingBurstTime[n];
    for (int i = 0; i < n; i++) {
        remainingBurstTime[i] = burstTime[i];
    }

    CircularQueue queue(n);
    for (int i = 0; i < n; i++) {
        queue.enqueue(i);  // enqueue process index
    }

    int currentTime = 0;

    while (!queue.isEmpty()) {
        int i = queue.dequeue();
        if (remainingBurstTime[i] > quantum) {
            cout << "Process " << processes[i] << " executed from " << currentTime << " to " << currentTime + quantum << endl;
            currentTime += quantum;
            remainingBurstTime[i] -= quantum;
            queue.enqueue(i); 
        } else {
            cout << "Process " << processes[i] << " executed from " << currentTime << " to " << currentTime + remainingBurstTime[i] << " and completed.\n";
            currentTime += remainingBurstTime[i];
            remainingBurstTime[i] = 0;
        }
    }
}

int main() {
    int n, quantum;
    cout << "Enter the number of processes: ";
    cin >> n;

    int *processes = new int[n];
    int *burstTime = new int[n];

    cout << "Enter process IDs and their burst times:\n";
    for (int i = 0; i < n; i++) {
        cin >> processes[i] >> burstTime[i];
    }

    cout << "Enter quantum time: ";
    cin >> quantum;

    roundRobinScheduling(processes, n, burstTime, quantum);

    delete[] processes;
    delete[] burstTime;
    return 0;
}
