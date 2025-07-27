#include<iostream>

using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num = start ^ goal;

        // calculate the number of 1's in binary representation of num.
        int numberOfOnes = 0;
        while(num != 0){
            int rem = num % 2;
            numberOfOnes += ((rem == 1) ? 1 : 0);
            num = num/2;
        }
        return numberOfOnes;
    }
};
