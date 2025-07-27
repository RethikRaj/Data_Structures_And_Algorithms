#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

void iterateUnordered_map(unordered_map<string,string>& uom){
    unordered_map<string,string>::iterator it = uom.begin();
    while(it != uom.end()){
        pair<string,string> p = *it;
        string key = p.first;
        string value = p.second;
        cout << key << "->" << value << endl; 
        it++;
    }

    // Method 2 :
    // unordered_map<string,string>::iterator it;
    // for(it = uom.begin();it != uom.end();it++){
    //     string key = it->first;
    //     string value = it->second;
    //     cout << key << "->" << value << endl; 
    // }
    
}

void iterateOrdered_map(map<string,string>& om){
    map<string,string>::iterator it = om.begin();
    while(it != om.end()){
        pair<string,string> p = *it;
        string key = p.first;
        string value = p.second;
        cout << key << "->" << value << endl; 
        it++;
    }
}

int main(){
    // Unordered map
    // creation
    unordered_map<string,string> table;

    // insertion
    table["in"] = "india";
    //table.at("br") = "brazil"; gives error because not exist
    table["br"] = "brazil";
    table.at("br") = "brazil2"; // this works as key exists 
    table.insert(make_pair("en","england"));
    pair<string,string> p;
    p.first = "usa";
    p.second = "united states of america";
    table.insert(p);

    // iterate 
    iterateUnordered_map(table);

    // find => returns an iterator 
    unordered_map<string,string>::iterator it2 = table.find("in");

    if(it2 != table.end()){ // key found
        cout << "Key Found" << endl;
        cout << "Key is : " << (*it2).first << endl;
        cout << "value at that key is : " << (*it2).second << endl;
    }else{
        cout << "Key Not Found" << endl;
    }


    // count
    if(table.count("in") == 0){
        cout << "Key Not Found" << endl;
    }
    if(table.count("in") == 1){
        cout << "Key Found" << endl;
    }


    // size,at,[],clear,empty
    // cout << table.at("in") << endl;
    // //table.at("in") = "india2";
    // table["in"] = "India3";
    // cout << table.at("in") << endl;
    // cout << table.size() << endl;
    // table.clear();
    // cout << table.size() << endl;

    // if(table.empty() == true) {
    //     cout << "map is empty" << endl;
    // }
    // else {
    //     cout << "map is not empty" << endl;
    // }




    // Ordered map 
    // same as unordered map with two differences
    // 1. Operation : O(logn)
    // 2. Keys are maintained in sorted order.

    map<string,string> ordered_table;

    // insertion
    ordered_table["in"] = "india";
    ordered_table["br"] = "brazil";
    ordered_table.insert(make_pair("en","england"));
    pair<string,string> p2;
    p2.first = "usa";
    p2.second = "united states of america";
    ordered_table.insert(p2);

    // iterate
    iterateOrdered_map(ordered_table);

    





    return 0;
}