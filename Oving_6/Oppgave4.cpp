#include "Oppgave4.h"
#include "std_lib_facilities.h"
#include <cmath>
#include "Graph.h"
#include "AnimationWindow.h"
#include "string"
#include "Oppgave3.h"


istream& operator>>(istream& is, Temps& t){
	double inMax, inMin;
	is >> inMax >> inMin;
	if (!is) return is;

	t = Temps{ inMax, inMin };
	return is;
}

void readTempsFromFile(vector<Temps> readTemps ,string filename){
    ifstream temp_file{ filename };
	string line;
    Temps t;
	while (getline(temp_file, line))
	{
		//cout << line  <<endl;
		istringstream iss{ line };
		iss >> t;
		readTemps.push_back(t);
	}
}

vector<double> tempVector(string filename){
    vector<double> tempVectorDouble;
    double number;
    ifstream myfile (filename);
    while ( myfile>>number){
        tempVectorDouble.push_back(number);
    }
    return tempVectorDouble;
}

void tempStats(string filename){
    vector<double> temperatures = tempVector(filename);
    cout<<"Max temperatur er: "<<*max_element(temperatures.begin(), temperatures.end())<<endl;
    cout<<"Dette var dag: "<< (max_element(temperatures.begin(), temperatures.end()) - temperatures.begin())/2 + 1<<endl;
    cout<<"Min temperatur er: "<<*min_element(temperatures.begin(), temperatures.end())<<endl;
    cout<<"Dette var dag: "<< (min_element(temperatures.begin(), temperatures.end()) - temperatures.begin())/2 +1<<endl;
}