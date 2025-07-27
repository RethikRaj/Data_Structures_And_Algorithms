#include <iostream>

using namespace std;

string removeOccurrences(string s, string part) {
    // Initailse answer
    string ans = "";
    int s_length = s.length();
    int part_length = part.length();

    for(int i=0;i<s_length;i++){
        // push the curr char
        ans.push_back(s[i]);

        // Now check pattern(part)
        if(ans.length() < part_length){
            continue;
        }
        else{
            if(ans.substr(ans.length()-part_length,part_length).compare(part) == 0){
                int j = 0;
                while(j < part_length){
                    ans.pop_back();
                    j++;
                }
            }
        }
    }
    return ans;
}

string removeOccurrences(string s, string pattern) {
        

    //jab tak full string k andar pattern string 
    //milti rahegi, tab tak loop chalao
    
    while(s.find(pattern) != string::npos) {
        //full string me se erase karo
        //erase function k 2 argument hai
        //first arguement me, pattern ka starting index dena hai
        // full.find(pattern), hume starting index of pattern inside
        //full string provide krra hau
        //2nd argument, usme specify krna hai, k kitne character
        //remove karna chahte ho, starting index se
        s.erase(s.find(pattern), pattern.length());
    }
    return s;

}