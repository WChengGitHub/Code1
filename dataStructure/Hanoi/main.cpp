#include <iostream>
#include<string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
void Hanoi(int n,string A,string B,string C);
int main(int argc, char** argv) {
	Hanoi(10,"A","B","C");
	return 0;
}
void Hanoi(int n,string A,string B,string C){
	if(n==1){
		cout<<A<<"-->"<<C<<endl;
	}else{
		Hanoi(n-1,A,C,B);
		cout<<A<<"-->"<<C<<endl;
		Hanoi(n-1,B,A,C);
	}
}
