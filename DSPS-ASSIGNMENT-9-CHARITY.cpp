/* a charity management system need to manage the ijnformation about donors , donation and other releavant information sytem need to mainttain information about  each donor system shuold able to add new donor remove the donor , update the information of the donor search the specific donor also it should display all the information of all the donor present in the database . use the concept of linklist to implement above system */
//need to update it -remove function
#include<iostream>
using namespace std;

class donor{
    public:
    string name,id;
    int donation;
    donor *next;
//pointing to next node , donor is type of data here . pointer variable to store the address of next node of donor type
    void acceptDonor();
    void displayDonor();
    void searchDonor(string sname);
    void modifyDonor(string name);
}*start=NULL,*temp=NULL;      //dynamic pointer object declare

//accept the information
void donor::acceptDonor(){
    donor *nnode;
    nnode = new donor;  //dynamic data allocation with donor is the class 
    cout<<"Enter Donor Name: ";
    cin>>nnode->name;
    cout<<"Enter Donor ID: ";
    cin>>nnode->id;
    cout<<"Enter Donation Amount: ";
    cin>>nnode->donation;
//single node
    nnode->next = NULL;
    if(start == NULL){
        start = nnode;
    }
    //if any other node is present
    else{
        temp = start;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = nnode;
    }
}

void donor::displayDonor(){
    temp = start;
    if(temp == NULL){
        cout<<"No Donors in the System.\n";
        return;
    }
    while(temp != NULL){
        cout<<"\n"<<temp->name<<"\t"<<temp->id<<"\t"<<temp->donation<<endl;
        temp = temp->next;
    }
}

void donor::searchDonor(string sname){
    temp = start;
    bool found = false;
    while(temp != NULL){
        if(temp->name == sname){
            cout<<"Donor Found: "<<temp->name<<"\t"<<temp->id<<"\t"<<temp->donation<<endl;
            found = true;
            break;
        }
        temp = temp->next;
    }
    if(!found){
        cout<<"Donor Not Available\n";
    }
}

void donor::modifyDonor(string name){
    temp = start;
    bool found = false;
    while(temp != NULL){
        if(temp->name == name){
            cout<<"Enter New Donor Name: ";
            cin>>temp->name;
            cout<<"Enter New Donor ID: ";
            cin>>temp->id;
            cout<<"Enter New Donation Amount: ";
            cin>>temp->donation;
            found = true;
            cout<<"Donor Updated Successfully.\n";
            break;
        }
        temp = temp->next;
    }
    if(!found){
        cout<<"Donor Not Available\n";
    }
}

int main(){
    donor list;
    string name;   //name to search and modify
    int choice;
    while(true){
        cout<<"\nDonation Management System";
        cout<<"\n1. Add Donor\n2. Display Donor\n3. Search Donor\n4. Modify Donor\n5. Delete Donor\n6.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                list.acceptDonor();
                break;
            case 2:
                cout<<"\nDonor Name\tID\tDonation\n";
                list.displayDonor();
                break;
            case 3:
                cout<<"Enter Donor Name to Search: ";
                cin.ignore();
                getline(cin, name);
                list.searchDonor(name);
                break;
            case 4:
                cout<<"Enter Donor Name to Modify: ";
                cin.ignore();
                getline(cin, name);
                list.modifyDonor(name);
                break;
            case 5:
                cout<<"Delete\n";
                break;
            case 6: cout<<"Exiting...";
            break;
            default:
                cout<<"Enter A Valid Choice\n";
        }

    }
}
