/*
    Name: Anas Saad
    Matric number: 2510059
    Module code: AC21008 
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "lms.hpp"

using namespace std;

// ======================
// book class Functions
// ======================

// constructor
Book::Book() {

}

// constructor with parameters
Book::Book(string bookTitle, string bookAuthor, string bookISBN, bool bookAvailable) {
    this->title = bookTitle;
    this->author = bookAuthor;
    this->ISBN = bookISBN;
    this->available = bookAvailable;
}

// getter functions for Book class
string Book::getTitle() {
    return this->title;
}

string Book::getAuthor() {
    return this->author;
}

string Book::getISBN() {
    return this->ISBN;
}

bool Book::getAvailable() {
    return this->available;
}

// setter functions for Book class
void Book::setTitle(string newTitle) {
    this->title = newTitle;
}

void Book::setAuthor(string newAuthor) {
    this->author = newAuthor;
}

void Book::setISBN(string newISBN) {
    this->ISBN = newISBN;
}

void Book::setAvailable(bool newAvailable) {
    this->available = newAvailable;
}

// ====================
// user Class Functions
// ====================

// constructor
User::User() {

}

// constructor with parameters
User::User(string userID, string userName) {
    ID = userID;
    name = userName;
}

// getter functions for User class
string User::getID() {
    return this->ID;
}

string User::getName() {
    return this->name;
}

vector<Book> User::getBorrowedBooks() {
    return this->borrowedBooks;
}

// setter functions for User class
void User::setID(string newID) {
    this->ID = newID;
}

void User::setName(string newName) {
    this->name = newName;
}

// borrows book and adds it to the user's list of borrowed books
void User::borrowBook(Book borrowedBook) {
    borrowedBooks.push_back(borrowedBook);
}

// returns book and removes it from the user's list of borrowed books
void User::returnBook(string bookTitle) {
    auto it = borrowedBooks.begin();

    while (it != borrowedBooks.end()) {
        if (it->getTitle() == bookTitle) {
            borrowedBooks.erase(it);
            cout << "\n=================================" << endl;
            cout << "User '" << name << "' has returned the book '" << bookTitle << "'" << endl;
            cout << "=================================" << endl;
            return;
        }
        ++it;
    }

    // if loop completes without returning then the book was not found
    cout << "\n=================================" << endl;
    cout << "User '" << name << "' does not have the book '" << bookTitle << "'" << endl;
    cout << "=================================" << endl;
}

// displays the list of borrowed books for a user
void User::displayBorrowedBooks() {
    cout << "\nBorrowed books by user '" << name << "': " << endl;
    cout << "=================================" << endl;
    for (auto& book : borrowedBooks) {
        cout << "Title: " << book.getTitle() << endl;
        cout << "Author: " << book.getAuthor() << endl;
        cout << "ISBN: " << book.getISBN() << endl;
        cout << "=================================" << endl;
    }
}

// ======================
// library Class Functions
// ======================

// constructor
Library::Library() {

}

// adds a book to the library
void Library::addBook(string bookTitle, string bookAuthor, string bookISBN) {
    Book newBook(bookTitle, bookAuthor, bookISBN, true);
    
    books.push_back(newBook);

    cout << "\n=================================" << endl;
    cout << "Book '" << newBook.getTitle() << "' added" << endl;
    cout << "=================================" << endl;
}

// remove a book from the library
void Library::removeBook(string bookTitle) {
    int removeIndex = searchBook(books, bookTitle, false);

    if (removeIndex != -1) {
        cout << "\n=================================" << endl;
        cout << "Book '" << books[removeIndex].getTitle() << "' removed" << endl;
        cout << "=================================" << endl;

        books.erase(books.begin() + removeIndex);
    } else {
        cout << "\n=================================" << endl;
        cout << "Book '" << bookTitle << "' not found" << endl;
        cout << "=================================" << endl;
    }
}

/*
    searches for a book in the library

    if searchByISBN is true, then it searches for a book by it's ISBN
    otherwise search by title. this saves me making a different function
    for searching by ISBN
*/
int Library::searchBook(vector<Book>& books, const string searchString, bool searchByISBN) {
    for (int i = 0; i < books.size(); i++) {
        if (searchByISBN == true) {
            if (books[i].getISBN() == searchString) {
                return i;
            }
        } else {
            if (books[i].getTitle() == searchString) {
                return i;
            }
        }
    }
    return -1;
}

