#include <iostream>
#include <windows.h>
#include <cstdlib> // Add this for the exit function
using namespace std;
const int MAX = 5;
class pizzaparlour
{
 int front, rear;
 int Orders[MAX];
public:
 pizzaparlour()
 {
 front = rear = -1;
 }
 bool addOrder(int data);
 void serveOrder();
 void display();
};
bool pizzaparlour::addOrder(int id)
{
 if (rear == -1)
 {
 front = rear = 0;
 Orders[rear] = id;
 return true;
 }
 else
 {
 int pos = (rear + 1) % MAX;
 if (pos == front)
 {
 cout << "\nCafe is full. Please wait.\n";
 return false;
 }
 else
 {
 rear = pos;
 Orders[rear] = id;
 return true;
 }
 }
}
void pizzaparlour::serveOrder()
{
 if (front == -1)
 {
 cout << "\n No Orders in Cafe. [Cafe is empty]\n";
 return;
 }
 else
 {
 cout << "\n Order No. " << Orders[front] << " is processed.\n";
 if (front == rear)
 {
 front = rear = -1;
 }
 else
 {
 front = (front + 1) % MAX;
 }
 }
}
void pizzaparlour::display()
{
 int i = 0;
 if (front == -1)
 {
 cout << "\nCafe is empty. No Orders.\n";
 return;
 }
 else
 {
 cout << "Order Id's: \n";
 for (i = front; i != rear; i = ((i + 1) % MAX))
 {
 cout << Orders[i] << " ";
 }
 cout << Orders[rear];
 }
}
void intro()
{
 char name[50] = "\nDayDream Cafe \n";
 for (int i = 0; name[i] != '\0'; i++)
 {
 Sleep(50);
 cout << name[i]; // Fix the typo here (name[1] to name[i])
 }
}
int main()
{
 int ch, id = 0;
 pizzaparlour q;
 do
 {
 cout << "\n\n------------------------------";
 intro();
 cout << "----------------------";
 cout << "\n\n****MENU****\n";
 cout << "1. Accept Order\n";
 cout << "2. Serve Order\n";
 cout << "3. Display Orders\n";
 cout << "4. Exit";
 cout << "\nChoice: ";
 cin >> ch;
 switch (ch)
 {
 case 1:
 id++;
 if (q.addOrder(id))
 {
 cout << "Thank you for Order. Order id is : " << id;
 }
 else
 {
 id--;
 }
 break;
 case 2:
 q.serveOrder();
 break;
 case 3:
 q.display();
 break;
 }
 } while (ch != 4);
 cout << "\nThank you. Keep visiting.";
}
