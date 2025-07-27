#include <iostream>
#include <unordered_map>

using namespace std;



string isSubset(int a1[], int a2[], int n, int m) {
    if(m > n){
        return "No";
    }
    
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a1[i]]++;
    }
    
    for(int i=0;i<m;i++){
        int currEle = a2[i];
        // check currEle present or not
        if(mp.find(currEle) == mp.end()){
            return "No";
        }
        else{
            // currELe is present
            // check whether currEle frequency == 0
            if(mp[currEle] == 0){
                return "No";
            }else{
                mp[currEle]--;
            }
        }
    }
    
    return "Yes";
}

