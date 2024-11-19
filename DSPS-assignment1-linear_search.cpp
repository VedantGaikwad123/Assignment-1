#include<iostream>
using namespace std;

class linsearch{
    public:
    int arr[10] , n , found =0 , i , target , count = 0;
    int lfound = 0;
    
    void accept(){
        cout<<"Enter size of array :";
        cin>>n;
        
        for(i=0;i<n;i++){
            cout<<"Enter "<<i<<" th Element : ";
            cin>>arr[i];
        }
        
        cout<<"Enter Element To Search : ";
        cin>>target;    
    }
    
    void search(){
        for(i=0;i<n;i++){
            if(arr[i]==target){
                found = 1;
                break;
            }
        }
        if(found){
            cout<<"\nElement "<<target<<" Present At "<<i<< " Position";
        }
        else{
            cout<<"\nElement Not Present";
        }
        
        //count
        for(i=0;i<n;i++){
            if(arr[i]==target){
                count+=1;
            }
        }
        if(count>1){
            cout<<"\nElement "<<target<<" Repeated "<<count<<" Times";
        } 
        else if(count==1){
            cout<<"\nElement "<<target<<" Does Not Repeat";
        }
        else{
            cout<<"\nElement "<<target<<" Repeats Only Once ";
        }
    }
    
    int lastOccur(){
        for(i=n-1;i>=0;i--){
            if(arr[i]==target){
                lfound=1;
                break;
            }
        }
        if(lfound){ 
            cout<<"\nLast Occurrence Of "<<target<<" Is At Position "<<i;
        }
        return i;
    }
    
};

int main(){
    linsearch test;
    test.accept();
    test.search();
    test.lastOccur();
    return 0;
}
