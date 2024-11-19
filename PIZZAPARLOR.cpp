//pizza parlor


#include<iostream>
#include<string>
using namespace std;

const int MAX=5;
const float PIZZA_COST=100.0;

//class created for storing order-info
class PizzaShop{
private:
    string name[MAX];
    int quantity[MAX];
    string mobile[MAX];
    int front,rear;

public:

//constructor to initialise front and rear to -1 (empty)
    PizzaShop(){
        front=-1;
        rear=-1;
    }
//direct check
    bool isEmpty(){
        return front==-1;
    }

    bool isFull(){
        return (rear+1)%MAX==front;
    }

    void placeOrder(string n,int q,string m){
        if(isFull()){
            cout<<"Order queue is full! Can't place order.\n";
            return;
        }
        if(isEmpty()){
            front=rear=0;
        }else{
            rear=(rear+1)%MAX;
        }
        name[rear]=n;
        quantity[rear]=q;
        mobile[rear]=m;
        cout<<"Order placed successfully.\n";
    }

    void serveOrder(){
        if(isEmpty()){
            cout<<"No orders to serve!\n";
            return;
        }
        cout<<"Serving order for: "<<name[front]<<"\n";
        if(front==rear){
            front=rear=-1;
        }else{
            front=(front+1)%MAX;
        }
    }

    void peakOrder(){
        if(isEmpty()){
            cout<<"No orders to peak!\n";
            return;
        }
        cout<<"Next order for: "<<name[front]<<"\n";
    }

    void displayOrders(){
        if(isEmpty()){
            cout<<"No orders to display!\n";
            return;
        }
        int idx=front,i=0;
        while(idx!=rear){
            displayOrderDetails(idx,i);
            idx=(idx+1)%MAX;
            i++;
        }
        displayOrderDetails(idx,i);
    }

    void displayOrderDetails(int idx,int orderNum){
        float bill=quantity[idx]*PIZZA_COST;
        if(orderNum==0){ 
            bill*=0.90;
        }
        else if(orderNum==1){
        bill*=0.95;
    }
        cout<<"\n"<<name[idx]<<"\t"<<quantity[idx]<<"\t"<<mobile[idx]<<"\t"<<bill<<" Rs\n";
    }
    
    void deleteOrder(string searchname){
        if(isEmpty()){
            cout<<"No orders to delete!\n";
            return;    //to break the flow of function and come out of it  
        } 
        int found=0;
        for(int i=front;i!=rear;i=(i+1)%MAX){
            if(searchname==name[i]){
                found=i;
                break;
            }
        }
        if(found==0 && searchname==name[rear]) found=rear;
        if(found!=0){
            cout<<"\nOrder Deleted Successfully with only 60% Refund"<<endl;
            cout<<"Amount to be deducted: "<<PIZZA_COST*0.40<<" Rs\n";
            for(int i=found;i!=rear;i=(i+1)%MAX){
                name[i]=name[(i+1)%MAX];
                quantity[i]=quantity[(i+1)%MAX];
                mobile[i]=mobile[(i+1)%MAX];
            }
            if(found==rear){
                 rear=(rear-1+MAX)%MAX;
                  front=rear=-1;
            } 
        }else{
            cout<<"Order not found.\n";
        }
    }
};

int main(){
    PizzaShop shop;
    int choice,qty;
    string name,mobile,strname;
    do{
        cout<<"\nPIZZA PARLOR\n1. Place Order\n2. Serve Order\n3. Peak Order\n4. Display Orders\n5. Delete Order\n6. Exit\n";
        cout<<"Enter Your Choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cin.ignore();
                cout<<"Enter Name: ";
                getline(cin,name);
                cout<<"Enter Quantity: ";
                cin>>qty;
                cout<<"Enter Mobile: ";
                cin>>mobile;
                shop.placeOrder(name,qty,mobile);
                break;
            case 2:
                shop.serveOrder();
                break;
            case 3:
                shop.peakOrder();
                break;
            case 4:
                cout<<"\nName\tQuantity\tMobile\tBill Amount";
                shop.displayOrders();
                break;
            case 5:
                cout<<"Enter Name: ";
                cin>>strname;
                shop.deleteOrder(strname);
                break;
            case 6:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid option!\n";
        }
    }while(choice!=6);
    return 0;
}
