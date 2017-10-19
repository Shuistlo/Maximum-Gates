#ifndef MAXIMUM_GATES_H
#define MAXIMUM_GATES_H

#include <vector>
using std::vector;

// TODO: Your answer for question 2 goes here
int maximumGates(vector<int> arrives, vector<int> departs){
    int gates = 1; //starting number of gates must be 1
    if(arrives.size() == 0){
        return 0;
    }

    int currentPlaneIndex = 1; //current plane being looked at
    while(currentPlaneIndex < arrives.size()){
        bool gateAvailable = false;
        int availableGateSearch = 0; //will start looking here to see if the gate is available
        while((gateAvailable == false) && (availableGateSearch < currentPlaneIndex)){
            if(departs[availableGateSearch] < arrives[currentPlaneIndex]){
                departs.erase(departs.begin() + availableGateSearch);
                gateAvailable = true;
            }
            else{
                availableGateSearch++;
            }
        }
        currentPlaneIndex++;
    }
    return departs.size();
}




// Do not write any code below this line


#endif
