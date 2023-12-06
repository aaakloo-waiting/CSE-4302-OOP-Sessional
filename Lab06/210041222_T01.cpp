#include <iostream>
#include <vector>
#include <map>
#include <string>

class Student {
private:
    std::string firstName;
    std::string lastName;
    std::string id;
    int birthYear;
    std::map<std::string, float> courseMarks;
    static int totalStudents;
    static float totalCGPA;

public:
    Student(std::string first, std::string last, std::string studentId, int birthYear) 
        : firstName(first), lastName(last), id(studentId), birthYear(birthYear) {
        totalStudents++;
        totalCGPA += 0.0;
    }

    void enrollInCourses(std::string courseName) {
        courseMarks[courseName] = 0.0;
    }

    void obtainedMarks(std::string courseName, float marks) {
        if (courseMarks.find(courseName) != courseMarks.end()) {
            courseMarks[courseName] = marks;
        }
    }

    float setGPAForEachCourse() {
        if (courseMarks.empty()) return 0.0;

        float totalGPA = 0.0;
        for (const auto& entry : courseMarks) {
            if (entry.second >= 90.0) {
                totalGPA += 4.0;
            } else if (entry.second >= 80.0) {
                totalGPA += 3.0;
            } else if (entry.second >= 70.0) {
                totalGPA += 2.0;
            } else if (entry.second >= 60.0) {
                totalGPA += 1.0;
            }
        }
        return totalGPA / courseMarks.size();
    }

    float displayCGPA() {
        return totalCGPA / totalStudents;
    }

    void willGraduate() {
        float cgpa = setGPAForEachCourse();
        std::cout << "Student " << firstName << " " << lastName << " with ID " << id << " ";
        if (cgpa >= 2.0) {
            std::cout << "will graduate." << std::endl;
        } else {
            std::cout << "will not graduate." << std::endl;
        }
    }

    void applyForScholarship() {
        float cgpa = setGPAForEachCourse();
        std::cout << "Student " << firstName << " " << lastName << " with ID " << id << " ";
        if (cgpa > 3.8) {
            std::cout << "is eligible for a scholarship." << std::endl;
        } else {
            std::cout << "is not eligible for a scholarship." << std::endl;
        }
    }

    void participateInInternship(std::string company, std::string courseName) {
        float cgpa = setGPAForEachCourse();
        std::cout << "Student " << firstName << " " << lastName << " with ID " << id << " ";
        if (cgpa > 3.0 && courseMarks.find(courseName) != courseMarks.end()) {
            std::cout << "can do an internship at " << company << "." << std::endl;
        } else {
            std::cout << "cannot do an internship at " << company << "." << std::endl;
        }
    }

    ~Student() {
        float cgpa = setGPAForEachCourse();
        std::cout << "Student " << firstName << " " << lastName << " with ID " << id << " enrolled in the following courses:" << std::endl;
        for (const auto& entry : courseMarks) {
            std::cout << entry.first << ": " << entry.second << std::endl;
        }
        std::cout << "Graduation Status: ";
        willGraduate();
        std::cout << "Scholarship Status: ";
        applyForScholarship();
        std::cout << "Internship Status: ";
        participateInInternship("Y Company", "X Course");
        totalStudents--;
        totalCGPA -= cgpa;
    }
};

int Student::totalStudents = 0;
float Student::totalCGPA = 0.0;

int main() {
    Student student1("John", "Doe", "12345", 2000);
    student1.enrollInCourses("Math");
    student1.enrollInCourses("Science");
    student1.obtainedMarks("Math", 95);
    student1.obtainedMarks("Science", 88);

    Student student2("Alice", "Smith", "67890", 1999);
    student2.enrollInCourses("History");
    student2.enrollInCourses("English");
    student2.obtainedMarks("History", 78);
    student2.obtainedMarks("English", 92);

    Student student3("Bob", "Johnson", "54321", 2001);
    student3.enrollInCourses("Physics");
    student3.enrollInCourses("Chemistry");
    student3.enrollInCourses("Biology");
    student3.obtainedMarks("Physics", 85);
    student3.obtainedMarks("Chemistry", 75);
    student3.obtainedMarks("Biology", 92);

    student1.willGraduate();
    student2.willGraduate();
    student3.willGraduate();

    student1.applyForScholarship();
    student2.applyForScholarship();
    student3.applyForScholarship();

    student1.participateInInternship("XYZ Inc.", "Math");
    student2.participateInInternship("ABC Corp.", "History");
    student3.participateInInternship("DEF Ltd.", "Biology");

    std::cout << "Average CGPA of the 3 students: " << Student::totalCGPA / Student::totalStudents << std::endl;

    return 0;
}
