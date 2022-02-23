#include "Oppgave1.h"
#include "std_lib_facilities.h"
#include <cmath>
#include "Graph.h"
#include "AnimationWindow.h"
#include "string"

void toFile(){
    ofstream myfile;
    myfile.open("Oppgave1.txt");
    string toFileString;
    cout<<"Hva ønsker du å legge til i tekstfilen? (quit for å avslutte): ";
    cin>>toFileString;
    while (toFileString != "quit"){
        myfile<<toFileString<<endl;
        cin>>toFileString;
        cout<<"Noe mer du vil legge til? ";
    }
    myfile.close();
}

void fromFileWithCount(string filename){
    string line;
    int count = 1;
    ifstream myfile (filename);
    if (myfile.is_open()){
        while (getline(myfile,line)){
            cout<<count<<" "<<line<<endl;
            count+=1;
        }
        myfile.close();
    }
    else{
        cout<<"Filen eksisterer ikke"<<endl;
    }
}

void fromFile(string filename){
    string line;
    ifstream myfile (filename);
    if (myfile.is_open()){
        while (getline(myfile,line)){
            cout<<line<<endl;
        }
        myfile.close();
    }
    else{
        cout<<"Filen eksisterer ikke"<<endl;
    }
}

