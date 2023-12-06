#include <fstream> //for file-stream functions
#include <iostream>
#include <typeinfo> //for typeid()

using namespace std;
#include <process.h>//for exit()

const int LEN = 32;
enum product_type {tbook, tdvd};

class Product
{
private:
    int u_price;
    char title[LEN];
    static Product* arrap[];
    static int n;
    int ID;

public:
    virtual void getdata()
    {
        cin.ignore(10, '\n');
        cout << " Enter title ";
        cin >> title;
        cout << " Enter unit price: ";
        cin >> u_price;
        cout<< " ID: ";
        cin>>ID;
    }
    virtual void putdata()
    {
        cout << "\n Title: " << title;
        cout << "\n unit price: "<< u_price;
    }

    virtual product_type get_type();
    static void add();
    static void display();
    static void read(); //read from disk file
    static void write(); //write to disk file
};

Product* Product::arrap[10];
int Product::n;

class Book:public Product
{
private:
    char author[LEN];
public:
    void getdata()
    {
        Product::getdata();
        cout << " Enter Author: ";
        cin >> author;

    }
    void putdata()
    {
        Product::putdata();
        cout << "\n Author: " << author;
    }
};

class DVD:public Product
{
private:
    char director[LEN];
public:
    void getdata()
    {
        Product::getdata();
        cout << " Enter Director: ";
        cin >> director;

    }
    void putdata()
    {
        Product::putdata();
        cout << "\n Director: " << director;
    }
};

void Product::add()
{
    char ch;
    cout << "'b' to add a Book"
         "\n'd' to add a DVD"
         "\nEnter selection:";
    cin >> ch;
    switch(ch)
    {
    case 'b':
        arrap[n] = new Book;
        break;
    case 'd':
        arrap[n] = new DVD;
        break;
    default:
        cout << "\nUnknown employee type\n";
        return;
    }
    arrap[n++]->getdata();
}

void Product::display()
{
    for(int j=0; j<n; j++)
    {
        cout << (j+1); //display number
        switch( arrap[j]->get_type() ) //display type
        {
        case tbook:
            cout << ". Type: BOOK";
            break;
        case tdvd:
            cout << ". Type: DVD";
            break;
        default:
            cout << ". Unknown type";
        }
        arrap[j]->putdata();
        cout << endl;
    }
}

product_type Product::get_type()
{
    if( typeid(*this) == typeid(Book) )
        return tbook;
    else if( typeid(*this)==typeid(DVD) )
        return tdvd;
    else
    {
        cerr << "\nBad employee type";
        exit(1);
    }
    return tbook;
}

void Product::write()
{
    int size;
    cout << "Writing " << n << " products.\n";
    ofstream ouf; //open ofstream in binary
    product_type ptype; //type of each employee object
    ouf.open("PRODUCT.DAT", ios::trunc | ios::binary);
    if(!ouf)
    {
        cout << "\nCan’t open file\n";
        return;
    }
    for(int j=0; j<n; j++) //for every employee object
    {
        //get its type
        ptype = arrap[j]->get_type();

        //write type to file
        ouf.write( (char*)&ptype, sizeof(ptype) );
        switch(ptype) //find its size
        {
        case tbook:
            size=sizeof(Book);
            break;
        case tdvd:
            size=sizeof(DVD);
            break;
        } //write employee object to file
        ouf.write( (char*)(arrap[j]), size );
        if(!ouf)
        {
            cout << "\nCan’t write to file\n";
            return;
        }
    }
}

void Product::read()
{
    int size; //size of employee object
    product_type ptype; //type of employee
    ifstream inf; //open ifstream in binary
    inf.open("PRODUCT.DAT", ios::binary);
    if(!inf)
    {
        cout << "\nCan’t open file\n";
        return;
    }
    n = 0; //no employees in memory yet
    while(true)
    {
        //read type of next employee
        inf.read( (char*)&ptype, sizeof(ptype) );
        if( inf.eof() ) //quit loop on eof
            break;
        if(!inf) //error reading type
        {
            cout << "\nCan’t read type from file\n";
            return;
        }
        switch(ptype)
        {
        //make new employee
        case tbook: //of correct type
            arrap[n] = new Book;
            size=sizeof(Book);
            break;
        case tdvd:
            arrap[n] = new DVD;
            size=sizeof(DVD);
            break;
        default:
            cout << "\nUnknown type in file\n";
            return;
        } //read data from file into it
        inf.read( (char*)arrap[n], size );
        if(!inf) //error but not eof
        {
            cout << "\nCan’t read data from file\n";
            return;
        }
        n++; //count product
    } //end while
    cout << "Reading " << n << " products\n";
}

int main()
{
    char ch;
    while(true)
    {
        cout<<
        " 'a' --- add product\n"
        " 'w' --- write all employee data to file\n"
        " 'r' --- rad all employee data from file\n"
        " 'x' --- exit\n"
        "Enter selection: ";
        cin>>ch;
        switch(ch){
            case 'a': Product::add(); break;
            case 'w': Product::write(); break;
            case 'r': Product::read(); break;
            case 'x': exit(0);
            default: cout<<"\nUnknown command";
        }
    }
    return 0;
}