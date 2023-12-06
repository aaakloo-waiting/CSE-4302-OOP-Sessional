// Generic classes are the one with template
#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();

template <typename T>
class MathOperation
{
public:
    class negativeSqrtError{
    };
    class zeroDivisionError{
    };
    T add(T a, T b)
    {
        return a + b;
    }
    T divide(T a, T b)
    {
        if (!b){
            throw zeroDivisionError();
        }      
        else
        {
            return a / b;
        }
    }
    double Sqrt(T a)
    {
        if (a<0)
        {
            throw negativeSqrtError();
        }
        else
        {
            return sqrt(static_cast<double>(a));
        }
    }
};

int main()
{
        MathOperation<double> doubleOperation;
        MathOperation<long long> longOperation;
        cout<<"Double Operation: \n";
        cout<<doubleOperation.add(3.41, 7.59)<<endl;
        cout<<"long long operation: \n";
        cout<<longOperation.add(116, 423)<<endl;
    try{
        cout<<longOperation.Sqrt(-1);
    }
    catch(MathOperation<long long>::negativeSqrtError){
        cout << "Exception! Can't have any sqrt of negative number" << endl;
    }
    try{
        cout<<doubleOperation.Sqrt(-9.63)<<endl;
    }
    catch(MathOperation<double>::negativeSqrtError){
        cout << "Exception! Can't have any sqrt of negative number" << endl;
    }
    try{
        cout<<doubleOperation.divide(8.63, 0.0)<<endl;
    }
    catch(MathOperation<double>::zeroDivisionError){
        cout << "Exception! Can't perform division with denominator value 0" << endl;       
    }
    try{
        cout<<longOperation.divide(863, 0)<<endl;
    }
    catch(MathOperation<long long>::zeroDivisionError){
        cout << "Exception! Can't perform division with denominator value 0" << endl;       
    }
    return 0;
}
