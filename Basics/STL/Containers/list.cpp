#include <iostream>
#include <list>

using namespace std;

void printList(list<int>& l){
    list<int>::iterator it = l.begin();
    while(it != l.end()){
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

int main(){
    //creation
    list<int> myList;

    //insertion
    myList.push_back(10);
    //10
    myList.push_back(20);
    //10 -> 20
    myList.push_back(30);
    //10 -> 20 -> 30
    myList.push_back(40);
    //10->20->30->40

    myList.push_front(100);
    //100->10->20->30->40

    myList.pop_back();
    //100->10->20->30

    myList.pop_front();
    //10->20->30

    // cout << myList.front() << endl; //10
    // cout << myList.back() << endl; // 30



    // Iteration through iterators
    list<int>::iterator it = myList.begin();
    while(it != myList.end()){
        cout << *it << " ";
        it++;
    }
    cout << endl;

    // Removing 
    myList.push_back(10);
    //10->20->30->10
    myList.remove(10); // removes all occurences of 10
    // 20->30
    printList(myList);

    // swap,insert , erase
    // same as vector



    


    //size , clear ,empty
    // cout << myList.size() << endl;
    // myList.clear();
    // cout << myList.size() << endl;

    // if(myList.empty() == true) {
    //     cout << "List is empty" << endl;
    // } 
    // else {
    //     cout << "list is not empty" << endl;
    // }
    
    return 0;
}