#include <bits/stdc++.h>
using namespace std;

bool canAllocateBooks(vector<int>& arr, int n, int m, int mid){
    // Since each student must get atleast one book therefore extraBooks = n - m
    int extraBooksCount = n - m;
    int currStudent = 1;
    int booksAllocatedToCurrStudent = 0;
    int pagesAllocatedToCurrStudent = 0;
    int i = 0;
    while(i < n){
        if(pagesAllocatedToCurrStudent + arr[i] <= mid){
            // 1st book allocated to this student
            if(booksAllocatedToCurrStudent == 0){
                booksAllocatedToCurrStudent += 1;
                pagesAllocatedToCurrStudent += arr[i];
                i += 1;
            }
            else{ 
                // going to allocate more than one book => Also check if extraBooksCount != 0
                if(extraBooksCount == 0){
                    currStudent += 1;
                    if(currStudent > m){
                        return false;
                    }
                    booksAllocatedToCurrStudent = 0;
                    pagesAllocatedToCurrStudent = 0;
                }
                else{
                    extraBooksCount -= 1;
                    booksAllocatedToCurrStudent += 1;
                    pagesAllocatedToCurrStudent += arr[i];
                    i += 1;
                    
                }
            }
        }
        else{
            currStudent += 1;
            if(currStudent > m){
                return false;
            }
            booksAllocatedToCurrStudent = 0;
            pagesAllocatedToCurrStudent = 0;
        }
    }

    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    if(n < m){
        // not possible
        return -1;
    }

    int maxEle = INT_MIN;
    int sum = 0;

    for(int i = 0; i < n; i++){
        maxEle = max(maxEle, arr[i]);
        sum += arr[i];
    }

    if(n == m){
        return maxEle;
    }


    int low = maxEle;
    int high = sum;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(canAllocateBooks(arr, n, m, mid)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return ans;
}