//queue operation 
#include<iostream>
using namespace std;

int queue[5];
int n = 5;
int r = -1, f = -1;

void enqueue(int x) {
    if ((r + 1) % n == f) {
        cout << "Queue is Full" << endl;
    }
    else if (r == -1 && f == -1) {
        r = 0;
        f = 0;
        queue[r] = x;
        cout << "Element " << x << " Entered Successfully" << endl;
    }
    else {
        r = (r + 1) % n;
        queue[r] = x;
        cout << "Element " << x << " Entered Successfully" << endl;
    }
}

void dequeue() {
    if (r == -1 && f == -1) {
        cout << "Queue is empty" << endl;
    }
    else if (r == f) {
        cout << "Element " << queue[f] << " Dequeued" << endl;
        r = -1;
        f = -1;
    }
    else {
        cout << "Element " << queue[f] << " Dequeued" << endl;
        f = (f + 1) % n;
    }
}

void display() {
    if (r == -1 && f == -1) {
        cout << "Queue is empty" << endl;
    }
    else {
        int i = f;
        cout << "Queue elements: ";
        while (i != r) {
            cout << queue[i] << " ";
            i = (i + 1) % n;
        }
        cout << queue[r] << endl;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    display();

    enqueue(60);
    display();

    return 0;
}
