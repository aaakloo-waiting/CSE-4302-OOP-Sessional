#include<iostream>

using namespace std;

class Weight{
private:
    const double kgPoundconverter = 2.205;
    int pound;
    double ounce;
public:
    Weight(){//deafault constructor
        pound=0;
        ounce=0;
    }
    Weight(int P, double O){//argumented constructor
        pound=P;
        ounce=O;
    }
    Weight(double kg){//Weight constructor holding operator double to be overloaded
        double temp=kg*kgPoundconverter;
        pound=static_cast<int>(temp);
        ounce=(temp-pound)*16;
    }
    void showWeight(){
        cout<<"Pound: "<<pound<<endl<<"Ounce: "<<ounce<<endl;
    }
    operator double(){
        return (pound-(ounce)/16)*kgPoundconverter;
    }
    
};

int main(){
    Weight w1(100), w2(50, 37);
    double w1kgWeight = w1, w2kgWeight = w2;
    cout<<"Converted weight of w1: "<<w1kgWeight<<endl;
    cout<<"Converted weight of w2: "<<w2kgWeight<<endl;
    return 0;
}