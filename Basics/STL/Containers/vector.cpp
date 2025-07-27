#include <iostream>
#include <vector>

using namespace std;

void printVector1(vector<int>& v){
    cout << "Printing vector method 1 : ";
    for(int i=0;i<v.size();i++){
        //cout << v.at(i) << " ";
        cout << v[i] << " ";
    }
    cout << endl;
}

void printVector2(vector<int>& v){
    cout << "Printing vector method 2 : ";
    for(auto ele : v){ // for-each loop
        cout << ele << " ";
    }
    cout << endl;
}

void printVectorIterator(vector<int>& v){
    vector<int>::iterator it = v.begin(); // it points to first element
    while(it != v.end()){ // it points to last element + 1
        cout << *it << " ";
    }
    cout << endl;
}

void incrementElementByOne(vector<int> v){
    for(int i=0;i<v.size();i++){
        v[i] = v[i] + 1;
    }
}

void multiplyByTen(vector<int>& v){
    for(int i=0;i<v.size();i++){
        v[i] = v[i] * 10;
    }

    // for (auto& it : v) {  // Use a reference to each element
    //     it = it * 10;
    // }

    // NO change oocurs because it creates copy and changes
    // for (auto it : v) {  // Use a reference to each element
    //     it = it * 10;
    // }
}


int main(){

    // Creation :
    vector<int> vec; // size() = 0;
    cout << "Size is : " << vec.size() << endl;

    // Initialisation
    vector<int> srr(7); //initialises with zero
    srr.push_back(20); // 20 inserted after 7 zeroes
    printVector1(srr);

    vector<int> arr(5,-1); // intitalises a vector of initial size 5 and with -1
    arr.push_back(10); // 10 inserted after 5 -1's
    printVector1(arr);
    vector<int> brr = {1,2,3,4,5};
    vector<int> crr{1,2,3,4,5};

    // Copy vector :
    /* In C++, when you create a new vector by copying another vector (either by using the copy constructor or copy assignment), you create a separate copy of the original vector. This means that each vector has its own separate memory allocation and modifying one will not affect the others.*/
    vector<int> drr = {10,20,30,40,50};
    vector<int> err(drr);
    vector<int> frr = drr;


    // inserting
    vector<int> v;
    v.push_back(27);
    v.push_back(34);
    v.push_back(40);

    // insetring at a particular index => insert(iterator pos, value)
    v.insert(v.begin(), 100000);

    //cout << v[0] << endl; => 100000

    printVector1(v);
    printVector2(v);

    // Front element and back(last) element
    cout << "Front element: " << v[0] << endl;
    cout << "Front element: " << v.front() << endl;
    cout << "End Element: " << v[v.size() - 1] << endl;
    cout << "End Element: " << v.back() << endl;

    // size of vector:
    cout << "The size of vector is : " << v.size()<< endl;

    // delete ->from end
    v.pop_back();
    cout << "The size of vector is : " << v.size() << endl; // 2
    v.pop_back();
    cout << "The size of vector is : " << v.size() << endl; // 1
    v.pop_back();
    cout << "The size of vector is : " << v.size() << endl; // 0
    // popping when size of vector is zero gives unusual behaviour

    // clear 
    v.clear(); // makes size of vector as zero by clearing all data inside the vector.
    cout << "The capacity of the vector is : " << v.capacity() << endl; // capacity remains same


    // Accesing

    vector<int> marks;
    //marks[0] = 10; or cout << marks[0]; => segmentation block since initial size is zero
    //marks.at(0); => segmentation block since initial size is zero

    cout << endl << endl;
 
    // empty => returns true or false
    cout << v.empty() << endl;


    // erase  => Removes one or more element => Syntax : v.erase(iterator start,iterator end) [start,end]
    vector<int> zrr(10,77);
    cout << "Before erasing : " << endl;
    printVector1(zrr);
    zrr.erase(zrr.begin()+5); // single element erased at index 5
    cout << "After erasing : " << endl;
    printVector1(zrr);
    zrr.erase(zrr.begin()+5,zrr.end()-1);
    cout << "After 2nd time erasing : " << endl;
    printVector1(zrr);



    // begin , end and iterator
    vector<int> distances(20,0);
    vector<int>::iterator it = v.begin();
    while(it != v.end()){
        cout << *it << " ";
    }
    cout << endl;




    // swapping vectors => swaps content , size ,capacity
    vector<int> something(20,-1);
    vector<int> anything(15,0);
    cout << "Before swapping : " << endl;
    printVector1(something);
    printVector1(anything);

    something.swap(anything);
    cout << "After swapping : " << endl;
    printVector1(something);
    printVector1(anything);



    // reserve
    // vector<int> people;
    // cout << people.capacity() << endl;// gives 0
    // cout << people.size() << endl;// gives 0

    vector<int> people;
    people.reserve(20);
    cout << people.capacity() << endl;// gives 20
    cout << people.size() << endl;// gives 0


    // max size
    vector<int> summa;
    cout << "Maximum size that can be allocated by os " << summa.max_size() << endl;



    // Pass by value  
    vector<int> nums = {1,2,3,4,5};
    cout << "Pass By value : " << endl; 
    cout << "Before incremneting : " << endl;
    printVector1(nums);
    incrementElementByOne(nums);
    cout << "After incremneting : " << endl;
    printVector1(nums);

    // Pass BY reference
    cout << "Pass By Reference : " << endl; 
    cout << "Before: " << endl;
    printVector1(nums);
    multiplyByTen(nums);
    cout << "After: " << endl;
    printVector1(nums);











    // 2D array / vector
    vector<vector<int>> matrix(5,vector<int>(20,-1)); // 5*20 matrix intialized with -1

    // jagged array
    vector<vector<int>> matrix2(5);
    for(int i=0;i<matrix2.size();i++){
        int noOfColumns;
        cin >> noOfColumns;
        matrix2[i] = vector<int>(noOfColumns,-1);
    }
    

    return 0;
}