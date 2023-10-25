#include <iostream>
#include <string>
#include <algorithm> // For max_element
#include <numeric>   // For accumulate

using namespace std;

struct Student {
    string ID;
    string name;
    double finalExam;
    double assignments[4];
    double midterm;
    double teamProject;    
};

char getLetterGrade(double numericGrade) {
    if (numericGrade >= 90) return 'A';
    if (numericGrade >= 80) return 'B';
    if (numericGrade >= 70) return 'C';
    if (numericGrade >= 60) return 'D';
    return 'F';
}

int main() {
    Student students[17] = { 
         {"486422", "Caroline, May Mary Crompton", 92, {100, 100, 100, 100}, 88, 17},
        {"490751", "Delorme, Noel Francis", 76, {81, 68, 100, 84}, 79, 15},
        {"491225", "Desjarlais, Stacey Lee", 84, {100, 100, 92, 100}, 76, 12},
        {"493273", "Favel, Katherine Elizabeth C.", 86, {100, 100, 100, 100}, 86, 20},
        {"494452", "Francis, Kelly Lynn", 92, {100, 100, 100, 87}, 73, 20},
        {"497561","Goforth, Lisa Anne", 0, {0, 82, 96, 100}, 68, 16}, 
        {"493469","La Rose, Tia Rai", 87, {100, 82, 84, 100}, 71, 20}, 
        {"488906","Merasty, Yolanda Patricia", 57, {0, 0, 0, 0}, 62, 3}, 
        {"495834","Peigan, Anne-Marie", 90, {96, 93, 0, 97}, 84, 13},
        {"493796","Starr, Tara Joy", 94, {100, 100, 0, 100}, 90, 20}, 
        {"496721","Sun, Hao", 98, {100, 0, 0, 100}, 83, 13}, 
        {"496509","Taypotat, Morley James Dale",78, {100, 100, 100, 100}, 93, 17}, 
        {"494689","Thomson, Michelle Melanie", 98, {87, 100, 100, 100}, 69, 20}, 
        {"493657","Toutsaint, Florence Christine", 80, {100, 100, 100, 81}, 71, 11}, 
        {"491158","Young, Adam Robert John", 97, {100, 100, 100, 100}, 85, 20}, 
        {"492676","Yuzicappi, Deanna Marlene", 82, {100, 72, 76, 100}, 75, 15}, 
        {"494521","Askew, Lucas Daniel", 66, {80, 88, 76, 100}, 68, 20}
     };

    double highestGrade = 0;
    Student highestGradeStudent;
    double sumGrade = 0;

    for (int i = 0; i < 17; ++i) {
        Student& student = students[i];
        double totalNumericGrade = 0.0;

        totalNumericGrade += student.finalExam * 0.40; // Final exam x 40%
        totalNumericGrade += student.teamProject ; // 
        
        double assignmentSum = accumulate(begin(student.assignments), end(student.assignments), 0.0) / 4.0;
        totalNumericGrade += assignmentSum * 0.2; // Assignments x 20%

        totalNumericGrade += student.midterm * 0.2; // Midterm x 20%

        char letterGrade = getLetterGrade(totalNumericGrade);
        
        cout << "Student ID: " << student.ID
             << ", Name: " << student.name
             << ", Total Numeric Grade: " << totalNumericGrade
             << ", Letter Grade: " << letterGrade
             << endl;

        // Update the highest grade and corresponding student
        if (totalNumericGrade > highestGrade) {
            highestGrade = totalNumericGrade;
            highestGradeStudent = student;
        }

        // Update the sum for average calculation
        sumGrade += totalNumericGrade;
    }

    // Calculate average grade
    double averageGrade = sumGrade / 17;

    cout << "Highest Numeric Grade: " << highestGrade
         << ", Student ID: " << highestGradeStudent.ID
         << ", Name: " << highestGradeStudent.name
         << endl;

    cout << "Average Grade of All Students: " << averageGrade << endl;

    return 0;
}
