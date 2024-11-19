#include<iostream>
#include<string>
using namespace std;
    
class book {
public:
    string title;
    string author;
    string publisher;
    float price;
    int stock;

    book() {
        title = "Not Added";
        author = "Not Added";
        publisher = "Not Added";
        price = 0.0;
        stock = 0;
    }
    
    ~book(){
        //distructor
        //delete object name ;
        //no of object == no of times distructor is called
        
    }

    void accept() {
        cout << "Enter Book Title: ";
        cin >> title;
        cout << "Enter Book Author Name: ";
        cin >> author;
        cout << "Enter Book Publisher: ";
        cin >> publisher;
        cout << "Enter Book Price: ";
        cin >> price;
        cout << "Enter No. Of Copies: ";
        cin >> stock;
    }

    void display() {
        if (title != "") {
            cout << title << "\t" << author << "\t" << publisher << "\t" << price << "\t" << stock << "\n";
        }
    }

    int search(string searchTitle) {
        if (title == searchTitle) {
            return 1;
        } else {
            return 0;
        }
    }
    
    void requestcost(string searchTitle, int qty) {
        int flag = 0;
        if (title == searchTitle) {
            flag = 1;
        }
        
        if (flag) {
            int reqprice = price * qty;
            cout << "Total cost for " << qty << " copies of \"" << searchTitle << "\": " << reqprice << "\n";
        } else {
            cout << "Book Not Found!\n";
        }
    }

    void checkStock(string searchTitle) {
        if (title == searchTitle) {
            cout << "Stock available for \"" << searchTitle << "\": " << stock << " copies.\n";
        } else {
            cout << "Book Not Found!\n";
        }
    }
};

book b[100];

int main() {
    int choice, n = 0;

    do {
        cout << "\nEnter Your Choice\n";
        cout << "1. Accept Book\n2. Display Books\n3. Check Book Availability\n4. Request Book Cost\n5. Check Stock Position\n6. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter Number Of Books To Store: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    b[i].accept();
                }
                break;

            case 2:
                cout << "\nTitle\tAuthor\tPublisher\tPrice\tAvailable Copies In Stock\n";
                for (int i = 0; i < n; i++) {
                    b[i].display();
                }
                break;

            case 3: {
                string searchbook;
                int found = 0;
                cout << "\nEnter Book Title To Search: ";
                cin >> searchbook;
                for (int i = 0; i < n; i++) {
                    if (b[i].search(searchbook)) {
                        cout << "\nBook \"" << searchbook << "\" is available\n";
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    cout << "\nBook Not Available\n";
                }
                break;
            }
            case 4: {
                string searchTitle;
                int qty;
                cout << "Enter Book Title: ";
                cin >> searchTitle;
                cout << "Enter No Of Books: ";
                cin >> qty;
                
                int found = 0;
                for (int i = 0; i < n; i++) {
                    if (b[i].search(searchTitle)) {
                        b[i].requestcost(searchTitle, qty);
                        found = 1;
                        break;
                    }
                }
                
                if (!found) {
                    cout << "\nBook Not Available\n";
                }
                break;
            }
            case 5: {
                string searchTitle;
                cout << "Enter Book Title to Check Stock: ";
                cin >> searchTitle;

                int found = 0;
                for (int i = 0; i < n; i++) {
                    if (b[i].search(searchTitle)) {
                        b[i].checkStock(searchTitle);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    cout << "\nBook Not Available\n";
                }
                break;
            }
            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
