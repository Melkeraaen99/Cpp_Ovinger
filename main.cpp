// Øving 1 Thomas Melkeraaen

// Oppgave 1a)

#include "std_lib_facilities.h"

bool isFibonacciNumber(int n) {
	int a = 0;
	int b = 1;
	while (b < n) {
		int temp = b;
		b += a;
		a = temp;
	}
	return b == n;
}

/* Python kode

def isFibonacciNumber(n):
    a=0
    b=1
    while b<n:
        temp=b
        b+=a
        a=temp
    return b==n
*/

// Oppgave 2a)

/* Python
def maxOfTwo(a, b):
    if a > b:
        print("A is greater than B")
        return a
    else:
        print("B is greater than or equal to A")
        return b
*/

double maxOfTwo(double a, double b) {
	if (a>b) {
		cout<<"A is greater than B"<<endl;
		return a;
	}
	else {
		cout<<"B is greater than or equal to A"<<endl;
		return b;		
	}
}

int fibonacci(int n) {
	int a = 0;
	int b = 1;
	cout<<"Fibonacci numbers"<<endl;
	for (int i = 1; i < n+1; i++) {
		cout<<i<<" "<<b<<endl;
		int temp = b;
		b+=a;
		a=temp; 
	}
	cout<<"----"<<endl;
	return b;
}

int squareNumberSum(int n) {
	int totalSum = 0;
	for (int i =0; i<n; i++) {
		totalSum += i*i;
		cout<<i*i<<endl; 
	}
	cout<<totalSum<<endl;
	return totalSum;
}

int triangleNumbersBelow(int n) {
	int acc = 1;
	int num = 2;
	cout<<"Triangle numbers below "<<n<<":"<<endl;
	while (acc<n) {
		cout<<acc<<endl;
		acc+=num;
		num+=1;
	}
	cout<<"Next number is:"<<endl;
	return acc;
}

bool isPrime(int n) {
	for (int i = 2; i<n; i++) {
		if (n%i == 0) {
			return false;
		}
		else {
			return true;
		}
	}
}

int naivePrimeNumberSearch(int n) {
	for (int i = 2; i<n; i++) {
		if (isPrime(i) == true) {
			cout<<i<<" is a prime"<<endl;
		}
	}
}

int findGreatestDivisor(int n) {
	for (int divisor = n-1; divisor>=0; divisor--) {
		if (n%divisor == 0) {
			return divisor;
		}
	}
}

int main() {
	cout<<"Oppgave 1"<< endl;
	cout<<"Se kommentert under oppgaven"<< endl;
	cout<<isFibonacciNumber(5)<<endl;	
	cout<<"Oppgave 2a"<< endl;
	cout<<maxOfTwo(5,6)<< endl;
	cout<<"Oppgave 2b"<< endl;
	cout<<"Main laget og funker!"<< endl;
	cout<<"Oppgave 2c"<< endl;
	cout<<fibonacci(5)<<endl;
	cout<<"Oppgave 2d"<< endl;
	cout<<squareNumberSum(6)<<endl;
	cout<<"Oppgave 2e"<< endl;
	cout<<triangleNumbersBelow(20)<<endl;
	cout<<"Oppgave 2f"<< endl;
	cout<<isPrime(11)<<endl;
	cout<<"Oppgave 2g"<< endl;
	cout<<naivePrimeNumberSearch(10)<<endl;
	cout<<"Oppgave 2h"<< endl;	
	cout<<findGreatestDivisor(20)<<endl;
	return 0;
}