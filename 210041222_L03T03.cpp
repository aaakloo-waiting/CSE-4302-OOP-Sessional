#include <iostream>
#include <string>
#define nl "\n"
#define ll long long
using namespace std;

class Student
{
private:
    string nameFirst, nameLast, ID, Course;
    int DOB, Age;
    float Marks, GPA;

public:
    void setDetails(string namef, string namel, int age, string id, string course, int dob, float marks)
    {
        nameFirst = namef;
        nameLast = namel;
        Age = age;
        ID = id;
        Course = course;
        DOB = dob;
        Marks = marks;
    }
    int displayAge()
    {
        return Age;
    }
    float displayGPA()
    {
        if (Marks > 80)
            GPA = 4.00;
        else if (Marks > 70)
            GPA = 3.50;
        else if (Marks > 65)
            GPA = 3.25;
        else if (Marks > 60)
            GPA = 3.00;
        else if (Marks > 55)
            GPA = 2.75;
        else if (Marks > 50)
            GPA = 2.50;
        else if (Marks > 45)
            GPA = 2.25;
        else if (Marks > 40)
            GPA = 2.00;
        else
            GPA = 0.00;
        return GPA;
    }
    void willGraduate()
    {
        if (GPA < 2.0)
            cout << "Failed" << nl;
        else
            cout << "Graduated!!" << nl;
    }
    float updatedGPA()
    {
        Marks += (Marks * (0.1));
        return Marks;
    }
    void printTranscript()
    {
        cout << "ID: " << ID << nl << "Name: " << nameFirst << " " << nameLast << nl << "Age: " << Age << nl << "CG: " << GPA << nl;
    }
};

signed main()
{
    Student std1;
    std1.setDetails("Rahim", "Mia", 23, "42310", "TVE", 2000, 78);
    cout << std1.displayAge() << nl;
    cout << std1.displayGPA() << nl;
    std1.willGraduate();
    std1.updatedGPA();
    std1.printTranscript();
    return 0;
}