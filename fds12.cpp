#include <iostream>
#define MAX 10
using namespace std;

class Deque {
private:
    int arr[MAX];
    int front, rear;

public:
    Deque() : front(-1), rear(-1) {}

    bool isFull() {
        return (front == 0 && rear == MAX - 1) || front == rear + 1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int key) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at the beginning.\n";
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1;
        } else {
            front--;
        }

        arr[front] = key;
        cout << "Inserted " << key << " at the beginning.\n";
    }

    void insertRear(int key) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at the end.\n";
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = key;
        cout << "Inserted " << key << " at the end.\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the front.\n";
            return;
        }

        cout << "Deleted " << arr[front] << " from the front.\n";

        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the rear.\n";
            return;
        }

        cout << "Deleted " << arr[rear] << " from the rear.\n";

        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1;
        } else {
            rear--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Deque elements: ";
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        } while (i != (rear + 1) % MAX);

        cout << endl;
    }
};

int main() {
    Deque deque;
    int choice, value;

    do {
        cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Display\n4. Delete from Front\n5. Delete from Rear\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the beginning: ";
                cin >> value;
                deque.insertFront(value);
                break;
            case 2:
                cout << "Enter value to insert at the end: ";
                cin >> value;
                deque.insertRear(value);
                break;
            case 3:
                deque.display();
                break;
            case 4:
                deque.deleteFront();
                break;
            case 5:
                deque.deleteRear();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

