/*accept name,dob,insurance policy number,address, driving license number ,blood group , telephone,height,weight
use def/para/copy constructor and distructor
add , delete, modify,search 
use static member function
friend function / inline function
dynamic memory allocation*/
#include<iostream>
#include<string>
using namespace std;
class PIS{
    private:
    string name , ip_no , dl_no , bg, address;
    int height, weight;
    long contact;
    public:
    static int count;
    PIS(){
       name ="empty";
       ip_no="policy_number";
       dl_no = "driving_licence";
       bg="blood_group";
       address="default_address";
       height=1;
       weight=1;
       contact=1234567891;
    }
    
    PIS(int x){
        name ="deleted";
       ip_no="delt";
       dl_no = "deleted";
       bg="dltd";
       address="deleted";
       height=0;
       weight=0;
       contact=0313730;
    }
    
    ~PIS(){
        cout<<"Destructer is called"<<endl;
    }
    
    void accept(){
        cin.ignore();
        cout<<"Enter Name : ";
        getline(cin,name);
        cout<<"Enter insurance policy number : ";
        getline(cin,ip_no);
        cout<<"Enter driving licence number : ";
        getline(cin,dl_no);
        cout<<"Enter blood group : ";
        getline(cin,bg);
        cout<<"Enter Height : ";
        cin>>height;
        cin.ignore();
        cout<<"Enter Address : ";
        getline(cin,address);
        cout<<"Enter Weight : ";
        cin>>weight;
        cout<<"Enter Contact Number : ";
        cin>>contact;
        cin.ignore();
        count++;
    }
    
    void display(){
        cout<<PIS::retcount<<"\t"<<name<<"\t"<<ip_no<<"\t"<<dl_no<<"\t"<<bg<<"\t"<<address<<"\t"<<height<<"\t"<<weight<<"\t"<<contact<<endl;
    }
    
    void modify(string polno){
        if(polno == ip_no){
            cout<<"Record found"<<endl;
            accept();
            cout<<"Updated Successfully"<<endl;
        }
        else{
            cout<<"Record not Found";
        }
        
    }
    
    void deleted(string polno){
        if(polno == ip_no){
            PIS(0);
            cout<<"Deleted Successfully"<<endl;
        }
        else{
            cout<<"Entry Not Found"<<endl;
        }
    }
    static void retcount(){
        count++;
        cout<<count;
    }
};

int PIS::count=0;
PIS person[10];

int main(){
    string polno;
int choice , i=0, index=0;
do{
    cout<<"Personal Information System\n1.accept details\t2.display details\t3.delete details\t4.modify\t5.exit program\nEnter Your Choice : ";
    cin>>choice;
    switch(choice){
        case 1:person[i].accept();
        i++;
        break;
        case 2:
        cout<<"Count\tName\tlicence\tdrivingL\tblood\taddress\theight\tweight\tcontact"<<endl;
        for(index=0;index<i;index++){
            person[index].display();
        }
        break;
        case 3:
        cout<<"Enter Policy Number : ";
        cin>>polno;
        for(index =0;index<i;index++){
            person[index].deleted(polno);
        }
     
        break;
        case 4:
         
        cout<<"Enter Policy Number : ";
        cin>>polno;
        for(index=0;index<i;index++){
        person[index].modify(polno);
        }break;
        default: cout<<"Enter a valid choice...";
    }
    
}while(choice!=5);
    return 0;
}
