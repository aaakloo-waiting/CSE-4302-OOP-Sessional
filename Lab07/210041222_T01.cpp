#include<iostream>
#include<string>

using namespace std;

class StudentCollection{
private:
    static const int MaxStd=10;
    string names[MaxStd]; 
    double grades[MaxStd];
    int stdTotal;
public:
    StudentCollection():stdTotal(0){}
    void addStudent(const string& name, double grade){
        if(stdTotal<MaxStd){
            names[stdTotal]=name;
            grades[stdTotal]=grade;
            stdTotal++;
        }else{
            cout<<"Student Collection is Overflowing!"<<endl;
        }
    }
//Read operation
    void operator[] (const string& name){
        for(int i=0; i<stdTotal; i++){
            if(names[i]==name){
                cout<<"Name: "<<names[i]<<" Grades: "<<grades[i]<<endl;
            }
        }
    }
    // StudentCollection& operator= (double nG){
    //     grades[name]=nG;
    // }
//Write operation
    // void operator[] (string& name, double& newGrade){
    //     for(int i=0; i<10; i++){
    //         if(names[i]==name){
    //             grades[i]=newGrade
    //         }
    //     }
    // }
};

int main(){
    StudentCollection king;
    king.addStudent("Akbar", 93.4);
    king.addStudent("Babar", 90.7);
    king.addStudent("Humayun", 91.2);
    king.addStudent("Jahangir", 88.9);
    king.addStudent("Shah_Jahan", 89.5);
    king.addStudent("Aurangajeb", 93.4);
    king.addStudent("Bahadur_Shah", 90.7);
    king.addStudent("Azam_Shah", 91.2);
    king.addStudent("Jahandar_Shah", 88.9);
    king.addStudent("Shah_Alam", 89.5);
    king.addStudent("Mir_Jafar", 89.5);
    double nG=92.8;
    king["Babar"];
    // king["Akbar"]=nG;
    king["Akbar"];
    return 0;
}