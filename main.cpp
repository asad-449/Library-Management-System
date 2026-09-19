#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
};

void addBook() {
    Book b;

    ofstream file("books.txt", ios::app);

    cout << "Enter Book ID: ";
    cin >> b.id;

    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, b.title);

    cout << "Enter Author Name: ";
    getline(cin, b.author);

    file << b.id << "|" << b.title << "|" << b.author << endl;

    file.close();

    cout << "\nBook Added Successfully!\n";
}

void displayBooks() {
    ifstream file("books.txt");
    string line;

    cout << "\n===== Book Records =====\n";

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void searchByTitle() {
    string title;
    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, title);

    ifstream file("books.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.find(title) != string::npos) {
            cout << line << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Book Not Found!\n";

    file.close();
}

void searchByAuthor() {
    string author;
    cin.ignore();

    cout << "Enter Author Name: ";
    getline(cin, author);

    ifstream file("books.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.find(author) != string::npos) {
            cout << line << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Book Not Found!\n";

    file.close();
}

void issueBook() {
    cout << "\nBook Issued Successfully!\n";
}

void returnBook() {
    cout << "\nBook Returned Successfully!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search By Title\n";
        cout << "4. Search By Author\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";

        cin >> choice;

        switch(choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchByTitle(); break;
            case 4: searchByAuthor(); break;
            case 5: issueBook(); break;
            case 6: returnBook(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice!\n";
        }

    } while(choice != 7);

    return 0;
}
