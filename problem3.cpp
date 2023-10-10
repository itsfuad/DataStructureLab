#include <iostream>

using namespace std;

struct Student
{
    string id;
    int semesters;
    int credits;
    float cgpa;
};


int main(){
    Student students[10];


    students[0].id = "22-11111-1";
    students[0].semesters = 2;
    students[0].credits = 30;
    students[0].cgpa = 3.75;

    students[1].id = "22-11111-2";
    students[1].semesters = 2;
    students[1].credits = 30;
    students[1].cgpa = 3.75;

    students[2].id = "22-11111-3";
    students[2].semesters = 3;
    students[2].credits = 30;
    students[2].cgpa = 3.24;

    students[3].id = "22-11111-4";
    students[3].semesters = 3;
    students[3].credits = 60;
    students[3].cgpa = 3.88;

    students[4].id = "22-11111-5";
    students[4].semesters = 3;
    students[4].credits = 60;
    students[4].cgpa = 3.88;

    students[5].id = "22-11111-6";
    students[5].semesters = 3;
    students[5].credits = 60;
    students[5].cgpa = 3.23;

    students[6].id = "22-11111-7";
    students[6].semesters = 3;
    students[6].credits = 60;
    students[6].cgpa = 3.88;

    students[7].id = "22-11111-8";
    students[7].semesters = 4;
    students[7].credits = 80;
    students[7].cgpa = 3.58;

    students[8].id = "22-11111-9";
    students[8].semesters = 4;
    students[8].credits = 80;
    students[8].cgpa = 3.88;

    students[9].id = "22-11111-10";
    students[9].semesters = 4;
    students[9].credits = 80;
    students[9].cgpa = 3.88;


    cout << "Scholarship students: " << endl;
    for(int i=0; i<15; i++){
        if(students[i].cgpa >= 3.75){
            cout << students[i].id << endl;
        }
    }

    cout << "Students with more than 50 credits: " << endl;
    for(int i=0; i<15; i++){
        if(students[i].credits > 50){
            cout << students[i].id << endl;
        }
    }

    cout << "Students with more than 2 semesters and 28 credits: " << endl;
    for(int i=0; i<15; i++){
        if(students[i].semesters > 2 && students[i].credits > 28){
            cout << students[i].id << endl;
        }
    }

    return 0;
}
