#include <iostream>

using namespace std;

class Complex{
protected:
    int real;
    int imag;

public:
    Complex(){
        real = imag = INT_MIN;
    }
    Complex(int real,int imag){
        this->real = real;
        this->imag = imag;
    }

    Complex operator + (const Complex &obj){
        Complex res;
        res.real = this->real + obj.real;
        res.imag = this->imag + obj.imag;
        return res;
    }

    Complex operator *(const Complex &obj){
        Complex res;
        res.real = ((this->real)*(obj.real)) - ((this->imag)*(obj.imag));
        res.imag = ((this->real)*(obj.imag)) + ((this->imag)*(obj.real));
        return res;
    }

    bool operator ==(const Complex &obj){
        return (this->real == obj.real) && (this->imag == obj.imag);
    }

    void printComplex(){
        cout << "[" << this->real << "+" << " i "<< this->imag << "]" << endl;
    }

};

int main(){
    Complex A(10,20);
    A.printComplex();
    Complex B(30,40);
    B.printComplex();

    int sum = 2 + 3;
    float sum2 = 2.3 + 3.4;
    double sum3 = 4.5 + 6;

    Complex C = A + B; 
    C.printComplex();

    Complex D = A*B;
    D.printComplex();

    bool isEqual = (A==B);
    cout << isEqual << endl;

    return 0;
}