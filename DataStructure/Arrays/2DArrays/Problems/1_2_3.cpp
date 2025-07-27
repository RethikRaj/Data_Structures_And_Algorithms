#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

bool searching(vector<vector<int>>& v,int target){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j] == target){
                return true;
            }
        }
    }
    return false;

    // Can do by column wise also
}

int getMax(vector<vector<int>>& v){
    int maxAns = INT_MIN;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            maxAns = max(v[i][j],maxAns);
        }
    }
    return maxAns;

    // Can do by column wise also
}

int getMin(vector<vector<int>>& v){
    int minAns = INT_MAX;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            minAns = min(v[i][j],minAns);
        }
    }
    return minAns;

    // Can do by column wise also
}

void printRowSum(vector<vector<int>>& v){
    for(int i=0;i<v.size();i++){
        int sum = 0;
        for(int j=0;j<v[i].size();j++){
            sum += v[i][j];
        }
        cout << "The sum of row " << i << " is : " << sum << endl;
    }
}

void printColSum(vector<vector<int>>& v){
    for(int i=0;i<v[i].size();i++){
        int sum = 0;
        for(int j=0;j<v.size();j++){
            sum += v[j][i];
        }
        cout << "The sum of col " << i << " is : " << sum << endl;
    }    
}

int mainDiagSum(vector<vector<int>>& v){
    int sum = 0;
    for(int i=0;i<v.size();i++){
        sum += v[i][i]; 
    }
    return sum;
}

int secondaryDiagSum(vector<vector<int>>& v){
    int sum = 0;
    for(int i=0;i<v.size();i++){
        sum += v[i][v.size()-i-1];
    }
    return sum;
}

void transpose(vector<vector<int>>& v){
    // using upper right
    // for(int i=0;i<v.size();i++){
    //     for(int j=i;j<v[i].size();j++){
    //         swap(v[i][j],v[j][i]);
    //     }
    // }

    // Method 2 : Can us lower traingle
    for(int i=0;i<v.size();i++){
        for(int j=0;j<i;j++){
            swap(v[i][j],v[j][i]);
        }
    }

}

void printVector(vector<vector<int>>& v){
    for(int i=0;i<v.size();i++){
        for(auto it : v[i]){
            cout << it << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int>> v;
    vector<int> vec1 = {10,20,30,40};
    vector<int> vec2 = {50,60,70,80};
    vector<int> vec3 = {90,100,110,120};
    vector<int> vec4 = {130,140,150,160};

    v.push_back(vec1);
    v.push_back(vec2);
    v.push_back(vec3);
    v.push_back(vec4);

    printVector(v);

    cout << "The maximum element is : " << getMax(v) << endl;
    cout << "The minimum element is : " << getMin(v) << endl;
    cout << "Main diagonal sum is : " << mainDiagSum(v) << endl;
    cout << "Secondary diagonal sum is : " << secondaryDiagSum(v) << endl;


    cout << "Printing row sum : " << endl;
    printRowSum(v);

    cout << "Printing col sum : " << endl;
    printColSum(v);

    transpose(v);
    cout << "Transposing matrix : " << endl;
    cout << "After transpose : " << endl;
    printVector(v);
    


    
    return 0;
}