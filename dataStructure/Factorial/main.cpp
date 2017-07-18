#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int Factorial(int n);
int main(int argc, char** argv) {
	cout<<Factorial(4)<<endl;
	return 0;
}
int Factorial(int n){
	if(n==0){
		return 1;
	}else{
		return n*Factorial(n-1);
	}
}
