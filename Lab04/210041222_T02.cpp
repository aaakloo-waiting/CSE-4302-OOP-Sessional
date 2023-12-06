#include <iostream>
#include <map>
#define ll long long
#define nl '\n'
#define spc " "
using namespace std;
class Student
{
private:
    string firstName, lastName, studentID, course;
    int birthYear;
    float cgpa, marks, gpa;

public:
    // map<string, float> course, GPA;
    static int totalStudent;
    Student()
    {
        firstName = "";
        lastName = "";
        studentID = "";
        birthYear = 0;
        totalStudent++;
    }
    Student(string fname, string lname, string id, int bYear)
    {
        firstName = fname;
        lastName = lname;
        studentID = id;
        birthYear = bYear;
        totalStudent++;
    }
    ~Student()
    {
        totalStudent--;
    }
    void enrollInCourse(string cname)
    {
        course = cname;
        marks = 0.0;
    }
    string generateEmail()
    {
        string in = "@iut-dhaka.edu";
        return ((firstName + lastName + in));
    }
    void obtained_marks(string cname, float mark)
    {
        course = cname;
        marks = mark;
    }
    void setGPAForEachCourse()
    {

        if (marks > 80)
            gpa = 4.00;
        else if (marks > 70)
            gpa = 3.50;
        else if (marks > 65)
            gpa = 3.25;
        else if (marks > 60)
            gpa = 3.00;
        else if (marks > 55)
            gpa = 2.75;
        else if (marks > 50)
            gpa = 2.50;
        else if (marks > 45)
            gpa = 2.25;
        else if (marks > 40)
            gpa = 2.00;
        else gpa = 0.00;
    }
    float displayCGPA()
    {
        cgpa = gpa;
        return cgpa;
    }
    void willGraduate()
    {
        (cgpa < 2.0) ? cout << "Fail" : cout << "Will Graduate";
        cout << nl;
    }
    void applyForScholarship()
    {
        (cgpa > 3.8) ? cout << "Scholar" : cout << "No scholarship!";
        cout << nl;
    }
    void participateInInternship(string company, string cname)
    {
        if (cgpa > 3.0)
            cout << company << " chose you for internship" << nl;
        else
            cout << "No Job!" << nl;
    }
    void printAcademicRecord()
    {
        cout << firstName << spc << lastName << nl << studentID << nl << generateEmail() << nl << course<<nl;
        willGraduate();
        applyForScholarship();
        participateInInternship("Google", "DSA");
    }
};
int Student::totalStudent = 0;
signed main()
{
    Student s1("Akib", "Haider", "222", 2003);
    s1.enrollInCourse("DSA");
    s1.obtained_marks("DSA", 95);
    s1.printAcademicRecord();
    return 0;
}