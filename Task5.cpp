// Library Managerment System
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool isAvailable;

    Book(const string& t, const string& a, const string& i)
        : title(t), author(a), isbn(i), isAvailable(true) {}
};

struct Borrower {
    string name;
    string borrowedBookISBN;
    time_t borrowDate;

    Borrower(const string& n, const string& isbn)
        : name(n), borrowedBookISBN(isbn), borrowDate(time(0)) {}
};

class Library {
private:
    vector<Book> books;
    vector<Borrower> borrowers;

public:
    void addBook(const string& title, const string& author, const string& isbn) {
        books.emplace_back(title, author, isbn);
        cout << "Book added: " << title << endl;
    }

    void searchBook(const string& query) {
        cout << "Search Results:" << endl;
        bool found = false;
        for (const auto& book : books) {
            if (book.title.find(query) != string::npos || 
                book.author.find(query) != string::npos || 
                book.isbn == query) {
                cout << "Title: " << book.title << ", Author: " << book.author 
                     << ", ISBN: " << book.isbn 
                     << ", Available: " << (book.isAvailable ? "Yes" : "No") << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No books found." << endl;
        }
    }

    void checkoutBook(const string& isbn, const string& borrowerName) {
        for (auto& book : books) {
            if (book.isbn == isbn && book.isAvailable) {
                book.isAvailable = false;
                borrowers.emplace_back(borrowerName, isbn);
                cout << "Book checked out: " << book.title << " to " << borrowerName << endl;
                return;
            }
        }
        cout << "Book not available for checkout." << endl;
    }

    void returnBook(const string& isbn) {
        for (auto& book : books) {
            if (book.isbn == isbn && !book.isAvailable) {
                book.isAvailable = true;
                cout << "Book returned: " << book.title << endl;
                calculateFine(isbn);
                return;
            }
        }
        cout << "Book not found or already returned." << endl;
    }

    void calculateFine(const string& isbn) {
        for (const auto& borrower : borrowers) {
            if (borrower.borrowedBookISBN == isbn) {
                time_t now = time(0);
                double daysOverdue = difftime(now, borrower.borrowDate) / (60 * 60 * 24) - 14; // Assuming 14 days loan period
                if (daysOverdue > 0) {
                    double fine = daysOverdue * 10; // 10 Rupees per day
                    cout << "Fine for overdue book: $" << fixed << setprecision(2) << fine << endl;
                } else {
                    cout << "No fine for this book." << endl;
                }
                return;
            }
        }
        cout << "No record of this book being borrowed." << endl;
    }
};

int main() {
    Library library;
    int choice;
    string title, author, isbn, borrowerName;

    do {
        cout << "\n=== Library Management System ===" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Search Book" << endl;
        cout << "3. Checkout Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Exit" << endl;
        cout << "=================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character after the choice input

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                cout << "Enter book ISBN: ";
                getline(cin, isbn);
                library.addBook(title, author, isbn);
                break;
            case 2:
                cout << "Enter search query (title, author, or ISBN): ";
                getline(cin, title);
                library.searchBook(title);
                break;
            case 3:
                cout << "Enter book ISBN to checkout: ";
                getline(cin, isbn);
                cout << "Enter borrower name: ";
                getline(cin, borrowerName);
                library.checkoutBook(isbn, borrowerName);
                break;
            case 4:
                cout << "Enter book ISBN to return: ";
                getline(cin, isbn);
                library.returnBook(isbn);
                break;
            case 5:
                cout << "Exiting system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
