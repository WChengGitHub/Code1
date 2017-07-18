#include <iostream>
#include<assert.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int stackIncreasement=10;
class SeqStack{
	public:
		SeqStack(int size);
		~SeqStack(){
			delete elements;
		}
		bool pop(int&x);
		bool push(int x);
		bool getTop(int&x);
		bool isFull();
		bool isEmpty();
		void show();
	private:
		int * elements;
		int top;
		int maxSize;
		void overflowProcess();
};
int main(int argc, char** argv) {
	SeqStack stack(3);
	int x=2;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.show();
	stack.pop(x);
	stack.show();
	return 0;
}
SeqStack::SeqStack(int size){
	elements=new int[size];
	assert(elements!=NULL);
	top=-1;
	maxSize=size;
}
void SeqStack::overflowProcess(){
	int * newElements=new int[maxSize+stackIncreasement];
	assert(newElements!=NULL);
	for(int i=0;i<maxSize;i++){
		newElements[i]=elements[i];
	}
	maxSize=maxSize+stackIncreasement;
}
bool SeqStack::isFull(){
	if(top==maxSize-1){
		return true;
	}else{
		return false;
	}
}
bool SeqStack::isEmpty(){
	if(top==-1){
		return true;
	}else{
		return false;
	}
}
bool SeqStack::pop(int&x){
	if(isEmpty()){
		return false;
	}
	x=elements[top];
	top--;
	return true;
}
bool SeqStack::push(int x){
	if(isFull()){
		overflowProcess();
	}
	top++;
	elements[top]=x;
	return true;
}
void SeqStack::show(){
	for(int i=0;i<=top;i++){
		cout<<elements[i]<<" "; 
	}
	cout<<endl<<endl;
}
