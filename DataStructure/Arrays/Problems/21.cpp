#include <iostream>
#include <vector>

using namespace std;

// Method 4:
// int findMissingNumber4(vector<int> nums){
//     for(int i=0;i<nums.size();i++){
//         int index = nums[i] - 1;
//         if(i != index && nums[index] != ){

//         }else{

//         }
//     }
// }

// Method 3 : treat a[i] as index => SC:O(1) (Best)
int findMissingNumber(vector<int> nums){
    // Since i am changing inside nums => Pass by value

    for(int i=0;i<nums.size();i++){
        int index = abs(nums[i])-1;
        if(nums[index] > 0){
            nums[index] *= -1;
        }
    }

    // find the index of positive element
    for(int i=0;i<nums.size();i++){
        if(nums[i] > 0){
            return i+1;
        }
    }
    return -1;
}

// method 3 : Implementatiomn 2 
int findMissingNumberOneBasedIndexing(vector<int> nums){
    // Make one based
    nums.insert(nums.begin(),INT_MIN);

    // Our consideration is from 1 to nums.size();
    for(int i=1;i<nums.size();i++){
        int index = abs(nums[i]);
        if(nums[index] >0){
            nums[index] *= -1;
        }
    }

    for(int i=1;i<nums.size();i++){
        if(nums[i] > 0){
            return i;
        }
    }
    return -1;
}


// Method 2 : mapping

// Method 1 : Visted array


int main(){
    vector<int> nums = {1,3,5,3,4};
    cout << "Missing Number is : " << findMissingNumber(nums) << endl;
    cout << "Missing Number is : " << findMissingNumberOneBasedIndexing(nums) << endl;
    return 0;
}