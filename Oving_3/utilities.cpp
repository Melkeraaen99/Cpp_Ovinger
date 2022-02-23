#include "std_lib_facilities.h"
#include <cmath>
#include "Graph.h"
#include "AnimationWindow.h"
#include "utilities.h" 

void randomWithLimits(int lower, int upper, int repeat){
    int number_in_limit = rand();
    int count = 0;
    while (count<repeat){
        number_in_limit = rand();
        if (number_in_limit >= lower && number_in_limit <= upper){
            cout<<number_in_limit<<endl;
            count+=1;
        }
    } 
}

int randomTarget(int lower, int upper){
    int count = 0;
    int target = 0;
    while (count<1){
        int number_in_limit = rand();
        if (number_in_limit >= lower && number_in_limit <= upper){
            target = number_in_limit;
            count+=1;
        }
    }
    return target; 
}