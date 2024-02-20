#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int numberOfCopies;
    Book* nextBookNode;

    Book(string t, string a, int copies) : title(t), author(a), numberOfCopies(copies), nextBookNode(nullptr) {}
};

void addBook(Book*& head, string title, string author, int copies) {
    Book* currentBook = head;
    
    while (currentBook) {
        if (currentBook->title == title) {
            currentBook->numberOfCopies += copies;
            cout << "Book already exists. Added " << copies << " copies to the existing number of copies." << endl;
            return;
        } 
        currentBook = currentBook->nextBookNode;
    }

    Book* newBook = new Book(title, author, copies);

    if (!head) {
        head = newBook;
    } else {
        currentBook = head;
        while (currentBook->nextBookNode) {
            currentBook = currentBook->nextBookNode;
        }
        currentBook->nextBookNode = newBook;
    }

    cout << "Book added successfully." << endl;
}

void borrowBook(Book*& head) {
    string title;
    int copiesWanted;

    cout << "Enter the title of the book you want to borrow: ";
    cin.ignore();
    getline(cin, title);

    Book* currentBook = head;

    while (currentBook) {
        if (currentBook->title == title) {
            cout << "Enter the number of copies you want to borrow: ";
            cin >> copiesWanted;

            if (copiesWanted <= currentBook->numberOfCopies && copiesWanted > 0) {
                currentBook->numberOfCopies -= copiesWanted;
                cout << "Book borrowed successfully. Number of copies remaining: " << currentBook->numberOfCopies << endl;
            } else {
                cout << "Invalid number of copies. Please enter a valid number." << endl;
            }

            return;
        }
        currentBook = currentBook->nextBookNode;
    }

    cout << "Book not found in the library." << endl;
}

void removeBook(Book*& head, string title) {
    if (!head) {
        cout << "Library is empty. Cannot remove book." << endl;
        return;
    }

    if (head->title == title) {
        Book* temp = head;
        head = head->nextBookNode;
        delete temp;
        cout << "Book removed successfully." << endl;
        return;
    }

    Book* currentBook = head;
    while (currentBook->nextBookNode && currentBook->nextBookNode->title != title) {
        currentBook = currentBook->nextBookNode;
    }

    if (currentBook->nextBookNode) {
        Book* temp = currentBook->nextBookNode;
        currentBook->nextBookNode = currentBook->nextBookNode->nextBookNode;
        delete temp;
        cout << "Book removed successfully." << endl;
    } else {
        cout << "Book not found in the library." << endl;
    }
}

void searchByTitle(Book* head, string title) {
    Book* currentBook = head;
    while (currentBook) {
        if (currentBook->title == title) {
            cout << "Book found: " << currentBook->title << " by " << currentBook->author << ", Copies: " << currentBook->numberOfCopies << endl;
            return;
        }
        currentBook = currentBook->nextBookNode;
    }
    cout << "Book not found in the library." << endl;
}

void displayAllBooks(Book* head) {
    Book* currentBook = head;
    while (currentBook) {
        cout << "Title: " << currentBook->title << ", Author: " << currentBook->author << ", Copies: " << currentBook->numberOfCopies << endl;
        currentBook = currentBook->nextBookNode;
    }
}

int main() {
    Book* library = nullptr;
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Search by Title" << endl;
        cout << "4. Display All Books" << endl;
        cout << "5. Borrow Book" << endl;
        cout << "6. Exit" << endl;


        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, author;
                int copies;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, author);
                cout << "Enter number of copies: ";
                cin >> copies;
                addBook(library, title, author, copies);
                break;
            }
            case 2: {
                string title;
                cout << "Enter the title of the book to remove: ";
                cin.ignore();
                getline(cin, title);
                removeBook(library, title);
                break;
            }
            case 3: {
                string title;
                cout << "Enter the title of the book to search: ";
                cin.ignore();
                getline(cin, title);
                searchByTitle(library, title);
                break;
            }
            case 4:
                displayAllBooks(library);
                break;
            case 5:
                borrowBook(library);
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}