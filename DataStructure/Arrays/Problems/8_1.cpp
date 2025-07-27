#include <iostream>
#include <vector>
using namespace std;

void sortColors(int nums[],int size) {
    int redCount = 0;
    int whiteCount = 0;
    int blueCount = 0;
    for(int i=0;i<size;i++){
        if(nums[i] == 0){
            redCount++;
        }else if(nums[i] == 1){
            whiteCount++;
        }else{
            blueCount++;
        }
    }

    int index = 0;
    while(redCount-- != 0){
        nums[index] = 0;
        index++;
    }

    while(whiteCount-- != 0){
        nums[index] = 1;
        index++;
    }

    while(blueCount-- != 0){
        nums[index] = 2;
        index++;
    }        
}

void sortColorsPointerApp(vector<int>& arr){
    int index = 0;
        int left = 0;
        int right = arr.size()-1;

        while(index <= right){
            if(arr[index] == 0){
                swap(arr[index],arr[left]);
                index++;
                left++;
            }
            else if(arr[index] == 2){
                swap(arr[index],arr[right]);
                right--;
                //catch -> no need of index++
                //index++
            }
            else if(arr[index] == 1){
                index++;
            }
        }
}

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {2,0,2,1,1,0};
    int n = 6;

    sortColors(arr,n);
    printArray(arr,n);
}