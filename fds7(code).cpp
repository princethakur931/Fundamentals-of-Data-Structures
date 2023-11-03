//code by prince thakur
#include<iostream>
#include<string.h>
using namespace std;
class node
{
friend class list;
int prnno;
char name[30];
node* next;
public:
node(int d,char s[10])
{
prnno=d;
strcpy(name,s);
next=NULL;
}
};
class list
{
node* start;
public:
list()
{
start=NULL;
}
void display()
{
node* ptr;
ptr=start;
cout << " \n Info is: \n ";
while(ptr!=NULL)
{
cout<<"\n"<<ptr->prnno;
cout<<"\t"<<ptr->name;
ptr=ptr->next;
}
}
void insertmember();
void createmember();
void insertpresident();
void insertsecretary();
void deletemember();
void delete1();void deletesecretary();
void deletepresident();
void count();
void reverse(node *);
void reverse1()
{
reverse(start);
}
void concatination(list,list);
};
void list::insertmember()
{
int prnno;
char name[30];
node* ptr,*temp;
cout<<"\nEnter prnno:";
cin>>prnno;
cout<<"\nEnter name:";
cin>>name;
temp=new node(prnno,name);
if(start==NULL)
{
start=temp;
}
else
{
ptr=start;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=temp;
}
}
void list::insertpresident()
{
int prnno;
char name[30];
node* temp;
cout<<"\nEnter prnno:";
cin>>prnno;
cout<<"\nEnter name:";
cin>>name;
temp=new node(prnno,name);
temp->next=start;
start=temp;
}
void list::insertsecretary()
{
int prnno;
char name[30];
node* ptr,*temp;
cout<<"\n Enter prnno:";
cin>>prnno;
cout<<"\nEntername:";
cin>>name;
temp=new node(prnno,name);
ptr=start;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=temp;
}
void list::createmember()
{
int ch;
char ans;
do
{
cout<<"\nEnter your choice:";
cout<<"\n1-member\n2-secretary\n3-president"<<endl;
cin>>ch;
switch(ch)
{
case 1:
insertmember();
break;
case 2:
insertsecretary();
break;
case 3:
insertpresident();
break;
default:
cout<<"\nInvalide choice";
break;
}
cout<<"\n insert more ? (y/n) : ";
cin>>ans;
}while(ans == 'y');
}
void list::delete1()
{
int ch;
char ans;
do
{
cout<<"\nEnter your choice:";
cout<<"\n1-member\n2-secretary\n3-president"<<endl;
cin>>ch;
switch(ch)
{
case 1:
deletemember();
break;
case 2:
deletesecretary();
break;
case 3:
deletepresident();
break;
default:
cout<<"\nInvalide choice";
break;
}
cout<<"\nDelete more (y/n): ";
cin>>ans;
}while(ans=='y');
}
void list::deletesecretary()
{
node* ptr,*prev;
ptr=start;
while(ptr->next!=NULL)
{
prev=ptr;
ptr=ptr->next;
}
prev->next=NULL;
delete ptr;
cout<<"\ndeleted";
}
void list::deletepresident()
{
node* ptr;
ptr=start;
start=start->next;
delete ptr;
cout<<"\n deleted";
}
void list::deletemember()
{
    int p;
    node* ptr,*prev;
    cout<<"\nEnter prnno. to delete:";
    cin>>p;
    ptr=start;
    prev = NULL; // Initialize prev to NULL
    while(ptr != NULL)
    {
        if(ptr->prnno == p)
        {
            if(prev == NULL)
            {
                start = ptr->next;
            }
            else
            {
                prev->next = ptr->next;
            }
            ptr->next = NULL;
            delete ptr;
            cout<<"\ndeleted";
            return; // Exit the function after deletion
        }
        prev = ptr;
        ptr=ptr->next;
    }
    cout<<"\n data not found!";
}
void list::count()
{
node* ptr;
int cnt=0;
ptr=start;
while(ptr!=NULL)
{
cnt++;
ptr=ptr->next;
}
cout<<"\ntotal no. of nodes is:"<<cnt;
}
void list::reverse(node* ptr)
{
if(ptr==NULL)
return ;
else
{
reverse(ptr->next);
}
cout<<"\n"<<ptr->prnno;
cout<<"\t"<<ptr->name;
}
void list::concatination(list s1,list s2)
{
node* ptr;
ptr=s1.start;
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next=s2.start;
s1.display();
}
int main()
{
int ch;
char ans;
list sll1,sll2,s1,s2;
do
{
cout<<"\nEnter your choice:";
cout<<"\n1-create member\n2-display\n3-delete member\n4-No.of node\n5-reverse\n6-concatenate"<<endl;

cin>>ch;
switch(ch)
{
case 1:
sll1.createmember();
break;
case 2:
sll1.display();
break;
case 3:
cout<<"\nEnter the node to be deleted in list:";
sll1.delete1();
break;
case 4:
cout<<"\nNo. of node is:";
sll1.count();
break;
case 5:
cout<<"\nreversed is:";
sll1.reverse1();
break;
case 6:
sll2.createmember();
sll1.concatination(sll1,sll2);
break;
default:
cout<<"\nInvalide choice";
break;
}
cout<<"\n\n Do you want to continue ? (y/n): ";
cin>>ans;
}while(ans=='y');
return 0;
}
