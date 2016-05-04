#include <iostream>
using namespace std;

int GetNthFib(int n) {
	if(n == 1 || n == 2) {
		return 1;
	}
	else
		return (GetNthFib(n-2) + GetNthFib(n-1));
}

int factorial(int n) {
	if(n == 1) return 1;
	else return n*factorial(n-1);
}

int primefactor(int n) {
	
}
int main() {
	int n;
	cout<<"Please input n: ";
	cin>>n;
	// cout<<"the "<<n<<"th fibonacci number is: "<<GetNthFib(n)<<endl;
	cout<<"the "<<n<<"'s factorial is: "<<factorial(n)<<endl;


	return 0;
}