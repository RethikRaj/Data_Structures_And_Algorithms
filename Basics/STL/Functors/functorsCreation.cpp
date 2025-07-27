#include <iostream>

using namespace std;

class functorOne{
    public:
        bool operator()(int a,int b){
            return a > b;
        }
};

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

class StudentFunctor{
    public:
        bool operator()(Student a,Student b){
            return a.marks < b.marks;
        }
};

int main(){

    int x = 10;
    int y = 20;

    functorOne cmp;

    if(cmp(x,y)){
        cout << "x is greater than y" << endl;
    }else{
        cout << "x is less than y" << endl;
    }


    Student s1 = Student(100,20,"Rethik");
    Student s2 = Student(200,25,"Raj");

    StudentFunctor sf;

    if(sf(s1,s2)){
        cout << "s1 is less than s2" << endl;
    }
    else{
        cout << "s1 is greater than s2" << endl;
    }


    return 0;
}