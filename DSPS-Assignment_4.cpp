#include<iostream>
using namespace std;
int main(){
    string str, stackrev;
    int top =-1,i=0,flag=0;
    cout<<"Enter String : ";
    getline(cin,str);
    
    //move to stack in reverse order
    while(str[i]!='\0'){
        if(str[i]==' ' || str[i]==','){
            i++;
            continue;
        }
        else{
            top++;
            stackrev[top]=str[i];
            i++;
        }
    }
    i = 0;
    while(str[i]!='\0'){
        if(str[i]==' ' || str[i]==','){
            i++;
            continue;
        }
        else{
            if(str[i]!=stackrev[top]){
               flag = 1;
               break;
            }
            top--;
            i++;  
        }
    }
    if(flag==1){ 
        cout<<"String is not a palindrome";
    }
    else{
        cout<<"String is palindrome";
      
    }
    
    return 0;
}
