//assignment 6 of oops
/*create a cpp class name television that has data member to hold model number screen size in inches , the price . member 
function include overloaded insertion and extraction operator , if more than 4 digits are entered for the model number , 
if the screen size is 12 or great er than 17 inches or if the price is negative or over the 5000 dollar then throw an 
integer . write a main function that instantiates a television ,allow user to enter the data and display the at member . 
if an exception is called replace the data member value with 0 value.*/

#include<iostream>
using namespace std;
class television{
    int modelnumber,price,screensize;
    public:
    friend ostream operator<<(ostream &dout,television &t);
    friend istream operator>>(istream &din,television &t);
};
istream operator>>(istream &din, television &t){
    cout<<"enter the model name,size,prize";
    din>>t.modelnumber>>t.screensize>>t.price;
    try{
        if(t.modelnumber>9999||t.screensize>70||t.screensize<12||t.price<0||t.price>5000){
            throw 10;
        }
    }
    catch(int e){
        cout<<"exception is caught";
        t.screensize=0;
        t.price=0;
        t.modelnumber=0;
    }
}
ostream operator<<(ostream &dout, television &t){
    dout << "Model number: " << t.modelnumber << endl;
    dout << "Size: " << t.screensize << " inches" << endl;
    dout << "Price: $" << t.price << endl;
    return dout; 
}
int main(){
    television tv;
    cin >> tv;  
    cout << tv; 
    return 0;
}
