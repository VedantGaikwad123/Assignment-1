#include<iostream>
#include<string>
using namespace std;

class student{
 public:
    int rno;
    string name;

    void accept();
    void display();
    void lsearch(int key, int n);
    void binsearch(int n);
}s[100]; 

void student::accept(){
    cout<<"Enter Name Of Student :";
    cin>>name;
    cout<<"Enter Roll Of Student :";
    cin>>rno;
}

void student::display() {
    cout<<name<<"\t"<<rno<<endl;
}

void student::lsearch(int key, int n){

    for(int i = 0 ; i < n; i++){
        if(s[i].rno == key){
            cout<<"Student Attended The Training Session\n";
            return;
        }
    }
    cout<<"Student "<<key<<" Does Not Attend The Training Session\n";
}

void student::binsearch(int n){
    int keys;
    cout<<"Enter Roll No To Search :";
    cin>>keys;

//bubble sorting to sort the unsorted array
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(s[j].rno > s[j + 1].rno){
                student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    int high = n-1, mid, low = 0;

    while(low<=high){
        mid = (low + high)/2;
        if(s[mid].rno == keys){
            cout<<"Student Attended The Training Session, Present At "<<mid<<" Position";
            return;
        }
        else if(s[mid].rno > keys){
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    cout<<"Student "<<keys<<" Does Not Attend The training Session\n";
}

int main(){
    int choice;
    int n = 0;
    do{
        cout<<"\nChoices\n1.Accept Student Details\n2.Display Details\n3.Search Using Linear Search\n4.Search Using Binary Search\n5.Exit\n";
        cout<<"Enter Your Choice :";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter No. Of Student Info To Fill :";
                cin>>n;
                for(int i= 0;i<n;i++){
                    s[i].accept();
                }
                break;
            
            case 2:
                cout<<"Name\tRoll No\n";
                for(int i = 0;i<n;i++){
                    s[i].display();
                }
                break;
            
            case 3: {
                int key;
                cout<<"Enter Roll No To Search :";
                cin>>key;
                s[0].lsearch(key,n);
                break;
            }
            
            case 4:
                s[0].binsearch(n);
                break;

            case 5:
                return 0;
        }
    }while(choice!=5);
    
    return 0;
}
