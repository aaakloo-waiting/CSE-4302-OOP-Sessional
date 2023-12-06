#include<iostream>
#include<string>
#define spc " "
#define nl '\n'
using namespace std;
class Library{
    int work_hrs;
    string Lib_loaction, Lib_name;
    public:
        Library(string l_nm, int w_hr, string l_loc):Lib_name(l_nm), work_hrs(w_hr), Lib_loaction(l_loc){};
        string get_L_name(){
            return Lib_name;
        }
        int get_work_hrs(){
            return work_hrs;
        }
        string get_L_location(){
            return Lib_loaction;
        }
        void set_L_name(string nm){
            Lib_name=nm;
        }
        void set_work_hrs(int wrk_hr){
            work_hrs=wrk_hr;
        }
        void set_L_location(string loc){
            Lib_loaction=loc;
        }
        void print_Lib_info(){
            cout<<"Location: "<<Lib_loaction<<spc<<"name: "<<Lib_name<<spc<<"Working hour: "<<work_hrs<<nl;
        }
};

class Book:public Library{
    string title, author;
    int pub_date, ISBN, edition;
    public:
        Book(string tle, string au, int p_d, int isbn, int ed, string l_nm, int w_hr, string l_loc):title(tle), author(au), pub_date(p_d), ISBN(isbn), edition(ed), Library(l_nm, w_hr, l_loc){}
        string get_B_title(){return title;}
        string get_author(){return author;}
        int get_pub_date(){return pub_date;}
        int get_ISBN(){return ISBN;}
        int get_B_edition(){return edition;}
        void print_Book_info(){
            cout<<"Title: "<<title<<spc<<"Author: "<<author<<spc<<"Published: "<<pub_date<<spc<<"ISBN: "<<ISBN<<spc<<"Edition: "<<edition<<nl;
        }
};
class Member:public Library{
    string m_name, email, phone, postal_mail, membership_stat;
    public:
        Member(string m_nm, string eml, string pml, string phn, string mem_stat, string l_nm, int w_hr, string l_loc):Library(l_nm, w_hr, l_loc){
            m_name=m_nm;
            email=eml;
            postal_mail=pml;
            phone=phn;
            membership_stat=mem_stat;
        }
        string get_mem_name(){return m_name;}
        string get_mem_email(){return email;}
        string get_mem_phone(){return phone;}
        string get_mem_pmail(){return postal_mail;}
        string get_membership_stat(){return membership_stat;}

        void print_Member_info(){
            cout<<"Name: "<<m_name<<spc<<"Email: "<<email<<spc<<"Pmail: "<<postal_mail<<spc<<"Phone: "<<phone<<spc<<"Status: "<<membership_stat<<nl;
        }
};

int main(){
    Book b1("Deyal", "Humayun Ahmed", 2015, 1234, 2, "IUT_Library", 8, "Gazipur");
    Book b2("OOP", "Robert", 2010, 1233, 11, "IUT_Library", 8, "Gazipur");
    Book b3("COA", "William", 2011, 1111, 7, "IUT_Library", 8, "Gazipur");
    Book b4("LA", "Gilbert", 2013, 1210, 5, "IUT_Library", 8, "Gazipur");
    Book b5("DS", "Cormen", 2009, 1101, 6, "IUT_Library", 8, "Gazipur");
    Book b6("EDC", "Haymen", 2007, 1001, 2, "IUT_Library", 8, "Gazipur");
    Book b7("Omrito", "Shorodindu", 1883, 1203, 31, "IUT_Library", 8, "Gazipur");
    Book b8("Schaum's C", "Schaum", 1990, 1401, 14, "IUT_Library", 8, "Gazipur");
    Book b9("Badshah namdar", "Humayun", 1997, 2310, 4, "IUT_Library", 8, "Gazipur");
    Book b10("Altair", "remo", 2004, 3210, 3, "IUT_Library", 8, "Gazipur");

    Member m1("sakeef", "sakef@gamil", "sakef@pmail", "01789", "Guest", "IUT_Library", 8, "Gazipur");
    Member m2("Sameen", "sameen@gmail", "sameen@pmail", "01256", "Staff", "IUT_Library", 8, "Gazipur");
    Member m3("Alif", "alif@gmail", "alif@pmail", "01425", "Staff", "IUT_Library", 8, "Gazipur");
    Member m4("Jyoti", "jyoti@gmail", "jyoti@pmail", "01254", "Faculty", "IUT_Library", 8, "Gazipur");
    Member m5("Abrar", "abrar@gmail", "abrar@pmail", "01862", "student", "IUT_Library", 8, "Gazipur");;

    cout<<"Library Info:"<<nl;
    b1.print_Lib_info();
    cout<<"Booklist:"<<nl;
    b1.print_Book_info();
    b2.print_Book_info();
    b3.print_Book_info();
    b4.print_Book_info();
    b5.print_Book_info();
    b6.print_Book_info();
    b7.print_Book_info();
    b8.print_Book_info();
    b9.print_Book_info();
    b10.print_Book_info();
    cout<<"Member Info:"<<nl;
    m1.print_Member_info();
    m2.print_Member_info();
    m3.print_Member_info();
    m4.print_Member_info();
    m5.print_Member_info();
    return 0;
}
/*
*/