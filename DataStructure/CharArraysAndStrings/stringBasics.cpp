#include <iostream>

using namespace std;

int main(){
    //creation
    // string str;
    // str.push_back('l');
    // str.push_back('o');
    // str.push_back('v');
    // str.push_back('e');
    // str.pop_back();
    // cout << str << endl;
    
    // cout << "enter the input" << endl;
    // //input
    // cin >> str;
    // //output
    // cout << "Str: " << str << endl;
    // cout << str[0] << endl;


    // string sentence;

    // //cin >> sentence;
    // getline(cin, sentence, '\n');

    // cout << sentence << endl;


    // inbuilt functions
    // cout << name[0] << endl;
    // cout << name.at(0) << endl;

    // cout << name.front() << endl;
    // cout << name.back() << endl;
    // cout << name.length() << endl;



    // iterating using iterators
    // auto it = name.begin();

    // while(it != name.end()) {
    //     cout << *it << " ";
    //     it++;
    // }
    // cout << endl;


    // find
    // string name = "Hello Jee Kaise ho Saare" ;
    // string word = "Kaise ho";

    // if(name.find(word) != string::npos) {
    //     ///found
    // }
    // else {
    //     //not found
    // }



    // compare
    // string s1 = "love";
    // string s2 = "amit";

    // cout << s1.compare(s2) << endl;


    // substr (starting index,length of substr) => returns a string from [startingIndex, startingIndex+length-1]
    string name = "Rethik Raj";
    cout << name.substr(1,5) << endl;




    //empty and clear
     
    // string name = "Maharana Pratap";
    // name.clear();
    // if(name.empty() ){
    //     cout << "String is empty" ; 
    // }
    // else {
    //     cout << "string is not empty";
    // }


    // append (just use +)
    // string ans = fName + " " + lName;
    // cout << ans << endl;

    

    return 0;
}