#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    void findNGE(vector<int>& arr,unordered_map<int,int> &NGE){
        stack<int> s;
        s.push(-1);

        for(int i=arr.size()-1;i>=0;i--){
            int curr = arr[i];
            while(!s.empty() && s.top() != -1 &&s.top() <= curr){
                s.pop();
            }
            // store ans
            NGE[arr[i]] = s.top();
            // push curr
            s.push(curr);
        }
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> NGE; // nums2[i]->NGE
        // store NGE of each element in nums2 in map
        findNGE(nums2,NGE);
        auto it = NGE.begin();
        while(it != NGE.end()){
            cout << ((*it).second) << " ";
            it++;
        }
        // By now we have got NGE of all elements in nums2

        // make ans
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(NGE[nums1[i]]);
        }
        return ans;
    }
};