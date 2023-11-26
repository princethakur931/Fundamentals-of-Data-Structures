#include <iostream>
using namespace std;

const int MAX_ORDERS = 100; // Maximum number of orders
int front = -1, rear = -1;
int orders[MAX_ORDERS];

// Function to check if the queue is empty
bool isEmpty() {
    return front == -1 && rear == -1;
}

// Function to check if the queue is full
bool isFull() {
    return (rear + 1) % MAX_ORDERS == front;
}

// Function to enqueue an order
void enqueue(int order) {
    if (isFull()) {
        cout << "Sorry, the pizza parlor is full. Cannot accept more orders." << endl;
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_ORDERS;
        }
        orders[rear] = order;
        cout << "Order " << order << " placed successfully." << endl;
    }
}

// Function to dequeue an order
void dequeue() {
    if (isEmpty()) {
        cout << "No orders to serve." << endl;
    } else {
        int servedOrder = orders[front];
        cout << "Order " << servedOrder << " served and removed from the queue." << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_ORDERS;
        }
    }
}

// Function to display the orders in the queue
void displayOrders() {
    if (isEmpty()) {
        cout << "No orders in the queue." << endl;
    } else {
        cout << "Orders in the queue: ";
        int i = front;
        while (true) {
            cout << orders[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX_ORDERS;
        }
        cout << endl;
    }
}

int main() {
    int M;
    cout << "Enter the maximum number of orders the pizza parlor can accept (M): ";
    cin >> M;

    char choice;
    do {
        cout << "\n1. Accept an order\n2. Serve an order\n3. Display orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                if (rear - front + 1 == M) {
                    cout << "The pizza parlor is at full capacity. Cannot accept more orders." << endl;
                } else {
                    int newOrder;
                    cout << "Enter the order number: ";
                    cin >> newOrder;
                    enqueue(newOrder);
                }
                break;

            case '2':
                dequeue();
                break;

            case '3':
                displayOrders();
                break;

            case '4':
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != '4');

    return 0;
}

