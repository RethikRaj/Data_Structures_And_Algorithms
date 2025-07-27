#include <bits/stdc++.h> 

class Solution{
    public:
        // Method 1 : Brute force : Find all pairs and check condtion
        long long bruteForce(long long* &arr,int n){
            long long countInv = 0;
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    if(arr[i] > arr[j]){
                        countInv++;
                    }
                }
            }
            return countInv;
        }

        // Method 2 : Modified mergeSort
        void merge(long long* &arr,int low,int mid,int high,long long &countInv){
            vector<long long> temp;
            int i = low;
            int j = mid+1;

            while(i <= mid && j <= high){
                if(arr[i] > arr[j]){
                    countInv += (mid-i+1);
                    temp.push_back(arr[j]);
                    j++;
                }else{
                    temp.push_back(arr[i]);
                    i++;
                }
            }

            while(i <= mid){
                temp.push_back(arr[i]);
                i++;
            }

            while(j <= high){
                temp.push_back(arr[j]);
                j++;
            }

            for(int i=low,j=0;i<=high;i++,j++){
                arr[i] = temp[j];
            }
        }

        void mergeSort(long long* &arr,int low,int high,long long &countInv){
            if(low >= high){
                return;
            }
            // Divide
            int mid = low + (high-low)/2;
            mergeSort(arr,low,mid,countInv);
            mergeSort(arr,mid+1,high,countInv);
            merge(arr,low,mid,high,countInv);
        }


        long long getInversions(long long *arr, int n){
            // return bruteForce(arr, n);

            long long countInv = 0;
            mergeSort(arr,0,n-1,countInv);
            return countInv;

        }
}

// Same Method 2 : But a different way of coding
class Solution2 {
  public:
    long long int merge(long long arr[],vector<long long> &temp,int start,int mid,int end){
        int i = start, j = mid+1, z = start;
            
        long long int c = 0;
        while(i <= mid && j <= end){
            if(arr[i] > arr[j]){
                c += (mid-i+1);
                temp[z] = arr[j];
                j++;
            }else{
                temp[z] = arr[i];
                i++;
            }
            z++;
        }
        
        while(i <= mid){
            temp[z] = arr[i];
            i++;z++;
        }
        
        while(j <= end){
            temp[z] = arr[j];
            j++;z++;
        }
        
        for(int i=start;i<= end;i++){
            arr[i] = temp[i];
        }
        
        return c;
    }
    
    long long int mergeSort(long long arr[],vector<long long> &temp,int start,int end){
        if(start >= end){
            return 0;
        }
        int mid = start + (end-start)/2;
        long long int c = 0;
        c += mergeSort(arr,temp,start,mid);
        c += mergeSort(arr,temp,mid+1,end);
        c += merge(arr,temp,start,mid,end);
        return c;
    }
    
    long long int inversionCount(long long arr[], int n) {
        long long int c = 0;
        vector<long long> temp(n,0);
        c = mergeSort(arr,temp,0,n-1);
        return c;
    }
};