#include <iostream>
#include <string>
#define ll long long
#define nl '\n'
#define spc " "
using namespace std;

class Flight
{
private:
    int flightNumber;
    string destination;
    float distance, maxFuelCapacity;

public:
    Flight()
    {
        flightNumber = 0;
        destination = "";
        distance = 0.0;
        maxFuelCapacity = 0.0;
    }
    Flight(int fnum, string dest, float dist, float maxFuel)
    {
        flightNumber = fnum;
        destination = dest;
        distance = dist;
        maxFuelCapacity = maxFuel;
    }
    ~Flight()
    {
        cout << flightNumber << " has been destructed" << nl;
    }
    float calFuel()
    {
        if (distance <= 1000)
        {
            return 500;
        }
        else if (distance <= 2000)
        {
            return 1100;
        }
        else
            return 2200;
    }
    void showInfo()
    {
        cout << "Flight info:" << nl << flightNumber << nl << destination << nl << distance << nl << maxFuelCapacity << nl;
        (calFuel() < maxFuelCapacity) ? cout << "Fit for travel" : cout << "Danger! Don't travel";
        cout << nl;
    }
};
signed main()
{
    Flight fly1(2, "Dublin", 1500, 2000), fly2;
    fly1.showInfo();
    fly2.showInfo();
    return 0;
}