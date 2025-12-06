#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
private:
    int *data;
    int front;
    int rear;
    int capacity;

public:
    CircularQueue(int size) {
        capacity = size + 1;
        data = new int[capacity];
        front = 0;
        rear = 0;
    };

    ~CircularQueue() {
        delete[] data;
    };

    bool empty() {
        return front == rear;
    };

    bool full() {
        return (rear + 1) % capacity == front;
    };

    bool enqueue(int value) {
        if(full()) {
            return false;
        }
        data[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    };

    bool dequeue() {
        if(empty()) {
            return false;
        }
        // value = data[front];
        front = (front + 1) % capacity;
        return true;
    };

    int getFront() {
        if(empty()) {
            // throw runtime_error("Empty");
            return -1;
        }
        return data[front];
    };
    int getRear() {
        if (empty()){
            // throw runtime_error("Empty");
            return -1;
        }
        return data[(rear - 1 + capacity) % capacity];
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    CircularQueue q(n);
    int cmd;
    for(int i = 0; i < m; i++){
        cin >> cmd;
        switch (cmd)
        {
        case 0:
            {cout << q.getFront() << endl;
            break;}
        
        case 1:
            {cout << q.getRear() << endl;
            break;}
        
        case 2:
            {int value;
            cin >> value;
            cout << (q.enqueue(value) ? 1 : 0) << endl;
            break;}

        case 3:
            {
                // int value;
                // cin >> value;
                cout << (q.dequeue() ? 1 : 0) << endl;
            break;}
        
        case 4:
            {
                cout << (q.empty() ? 1 : 0) << endl;
                break;
            }

        case 5:
        {
            cout << (q.full() ? 1 : 0) << endl;
            break;
        }
        }

    }
    return 0;
}
