#include<iostream>
using namespace std;
template<class T>
void selsort(T a[],int n){
for(int i=0;i<n;i++){
    for(int j =i+1;j<n;j++){
        if(a[i]>a[j]){
            T temp= a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}
cout<<"Sorted Successfully"<<endl;
}

int main(){
    int i;
    int a[5];
    float b[5];
    char c[5];
    int size;
    int choice,ch;

    cout<<"Enter Size Of Array : ";
    cin>>size;
    do{
        cout<<"\nSelection Sorting Program\n1.Accept Value\n2.Sort Array\n3.Display\n4.Exit Program"<<endl;
        cout<<"Enter Your Choice : ";
        cin>>choice;
        
        switch(choice){
            case 1:
            cout<<"\n1.Integer\t2.Float\t3.Char\nEnter Type Of Elements to Accept : ";
            cin>>ch;
            if(ch==1){
                for(int i =0;i<size;i++){
                    cout<<"Enter "<<i<<" th Element :";
                    cin>>a[i];
                }
                break;
            }
            else if(ch==2){
                for(i =0;i<size;i++){
                    cout<<"Enter "<<i<<" th Element :";
                    cin>>b[i];
                }
                break;
            }
            else if(ch ==3){
                for(i =0;i<size;i++){
                    cout<<"Enter "<<i<<" th Element :";
                    cin>>c[i];
                }
                break;
            }
            else{
                cout<<"Enter Valid Choice";
                break;
            }
            break;
            
            case 2:
      //      cout<<"\n1.Integer\t2.Float\t3.Char\nEnter Type Of Elements to Sort : ";
        //    cin>>ch;
            if(ch==1){
                selsort(a,size);
                break;
            }
            else if(ch==2){
                selsort(b,size);
                break;
            }
            else if(ch ==3){
                selsort(c,size);
                break;
            }
            else{
                cout<<"Enter Valid Choice";
                break;
            }
            break;
            case 3:
   //             cout<<"\n1.Integer\t2.Float\t3.Char\nEnter Type To Display : ";
     //           cin>>ch;
                if(ch==1){
                  for(i=0;i<size;i++){
                 cout<<" "<<a[i];     
                  }
                }
                else if(ch==2){
                        for(i=0;i<size;i++){
                 cout<<" "<<b[i];     
                  }
                }
                else if(ch ==3){
                    for(i=0;i<size;i++){
                 cout<<" "<<c[i];     
                  }
                }
                else{
                    cout<<"Enter Valid Choice";
                    break;
                }
                
            break;
            case 4:
            cout<<"Exiting Program...";
            break;

            default:
            cout<<"Invalid choice. Please enter a valid option."<<endl;
            break;
        }
    }while(choice!=4);
    return 0;
}
