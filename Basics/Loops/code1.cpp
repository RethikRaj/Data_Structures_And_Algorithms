#include<iostream>
using namespace std;

int main() {
	int i=1;
	for(; ; ) {
		cout << "value of i is :" << i << endl;
		if(i<5) {
			cout << "babbar" << endl;
			i=i+1;
		}
		else {
			break;
		}
		
	}

	cout << "Hi" << endl;

	
	// for(int i=0; i<3; i=i+1) {
	// 	cout<< endl << "Outer Loop " << i << endl << endl; 
		
	// 	for(int j=0; j<3; j=j+1) {
	// 		cout << "inner loop " << j << endl;
	// 	}
		
	// }
	
	// for(int i=0; i<5; i=i+1) {
	// 	cout << "A" << " ";
	// }
	// cout << endl;
	
	// for(int i=10 ;i>=0; i= i - 3) {
	// 	cout << i << endl;
	// }
	
	// for(int i=2; i<10; i=i+2) {
	// 	cout << i << endl;
	// }

	return 0;
}