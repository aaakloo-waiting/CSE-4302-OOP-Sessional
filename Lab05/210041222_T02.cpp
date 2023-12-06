#include <iostream>
#include <string>
#define ll long long
#define nl '\n'
#define spc " "
using namespace std;


class Medicine{
    private:
        string name, gen_name;
        float discountPercent, unitPrice, itemNum, ni, up;
    public:
        Medicine(){
            unitPrice=0.0;
            discountPercent=.05;
            name="";
            gen_name="";
        }
        Medicine(string nm, string genNmae, float prc){
            name=nm;
            gen_name=genNmae;
            unitPrice=prc;
        }
        float updatedPrice(float percent){
            percent/=100;
            percent*=unitPrice;
            up=unitPrice-percent;
            return up;
        }
        float getSellingPrice(float nos){
            if(itemNum>nos){
                ni=nos;
                return (nos*up);
            }
            else{
                cout<<"Item unavailable"<<nl;
            }            
        }
        float readjustedPrice(){
            ((itemNum*unitPrice)-(ni*up))/(itemNum-ni);          
        } 
        void resetPrice() const{
            cout<<name<<nl<<gen_name<<nl<<discountPercent<<nl<<unitPrice<<nl<<itemNum<<nl;
        }
};
int main(){
    Medicine napa("Xp", "Montilucast", 10.0);
    return 0;
}