#include<iostream>
using namespace std;

bool isPrime(int num){
    if(num == 0 || num == 1){
        return false;
    }
    for(int i=2;i<num;i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int fibbiUtil(int termNumber){
    if(termNumber == 0 || termNumber==1){
        return termNumber;
    }
    return fibbiUtil(termNumber-1) + fibbiUtil(termNumber-2);
}

int fibbi(int max){
    int termNumber = 0;
    int fibbiAns = fibbiUtil(termNumber);
    int sum = 0;
    while(fibbiAns < max){
        if(isPrime(fibbiAns)){
            sum += fibbiAns;
        }
        termNumber++;
        fibbiAns = fibbiUtil(termNumber);
    }
    return sum;
}

int main() {
  int max;
  cin >> max;
  cout << fibbi(max) << endl; 
  return 0;
}
