#include <iostream>
using namespace std;

class ReadingMaterial {
protected:
    string title;
    string author;
    int id;

public:
    ReadingMaterial(string t, string a, int i) {
        title = t;
        author = a;
        id = i;
    }

    virtual void displayDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ID: " << id << endl;
    }

    virtual ~ReadingMaterial() {}  
};


class Book : public ReadingMaterial {
private:
    int numberOfPages;
    string genre;

public:
    Book(string t, string a, int i, int pages, string g)
        : ReadingMaterial(t, a, i) {
        numberOfPages = pages;
        genre = g;
    }

    void displayDetails() override {
        ReadingMaterial::displayDetails();
        cout << "Pages: " << numberOfPages << endl;
        cout << "Genre: " << genre << endl;
    }
};


class Magazine : public ReadingMaterial {
private:
    int issueNumber;
    string month;

public:
    Magazine(string t, string a, int i, int issue, string m)
        : ReadingMaterial(t, a, i) {
        issueNumber = issue;
        month = m;
    }

    void displayDetails() override {
        ReadingMaterial::displayDetails();
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Month: " << month << endl;
    }
};

class AudioBook : public ReadingMaterial {
private:
    int duration; 
    string narrator;

public:
    AudioBook(string t, string a, int i, int d, string n)
        : ReadingMaterial(t, a, i) {
        duration = d;
        narrator = n;
    }

    void displayDetails() override {
        ReadingMaterial::displayDetails();
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Narrator: " << narrator << endl;
    }
};

int main() {

    Book book("Harry Potter", "J.K. Rowling", 101, 500, "Fantasy");
    Magazine magazine("National Geographic", "Various", 102, 45, "January");
    AudioBook audioBook("The Alchemist", "Paulo Coelho", 103, 240, "John Smith");

    cout << "----- Book Details -----" << endl;
    book.displayDetails();

    cout << "\n----- Magazine Details -----" << endl;
    magazine.displayDetails();

    cout << "\n----- Audio Book Details -----" << endl;
    audioBook.displayDetails();

    return 0;
}
