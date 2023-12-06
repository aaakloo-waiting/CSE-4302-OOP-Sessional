#include<bits/stdc++.h>
#define spc " "
#define nl '\n'
using namespace std;

const double pi=2.0*acos(0.0);

class Shape{
    double area;
    public:
        Shape(double a):area(a){}
        void get_area(){
            cout<<"Area (A): "<<area<<nl;
        }
        void set_area(double a){
            area=a;
        }
};

//When one class is used multiple times, we just need to write the bare minimum functions
// 1. No getter or setter fn in base classes 2. No variable to strore common things like float area
class TwoDimensionalShape:public Shape{
    double perimeter;
    public:
        TwoDimensionalShape(double p, double a):perimeter(p), Shape(a){}
        void get_perimeter(){
            cout<<"Perimeter(P): "<<perimeter<<nl;
        }
        void set_perimeter(double p){
            perimeter=p;
        }
        void whoAmIS(){
            cout<<"I am a two-dimensional shape."<<nl;
        }
};

class ThreeDimensionalShape:public Shape{
    double volume;
    public:
        ThreeDimensionalShape(double v, double a):volume(v), Shape(a){}
        void get_volume(){
            cout<<"Volume(V): "<<volume<<nl;
        }
        void set_volume(double v){
            volume=v;
        }
        void whoAmIS(){
            cout<<"I am a three-dimensional shape."<<nl;
        }
};

class Circle:public TwoDimensionalShape{
    double radius;
    public:
        Circle(double r):radius(r), TwoDimensionalShape((2*pi*r), (pi*r*r)){}
        void whoAmI(){
            cout<<"I am Circle."<<spc;
            whoAmIS();
        }
};

class Triangle:public TwoDimensionalShape{
    double s;
    public:
        Triangle(double a, double b, double c):s((a+b+c)/2), TwoDimensionalShape((2*s), (sqrt(s*(s-a)*(s-b)*(s-c)))){}
        void whoAmI(){
            cout<<"I am Triangle."<<spc;
            whoAmIS();
        }
};

class Rectangle:public TwoDimensionalShape{
    double length, width;
    public:
        Rectangle(double l, double w):length(l), width(w), TwoDimensionalShape(2*(l+w), (l*w)){}
        void whoAmI(){
            cout<<"I am Rectangle."<<spc;
            whoAmIS();
        }
};

class Cube:public ThreeDimensionalShape{
    double side_l;
    public:
        Cube(double sl):side_l(sl), ThreeDimensionalShape((sl*sl*sl), (6*sl*sl)){}
        void whoAmI(){
            cout<<"I am Cube."<<spc;
            whoAmIS();
        }
};

class Sphere:public ThreeDimensionalShape{
    double sp;
    public:
        Sphere(double s):sp(s), ThreeDimensionalShape((4/3)*pi*s*s*s, 4*pi*s*s){}
        void whoAmI(){
            cout<<"I am Sphere."<<spc;
            whoAmIS();
        }
};

class Cylindar:public ThreeDimensionalShape{
    double R, H;
    public:
        Cylindar(double r, double h): R(r), H(h), ThreeDimensionalShape((1/3)*pi*r*r*h, (2*pi*r*h+2*pi*r*r)){}
        void whoAmI(){
            cout<<"I am Cylindar"<<spc;
            whoAmIS();
        }

};
int main(){
    Circle c(5.0);
    Triangle t(10.0, 9.0, 7.0);
    Cube cb(5.0);
    Sphere s(3.0);
    Cylindar cl(10.0, 6.0);
    Rectangle r(4.0, 5.0);
    c.whoAmI();
    cb.whoAmI();
    t.whoAmI();
    s.whoAmI();
    cl.whoAmI();
    r.whoAmI();
    return 0;
}
/*
*/