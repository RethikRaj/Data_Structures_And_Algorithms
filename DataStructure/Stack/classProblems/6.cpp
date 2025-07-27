#include <iostream>
#include <stack>

using namespace std;

void sortedInsert(stack<int> &s,int val){
	// Base case
	if(s.empty() || s.top() < val){
		s.push(val);
		return;
	}
	// 1 case
	int topEle = s.top();
	s.pop();
	// recursion
	sortedInsert(s, val);
	// backtrack
	s.push(topEle);
}

void sortStack(stack<int> &s){
	if(s.empty()){
		return;
	}

	// 1 case 
	int topEle = s.top();
	s.pop();
	// recursion
	sortStack(s);
	// Backtrack
	sortedInsert(s,topEle);
}
