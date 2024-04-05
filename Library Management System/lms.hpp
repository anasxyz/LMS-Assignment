/*
    Name: Anas Saad
    Matric number: 2510059
    Module code: AC21008 
*/

#ifndef LMS_HPP
#define LMS_HPP

#include <iostream>
#include <vector>

using namespace std;

// class that handles book objects
class Book {
private:
    string title; // title of book
    string author; // author of book
    string ISBN; // internation standard book number
    bool available; // availability of book

public:
    Book(); // constructor
    Book(string bookTitle, string bookAuthor, string bookISBN, bool bookAvailable); // constructor with parameters

    string getTitle(); // returns title
    string getAuthor(); // returns author
    string getISBN(); // returns ISBN
    bool getAvailable(); // returns availability

    void setTitle(string newTitle); // sets title to a new title
    void setAuthor(string newAuthor); // sets author to a new author
    void setISBN(string newISBN); // sets ISBN to a new ISBN
    void setAvailable(bool newAvailable); // sets availability to a new availability
};

// class that handles user objects
class User {
private:
    string ID; // ID of user
    string name; // name of user
    vector<Book> borrowedBooks; // borrowed books of user

public:
    User(); // constructor
    User(string userID, string userName); // constructor with parameters

    string getID(); // returns ID
    string getName(); // returns name
    vector<Book> getBorrowedBooks(); // returns borrowed books of user

    void setID(string newID); // sets ID to a new ID
    void setName(string newName); // sets name to a new name

    void borrowBook(Book borrowedBook); // adds book to user's borrowed books
    void returnBook(string bookTitle); // removes book from user's borrowed books

    void displayBorrowedBooks(); // displays borrowed books of user
};

// class that handles the library
class Library {
private:
    vector<Book> books; // list of books
    vector<User> users; // list of users

public:
    Library(); // constructor

    void addBook(string bookTitle, string bookAuthor, string bookISBN); // adds a book to list of books
    void removeBook(string bookTitle); // removes book from list of books
    int searchBook(vector<Book>& books, const string searchString, bool searchByISBN); // helper function: searches for a book
    int searchUser(vector<User>& users, const string searchName); // helper function: searches for a user
    void searchAndDisplay(string searchTitle); // searches for and displays a book
    
    void addUser(string userID, string userName); // adds user to list of users
    void removeUser(string userName); // removes a user from list of users
    void displayAllUsers(); // displays all users

    void borrowBook(string borrowTitle, string userName); // calls borrowBook function in user class
    void returnBook(string bookTitle, string userName); // class returnBook function in user class

    void displayBooks(bool onlyAvailable); // displays books - bool value = true means only displays available books
    void displayBorrowedBooks(string userName); // displays borrowed books of a user

    void clearLibrary(); // clears lists of books and users

    void saveBooks(); // saves book to file
    void saveUsers(); // save users to file
    void saveLibrary(); // saves library to file

    void loadBooks(); // loads books from file
    void loadUsers(); // loads users from file
    void loadLibrary(); // loads library from file
};

#endif