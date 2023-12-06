// Generic classes are the one with template
#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();

template <typename T>
class MathOperation
{
public:
    T add(T a, T b)
    {
        return a + b;
    }
    T divide(T a, T b)
    {
        if (b)
            return a / b;
        else
        {
            cout << "Exception! Can't perform division with zero" << endl;
            return INF;
        }
    }
    double Sqrt(T a)
    {
        if (a >= 0)
        {
            return sqrt(static_cast<double>(a));
        }
        else
        {
            cout << "Exception! Can't have any sqrt of negative number" << endl;
            return 0.0;
        }
    }
};

int main()
{
    MathOperation<double> doubleOperation;
    MathOperation<long long> longOperation;
    cout<<"Double Operation: \n";
    double a1=doubleOperation.add(3.41, 7.59);
    double a2=doubleOperation.divide(8.63, 1.29);
    cout<<a1<<" "<<a2<<endl;
    cout<<doubleOperation.Sqrt(5.63)<<endl;
    cout<<"long long operation: \n";
    cout<<longOperation.add(116, 423)<<endl;
    cout<<longOperation.divide(113, 100)<<endl;
    cout<<longOperation.Sqrt(15);
    return 0;
}