// searches for a user in the library
int Library::searchUser(vector<User>& users, const string searchName) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getName() == searchName) {
            return i;
        }
    }
    return -1;
}

// searches for a book in the library and displays its details
void Library::searchAndDisplay(string searchTitle) {
    int searchResult = searchBook(books, searchTitle, false);

    if (searchResult != -1) {
        cout << "\n=================================" << endl;
        cout << "Search Results for '" << searchTitle << "':" << endl;
        cout << "=================================" << endl;
        cout << "Title: " << books[searchResult].getTitle() << endl;
        cout << "Author: " << books[searchResult].getAuthor() << endl;
        cout << "ISBN: " << books[searchResult].getISBN() << endl;
        cout << "Availability: " << (books[searchResult].getAvailable() ? "Available" : "Not Available (Borrowed)");
        cout << "\n=================================" << endl;
    } else {
        cout << "\n=================================" << endl;
        cout << "No results found for '" << searchTitle << "'." << endl;
        cout << "=================================" << endl;
    }
}

// displays available books in the library
void Library::displayBooks(bool onlyAvailable) {
    cout << "\nAvailable books: " << endl;
    cout << "=================================" << endl;
    for (auto& book : books) {
        if (onlyAvailable == true) {
            if (book.getAvailable()) {
                cout << "Title: " << book.getTitle() << endl;
                cout << "Author: " << book.getAuthor() << endl;
                cout << "ISBN: " << book.getISBN() << endl;
                cout << "Availability: Available";
                cout << "\n=================================" << endl;
            }
        } else {
            if (book.getAvailable()) {
                cout << "Title: " << book.getTitle() << endl;
                cout << "Author: " << book.getAuthor() << endl;
                cout << "ISBN: " << book.getISBN() << endl;
                cout << "Availability: Available";
                cout << "\n=================================" << endl;
            } else {
                cout << "Title: " << book.getTitle() << endl;
                cout << "Author: " << book.getAuthor() << endl;
                cout << "ISBN: " << book.getISBN() << endl;
                cout << "Availability: Not Available (Borrowed)";
                cout << "\n=================================" << endl;
            }
        }
        
    }
}

// adds user to the library
void Library::addUser(string userID, string userName) {
    User newUser(userID, userName);
    
    users.push_back(newUser);

    cout << "\n=================================" << endl;
    cout << "User #" << newUser.getID() << " '" << newUser.getName() << "' added" << endl;
    cout << "=================================" << endl;
}

// removes user from the library
void Library::removeUser(string userName) {
    int removeIndex = searchUser(users, userName);

    if (removeIndex != -1) {
        cout << "\n=================================" << endl;
        cout << "User #" << users[removeIndex].getID() << " '" << users[removeIndex].getName() << "' removed" << endl;
        cout << "=================================" << endl;

        users.erase(users.begin() + removeIndex);
    } else {
        cout << "\n=================================" << endl;
        cout << "User '" << userName << "' not found" << endl;
        cout << "=================================" << endl;
    }
}

// display details of all users in the library
void Library::displayAllUsers() {
    cout << "\nAll users: " << endl;
    cout << "=================================" << endl;
    for (int i = 0; i < users.size(); i++) {
        cout << "ID: " << users[i].getID() << " | Name: " << users[i].getName() << endl;
        cout << "=================================" << endl;
    }
}
 
