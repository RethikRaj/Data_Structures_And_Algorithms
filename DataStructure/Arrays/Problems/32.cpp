#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(vector<int> &arr) {
        int smallestIndexOfRepeatingElement = INT_MAX;
        unordered_map<int,int> mp;
        
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i]) != mp.end()){
                smallestIndexOfRepeatingElement = min(smallestIndexOfRepeatingElement,mp[arr[i]]);
            }
            else{
                mp[arr[i]] = i;
            }
        }
        
        
        if(smallestIndexOfRepeatingElement == INT_MAX){
            return -1;
        }else{
            return smallestIndexOfRepeatingElement + 1;
        }
    }
};