//code by prince thakur
#include<iostream>
using namespace std;

const int MAX = 50;
class stack
{
    int top;
    char data[MAX];
    public:
        stack()
        {
            top = -1;
        }
    bool isfull();
    bool isempty();
    void push(char ch);
    char pop();
    void display();
    void chkparenthesis();


};

bool stack::isfull()
{
    if (top==MAX-1)
    {
        return 1;
    }
    else return 0;
    
}

bool stack::isempty()
{
    if (top == -1)
    {
       return 1;
    }
    else return 0;
    
}

void stack :: push(char ch)
{
    if (!isfull())
    {
        top++;
        data[top]=ch;
        
    }

    else cout<<"\nStack is full !!!!\n";
    
}

char stack ::pop()
{
    if (!isempty())
    {
        char ch=data[top];
        top--;
        return ch;
    }
    else cout<<"\nStack is empty !!!!\n";
    
}

void stack::display()
{
    if (!isempty()) 
        cout<<"\nThe stack is empty !!";

    else 
    {
        cout<<"The stack is :- "<<endl;
        for (int i = 0; i <= top; i++)
        {
            cout<<"["<<data[i]<<"]"<<endl;
        }
        
    }
    
}

void stack ::chkparenthesis()
{
    cout<<"Please enter the delimiter at end:(#)";
    cout<<"\nEnter the expression :- ";
    cin.getline(data,MAX,'#');
    char ch;
    bool flag = 0;
    for (int i = 0; data[i] != '\0'; i++)
    {
        if (data[i]=='(' || data[i]=='{' || data[i]=='[')
    {
        push(data[i]);
    }
        if (data[i]==')' || data[i]=='}' || data[i]==']')
    {
       ch = pop();
       if ((data[i]==')' && (ch!='(')) || (data[i]=='}' && (ch!='{'))|| (data[i]==']' && (ch!='[')))
       {
            flag =1;
            cout<<"\nParenthesis is unbalanced !!";
            break;
       }

       else 
       {
        cout<<"\nParentesis is balanced !!";
        break;
       }
       
    }
    
    }
    
}

int main()
{
    int choice;
    do
    {
        stack s;
        s.chkparenthesis();
        cout<<"\nDO u want to continue (1/0):- ";
        cin>>choice;
    } while (choice!=0);
    
}
