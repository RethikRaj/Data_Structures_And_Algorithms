#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
     
    vector<long long> ans;
    
    deque<long long int> dq;// stores indexes of negative elements in curr window
    
    // Step1 : Process first window -> first k elements
    for(int i=0;i<k;i++){
        if(arr[i] < 0){
            dq.push_back(i);
        }
    }
    
    // step 2: Store ans of first window
    if(dq.empty()){
        ans.push_back(0);
    }else{
        int index = dq.front();
        ans.push_back(arr[index]);
    }
    
    // Step 3: Process remaining windows
    for(int i=k;i<n;i++){
        // Removal 
        // Always before using dq.front() , check !dq.empty()
        if(!dq.empty() && dq.front() < i-k+1){
            dq.pop_front();
        }
        
        // addition
        if(arr[i] < 0){
            dq.push_back(i);
        }
        
        // Store ans of curr window
        if(dq.empty()){
            ans.push_back(0);
        }else{
            int index = dq.front();
            ans.push_back(arr[index]);
        }
    }
    
    return ans;
}