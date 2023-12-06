#include<bits/stdc++.h>
using namespace std;

class Furniture{
    public:
    class InvalidQuantityException{};
    class InvalidPriceException{};
    class InvalidExceedQuantityException{};
    int modelno, unit_price, quantity, flag;
    string material;
    // public:
    Furniture(int m, string mat, int up, int q, int f):modelno(m), material(mat), unit_price(up), quantity(q), flag(f){}
    Furniture(){}
    void putqnt(int qnt){
        if(qnt==0){
            throw InvalidQuantityException();
        }else if(qnt>50){
            throw InvalidExceedQuantityException();
        }      
        else{
            quantity=qnt;
        }
    }
    void putprice(int up){
        if(up==0){
            throw InvalidPriceException();
        }else{
            unit_price=up;
        }
    }
    void putmn(int model){
        modelno=model;
    }
    void putmaterial(string mat){
        material=mat;
    }
    int getflag(){
        return flag;
    }
    string getmat(){
        return material;
    }
    int getup(){
        return unit_price;
    }
    int getqnt(){
        return quantity;
    }
    int getmodel(){
        return modelno;
    }
    virtual void getinfo(){
        cout<<material<<" "<<modelno<<" "<<unit_price<<" "<<quantity<<endl;
    }
};

class Table:public Furniture{
    public:
    string purpose;
    Table(int m, string mat, int up, int q, string p, int f):Furniture(m, mat, up, q, f), purpose(p){}
    virtual void getinfo(){
        cout<<material<<" "<<modelno<<" "<<unit_price<<" "<<quantity<<" "<<purpose<<endl;
    }
    string getpurpose(){return purpose;}
};
class Chair:public Furniture{
    public:
    int legnum;
    Chair(int m, string mat, int up, int q, int l, int f):Furniture(m, mat, up, q, f), legnum(l){}
    virtual void getinfo(){
        cout<<material<<" "<<modelno<<" "<<unit_price<<" "<<quantity<<" "<<legnum<<endl;
    }
    int getlegnum(){return legnum;}
};
class Bed:public Furniture{
    public:
    Bed(int m, string mat, int up, int q, int f):Furniture(m, mat, up, q, f){}
    virtual void getinfo(){
        cout<<material<<" "<<modelno<<" "<<unit_price<<" "<<quantity<<endl;
    }
};
class DiningTable:public Table{
    public:
    int seat_limit;
    DiningTable(int m, string mat, int up, int q, string p, int s, int f):Table(m, mat, up, q, p, f), seat_limit(s){}
    virtual void getinfo(){
        cout<<material<<" "<<modelno<<" "<<unit_price<<" "<<quantity<<" "<<purpose<<" "<<seat_limit<<endl;
    }
};

void sortbyFurnituretype(Furniture* farray[]){
    for(int i=0; i<9; i++){
        for(int j=1; j<10; j++){
            if(farray[i]->getflag()>farray[j]->getflag()){
                Furniture* temp=farray[j];
                farray[j]=farray[i];
                farray[i]=temp;
            }
        }
    }
}

int main(){
    Furniture* farray[10];
    Bed b1(3, "wood", 10000, 4, 1);
    Bed b2(5, "wood", 7000, 9, 1);
    Bed b3(1, "board", 9000, 2, 1);
    Bed b4(11, "board", 6000, 1, 1);
    Table t1(7, "plywood", 40000, 7, "Reading", 0);
    Table t2(8, "wood", 50000, 9, "Book Storing", 0);
    Table t3(3, "plastic", 12000, 14, "Eating", 0);
    Chair c1(2, "wood", 2000, 5, 4, 2);
    Chair c2(10, "plastic", 900, 2, 4, 2);
    Chair c3(3, "foam", 1750, 3, 6, 2);
    farray[0]=&b1;
    farray[1]=&b2;
    farray[2]=&b3;
    farray[3]=&b4;
    farray[4]=&t1;
    farray[5]=&t2;
    farray[6]=&t3;
    farray[7]=&c1;
    farray[8]=&c2;
    farray[9]=&c3;
    // Furniture f1;
    // f1.putmaterial("wood");
    // f1.putmn(1);
    // try{
    //     f1.putprice(0);
    // }catch(Furniture::InvalidPriceException){
    //     cout<<"Price cant be zero"<<endl;
    // }
    // try{
    //     f1.putqnt(120);
    // }catch(Furniture::InvalidExceedQuantityException){
    //     cout<<"Too much amount loaded"<<endl;
    // }
    // sortbyFurnituretype(farray);
    for(int i=0; i<10; i++){
        farray[i]->getinfo();
    }
    return 0;
}