#include <iostream>
#include <vector>

using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
	int s = 0;
	int e = n-1;

	int mid = s+(e-s)/2;
	int floor = -1;
	int ceil = -1;

	while( s <= e){
		if(arr[mid] >= x){
			ceil = arr[mid];
			e = mid-1;
		}
		if(arr[mid] <= x){
			floor = arr[mid];
			s = mid+1;
		}
		// update mid
		mid = s + (e-s)/2;
	} 

	pair<int,int> p;
	p.first = floor;
	p.second = ceil;
	return p;
}