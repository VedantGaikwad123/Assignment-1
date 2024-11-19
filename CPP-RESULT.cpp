#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;

class student{
public:
    string name, prn, mothername;

    void accept(){
        cin.ignore();
        cout<<"Enter Student Name: ";
        getline(cin, name);
        cout<<"Enter Permanent Roll Number: ";
        getline(cin, prn);
        cout<<"Enter Mother Name: ";
        getline(cin,mothername);
    }

    void display(){
        cout<<left<<setw(20)<<name<<setw(15)<<prn<<setw(20)<<mothername;
    }
};

class academic : virtual public student{
public:
    int cia_marks, endsem_marks;
    string course_name, course_type, course_code;

    void accept(){
        cout<<"Enter Course Name: ";
        cin.ignore(); 
        getline(cin, course_name);
        cout<<"Enter Course Code: ";
        getline(cin, course_code);
        cout<<"Enter Course Type: ";
        getline(cin, course_type);
        cout<<"Enter CIA Exam Marks: ";
        cin>>cia_marks;
        cout<<"Enter End Sem Exam Marks: ";
        cin>>endsem_marks;
        cin.ignore(); 
    }

    int total_marks(){
        return cia_marks + endsem_marks;
    }

    void display(){
        int total = total_marks();
        cout<<left<<setw(20)<<course_name<<setw(15)<<course_code<<setw(15)<<course_type<<setw(10)<<cia_marks<<setw(15)<<endsem_marks<<setw(10)<<total<<endl;
    }
};

class sportclass : virtual public student{
public:
    string sport_name;
    char sport_grade;

    void accept(){
        cout<<"Enter Sport Name: ";
        cin.ignore(); 
        getline(cin,sport_name);
        cout<<"Enter "<<sport_name<< " Grade: ";
        cin>>sport_grade;
        cin.ignore();
    }

    void display(){
        cout<<left<<setw(20)<<sport_name<<setw(15)<<sport_grade<<endl;
    }
};

class result : public academic, public sportclass{
public:
    academic subjects[3];

    void accept_academic(){
        for(int i = 0;i<3;i++){
            subjects[i].accept();
        }
    }

    void display_academic(){
        cout<<left<<setw(20)<<"Course Name"<<setw(15)<<"Course Code"<<setw(15)<<"Course Type"<<setw(10)<<"CIA Marks"<<setw(15)<<"ENDSEM Marks"<<setw(10)<<"Total"<<endl;
        for(int i = 0;i<12;i++){
            subjects[i].display();
        }
    }

    void display(){
        student::display();
        cout<<endl;
        display_academic();
        sportclass::display();
    }
};

result reslt[100];

int main(){
    int choice, userindex = 0;

    do{
        cout<<"1. Accept User Info\t2. Display Result\t3. Modify Student Info\t4. Exit\n";
        cout<<"Enter Your Choice: ";
        cin>>choice;

        switch(choice){
        case 1:
            reslt[userindex].student::accept();
            reslt[userindex].accept_academic();
            int ynsport;
            cout<<"Do you participate in any sport (YES: 1\tNO: 2): ";
            cin>>ynsport;
            if(ynsport == 1){
                cin.ignore();
                reslt[userindex].sportclass::accept();
            }
            userindex++;
            break;

        case 2:
            if(userindex == 0){
                cout<<"No Student Data"<<endl;
            } 
            else{
                cout<<left<<setw(20)<<"Student Name"<<setw(15)<<"PRN"<<setw(20)<<"Mother Name"<<endl;
                for(int j = 0;j < userindex;j++){
                    reslt[j].display();
                    cout << endl;
                }
                cout<<endl;
                reslt[0].display_academic();
            }
            break;

        case 3:{
            string checkprn, checkmother;
            cout<<"Enter Permanent Roll Number: ";
            cin.ignore();
            getline(cin,checkprn);
            cout<<"Enter Mother's Name: ";
            getline(cin,checkmother);

            bool found = false;
            for(int j = 0;j<userindex;j++) {
                if(reslt[j].prn == checkprn && reslt[j].mothername == checkmother){
                    cout<<"Record Found. Modifying details..."<<endl;
                    reslt[j].student::accept();
                    reslt[j].accept_academic();
                    int ynsport;
                    cout<<"Do you participate in any sport (YES: 1\tNO: 2): ";
                    cin>>ynsport;
                    if(ynsport == 1) {
                        cin.ignore();
                        reslt[j].sportclass::accept();
                    }
                    found = true;
                    break;
                }
            }
            if(!found){
                cout << "No record found with the provided PRN and Mother's Name." << endl;
            }
            break;
        }

        case 4:
            cout<<"Exiting...\n";
            break;

        default:
            cout<<"Invalid choice! Please try again.\n";
            break;
        }
    }while(choice != 4);

    return 0;
}
