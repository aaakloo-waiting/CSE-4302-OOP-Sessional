#include <iostream>
#include <string>
#define ll long long
#define nl '\n'
#define spc " "
using namespace std;

class Product{
    private:
        string name;
        int id, price, quantity, category;
        bool isAvailable;
    public:
        static int totalVal;
        Product(){
            name="";
            id=price=quantity=category=0;
            isAvailable=false;
        }
        Product(string nm, int idin, int prc, int qnt){
            name=nm;
            id=idin;
            price=prc;
            quantity=qnt;
            totalVal+=(quantity*price);
        }
        void addToInventory(int addedqnt){
            quantity+=addedqnt;
            totalVal+=(quantity*price);
        }
        void purchase(int purchased_quantity){
            quantity-=purchased_quantity;
        }
        void applyProductDiscount(float percent){
            if(!isAvailable){
                totalVal-=(quantity*price*(percent/100.0));
                price-=(price*(percent/100));
                isAvailable=true;
            }
            else{
                cout<<"Already Discount Applied"<<nl;
            }
        }
        int updatePrice(float percent){
            price-=(price*(percent/100));
        }
        float displayInventoryValue() const{
            cout<<(price)<<nl;
        }
        static int getTotalInventoryValue(){
            return totalVal;
        }
        ~Product(){
            cout<<"Product Details: "<<nl<<"Name: "<<name<<nl<<"ID: "<<id<<nl<<"Price: "<<price<<nl<<"Quantity: "<<quantity<<nl;
        }


};
int Product::totalVal=0;
int main(){
    Product cake, cofee("Nescafe", 22, 10, 5), chips("Lays", 20, 15, 3);
    cake.addToInventory(2);
    cofee.purchase(3);
    cofee.applyProductDiscount(2.0);
    cofee.applyProductDiscount(20.0);
    cofee.displayInventoryValue();
    cout<<"Total Price: "<<Product::totalVal<<nl;
    return 0;
}

