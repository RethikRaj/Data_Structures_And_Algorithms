// right rotate by K

#include <bits/stdc++.h>
using namespace std;

class RightRotateByK {
    public:
        // Method 1 : 
        void rotateMethodOne(vector<int> &arr, int k) {
            int n = arr.size();
            k = k % n;
            // reverse first n - k elements
            reverse(arr.begin(), arr.begin() + n - k);
            // reverse last k elements
            reverse(arr.begin() + n - k, arr.end());
            // reverse whole array
            reverse(arr.begin(), arr.end());

            // way - 2 : 
            // reverse whole array
            // reverse(arr.begin(),arr.end());
            // // reverse first k elements
            // reverse(arr.begin(),arr.begin()+k);
            // // reverse last n-k elements
            // reverse(arr.begin()+k,arr.end());
        }

        // Method 2 : Cicular counting
        void rotateMethodTwo(vector<int> &arr, int k) {
            int n = arr.size();
            k = k % n;
            vector<int> temp(n);

            for(int i=0;i<n;i++){
                int newIndex = (i+k)%n;
                temp[newIndex] = arr[i];
            }

            arr = temp;
        }

        // Method 3 : store last k elements in temp then shift then copy back
        void rotateMethodThree(vector<int> &arr, int k) {
            int n = arr.size();
            k = k % n;

            // Step - 1: Store last k elements
            vector<int> temp(k);
            for(int i=n-k;i<n;i++){
                temp[i-(n-k)] = arr[i];
            }

            // Step - 2: Shift remaining n-k elements
            for(int i=n-k-1;i>=0;i--){
                arr[i+k] = arr[i];
            } 

            // Step - 3: Copy the elements in temp to first k positions in arr
            for(int i=0;i<k;i++){
                arr[i] = temp[i];
            }
        }

        // Method 4 : rotateByOne K times
        void rightShiftByOne(vector<int> &arr, int n) {
            // Using Logic of method 3
            // Step - 1: Store last k = 1 element
            int temp = arr[n-1];

            // Step - 2: Shift remaining n-k = n - 1 elements
            for(int i=n-2;i>=0;i--){
                arr[i+1] = arr[i];
            }

            // Step - 3: Copy the elements in temp to first k = 1 positions in arr
            arr[0] = temp;
        }

        void rotateMethodFour(vector<int> &arr, int k) {
            int n = arr.size();
            k = k % n;
            for(int i=0;i<k;i++){
                rightShiftByOne(arr,n);
            }
        }
};

class LeftRotateByK {
    
};
