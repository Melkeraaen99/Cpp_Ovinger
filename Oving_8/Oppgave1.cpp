#include "Oppgave1.h"
#include<iostream>
using namespace std;

void fillInFibonacciNumbers(int* result, int length){
    result[0] = 0;
    result[1] = 1;
    for (int i = 2; i < length; i++){
        result[i] = result[i-2] + result[i-1];
    }
}

void printArray(int* arr, int length){
    for (int i = 0; i<length; i++){
        cout<<arr[i]<<" ";
    }
}

void createFibonacci(){
    int n;
    cout << "Hvor mange tall ønsker du i Fibonaccirekken? ";
    cin >> n ;
    cout << "\n" << "Fibonaccirekken er: ";
    int *fibonacci = new int[n] {};
    fillInFibonacciNumbers(fibonacci, n);
    printArray(fibonacci, n);
}
