#include<iostream>
#include<string>
#define spc " "
#define nl '\n'
using namespace std;

const string cowSound="moo";
const string chickSound="buck buck";
const string catSound="meow";

class Animal{
    string habitat_area, sound;
    bool canFly, canSwim;
    public:
        Animal(string ha, string snd, bool cF, bool cS):habitat_area(ha), sound(snd), canFly(cF), canSwim(cS){}
        void set_area(string ha){
            habitat_area=ha;
        }
        void set_sound(string snd){
            sound=snd;
        }
        void set_Fly_stat(bool cF){
            canFly=cF;
        }
        void set_Swim_stat(bool cS){
            canSwim=cS;
        }
        string get_area(){
            return habitat_area;
        }
        bool get_Fly_stat(){
            return canFly;
        } 
        bool get_Swim_stat(){
            return canSwim;
        }
        void vocalise(){
            cout<<"Sound: "<<sound;
        }
};

class Cow:public Animal{
    public:
        Cow():Animal("Land", cowSound, false, true){}
};

class Cat:public Animal{
    public:
        Cat():Animal("Land", catSound, false, true){}
};

class Chicken:public Animal{
    public:
        Chicken():Animal("Land", catSound, true, true){}
};

int main(){
    Cat sandy;
    Cow robin;
    Chicken mokles;
    sandy.vocalise();
    cout<<nl;
    robin.vocalise();
    cout<<nl;
    mokles.vocalise();
    return 0;
}