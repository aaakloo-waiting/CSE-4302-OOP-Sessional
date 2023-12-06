#include<iostream>
#include<cmath>
#include<string>
using namespace std;
const int sz=8;
class TwoDimensionalShape{
    protected:
        string color, type;
        double edge, height, area, permimeter, total_edge;
    public:
        TwoDimensionalShape(double a, double b, string col){
            edge = a, height = b, area=a*b;
            set_color(col);
        }
        void set_color(string col){
            color=col;
        }
        string get_color(){
            return color;
        }
        void display(){
            cout<<"Shape Details: ";
            if(edge==height)
                cout<<"Edge: "<<edge<<endl;
            else
                cout<<"Base: "<<edge<<" Height: "<<height<<endl;
        }
        virtual void ShapeDetails(){}
};

class Triangle : public TwoDimensionalShape{
    public:
        Triangle(double base, double height, string c):TwoDimensionalShape(base, height, c){}
        virtual void ShapeDetails(){
            total_edge=3;
            type="Triange";
            if(height == (edge*1.732*0.5)){ // Equilateral condition
                area/=2;
                permimeter=3*edge;
            }else{ //Isoceles condition
                area/=2;
                double edge2=(edge/2)*(edge/2)+(height*height);
                edge2=sqrt(edge2);
                permimeter=edge+2*edge2;
            }
            cout<<"Number of sides: "<<total_edge<<endl<<"Type: "<<type<<endl<<"Area: "<<area<<endl<<"Perimeter= "<<permimeter<<endl<<"Color: "<<get_color()<<endl;
        }

};

class Rectangle : public TwoDimensionalShape{
    public:
        Rectangle(double edge1, double edge2, string c):TwoDimensionalShape(edge1, edge2, c){}
        virtual void ShapeDetails(){
            total_edge=4;
            type="Rectangle";
            permimeter=2*edge+2*height;
            cout<<"Number of sides: "<<total_edge<<endl<<"Type: "<<type<<endl<<"Area: "<<area<<endl<<"Perimeter= "<<permimeter<<endl<<"Color: "<<get_color()<<endl;
        }
};

class Square : public TwoDimensionalShape{
    public:
        Square(double edge, string c):TwoDimensionalShape(edge, edge, c){}
        virtual void ShapeDetails(){
            total_edge=4;
            type="Square"; 
            permimeter=4*edge;
            cout<<"Number of sides: "<<total_edge<<endl<<"Type: "<<type<<endl<<"Area: "<<area<<endl<<"Perimeter= "<<permimeter<<endl<<"Color: "<<get_color()<<endl;
        }

};

class Hexagon : public TwoDimensionalShape{
    public:
        Hexagon(double edge, string c):TwoDimensionalShape(edge, edge, c){}
        virtual void ShapeDetails(){
            total_edge=6;
            type="Hexagon";
            area*=1.5*1.732;
            permimeter=6*edge;
            cout<<"Number of sides: "<<total_edge<<endl<<"Type: "<<type<<endl<<"Area: "<<area<<endl<<"Perimeter= "<<permimeter<<endl<<"Color: "<<get_color()<<endl;

        }

};

int main(){
    TwoDimensionalShape* ShapeArray[sz];
    Triangle Isoceles(10, 5, "red"), Equilateral(3, 0.2598, "cyan");
    Rectangle white_board(40, 40, "white"), monitor_screen(15, 8, "transparent");
    Square key_pad(4, "gray"), key(0.5, "black");
    Hexagon honey_comb(1, "persian orange"), benzene(0.02, "light yellow");
    ShapeArray[0]=&Isoceles;
    ShapeArray[1]=&Equilateral;
    ShapeArray[2]=&white_board;
    ShapeArray[3]=&monitor_screen;
    ShapeArray[4]=&key_pad;
    ShapeArray[5]=&key;
    ShapeArray[6]=&honey_comb;
    ShapeArray[7]=&benzene;
    for(int i=0; i<sz; i++){
        ShapeArray[i]->ShapeDetails();
        cout<<endl;
    }
    return 0;
}