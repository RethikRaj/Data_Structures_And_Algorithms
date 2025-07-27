#include<iostream>

using namespace std;


class Student{
private:
    string name;
    int id;
    float* gpa;
    string gf;

public:
    Student(string name,int id,float gpa,string gf){
        this->name = name;
        this->id = id;
        this->gf = gf;
        *this->gpa = gpa;
    }

    string getName(){
        // can implement some logic for authorization, safety purposes
        return this->name;
    }

    void setName(string name){
        this->name = name;
    }

    float getGpa(){
        return *this->gpa;
    }

    // Similarly for all private attributes if needed implement getters and setters

    void study(){
        cout << this->name <<" is studying" << endl;
    }

    void sleep(){
        cout << this->name <<" is sleeping" << endl;
    }

    ~Student(){
        cout<< "Destructor is called " << endl;
        // Delete dynamically allocated memory during construction
        delete this->gpa;
    }
private:
    void gfChatting(){
        cout << this->name <<" is chatting with gf" << endl;
    }

};



int main(){
    Student R("Jisoo",1,9.9,"Chaeyoung");
    cout << "Name is " << R.getName() << endl;

    return 0;
}