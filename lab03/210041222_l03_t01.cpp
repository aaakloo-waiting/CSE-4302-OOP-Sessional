#include<iostream>
#define ll long long
using namespace std;

class Counter{
    private:
        int cnt, incrementSteps;
    public:
        void setIncrementStep(int step_val){
            incrementSteps=step_val;
        }
        int getCount(){
            return cnt;
        }
        void increment(){
            cnt+=incrementSteps;
        }
        void resetCount(){
            cnt=0;
        }
        bool isEven(){
            if(cnt&1){
                return 0;
            }
            return 1;
        }
};

signed main(){
    Counter cnt1;
    cnt1.resetCount();
    cnt1.setIncrementStep(3);
    cnt1.increment();
    cnt1.increment();
    cout<<cnt1.getCount()<<endl<<cnt1.isEven()<<endl;
    cnt1.resetCount();
    cout<<cnt1.getCount();
    return 0;
}