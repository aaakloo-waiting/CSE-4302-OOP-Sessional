#include <iostream>
#include <cmath>
using namespace std;

class Coordinate {
private:
    float abscissa;
    float ordinate;

public:
   
    Coordinate(float x = 0.0, float y = 0.0) : abscissa(x), ordinate(y) {}
    ~Coordinate() {}   
    void display() {
        cout << "(" << abscissa << ", " << ordinate << ")";
    }
    float getDistance(Coordinate c) {
        float dx = abscissa - c.abscissa;
        float dy = ordinate - c.ordinate;
        return sqrt(dx * dx + dy * dy);
    }

    float getDistance() {
        return sqrt(abscissa * abscissa + ordinate * ordinate);
    }

    void move_x(float val) {
        abscissa += val;
    }

 
    void move_y(float val) {
        ordinate += val;
    }

 
    void move(float val) {
        move_x(val);
        move_y(val);
    }

   
    bool operator==(Coordinate c) {
        return getDistance() == c.getDistance();
    }

   
    bool operator!=(Coordinate c) {
        return getDistance() != c.getDistance();
    }

 
    bool operator<(Coordinate c) {
        return getDistance() < c.getDistance();
    }

   
    Coordinate& operator++() {
        move(1.0);
        return *this;
    }

   
    Coordinate operator++(int) {
        Coordinate temp = *this;
        move(1.0);
        return temp;
    }
};

int main() {
    Coordinate c1(13.0, 12.0);
    Coordinate c2(-1.0, -1.0);
    Coordinate c3(2.0, 2.0);

    cout << "c1: ";
    c1.display();
    cout << endl;

    cout << "c2: ";
    c2.display();
    cout << endl;

    cout << "c3: ";
    c3.display();
    cout << endl;

    cout << "Distance between c1 and c2: " << c1.getDistance(c2) << endl;
    cout << "Distance from origin for c1: " << c1.getDistance() << endl;

    if (c1 == c2) {
        cout << "c1 is equal to c2" << endl;
    } else {
        cout << "c1 is not equal to c2" << endl;
    }

    if (c1 != c3) {
        cout << "c1 is not equal to c3" << endl;
    } else {
        cout << "c1 is equal to c3" << endl;
    }

    if (c1 < c3) {
        cout << "c1 is closer to the origin than c3" << endl;
    } else {
        cout << "c1 is not closer to the origin than c3" << endl;
    }

    cout << "Incrementing c1 using prefix increment: ";
    ++c1;
    c1.display();
    cout << endl;

    cout << "Incrementing c2 using postfix increment: ";
    c2++;
    c2.display();
    cout << endl;

    return 0;
}