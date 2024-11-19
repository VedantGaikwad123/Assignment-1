#include<iostream>
using namespace std;

class person{
  public:
  string name , designation,id;
  int salary;
 
  virtual void accept() = 0;
  virtual void display() = 0;  //do nothing operation
  
  
};

class doctor: public person{
  public: 
 void accept(){
     cout<<"Enter Name : ";
     cin>>name;
     cout<<"Enter Designation : ";
     cin>>designation ;
     cout<<"Enter ID : ";
     cin>>id;
     cout<<"Enter salary : ";
     cin>>salary;
 }
 
 void display(){
     cout<<name<<"\t"<<designation<<"\t"<<id<<"\t"<<salary<<endl;
     }
};
class AStaff: public person{
  public: 
 void accept(){
     cout<<"Enter Name : ";
     cin>>name;
     cout<<"Enter Designation : ";
     cin>>designation ;
     cout<<"Enter ID : ";
     cin>>id;
     cout<<"Enter salary : ";
     cin>>salary;
 }
 void display(){
     cout<<name<<"\t"<<designation<<"\t"<<id<<"\t"<<salary<<endl;
     }
};

class patient: public person{
  public: 
  int bill;
 void accept(){
     cout<<"Enter Name : ";
     cin>>name;
     cout<<"Enter Designation : ";
     cin>>designation ;
     cout<<"Enter ID : ";
     cin>>id;
     cout<<"Enter bill : ";
     cin>>bill;
 }
 void display(){
     cout<<name<<"\t"<<designation<<"\t"<<id<<"\t"<<bill<<endl;
     }
};

int main(){
doctor p;
AStaff q;
patient r;
int choice;
do{
    cout<<"1.Accept Information\n2.Display Information\n3.Search User\n4.Modify User\5.Exit Program\nEnter Your Choice : "
    
}while(choice!=5)
    p.accept();
    q.accept();
    r.accept();
    p.display();
    q.display();
    r.display();
    
    return 0;
}
