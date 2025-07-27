#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printDouble(int x){
    cout << x*2 << " ";
}

bool isEven(int x){
    return x%2 == 0;
}

int main(){
    vector<int> arr = {23,47,21,100,99,101,21,100,99,101};
    vector<int> arrSorted = {10,20,30,30,30,40,50};

    // forEach
    for_each(arr.begin(),arr.end(),printDouble);
    cout << endl;


    // find
    int target = 200;
    vector<int>::iterator it = find(arr.begin(),arr.end(),target);
    if(it != arr.end()){
        cout << "Element found at index : " << it - arr.begin() << endl;
    }else{
        cout << "Element not found" << endl;
    }

    // find_if
    auto it2 = find_if(arr.begin(),arr.end(),isEven);
    if(it2 != arr.end()){
        cout << "First Even number is : " << *it2 << endl;
    }else{
        cout << "No even number found" << endl;
    }

    // count
    int c = count(arr.begin(),arr.end(),target);
    cout << "Count of " << target << " is : " << c << endl;

    // count_if
    c = count_if(arr.begin(),arr.end(),isEven);
    cout << "Count of even numbers is : " << c << endl;


    // sort
    // sort(arr.begin(),arr.end());
    // for(int ele : arr){
    //     cout << ele << " ";
    // }

    // reverse
    // reverse(arr.begin(),arr.end());
    // for(int ele : arr){
    //     cout << ele << " ";
    // }


    // rotate
    // rotate(arr.begin(),arr.begin()+2,arr.end()); // Rotates 2 places to the left
    // for(int ele : arr){
    //     cout << ele << " ";
    // }

    // rotate-right
    rotate(arr.begin(),arr.end()-2,arr.end()); // Rotates 2 places to the right
    for(int ele : arr){
        cout << ele << " ";
    }

    cout << endl;

    cout << "HELOO" << endl;
    


    // unique - sorted range
    auto it3 = unique(arrSorted.begin(),arrSorted.end());
    // Before it3 elements are unique and from it3 to end are duplicates.
    arrSorted.erase(it3, arrSorted.end());
    for(int ele : arrSorted){
        cout << ele << " ";
    }

    // partition
    auto it4 = partition(arr.begin(),arr.end(),isEven);
    for(int ele : arr){
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}