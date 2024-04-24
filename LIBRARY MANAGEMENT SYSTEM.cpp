#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Book {
    string title;
    string author;
    string ISBN;
    bool available;
};

vector<Book> books;

void addBook() {
    string title, author, ISBN;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter ISBN: ";
    cin >> ISBN;

    Book newBook = {title, author, ISBN, true};
    books.push_back(newBook);
    cout << "Book added to the library: " << title << endl;
}

void searchBooks() {
    string keyword;
    cout << "Enter search keyword: ";
    cin.ignore();
    getline(cin, keyword);

    cout << "Search Results:" << endl;
    for (const Book& book : books) {
        if (book.title.find(keyword) != string::npos || book.author.find(keyword) != string::npos || book.ISBN.find(keyword) != string::npos) {
            cout << "Title: " << book.title << " | Author: " << book.author << " | ISBN: " << book.ISBN << " | Available: " << (book.available ? "Yes" : "No") << endl;
        }
    }
}

void checkoutBook() {
    string ISBN, borrowerName;
    cout << "Enter ISBN of the book to checkout: ";
    cin >> ISBN;
    cout << "Enter borrower's name: ";
    cin.ignore();
    getline(cin, borrowerName);

    for (Book& book : books) {
        if (book.ISBN == ISBN && book.available) {
            book.available = false;
            cout << "Book checked out: " << book.title << " by " << borrowerName << endl;
            return;
        }
    }
    cout << "Book not available or ISBN not found." << endl;
}

void returnBook() {
    string ISBN;
    cout << "Enter ISBN of the book to return: ";
    cin >> ISBN;

    for (Book& book : books) {
        if (book.ISBN == ISBN && !book.available) {
            book.available = true;
            cout << "Book returned: " << book.title << endl;
            return;
        }
    }
    cout << "Book not checked out or ISBN not found." << endl;
}

int main() {
    int choice;
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Search Books\n";
        cout << "3. Checkout Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBooks();
                break;
            case 3:
                checkoutBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
