#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // accumulate
    int sum = accumulate(arr.begin(), arr.end(), 0);// 0 is initial value   
    cout << "Sum: " << sum << endl;

    // innerProduct
    vector<int> first = {1, 2, 3};
    vector<int> second = {4, 5, 6};
    int innerProduct = inner_product(first.begin(), first.end(), second.begin(), 0);  // 0 is initial value       
    cout << "Inner Product: " << innerProduct << endl;

    // partial_sum
    vector<int> partialSumAns(arr.size()); // create an array of size arr.size() 
    partial_sum(arr.begin(), arr.end(), partialSumAns.begin());
    cout << "Partial Sum: " << endl;
    for (int i = 0; i < partialSumAns.size(); i++) {
        cout << partialSumAns[i] << " ";
    }
    cout << endl;

    // iota
    vector<int> iotaArr(10);
    iota(iotaArr.begin(), iotaArr.end(), 1);
    cout << "Iota Array: " << endl;
    for (int i = 0; i < iotaArr.size(); i++) {
        cout << iotaArr[i] << " ";
    }

    cout << endl;


    return 0;
}