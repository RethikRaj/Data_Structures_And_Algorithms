#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;






// Method 2 : TC : O(n*m) SC : O(1)
int numberOfBeams(vector<string>& bank) {
    int n = bank.size();
    int lastRowWithSecurityDevice = -1;
    int noOfSecurityDevicesInThatLastRowWithSecurityDevice = 0;
    int totalBeams = 0;

    for(int i=0;i<n;i++){
        int countOfSecurityDevices = 0;
        for(int j=0;j<bank[i].length();j++){
            if(bank[i][j] == '1'){
                countOfSecurityDevices += 1;

                // count Beams logic
                totalBeams += noOfSecurityDevicesInThatLastRowWithSecurityDevice;
            }
        }
        if(countOfSecurityDevices != 0){
            lastRowWithSecurityDevice = i;
            noOfSecurityDevicesInThatLastRowWithSecurityDevice = countOfSecurityDevices;
        }
    }
    return totalBeams;
}

// Method 1 : Create a mapping and used it : TC : O(n*m)mostly but in worst case O(n2*m) SC : O(n*m);
int numberOfBeams(vector<string>& bank) {
    int n = bank.size();
    // Mapping
    unordered_map<int,vector<int>> mapping;

    for(int i=0;i<n;i++){
        for(int j=0;j<bank[i].length();j++){
            if(bank[i][j] == '1'){
                mapping[i].push_back(j);
            }
        }
    }

    int numberOfBeams = 0;
    for(int row = 0;row < n;){
        vector<int> securityDevicesPositionInThisRowFirst = mapping[row];
        // Find the next row which have security devices
        int i = row+1; // i will denote the nextNonEmptyRow
        while(i<n && mapping.count(i) == 0){
            i++;
        }
        // Two conditions to get out of loop i >= n or mapping.count(i) == 1
        if(i<n){
            // Now i denotes the nonEmptyRow
            vector<int> securityDevicesPositionInThisRowSecond = mapping[i];
            numberOfBeams += (securityDevicesPositionInThisRowFirst.size()*securityDevicesPositionInThisRowSecond.size());
            // Dont use below because above .size() is O(1) 
            // for(int securityDevice : securityDevicesPositionInThisRowFirst){
            //     for(int securityDevice2 : securityDevicesPositionInThisRowSecond){
            //         numberOfBeams++;
            //     }
            // }
        }

        // Updation => Update row to next non empty row which has security devices
        row = i;
    }

    return numberOfBeams;
}