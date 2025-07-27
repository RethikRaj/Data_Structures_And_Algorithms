#include <iostream>
#include <string>
using namespace std;

class Student{
    public:
        // Attributes
        int id;
        int age;
        string name;
        float* gpa;

        // constructor
        Student(int id,int age,string name,float gpa){
            this->id = id;
            this->age = age;
            this->name = name;
            this->gpa = new float(gpa);
        }

        // copy constructor
        Student(const Student &srcobj){
            this->id = srcobj.id;
            this->age = srcobj.age;
            this->name = srcobj.name;
        }

        // Behaviour => Methods
        void study(){
            cout << this->name <<" is studying" << endl;
        }

        void sleep(){
            cout << this->name <<" is sleeping" << endl;
        }

        // destructor
        ~Student(){
            cout<< "Destructor is called " << endl;
            // Delete dynamically allocated memory during construction
            delete this->gpa;
        }
};


int main(){

    // Static allocation
    Student s1(1,20,"Rethik",9.8);
    s1.age = 40;
    s1.study();
    // copy object
    Student s2(s1); // Student s2 = s1;


    Student* s3 = new Student(2,21,"Raj",10);
    s3->age = 41;
    s3->study();
    delete s3;

    return 0;
}