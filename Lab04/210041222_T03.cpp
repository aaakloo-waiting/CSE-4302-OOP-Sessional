#include <iostream>
#include <string>
#include <algorithm>
#include<cmath>
#define ll long long
#define nl '\n'
#define spc " "
using namespace std;

class Rectangle
{
private:
    float length, width;
    float pr[2];

public:
    Rectangle() : length(1.0), width(1.0) {}
    Rectangle(float l, float w)
    {
        length = l;
        width = w;
    }
    float calculatePerimeter()
    {
        return (2 * (length + width));
    }
    float calculateArea()
    {
        return (length * width);
    }
    float calculateDiagonal()
    {
        return (sqrt(length * length + width * width));
    }
    void setDimension(float newLen, float newWidth)
    {
        if (newLen > 1.0 && newWidth < 20.0)
        {
            length = newLen;
            width = newWidth;
        }
    }
    float* getDimension()
    {
        pr[1] = width;
        pr[0] = length;
        return pr;
    }
};

int main()
{
    Rectangle r1, r2(10.0, 5.0);
    r1.setDimension(5.3, 6.4);
    r2.setDimension(0.3, 6.4);
    float* s1=r1.getDimension();
    float* s2=r2.getDimension();
    cout<<*(s1)<<spc<<*(s1+1)<<nl;
    cout<<*(s2)<<spc<<*(s2+1)<<nl;
    return 0;
}