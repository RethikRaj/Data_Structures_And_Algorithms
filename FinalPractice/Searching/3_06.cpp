#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getIndexOfLowerBound(vector<int>& potions, long long target){
        int low = 0;
        int high = potions.size() - 1;

        int ans = potions.size();
        while(low <= high){
            int mid = low + (high - low)/2;

            if(potions[mid] >= target){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        sort(potions.begin(), potions.end());
        vector<int> ans;

        for(int i=0; i < spells.size(); i++){
            long long target = ceil((double)success/ spells[i]);

            int indexOfLBOfTarget = getIndexOfLowerBound(potions, target);

            int numberOfSuccessPairs = potions.size() - indexOfLBOfTarget;

            ans.push_back(numberOfSuccessPairs);
        }

        return ans;
    }
};

// Two Pointer Approach 

class CustomSort{
    public:
    bool operator()(pair<int,int> &a, pair<int, int> &b){
        return a.first < b.first;
    }
};

class Solution {
public:

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<pair<int, int>> spellsDuplicate;
        for(int i=0; i < spells.size();i++){
            spellsDuplicate.push_back(make_pair(spells[i], i));
        }

        sort(spellsDuplicate.begin(), spellsDuplicate.end(), CustomSort());
        sort(potions.begin(), potions.end());

        int i = 0;
        int j = potions.size() - 1;
        vector<int> ans(spells.size());

        for (int i = 0; i < spellsDuplicate.size(); i++) {
            int spell = spellsDuplicate[i].first;
            int idx   = spellsDuplicate[i].second;

            // Move j left until product < success
            while (j >= 0 && 1LL * spell * potions[j] >= success) {
                j--;
            }

            // all potions from j+1 to end are valid
            ans[idx] = potions.size() - (j + 1);
        }

        return ans;
    }
};