#include<iostream>
#include<fstream> // File-Stream fn
#include<typeinfo> //for typeid() fn
#include<process.h> // for exit()

const int len=32; // max len of last name
const int maxEm=100; // maximum number of employees

enum employee_type {tmanager, tscientist, tlaborer};

using namespace std;

class employee{
    private:
        char name[len];
        unsigned long number;
        static int n;
        static employee* arrap[];
    public:
        virtual void getdata(){
            cin.ignore(10, '\n');
            cout<<"Enter last name: ";
            cin>>name;
            cout<<"Enter number: ";
            cin>>number;
        }      
        virtual void putdata(){
            cout<<"\n Name: "<<name;
            cout<<"\n Number: "<<number;
        }
        virtual employee_type get_type(); // returns enum employee_type data
        static void add(); // Add a new employee
        static void display(); // display info of all employees
        static void read(); // read from disk file
        static void write(); // write to the file
};

int employee::n; // Holds the current number of employees
employee* employee::arrap[maxEm]; // Array of pointers to employee objects

class manager:public employee{
    private:
        char title[len]; // Title of employee-> eg: "president" 
        double dues;
    public:
        void getdata(){
            employee::getdata();
            cout<<" Enter title: "; cin>>title;
            cout<<" Enter golf club dues: "; cin>>dues;
        }
        void putdata(){
            employee::putdata();
            cout<<" \n Title: "<<title;
            cout<<" \n Golf Club dues: "<<dues;
        }
};

class Scientist:public employee{
    private:
        int pubs; // Number of publications of that scientist
    public:
        void getdata(){
            employee::getdata();
            cout<<" Enter number of publications: "; cin>>pubs;
        }
        void putdata(){
            employee::putdata();
            cout<<" \n Number of publications: "<<pubs;
        }
};

class laborer:public employee{  
};

void employee::add(){
    char ch;
    cout<<
    "press 'm' to add a manager\n"
    "press 's' to add a scientist\n"
    "press 'l' to add a laborer\n"
    "Enter selection: ";
    cin>>ch;
    switch(ch){
        case 'm': arrap[n]=new manager; break;
        case 's': arrap[n]=new Scientist; break;
        case 'l': arrap[n]=new laborer; break;
        default: cout<<"\nUnknown employee type\n"; return;
    } 
    arrap[n++]->getdata(); // Get employee data from user
}

void employee::display(){
    for(int j=0; j<n; j++){
        cout<<(j+1); // Which number'th employee is trying to display
        switch(arrap[j]->get_type()) // returns the type of the employee predefined in enum employee_type
        {
            case tmanager: cout<<" Type: Manager"; break;
            case tscientist: cout<<" Type: Scientist"; break;
            case tlaborer: cout<<" Type: Laborer"; break;
            default: cout<<". Unknown type occured";
        }
        arrap[j]->putdata(); cout<<endl; // displays employee data
    }
}

employee_type employee::get_type(){
    if(typeid(*this) == typeid(manager))
        return tmanager;
    else if(typeid(*this) == typeid(Scientist))
        return tscientist;
    else if(typeid(*this) == typeid(laborer))
        return tlaborer;
    else{
        cerr<<"\nBad employee type"; exit(1);
        return tmanager;
    }
}

void employee::write(){
    int size;
    cout<<"Writing "<<n<<" employee.\n";
    ofstream ouf;
    employee_type etype;

    ouf.open("EMPLOY.txt", ios::trunc | ios::out); // Open EMPLOY.DAT file in trunc or binary mode
    if(!ouf){
        cout<<"\nCan't open file\n"; return;
    }
    for(int j=0; j<n; j++){
        etype = arrap[j]->get_type();
        ouf.write((char*)&etype, sizeof(etype));
        switch(etype){
            case tmanager: size=sizeof(tmanager); break;
            case tscientist: size=sizeof(tscientist); break;
            case tlaborer: size=sizeof(tlaborer); break;
        }
        // writes employee objects to the file
        ouf.write((char*) (arrap[j]), size);
        if(!ouf){
            cout<<"\nCan't write to file\n"; return ;
        }
    }
}

void employee::read(){
    int size;
    employee_type etype;
    ifstream inf;
    inf.open("EMPOY2.DAT", ios::in);
    if(!inf){
            cout<<"\nCan't open file\n"; return ;
    }
    n=0; // No employees in memory yet
    while(1){
        inf.read((char*)&etype, sizeof(etype));
        // Terminate when reaching at the end of file
        if(inf.eof()){
            break;
        }
        if(!inf){
            cout<<"Can't read type form file\n"; return;
        }
        switch(etype){
            case tmanager: arrap[n]=new manager;
            size=sizeof(manager);
            break;
            case tscientist: arrap[n]=new Scientist;
            size=sizeof(Scientist);
            break;
            case tlaborer: arrap[n]=new laborer;
            size=sizeof(laborer);
            break;
            default: cout<<"\nUnknown type in file\n"; return;
        }
        inf.read((char*)arrap[n], size);
        if(!inf){
            cout<<"\nCan't read data from file\n"; return;
        }
        n++;
    }
    cout<<"Reading "<<n<<" employees\n";
    
}

int main(){
    char ch;
    while(1){
        cout<<
        " 'a' --- add data for an employee\n"
        " 'd' --- display data for all employee\n"
        " 'w' --- write all employee data to file\n"
        " 'r' --- rad all employee data from file\n"
        " 'x' --- exit\n"
        "Enter selection: ";
        cin>>ch;
        switch(ch){
            case 'a': employee::add(); break;
            case 'd': employee::display(); break;
            case 'w': employee::write(); break;
            case 'r': employee::read(); break;
            case 'x': exit(0);
            default: cout<<"\nUnknown command";
        }
    }
    return 0;
}