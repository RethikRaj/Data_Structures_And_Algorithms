#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/* Logic : 
    1. comparator works same as in sort .
    2. But the top pointer points at last .
    3. So think reverse.
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
        // You think max heap occurs but min heap will come out.
        return s1.marks > s2.marks; 
    }
};


int main(){ 
    priority_queue<Student,vector<Student>,StudentComparator> pq; 
    pq.push(Student(100,20,"Rethik")); 
    pq.push(Student(90,21,"Raj"));
    pq.push(Student(95,22,"Raja"));

    while(!pq.empty()){
        cout << pq.top().name << " " << pq.top().age << " " << pq.top().marks << endl;
        pq.pop();
    }




    


    return 0;
}