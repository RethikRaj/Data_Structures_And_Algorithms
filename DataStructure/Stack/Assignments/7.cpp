#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// method 1 :PGE Concept
class StockSpanner {
public:
    // 2nd way of coding
    stack<pair<int,int>> s; // stores dayIndex for calculating PGE
    int dayIndex;
    StockSpanner() {
        s.push(make_pair(INT_MAX,-1));
        dayIndex = -1;
    }
    
    int next(int price) {
        dayIndex++;
        while(!s.empty() && s.top().first <= price){
            s.pop();
        }
        // calculate span
        int PGEIndex = s.top().second;
        int span = dayIndex - PGEIndex;

        // push dayIndex into stack
        s.push(make_pair(price,dayIndex));
        return span;
    }





    // 1st way of coding
    // vector<int> stockPrices;
    // stack<int> s; // stores dayIndex for calculating PGE
    // int dayIndex;
    // StockSpanner() {
    //     s.push(-1);
    //     dayIndex = -1;
    // }
    
    // int next(int price) {
    //     dayIndex++;
    //     stockPrices.push_back(price);
    //     while(!s.empty() && s.top() != -1 && stockPrices[s.top()] <= price){
    //         s.pop();
    //     }
    //     // calculate span
    //     int PGEIndex = s.top();
    //     int span = dayIndex - PGEIndex;

    //     // push dayIndex into stack
    //     s.push(dayIndex);
    //     return span;
    // }

};

// method 2 : 
class StockSpanner {
public:
    stack<pair<int,int>> s; // store (price,span)
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1; // span of any day is atleast 1 
        while(!s.empty() && s.top().first <= price){
            span += s.top().second;
            s.pop();
        }
        // push curr price,curr span
        s.push(make_pair(price,span));
        return span;
    }
};