/*
    "allows" a user to borrow a book

    and the reason it's "allows" is because it searches for the
    book and the user first then calls it's counterpart in the 
    user class to actually adjust the list of borrowed books
    of this user.
*/
void Library::borrowBook(string borrowTitle, string userName) {
    int bookIndex = searchBook(books, borrowTitle, false);
    int userIndex = searchUser(users, userName);

    if (bookIndex != -1 && userIndex != -1 && books[bookIndex].getAvailable()) {
        books[bookIndex].setAvailable(false);
        users[userIndex].borrowBook(books[bookIndex]);

        cout << "\n=================================" << endl;
        cout << "User #" << users[userIndex].getID() << " '" << users[userIndex].getName() << "' has borrowed the book '" << books[bookIndex].getTitle() << "'" << endl;
        cout << "=================================" << endl;
    } else if (bookIndex != -1 && !books[bookIndex].getAvailable()) {
        cout << "\n=================================" << endl;
        cout << "Book '" << borrowTitle << "' is unavailable to borrow" << endl;
        cout << "=================================" << endl;
    } else if (bookIndex == -1) {
        cout << "\n=================================" << endl;
        cout << "Book '" << borrowTitle << "' not found" << endl;
        cout << "=================================" << endl;
    } else if (userIndex == -1) {
        cout << "\n=================================" << endl;
        cout << "User '" << userName << "' not found" << endl;
        cout << "=================================" << endl;
    }
}

/*
    "allows" a user to return a book

    for the same reason as the function above
*/
void Library::returnBook(string bookTitle, string userName) {
    int bookIndex = searchBook(books, bookTitle, false);
    int userIndex = searchUser(users, userName);

    if (bookIndex != -1 && userIndex != -1 && books[bookIndex].getAvailable() == false) {
        books[bookIndex].setAvailable(true);
        users[userIndex].returnBook(bookTitle);
    } else if (books[bookIndex].getAvailable() == true) {
        cout << "\n=================================" << endl;
        cout << "Book '" << bookTitle << "' is already available to borrow" << endl;
        cout << "=================================" << endl;
    } else if (bookIndex != -1) {
        cout << "\n=================================" << endl;
        cout << "Book '" << books[bookIndex].getTitle() << "' not found" << endl;
        cout << "=================================" << endl;
    } else if (userIndex != -1) {
        cout << "\n=================================" << endl;
        cout << "User '" << users[userIndex].getName() << "' not found" << endl;
        cout << "=================================" << endl;
    }
}

// display list of borrowed books for a user
void Library::displayBorrowedBooks(string userName) {
    int userIndex = searchUser(users, userName);

    if (userIndex != -1) {
        users[userIndex].displayBorrowedBooks();
    } else {
        cout << "\n=================================" << endl;
        cout << "user '" << userName << "' not found" << endl;
        cout << "=================================" << endl;
    }
}

// clears all users and books in the library
void Library::clearLibrary() {
    users.clear();
    books.clear();
}

// saves the current state of books to a file
void Library::saveBooks() {
    ofstream bookFile("inventory.txt");
    if (bookFile.is_open()) {
        for (auto& book : books) {
            bookFile << "\"" << book.getISBN() << "\" \"" << book.getTitle() << "\" \"" << book.getAuthor() << "\" " << (book.getAvailable() ? "1" : "0") << "\n";
        }
        bookFile.close();
        cout << "Library books successfully saved to inventory.txt" << endl;
    } else {
        cerr << "Unable to open inventory.txt for saving" << endl;
    }
}

// saves the current state of users to a file
void Library::saveUsers() {
    ofstream userFile("users.txt");
    if (userFile.is_open()) {
        for (auto& user : users) {
            userFile << user.getID() << " " << user.getName() << " ";
            for (auto& book : user.getBorrowedBooks()) {
                userFile << book.getISBN() << " ";
            }
            userFile << "\n";
        }
        userFile.close();
        cout << "Library users successfully saved to users.txt" << endl;
    } else {
        cerr << "Unable to open users.txt for saving" << endl;
    }
}

// saves the current state of the library to files
void Library::saveLibrary() {
    cout << "\n=================================" << endl;

    // save books
    saveBooks();
    
    // save users
    saveUsers();

    cout << "=================================" << endl;
}

