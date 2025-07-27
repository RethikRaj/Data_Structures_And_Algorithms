#include<iostream>
using namespace std;

int getFactorial(int n) {
    //base case - mandatory
    if(n == 0 || n == 1) {
        return 1;
    }
    //recursive call - mandatory
    //fact(n) = n * fact(n-1);
    //recursion -> fact(n-1);
    int recursionKaAns = getFactorial(n-1);
    int finalAns = n * recursionKaAns;
    return finalAns;
    //processing - optional 
}

// print counting from n to 1 
void printCounting(int n) {
    //base case
    if(n == 0) {
        return;
    } 
    
    //processing
    cout << n << " "; 
    //recursive call 
    printCounting(n-1);
}

// print counting from 1 to n
void printCounting2(int n) {
    //base case
    if(n == 0) {
        return;
    } 
    //recursive call 
    printCounting(n-1);
    //processing
    cout << n << " "; 
}

int pow(int a,int n) {
    //base case
    if( n == 0) {
        return 1;
    }
    //recursive relation 
    //pow(n) = a * pow(n-1);
    int recKaAns = pow(a,n-1);
    int finalAns = a * recKaAns;
    return finalAns;
    //processing 
}

int fib(int n) {
   //base case
   if(n == 0 || n == 1) {
    return n;
   }
   //recursive relation
   //fib(n) = fib(n-1) + fib(n-2);
   int ans = fib(n-1) + fib(n-2);
   return ans;
   //processing  
}

int getSum(int n) {
    //base case
    if(n == 1) 
        return 1;
    //recursive relation
    //sum(n) = sum(n-1) + n;
    int ans = getSum(n-1) + n;
    return ans;
    //processing
}