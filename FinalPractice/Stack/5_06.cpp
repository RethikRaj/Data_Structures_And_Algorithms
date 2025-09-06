#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        stack<int> st;

        for(int i = 0;i < n; i++){
            int asteroid = asteroids[i];
            bool isAsteroidDestroyed = false;
             
            while(!st.empty() && st.top() > 0 && asteroid < 0){
                // collision happens
                if(st.top() == abs(asteroid)){
                    isAsteroidDestroyed = true;
                    st.pop();
                    break;
                }
                else if(st.top() > abs(asteroid)){
                    isAsteroidDestroyed = true;
                    break;
                }else{
                    st.pop();
                }
            }

            if(!isAsteroidDestroyed){
                st.push(asteroid);
            }
        }

        vector<int> ans(st.size());

        for(int i = st.size() - 1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }

        return ans;
        
    }
};