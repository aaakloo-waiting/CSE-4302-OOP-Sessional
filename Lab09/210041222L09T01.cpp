#include<iostream>
using namespace std;
const int sz=8;
class TwoDimensionalShape{
    public:
        double edge, height;
        TwoDimensionalShape(double a, double b){
            edge = a, height = b;
        }
        void display(){
            cout<<"Shape Details: ";
            if(edge==height)
                cout<<"Edge: "<<edge<<endl;
            else
                cout<<"Base: "<<edge<<" Height: "<<height<<endl;
        }
};

// Don't use the variable to store shape details (height, weight etc)
// We need to calculate them

class Triangle : public TwoDimensionalShape{
    public:
        Triangle(double base, double height):TwoDimensionalShape(base, height){}
};

class Rectangle : public TwoDimensionalShape{
    public:
        Rectangle(double edge1, double edge2):TwoDimensionalShape(edge1, edge2){}
};

class Square : public TwoDimensionalShape{
    public:
        Square(double edge):TwoDimensionalShape(edge, edge){}
};

class Hexagon : public TwoDimensionalShape{
    public:
        Hexagon(double edge):TwoDimensionalShape(edge, edge){}
};

int main(){
    TwoDimensionalShape* ShapeArray[sz];
    Triangle Isoceles(10, 5), Rhombus(3, 9);
    Rectangle pool(40, 70), monitor_screen(15, 8);
    Square key_pad(4), key(0.5);
    Hexagon honey_comb(1), benzene(0.02);
    ShapeArray[0]=&Isoceles;
    ShapeArray[1]=&Rhombus;
    ShapeArray[2]=&pool;
    ShapeArray[3]=&monitor_screen;
    ShapeArray[4]=&key_pad;
    ShapeArray[5]=&key;
    ShapeArray[6]=&honey_comb;
    ShapeArray[7]=&benzene;
    for(int i=0; i<sz; i++){
        ShapeArray[i]->display();
        cout<<endl;
    }
    return 0;
}