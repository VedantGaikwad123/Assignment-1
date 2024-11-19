#include<iostream>
#include<string>
using namespace std;

class bank {
public:
    string uname, ifsc;
    float balance;
    long phone;
    long accno;

private:
    long Accno;

public:
    bank() {
        balance = 1000;
        ifsc = "IFSC00002024";
    }

    void display_account() {
        cout << "Account No : " << accno << endl;
    }

    void accept() {
        cout << "Enter Username : ";
        cin >> uname;
        cout << "Enter Phone No : ";
        cin >> phone;
        cout << "Enter Balance : ";
        cin >> balance;
        cout << "Enter Account No (10 digit) : ";
        cin >> accno;
        Accno = accno;
    }

    void display() {
        cout << "\nUsername\tBalance\tIFSC Code\n";
        if (uname != "") {
            cout << uname << "\t" << balance << "\t" << ifsc << "\n";
        }
    }

    void deposit() {
        long acn;
        int deposit;
        cout << "Enter Account Number: ";
        cin >> acn;

        if (accno == acn) {
            cout << "Enter Amount To Deposit: ";
            cin >> deposit;
            balance += deposit;
            cout << "Deposit Successful. New Balance: " << balance << endl;
        } else {
            cout << "\nAccount Not Found\n";
        }
    }

    void withdraw() {
        long acn;
        int withdraw;
        cout << "Enter Account Number: ";
        cin >> acn;

        if (accno == acn) {
            cout << "Enter Amount To Withdraw: ";
            cin >> withdraw;
            if (withdraw <= balance) {
                balance -= withdraw;
                cout << "Withdraw Successful. Remaining Balance: " << balance << endl;
            } else {
                cout << "\nYou Don't Have Sufficient Balance!\n";
            }
        } else {
            cout << "\nUser Not Found\n";
        }
    }

    void check_balance() {
        long acn;
        cout << "Enter Account Number: ";
        cin >> acn;

        if (accno == acn) {
            cout << "Account Balance: " << balance << endl;
        } else {
            cout << "\nAccount Not Found\n";
        }
    }
};

bank user[100];

int main() {
    int choice;
    int userindex = 0;

    do {
        cout << "\nBank:";
        cout << "\n1. Accept Account Details";
        cout << "\n2. Display Account Details";
        cout << "\n3. Deposit Money";
        cout << "\n4. Withdraw Money";
        cout << "\n5. Check Balance";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (userindex < 100) {
                user[userindex].accept();
                userindex++;
            } else {
                cout << "User limit reached. Cannot accept more users.\n";
            }
            break;
        case 2:
            for (int i = 0; i < userindex; i++) {
                user[i].display();
            }
            break;
        case 3:
            for (int i = 0; i < userindex; i++) {
                user[i].deposit();
            }
            break;
        case 4:
            for (int i = 0; i < userindex; i++) {
                user[i].withdraw();
            }
            break;
        case 5:
            for (int i = 0; i < userindex; i++) {
                user[i].check_balance();
            }
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
