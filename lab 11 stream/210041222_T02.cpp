#include<iostream>
#include<fstream> // File-Stream fn
#include<typeinfo> //for typeid() fn
#include<process.h> // for exit()

const int len=32; // max len of last name
const int maxPr=100; // maximum number of employees

enum product_type {pbook, pdvd};

using namespace std;

class Product{
    private:
        char title[len];
        unsigned int UniqueID;
        unsigned int price;
        static int cnt;
        static Product* IVProd[];
    public:
        virtual void getdata(){
            cin.ignore(10, '\n');
            cout<<"Enter product title: ";
            cin>>title;
            cout<<"Enter Unique ID: ";
            cin>>UniqueID;
            cout<<"Enter Unit Price: ";
            cin>>price;
        }      
        virtual void putdata(){
            cout<<"\n Title: "<<title;
            cout<<"\n Unique ID: "<<UniqueID;
            cout<<"\n Unit Price: "<<price;
        }
        virtual product_type get_type(); 
        static void read(); // read from disk file
        static void write(); // write to the file
        static void add();
        static void display();
};

int Product::cnt; 
Product* Product::IVProd[maxPr]; // Array of pointers to product objects

class Book:public Product{
    private:
        char author[len];  
    public:
        void getdata(){
            Product::getdata();
            cout<<" Enter author name: "; cin>>author;
        }
        void putdata(){
            Product::putdata();
            cout<<" \n Author name: "<<author;
        }
};

class DVD:public Product{
    private:
        char director[len];
    public:
        void getdata(){
            Product::getdata();
            cout<<" Enter director name: "; cin>>director;
        }
        void putdata(){
            Product::putdata();
            cout<<" \n Number of publications: "<<director;
        }
};

product_type Product::get_type(){
    if(typeid(*this) == typeid(Book))
        return pbook;
    else if(typeid(*this) == typeid(DVD))
        return pdvd;
    else{
        cerr<<"\nProduct type error"; exit(1);
        return pbook;
    }
}

void Product::add(){
    char ch;
    cout<<
    "press 'b' to add a book\n"
    "press 'd' to add a dvd\n"
    "Enter selection: ";
    cin>>ch;
    switch(ch){
        case 'b': IVProd[cnt]=new Book; break;
        case 'd': IVProd[cnt]=new DVD; break;
        default: cout<<"\nUnknown product type\n"; return;
    } 
    IVProd[cnt++]->getdata(); 
}

void Product::display(){
    for(int j=0; j<cnt; j++){
        cout<<(j+1); // Which number'th employee is trying to display
        switch(IVProd[j]->get_type()) // returns the type of the employee predefined in enum employee_type
        {
            case pbook: cout<<" Type: Book"; break;
            case pdvd: cout<<" Type: DVD"; break;
            default: cout<<". Unknown type occured";
        }
        IVProd[j]->putdata(); cout<<endl; // displays employee data
    }
}

void Product::write(){
    int size;
    cout<<"Writing "<<cnt<<" products.\n";
    ofstream ouf;
    product_type ptype;

    ouf.open("Prodw.txt", ios::trunc | ios::binary); 
    if(!ouf){
        cout<<"\nCan't open file\n"; return;
    }
    for(int j=0; j<cnt; j++){
        ptype = IVProd[j]->get_type();
        ouf.write((char*)&ptype, sizeof(ptype));
        switch(ptype){
            case pbook: size=sizeof(pbook); break;
            case pdvd: size=sizeof(pdvd); break;
        }
        // writes employee objects to the file
        ouf.write((char*) (IVProd[j]), size);
        if(!ouf){
            cout<<"\nCan't write to file\n"; return ;
        }
    }
}

void Product::read(){
    int size;
    product_type ptype;
    ifstream inf;
    inf.open("Prodr.txt", ios::binary);
    if(!inf){
            cout<<"\nCan't open file\n"; return ;
    }
    cnt=0; 
    while(1){
        inf.read((char*)&ptype, sizeof(ptype));
        // Terminate when reaching at the end of file
        if(inf.eof()){
            break;
        }
        if(!inf){
            cout<<"Can't read type form file\n"; return;
        }
        switch(ptype){
            case pbook: IVProd[cnt]=new Book;
            size=sizeof(Book);
            break;
            case pdvd: IVProd[cnt]=new DVD;
            size=sizeof(DVD);
            break;
            default: cout<<"\nUnknown type in file\n"; return;
        }
        inf.read((char*)IVProd[cnt], size);
        if(!inf){
            cout<<"\nCan't read data from file\n"; return;
        }
        cnt++;
    }
    if(cnt>1)
        cout<<"Reading "<<cnt<<" products\n";
    else{
        cout<<"Reading 1 product\n";
    }
    
}

int main(){
    char ch;
    while(1){
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