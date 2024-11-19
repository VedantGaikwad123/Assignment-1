/*design a c++ program with class complex with data member for real and imaginary part provide default and 
parameterised constructor write a program to perform arithmetic operation of two complex numbers
using operator overloading (Using either member or friend function)*/

#include<iostream>
using namespace std;

class complex{
    private:
    
    public:
    int real,img;
    
    complex(){
        real = 0;
        img = 0;
    }
    
    complex(int x, int y){
        real =x;
        img =y;
    }
    
    void display(){
        if(img>=0){
            cout<<real<<"+"<<img<<"i"<<endl;
        }
        else{
            cout<<real<<" "<<img<<"i"<<endl;
        }
    }
    
     complex operator+(complex c2);
    friend complex operator-(complex c2);
     complex operator*(complex c2);
   complex operator/(complex c2);
    
    
}c1,c2,c3;

complex complex::operator+(complex c2){
  c3.real = c1.real + c2.real;
  c3.img = c1.img + c2.img;
  return c3;
}

complex operator-(complex c1,complex c2){
    c3.real = c1.real - c2.real;
    c3.img = c1.img - c2.img;
    return c3;
}

complex complex::operator*(complex c2){
    c3.real= c1.real * c2.real - c1.img * c2.img ;
    c3.img= c1.real * c2.real + c1.img * c2.img ;
    return c3;
}

complex complex::operator/(complex c2){
    c3.real = (c1.real * c2.real+c1.img *c2.img)/c2.real * c2.real + c2.img * c2.img;
    c3.img = (c1.img * c2.real+c1.real *c2.img)/c2.real * c2.real + c2.img * c2.img;
    return c3;
}


int main(){
    int choice;
    int rn, imgn;
    do{
        cout<<"1.Accept Numbers\t2.Display\t3.Exit\nEnter Your Choice : ";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"Enter Real and img part for first : "<<endl;
            cin>>rn>>imgn;
            c1=complex(rn,imgn);
            cout<<"Enter Real and img part for second : "<<endl;
            cin>>rn>>imgn;
            c2=complex(rn,imgn);
            case 2://display
            c1+c2;
                 c3.display();
            c1-c2;
                 c3.display();
            c1*c2;
                 c3.display();
            c1/c2;
            c3.display();
            break;
            case 3 :break;
        }
        
    }while(choice!=4);
    
  return 0;
}
