#include <iostream>

using namespace std;

void printCharArray(char arr[],int size){
    for(int i=0;i<size;i++){
        cout << (int)arr[i] << " ";
    }
    cout << endl;
}

// getLength
int getLength(char arr[],int size){
    int count = 0;
    int index = 0;
    while(index < size && arr[index] != '\0'){
        count++;
        index++;
    }
    return count;
}

void replaceCharacter(char originalChar,char newCharacter,char arr[],int size){
    int length = getLength(arr,size);
    for(int i=0;i<length;i++){
        if(arr[i] == originalChar){
            arr[i] = newCharacter;
        }
    }
}

void convertIntoUpperCase(char arr[],int size){
    int length = getLength(arr,size);
    for(int i=0;i<length;i++){ // if dont want to calculate length include one more condition that is arr[i] != '\0'
        char ch = arr[i];
        // Only when ch is lowercase then convert
        if(ch >= 'a' && ch <='z'){
            ch = ch - 'a'+'A';
            arr[i] = ch;
        }
        
    }
}

void convertIntoLowererCase(char arr[],int size){
    int length = getLength(arr,size);
    for(int i=0;i<length;i++){ // if dont want to calculate length include one more condition that is arr[i] != '\0'
        char ch = arr[i];
        // Only when ch is uppercase then convert
        if(ch >= 'A' && ch <='Z'){
            ch = ch - 'A'+'a';
            arr[i] = ch;
        }
    }
}

void reverseCharArray(char arr[],int size){
    int length = getLength(arr,size);
    int s = 0;
    int e = length-1;
    while(s <= e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}

bool isPalindrome(char arr[],int size){
    int length = getLength(arr,size);
    int s = 0;
    int e = length-1;
    while(s <= e){
        if(arr[s] != arr[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}



int main(){
    char arr[10];
    char brr[10] = {'a'}; // remaining nine values intialised with null character.
    int n = 10;
    
    printCharArray(arr,n); // garbage
    printCharArray(brr,n);
    
    cout << "Enter the input : ";
    cin >> brr; // replaces a(initialised value) with your given input.
    //cin >> brr+1; // does not replace a
    printCharArray(brr,n); 
    cout << "Length is : " << getLength(brr,n) << endl;;
    convertIntoUpperCase(brr,n);
    cout << brr << endl;
    convertIntoLowererCase(brr,n);
    cout << brr << endl;

    reverseCharArray(brr,n);
    cout << brr << endl;


    // getLine
    // char crr[100];

    // cout << "Enter input" << endl;
    // cin >> crr;
    // cin.getline(crr, 80, '.'); 
    // cout << endl << arr << endl;


    // inbuilt functions
    char arr1[100];
    cout << "Enter the input" << endl;
    cin >> arr1;

    char arr2[100];
    cout << "Enter the input" << endl;
    cin >> arr2;

    //cout << strlen(arr1) << endl;
    //cout << strcat(arr1,arr2) << endl;



    
}