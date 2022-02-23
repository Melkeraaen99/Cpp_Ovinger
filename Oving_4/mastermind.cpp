#include "std_lib_facilities.h"
#include <cmath>
#include "Graph.h"
#include "AnimationWindow.h"
#include "utilities.h" 
#include "string"
#include "mastermind.h"

int checkCharactersAndPosition(string fasit, string gjett){
    int correctPosition = 0;
    for (int i=0; i<fasit.length(); i++){
        if (fasit[i] == gjett[i]){
            correctPosition += 1;
        }
    }
    return correctPosition;
}

int checkCharacters(string fasit, string gjett){
    int characterInCode = 0;
    for (int i=0; i<fasit.length(); i++){
        for (int j=0; j<fasit.length(); j++){
            if (fasit[i] == gjett[j]){
                characterInCode += 1;
            }
        }
    }
    return characterInCode;
}

void playMastermind(){
    constexpr int size = 4;
    constexpr int letters = 6;
    string code = randomizeString(size, 'A', 'A'+(letters-1));
    int correctPossition = 0;
    int attempts = 0;
    int maxAttempts;
    cout<<"Hvor mange forsøk ønsker du å ha? ";
    cin>>maxAttempts;
    cout<<"Prøv å gjett den 4-tegnede koden bestående av karakterene A-F:"<<endl;
    // cout<<code<<endl;
    while(correctPossition<size && attempts<maxAttempts){
        string guess = readInputToString(size, 'A', 'A'+(letters-1));
        correctPossition = checkCharactersAndPosition(code, guess);
        int characterInCode = checkCharacters(code, guess);
        cout<<"Du gjettet: "<<guess<<endl;
        cout<<correctPossition<<" tegn var på riktig plass"<<endl;
        cout<<characterInCode<<" tegn finnes i koden"<<endl;
        attempts += 1;
    }
    if (correctPossition == size){
        cout<<"Gratulerer! Du klarte det på "<<attempts<<" forsøk!"<<endl;
    }
    else{
        cout<<"Beklager, men du suger!!!"<<endl;
    }
}
