#include<iostream>
using namespace std;

class CurrencyUSD
{
private:
    int dollar;
    int cents;

public:
    CurrencyUSD (int D = 0, int C = 0)
    {
        dollar = D;
        cents = C;
    }

    int getDollars()
    {
        return dollar;
    }

    int getCents()
    {
        return cents;
    }

    friend class CurrencyBDT; //CurrencyBDT class can access to this CurrencyUSD class
};

class CurrencyEuro
{
private:
    int euro;
    int cents;

public:
    CurrencyEuro (int E = 0, int C = 0)
    {
        euro = E;
        cents = C;
    }
    CurrencyEuro (int E , int C )
    {
        euro = E;
        cents = C;
    }

    int getEuros()
    {
        return euro;
    }

    int getCents()
    {
        return cents;
    }

    friend class CurrencyBDT;
};

class CurrencyBDT
{
private:
    int taka;
    int poisha;

public:
    CurrencyBDT (int T = 0, int P = 0)
    {
        taka = T;
        poisha = P;
    }
    operator CurrencyUSD()
    {
        float usdAmount = (taka + poisha * 0.01)/85;
        int usDollars = static_cast<int>(usdAmount);
        int cents = static_cast<int>((usdAmount - usDollars) * 100);
        return CurrencyUSD(usDollars, cents);
    }

    operator CurrencyEuro()
    {
        double euroAmount = (taka + poisha * 0.01)/135;
        int euros = static_cast<int>(euroAmount);
        int cents = static_cast<int>((euroAmount - euros) * 100);
        // return CurrencyEuro(euros, cents);
    }

    int getTaka()
    {
        return taka;
    }

    int getPoisha()
    {
        return poisha;
    }
};

int main()
{
    CurrencyBDT bdtAmount(10000, 50); // 10000 Taka and 50 Poisha

    CurrencyUSD usdAmount = bdtAmount;
    CurrencyEuro euroAmount = bdtAmount;

    cout << "Amount in Taka: " << bdtAmount.getTaka() << "/- and poisha: " << bdtAmount.getPoisha() << "Poisha\n";

    cout << "Amount in Dollars: " << usdAmount.getDollars() << "$ and cents: " << usdAmount.getCents() << "cents\n";
    cout << "Amount in Euros: " << euroAmount.getEuros() << "E and cents: " << euroAmount.getCents() << "cents\n";
    return 0;
}
