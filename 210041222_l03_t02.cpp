#include<iostream>
#include<string>
#define nl "\n"
#define ll long long
using namespace std;

class Book{
    private:
        string Title, Author;
        int pubYear;
        bool isAvailable;
    public:
        void setDetails(string title, string author, int year){
            Title=title;
            Author=author;
            pubYear=year;
        } 
        void checkOut(){
            isAvailable=0;
        }
        void checkIn(){
            isAvailable=1;
        }
        void displayStatus(){
            cout<<"Book Info: "<<endl<<"Title: "<<Title<<nl<<"Author: "<<Author<<nl<<"Publication Year: "<<pubYear<<nl<<"Status: ";
            if(isAvailable)
                cout<<"Available";
            else
                cout<<"Unavailable";
            cout<<nl;
        }
        bool isClassic(){
            if(pubYear<1973)
                return 1;
            else
                return 0;
        }
};

signed main(){
    Book book1;
    book1.setDetails("NimTree", "Bonoful", 1915);
    book1.checkOut();
    book1.displayStatus();
    book1.checkIn();
    book1.displayStatus();
    book1.isClassic();
    return 0;
}