// loads book data from a file into the library
void Library::loadBooks() {
    ifstream file("inventory.txt");
    if (file.is_open()) {
        string line;

        while (getline(file, line)) {
            string title;
            string author;
            string ISBN;
            bool available;

            string reader;
            int ticker = 0;

            for (int i = 0; i < line.length(); i++) {
                reader = line[i];

                if (reader == "\"") {
                    ticker++;
                }

                if (ticker == 0) {
                    ISBN.append(reader);
                } else if (ticker == 1) {
                    title.append(reader);
                } else if (ticker == 3) {
                    author.append(reader);
                } 
            }

            int lastIndex = line.size() - 1;
            available = (line[lastIndex] == '1');

            if (!title.empty()) {
                title.erase(0, 1);
            }
            if (!author.empty()) {
                author.erase(0, 1);
            }
            if (!ISBN.empty()) {
                ISBN.erase(ISBN.length() - 1, 1);
            }

            Book newBook(title, author, ISBN, available);
            books.push_back(newBook);
        }

        cout << "Library books successfully loaded from inventory.txt" << endl;

        file.close();
    } else {
        cerr << "Unable to open inventory.txt" << endl;
    }
}

// loads user data from a file into the library
void Library::loadUsers() {
    ifstream file2("users.txt");
    if (file2.is_open()) {
        string line;

        while (getline(file2, line)) {
            string ID;
            string name;
            vector<string> borrowedISBNs;

            string reader;
            int ticker = 0;

            istringstream iss(line);
            while (iss >> reader) {
                if (ticker == 0) {
                    ID = reader;
                } else if (ticker == 1) {
                    name = reader;
                } else {
                    borrowedISBNs.push_back(reader);
                }
                ticker++;
            }

            int userIndex = searchUser(users, name);
            if (userIndex == -1) {
                User newUser(ID, name);
                users.push_back(newUser);
                userIndex = users.size() - 1;
            }

            // reset ticker to 0 for reading borrowed ISBNs
            ticker = 0;

            for (const auto& ISBN : borrowedISBNs) {
                int bookIndex = searchBook(books, ISBN, true);
                if (bookIndex != -1) {
                    users[userIndex].borrowBook(books[bookIndex]);
                    books[bookIndex].setAvailable(false);
                }
                ticker++;
            }
        }

        cout << "Library users successfully loaded from users.txt" << endl;

        file2.close();
    } else {
        cerr << "Unable to open file users.txt" << endl;
    }
}

// load library data from a file into the library
void Library::loadLibrary() {
    cout << "\n=================================" << endl;

    // reset library
    clearLibrary();

    // load books
    loadBooks();

    // load users
    loadUsers();    

    cout << "=================================" << endl;
}

// ======================
// functions outside of classes
// ======================

// displays menu options
void displayMenu() {
    cout << "\n=================================" << endl;
    cout << "=== Library Management System ===" << endl;
    cout << "=================================" << endl;
    cout << "1. Add a book" << endl;
    cout << "2. Remove a book" << endl;
    cout << "3. Display available books" << endl;
    cout << "4. Display all books" << endl;
    cout << "=================================" << endl;
    cout << "5. Add user" << endl;
    cout << "6. Remove user" << endl;
    cout << "7. Display all users" << endl;
    cout << "=================================" << endl;
    cout << "8. Borrow book" << endl;
    cout << "9. Return book" << endl;
    cout << "10. Display borrowed books" << endl;
    cout << "=================================" << endl;
    cout << "11. Search Book" << endl;
    cout << "12. Save library" << endl;
    cout << "13. Load library" << endl;
    cout << "14. Clear library" << endl;
    cout << "=================================" << endl;
    cout << "0. Exit" << endl;
    cout << "=================================" << endl;
}

