#include<iostream>
#include<string>
#define nl '\n'
#define spc " "

using namespace std;

class Product{
    protected:
        string title, creator;
        int Unique_id;
        static int Product_sl_no;
    public:
        Product(string P_t, string c, int U_id) : title(P_t), creator(c), Unique_id(U_id){
            Product_sl_no++;
        }
        virtual void display_info() const{} =0;
        bool operator < (const Product &p){
            return (get_UniqueID() < p.get_UniqueID());
        }
        int get_UniqueID(){
            return Unique_id;
        }
        static int get_product_sl(){
            return Product_sl_no;
        }
        string get_title(){
            return title;
        }
};

class Book : public Product{
    public:
        Book():Product("", "", 0){}
        Book(string t, string a, int b_id):Product(t, a, b_id){}
        string get_author(){
            return creator;
        }
        void display_info(){
            cout<<"Book Info -> Title: "<<get_title()<<" Author: "<<get_author()<<" Unique ID: "<<get_UniqueID()<<nl;
        }        
};

class DVD:public Product{
    public:
        DVD():Product("", "", 0){}
        DVD(string t, string d, int d_id):Product(t, d, d_id){}
        string get_director(){
            return creator;
        }
        void display_info(){
            cout<<"DVD Info -> Title: "<<get_title()<<" Director: "<<get_director()<<" Unique ID: "<<get_UniqueID()<<nl;
        }
};

int Product::Product_sl_no=0;


int main(){
    Product* simple_inventory_system[10];
    int j=5;
    Book b0("War and Peace", "Tolostoy", 15), b1("Nondito Noroke", "Humayun A", 10), b2("Kisholoy", "Ahsan H", 20), b3("Tungovodra", "Shorodindu", 2), b4("Bangalir Mon", "Ahmod S", 13);
    DVD d0("DeathBed", "SSC", 7), d1("Minister", "Led Zeppelin", 19), d2("Mystery", "Maroon5", 23), d3("Rokter Gaan", "Kishore K", 37), d4("ISD", "Indalo", 22);
    simple_inventory_system[0]=&b0;
    simple_inventory_system[1]=&b1;
    simple_inventory_system[2]=&b2;
    simple_inventory_system[3]=&b3;
    simple_inventory_system[4]=&b4;
    simple_inventory_system[5]=&d0;
    simple_inventory_system[6]=&d1;
    simple_inventory_system[7]=&d2;
    simple_inventory_system[8]=&d3;
    simple_inventory_system[9]=&d4;
    for(int i=0; i<9; i++){
        for(int j=i+1; j<10; j++){
            if(*(simple_inventory_system[i])< *(simple_inventory_system[j])){
                *(simple_inventory_system[i]) ^= *(simple_inventory_system[j]) ^= *(simple_inventory_system[i]) ^= *(simple_inventory_system[j]);
            }
        }
    }
    for(int i=0; i<10; i++){
        cout<<simple_inventory_system[i]->display_info()<<nl;
    }
    return 0;
}