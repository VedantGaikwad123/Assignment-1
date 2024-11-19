/*singly link list*/
//assignment no 8 DSPS
#include<iostream>
using namespace std;

class lms{         //lms = library management system
    public:
    string title,author,publisher;
    int price,quantity;
    lms *next; //pointing to next node
    void accept();
    void display();
}*start=NULL, *temp=NULL;  //dynamic object declaration

//accepting th details
void lms::accept(){
    lms *nnode;       //newnode is the nnode
    nnode = new lms;      //dynamic data allocatio
    cout<<"Enter title : ";
    cin>>nnode->title;
    cout<<"Enter author : ";
    cin>>nnode->author;
    cout<<"Enter publisher : ";
    cin>>nnode->publisher;
    cout<<"Enter price : ";
    cin>>nnode->price;
    cout<<"Enter quantity : ";
    cin>>nnode->quantity;
    nnode->next=NULL;
    //single node
    if(start==NULL){
        start=nnode;
        temp=start;
    }
    //if present any other node
    else{
        temp=start;  
        while(temp->next!=NULL){ 
        temp=temp->next;
        }
        temp->next=nnode;
    }
}

//displaying the details for temp not equal to null
void lms::display(){
    lms *temp;
    temp=start;
    while(temp!=NULL){
        cout<<"\n"<<temp->title<<"\t"<<temp->author<<"\t"<<temp->publisher<<"\t"<<temp->price<<"\t"<<temp->quantity<<endl;
        temp = temp->next;  
    }
}

int main(){
    lms list;
    string tt;     //string to store title for searching
    int choice;
    //infinite loop
    while(true){
        cout<<"\nLibrary Management System";
        cout<<"\n1.Add Book\n2.Display Books\n3.Search Details\n4.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:list.accept(); 
            break;

            case 2:
            cout<<"\nTITLE\tAUTHOR\tPUBLISHER\tPRICE\tQUANTITY"<<endl;
            list.display(); 
            break;
            case 3:
            cout<<"Enter Title To Search : ";
            cin>>tt;
            break;
            case 4:
            cout<<"Exiting Program..."<<endl;
            break;
            default: 
            cout<<"Enter A Valid Choice"; 
            break;
        }
    }
    
    return 0;   
}
