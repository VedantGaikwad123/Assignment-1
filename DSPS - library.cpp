#include<iostream>
#include<string>
using namespace std;

class library {
public:
    string title;
    string author;
    float cost;

    void accept() {
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Book Author: ";
        getline(cin, author);
        cout << "Enter Book Cost: ";
        cin >> cost;
    }

    void display() {
        cout << title << "\t" << author << "\t" << cost << endl;
    }

    void ascOrder(library book[], int n) {
        library temp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (book[i].cost > book[j].cost) {
                    temp = book[i];
                    book[i] = book[j];
                    book[j] = temp;
                }
            }
        }
    }

    void descOrder(library book[], int n) {
        library temp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (book[i].cost < book[j].cost) {
                    temp = book[i];
                    book[i] = book[j];
                    book[j] = temp;
                }
            }
        }
    }

    int count(library book[], int n) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (book[i].title != "") {
                count++;
            }
        }
        return count;
    }

    void underfive(library book[], int n) {
        cout << "Books Under 500:" << endl;
        cout << "Title\tAuthor\tCost" << endl;
        for (int i = 0; i < n; i++) {
            if (book[i].cost < 500) {
                book[i].display();
            }
        }
    }

} book[100];

int main() {
    int choice;
    int n = 0;

    do {
        cout << "Library Management System";
        cout << "\n1. Accept Books\n2. Display Books in Ascending Order\n3. Display Books in Descending Order\n4. Count Total Books\n5. Display Books Under 500\n6. Exit\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter number of books: ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                book[i].accept();
            }
            break;

        case 2:
            cout << "Books in ascending order of cost:" << endl;
            cout << "Title\tAuthor\tCost" << endl;
            book[0].ascOrder(book, n);
            for (int i = 0; i < n; i++) {
                book[i].display();
            }
            break;

        case 3:
            cout << "Books in descending order of cost:" << endl;
            cout << "Title\tAuthor\tCost" << endl;
            book[0].descOrder(book, n);
            for (int i = 0; i < n; i++) {
                book[i].display();
            }
            break;

        case 4:
            int totalBooks;
            totalBooks = book[0].count(book, n);
            cout << "Number of books: " << totalBooks << endl;
            break;

        case 5:
            book[0].underfive(book, n);
            break;

        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
