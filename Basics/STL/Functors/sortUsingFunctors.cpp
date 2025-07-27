#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Logic : 
/* operator()(datatype a,datatype b) 
        1. returns true , then a is place before b
        2. returns false , then b is place before a
*/

class Student{
    public:
    int marks;
    int age;
    string name;
    Student(int marks,int age,string name){
        this->marks = marks;
        this->age = age;
        this->name = name;
    }
};


class StudentComparator{
    public:
    bool operator()(Student s1,Student s2){
        
        return s1.marks > s2.marks; // whenvever marks of s1 is greater than marks of s2 => s1 is place before s2 => Descending Order
    }
};

int main(){

    vector<Student> students = {Student(150,20,"Rethik"),Student(100,25,"Raj"),Student(200,30,"Raja")};

    // StudentComparator cmp;
    // sort(students.begin(),students.end(),cmp);

    sort(students.begin(),students.end(),StudentComparator());

    for(auto student : students){
        cout << student.name << " " << student.marks << endl;
    }


    return 0;
}