#include <iostream>
#include <vector>

using namespace std;

int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    // M truck
    int pickTimeM = 0;
    int travelTimeM = 0;
    int lastStopM = 0;
    // P truck
    int pickTimeP = 0;
    int travelTimeP = 0;
    int lastStopP = 0;
    // G truck
    int pickTimeG = 0;
    int travelTimeG = 0;
    int lastStopG = 0;

    for(int i=0;i<garbage.size();i++){
        // reached at currHouse
        string currHouse = garbage[i];
        // Now iterate the garbageType at currHouse
        for(char garbageType : currHouse){
            if(garbageType == 'M'){
                pickTimeM += 1;
                // since M truck has reached till iTh house => update lastStop of M
                lastStopM = i;
            }
            if(garbageType == 'P'){
                pickTimeP += 1;
                // since P truck has reached till iTh house => update lastStop of P
                lastStopP = i;
            }
            if(garbageType == 'G'){
                pickTimeG += 1;
                // since G truck has reached till iTh house => update lastStop of G
                lastStopG = i;
            }
        }
    }

    // Calculate travel time based on last stop
    // travel time of M
    for(int i=0;i<lastStopM;i++){
        travelTimeM += travel[i];
    }
    // travel time of P
    for(int i=0;i<lastStopP;i++){
        travelTimeP += travel[i];
    }
    // travel time of G
    for(int i=0;i<lastStopG;i++){
        travelTimeG += travel[i];
    }

    int totalTime = 0;
    int totalPickingTime = pickTimeM + pickTimeP + pickTimeG;
    int totalTravelTime = travelTimeM + travelTimeP + travelTimeG;

    totalTime = totalPickingTime + totalTravelTime;
    return totalTime;
}