// processes menu options / user's choice
void processMenu() {
    Library library;

    int choice;
    
    do {
        // display the menu
        displayMenu();

        // get user choice
        cout << "\n>>> Enter your choice: ";
        cin >> choice;

        // process choice
        switch (choice) {
            case 1: {
                string titleToAdd;
                string authorToAdd;
                string ISBNToAdd;

                cin.ignore();
                cout << "\nEnter book's title: ";
                getline(cin, titleToAdd);
                cout << "Enter book's author: ";
                getline(cin, authorToAdd);
                cout << "Enter book's ISBN: ";
                cin >> ISBNToAdd;

                library.addBook(titleToAdd, authorToAdd, ISBNToAdd);

                break;
            }
            case 2: {
                string bookToRemove;
                
                cin.ignore();
                cout << "\nEnter name of book to be removed: ";
                getline(cin, bookToRemove);

                library.removeBook(bookToRemove);

                break;
            }
            case 3:
                // true means display only available books
                library.displayBooks(true);

                break;
            case 4:
                // false means display all books
                library.displayBooks(false);

                break;
            case 5: {
                string IDToAdd;
                string nameToAdd;

                cin.ignore();
                cout << "\nEnter user's ID: ";
                getline(cin, IDToAdd);
                cout << "Enter user's name: ";
                getline(cin, nameToAdd);

                // remove spaces from user's ID and name
                nameToAdd.erase(remove_if(nameToAdd.begin(), nameToAdd.end(), ::isspace), nameToAdd.end());
                IDToAdd.erase(remove_if(IDToAdd.begin(), IDToAdd.end(), ::isspace), IDToAdd.end());

                library.addUser(IDToAdd, nameToAdd);

                break;
            }
            case 6: {
                string userToRemove;

                cin.ignore();
                cout << "\nEnter name of user to be removed: ";
                getline(cin, userToRemove);

                library.removeUser(userToRemove);

                break;
            }
            case 7:
                library.displayAllUsers();

                break;
            case 8: {
                string bookToBorrow;
                string userToBorrow;

                cin.ignore();
                cout << "\nEnter the title of the book to borrow: ";
                getline(cin, bookToBorrow);
                cout << "Enter the name of the user: ";
                getline(cin, userToBorrow);

                library.borrowBook(bookToBorrow, userToBorrow);

                break;
            }
            case 9: {
                string bookToReturn;
                string userReturning;

                cin.ignore();
                cout << "\nEnter the title of the book to return: ";
                getline(cin, bookToReturn);
                cout << "Enter the name of the user: ";
                getline(cin, userReturning);

                library.returnBook(bookToReturn, userReturning);

                break;
            }
            case 10: {
                string userToDisplay;

                cin.ignore();
                cout << "\nEnter the name of the user to display borrowed books: ";
                getline(cin, userToDisplay);

                library.displayBorrowedBooks(userToDisplay);

                break;
            }
            case 11: {
                string searchTitle;

                cin.ignore();
                cout << "\nEnter the title of book to search: ";
                getline(cin, searchTitle);

                library.searchAndDisplay(searchTitle);

                break;
            }
            case 12:
                library.saveLibrary();

                break;
            case 13:
                library.loadLibrary();

                break;
            case 14:
                library.clearLibrary();
                
                break;
            case 0:
                cout << "\nExiting the program. Goodbye!" << endl;

                break;
            default:
                cout << "\nInvalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 0);
}

// executes some test scenarios
void testScenarios() {
    Library library;

    // Scenario 1: Load the sample data files into the system
    library.loadLibrary();

    // Scenario 2: Add the book Jingo by Terry Pratchett to the library
    library.addBook("Jingo", "Terry Pratchett", "978-0061059062");

    // Scenario 3: Create a user profile for a user called Craig
    library.addUser("123456", "Craig");

    // Scenario 4: Have Alice borrow "The Hobbit"
    library.borrowBook("The Hobbit", "Alice");

    // Scenario 5: Have Alice return "The Hobbit"
    library.returnBook("The Hobbit", "Alice");

    // Scenario 6: Search for "To Kill a Mockingbird" in the library
    library.searchAndDisplay("To Kill a Mockingbird");

    // Scenario 7: Have Bob borrow "Sapiens: A Brief History of Humankind"
    library.borrowBook("Sapiens: A Brief History of Humankind", "Bob");

    // Scenario 8: Export the current data
    library.saveLibrary();
}

int main() {

    processMenu();

    // testScenarios();

    return 0;
}