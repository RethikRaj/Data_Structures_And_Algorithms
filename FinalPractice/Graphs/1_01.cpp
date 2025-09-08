#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // Pick any two edges => Pick edge[0] and edge[1] and get its end vertices
        int a = edges[0][0];
        int b = edges[0][1];

        int c = edges[1][0];
        int d = edges[1][1];

        return (a == c || b == c) ? c : d;
    }
};