#include "Oppgave2.h"
#include "std_lib_facilities.h"
#include <cmath>
#include "Graph.h"
#include "AnimationWindow.h"
#include "string"
#include <cctype>
#include <algorithm>

void countCharFromFile(string filename){
    string line, text;
    ifstream myfile (filename);
    
    if (myfile.is_open()){
        while (getline(myfile,line)){
            text += line;
        }
        myfile.close();
    }

    transform(text.begin(), text.end(), text.begin(),
    [](unsigned char c){ return tolower(c); });

    for (int i = 97; i<123; i++){
        int numOfTimes = count(text.begin(), text.end(), char(i));
        cout<<char(i)<<": "<<numOfTimes<<endl;
    }
}

