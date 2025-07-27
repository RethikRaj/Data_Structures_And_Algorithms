#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> v,int x,int y){
    for(int i=0;i<v.size();i++){
        int ele = v[i];
        if((ele+x == y) || (ele-x == y) || (ele == y)){
            continue;
        }else{
            return false;
        }
    }
    return true;
}

int solve(vector<int> &A, int B) {
    int n = A.size();
    
    vector<int> copy = A;
    
    int x = B;
    
    bool option1 = check(copy,x,copy[0]+x);
    bool option2 = check(copy,x,copy[0]-x);
    bool option3 = check(copy,x,copy[0]);
    
    return option1 || option2 || option3;    

}