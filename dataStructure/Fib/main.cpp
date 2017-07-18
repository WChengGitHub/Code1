#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int Fib(long n);
int Fib1(long n);
int main(int argc, char** argv) {
	cout<<Fib(13)<<endl;
	return 0;
}
int Fib(long n){
	if(n<=1){
		return n;
	}else{
		return Fib(n-1)+Fib(n-2);
	}
}
int Fib1(long n){
	int left=1;
	int right=0;
	int sum=0;
	if(n<=1){
		return n;
	}else{
		for(int i=2;i<=n;i++){
			sum=left+right;
			right=left;
			left=sum;
		}
	}
	return sum;
}
