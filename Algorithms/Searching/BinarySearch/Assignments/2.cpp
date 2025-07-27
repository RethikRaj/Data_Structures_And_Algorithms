#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Method 1 : sort using diff

// Method 2 : two pointer method
class Solution2 {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int h = arr.size()-1;
        while(h-l >= k){
            if(x-arr[l] > arr[h]-x){
                l++;
            }else{
                h--;
            }
        }

        // [l , h] is ans;
        vector<int> ans;
        for(int i=l;i<=h;i++){
            ans.push_back(arr[i]);
        }

        return ans;
    }
};


// Method 3 : Binary search + two pointer
class Solution {
public:
    int lowerBound(vector<int>& arr,int x){
        int s = 0;
        int e = arr.size()-1;
        int mid = s+(e-s)/2;
        // why initialized with end ? => if no greater element exist then i need to return 
        int ans = e;

        while( s <= e){
            if(arr[mid] >= x){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int index = lowerBound(arr,x);
        cout << index << endl;
        int h = index;
        int l = index-1;

        while(h-l <= k){
            cout << "h is " << h << " , l is :" << l << endl;
            if(l < 0){
                h++;
            }
            else if(h >= arr.size()){
                l--;
            }
            else if(x-arr[l] > arr[h]-x){
                h++;
            }else{
                l--;
            }
        }

        // (l , h) is ans;
        vector<int> ans;
        for(int i=l+1;i< h;i++){
            ans.push_back(arr[i]);
        }

        return ans;
    }
};



// My solution : WOrst
class Solution {
public:
    int binarySearch(vector<int>& arr,int x){
        int s = 0;
        int e = arr.size()-1;
        int mid = s+(e-s)/2;

        int ans = 0;

        while(s <= e){
            if(arr[mid] == x){
                return mid;
            }else if(x < arr[mid]){
                if(abs(arr[ans]-x) > abs(arr[mid]-x)){
                    ans = mid;
                }else if(abs(arr[ans]-x) == abs(arr[mid]-x)){
                    ans = min(ans,mid);
                }
                e = mid-1;
            }else{
                if(abs(arr[ans]-x) > abs(arr[mid]-x)){
                    ans = mid;
                }else if(abs(arr[ans]-x) == abs(arr[mid]-x)){
                    ans = min(ans,mid);
                }
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;

        // Step 1 : Find index of closest to x
        int index = binarySearch(arr,x);
        cout << index << endl;

        // Step 2
        int count = 0;
        ans.push_back(arr[index]);
        count++;
        int i = index-1;
        int j = index+1;
        while(count < k && i>=0 && j<arr.size()){
            cout << "i is : " << i << ", j is : " << j << endl;
            if(abs(arr[i]-x) < abs(arr[j]-x)){
                // arr[i] is closer
                ans.push_back(arr[i]);
                i--;
            }else if(abs(arr[i]-x) > abs(arr[j]-x)){
                // arr[j] is closer
                ans.push_back(arr[j]);
                j++;
            }else{
                // since equal => insert arr[i] as arr[i] < arr[j] always
                ans.push_back(arr[i]);
                i--;
            }
            count++;
        }

        if(count == k){
            sort(ans.begin(),ans.end());
            return ans;
        }else{
            // either i has exhausted or j has exhausted
            while(count < k && i >= 0){
                cout << "i is : " << i << ", j is : " << j << endl;
                ans.push_back(arr[i]);
                i--;
                count++;
            }

            while(count < k && j < arr.size()){
                cout << "i is : " << i << ", j is : " << j << endl;
                ans.push_back(arr[j]);
                j++;
                count++;
            }
        }

        sort(ans.begin(),ans.end());
        return ans;

    }
};

