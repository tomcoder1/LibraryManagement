#include<bits/stdc++.h>
using namespace std;


class Book {
    private:
        static int Database_BookID;
    public: 
        int bookID;
        string title;
        string author;
        bool availability;
        static vector<Book> bookList;
/*      CONSTRUCTOR*/
        Book (string t, string a, bool avail = true) : title(t), author(a), availability(avail) {
            bookID = Database_BookID++;
            bookList.push_back(*this); //*this --> the instance
        }
        void gettingBorrowed(){
            availability = false;
        }
/*       GETTING INFORMATION OF THE BOOK*/    
        void getData(){
            cout << "ID: " << bookID;
            cout << " / Book's title: " << title;
            cout << " / Book's author: " << author;
            cout << " / Availability: "  << (availability ? "Can be borrowed" : "Can't be borrowed");// ternary operator
            cout << "\n";
        }
/*      PRINT THE BOOKS*/    
        static void booksDatabase(){
            for (auto i : bookList)
                i.getData();
            cout << "\n";
        }
};

/*      initialize static member:*/
int Book::Database_BookID = 1;
vector<Book> Book::bookList;

class User {
    private:
        static int Database_UserID;
    public:
        int UserID;
        string name;
        vector<Book> borrowed_books;
/*      Constructor*/
        User (string n) : name(n){
            UserID = Database_UserID++;
        }
/*      Borrow a book*/
        void borrow_book(Book& t) {//pass by reference -> change the status of the book
            if (t.availability){
                borrowed_books.push_back(t);
                t.gettingBorrowed();
                cout << t.title << " borrowed successfully!" << "\n";
            }
            else    
                cout << t.title << " can't be borrowed rn, visit again!" << "\n";
        }
/*      Return book*/        
        void return_book(Book& t) {
            bool check = false;
            for (int i = 0; i < borrowed_books.size(); i++)
                if (borrowed_books[i].title == t.title){
                    check = true;
                    borrowed_books.erase(borrowed_books.begin() + i);
                    t.availability = true;
                    break;
                }
            if (check)
                cout << "Book has been returned!" << "\n";
            else
                cout << "You didn't borrow that lil bro!" << "\n";
        }
/*      Show borrowed books of 1 user*/
        void show_borrowed_books(){
            cout << "Books borrowed: " << "\n";
            for (auto book : borrowed_books){
                cout << book.title << " ";
            }
            cout << "\n";
        }
/*      print ID, name and borrowed books of a user*/       
        void get_data(){
            cout << "ID: " << UserID;
            cout << " / Name: " << name << "\n";
            show_borrowed_books();
            cout << "\n";
        }
};
//initialize static member
int User::Database_UserID = 1;

int main() {
    Book book1 ("Godfather", "Mario Ruzo");
    Book book2 ("Trinh Thang Binh voi cai benh thang tram", "Anh Phan");
    Book::booksDatabase();
    User user1 ("Steve");
    User user2 ("Tommy");
    user1.borrow_book(book2);
    user1.return_book(book2);
    user2.borrow_book(book2);
}
