#include "std_lib_facilities.h"
#include <cmath>
#include "Graph.h"
#include "AnimationWindow.h"

void message(){
    cout<<"Hello"<<endl;
}

void inputAndPrintInteger(){
    double tall = 0.0;
    cout<<"Skriv inn et tall: ";
    cin>>tall;
    cout<<"Du skrev: "<<tall<<endl;
}

int inputInteger(){
    int heltall=0;
    cout<<"Skriv inn et tall: ";
    cin>>heltall;
    return heltall;    
}

int inputIntegersAndPrintSum(){
    int sum_to_heltall = 0;
    sum_to_heltall += inputInteger();
    sum_to_heltall += inputInteger();
    cout<<"Summen av tallene: "<<sum_to_heltall<<endl;
    return sum_to_heltall;
}

bool isOdd(int n){
    if (n%2==0){
        return false;
    }
    else{
        return true;
    }
}

void printHumanReadableTime(int sec){
    int timer = sec/3600;
    int rest_sec_1 = sec%3600;
    int minutter = rest_sec_1/60;
    int sekunder = rest_sec_1%60;
    cout<<timer<<" time(r), "<<minutter<<" minutt(er) og "<<sekunder<<" sekund(er)"<<endl;
}

int sum_n_numbers(){
    int n = 0;
    int tall = 0;
    int sum = 0;
    cout<<"Hvor mange tall ønsker du å summere? ";
    cin>>n;
    for (int i = 0; i<n; i++) {
        cout<<"Tall: ";
        cin>>tall;
        sum += tall;
    }
    return sum;
}

int sum_n_numbers_not_zero(){
    int tall = 1;
    int sum = 0;
    while (tall != 0) {
        cout<<"Tall: ";
        cin>>tall;
        sum += tall;
    }
    return sum;
}

double inputDouble(){
    double desimaltall=0;
    cout<<"Skriv inn et desimaltall: ";
    cin>>desimaltall;
    return desimaltall;  
}

double nok_to_euro(){
    double kurs = 9.75;
    double nok = inputDouble();
    double euro = nok/kurs;
    return euro;
}

void multiplicationTable(){
    int length = 0;
    int height = 0;
    cout<<"Anngi bredde: ";
    cin>>length;
    cout<<"Anngi høyde: ";
    cin>>height;
    for (int i=1; i<length+1; i++) {
        for (int j=1; j<height+1; j++){
            cout<<(j == 1 ? "\n " : "")<<setw(5)<<i*j;
        }
    }
}

double discriminant(double a, double b, double c){
    return ((b*b)-4*a*c);
}

void printRealRoots(double a, double b, double c){
    vector<double> xVector;
    if (discriminant(a,b,c)==0) {
        xVector.push_back((-b+sqrt(discriminant(a, b, c)))/(2*a));
    }
    else if (discriminant(a,b,c)>0) {
        xVector.push_back((-b+sqrt(discriminant(a, b, c)))/(2*a));
        xVector.push_back((-b-sqrt(discriminant(a, b, c)))/(2*a));
    }
    cout<< "[";
    for (int i=0; i<xVector.size(); i++){
        cout<<xVector.at(i);
        if (i < xVector.size()-1) {
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

void solveQuadraticEquation(){
    double a = 0;
    double b = 0;
    double c = 0;
    cout<<"Skriv inn a-, b- og c-verdiene: "<<endl<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;
    cout<<"c: ";
    cin>>c;
    printRealRoots(a,b,c);
}

void meny(){
    int valg = 1;
    while (valg!=0) {
        cout<<endl<<"Velg funksjon: "<<endl<<"0) Avslutt"<<endl<<"1) Summer to tall"<<endl<<"2) Summer flere tall"
        <<endl<<"3) konverter NOK til EURO"<<endl<<"4) Skriv ut en gangetabell"<<endl<<"5) Løs ligning"<<endl
        <<"Anngi valg (0-5): ";
	    cin>>valg;
        if (valg==1) {
            inputIntegersAndPrintSum();
        }
        if (valg==2) {
            cout<<sum_n_numbers()<<endl;
        }
        if (valg==3) {
            cout<<nok_to_euro()<<endl;
        }
        if (valg==4) {
            multiplicationTable();
        }
        if (valg==5) {
            solveQuadraticEquation();
        }
    }
}

void pythagoras(){
    using namespace Graph_lib;
    using namespace TDT4102;
    AnimationWindow win{100,100, 1000, 1000, "Pythagoras"};
    Point point1{400,300};
    Point point2{400,600};    
    Point point3{600,600};
    win.draw_triangle(point1, point2, point3, Color::black);
    win.draw_quad(point1, point2, Point{100, 600}, Point{100, 300}, Color::green);
    win.draw_quad(point2, point3, Point{600, 800}, Point{400, 800}, Color::red);
    win.draw_quad(point1, point3, Point{900, 400}, Point{700, 100}, Color::blue);
    win.wait_for_close();
}

vector<float> calculateBalance(float innskudd, int rente, int year){
    double saldo = 0;
    vector<float> saldoVector;
    for (int i = 0; i<year+1; i++){
        saldo = innskudd*(pow(((1+(static_cast<float>(rente))/100)),i));
        saldoVector.push_back(saldo);
    }

    return saldoVector;
    // cout<< "[";
    // for (int j=0; j<saldoVector.size(); j++){
    //     cout<<saldoVector.at(j);
    //     if (j < saldoVector.size()-1) {
    //         cout<<", ";
    //     }
    // }
    // cout<<"]"<<endl;
}

void printBalance(vector<int> saldo_Vector){
    int rente = 0;
    int year = 0;
    vector<float> ny_saldoVector;
    cout<<"Antall år? ";
    cin>>year;
    cout<<"Rente (heltall)? ";
    cin>>rente;
    for (int i=0; i<saldo_Vector.size(); i++){
        ny_saldoVector = calculateBalance(saldo_Vector.at(i), rente, year);
        for (int j=0; j<ny_saldoVector.size(); j++){
            if (j==0){
                cout<<endl;
                cout<<"År"<<"   "<<"Saldo"<<endl;
            }
            cout<<j<<"    "<<ny_saldoVector.at(j)<<endl;        
        }
    }
}