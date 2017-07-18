#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
class SeqQueue{
	public:
		SeqQueue(int size);
		~SeqQueue();
		bool isFull();
		bool isEmpty();
		bool enQueue(int x);
		bool deQueue(int&x);
		bool getFront(int&x);
		void show();
	private:
		int front,rear;
		int maxSize;
		int * a;	
};
int main(int argc, char** argv) {
	int x;
	SeqQueue seqQueue(5);
	seqQueue.enQueue(1);
	seqQueue.enQueue(2);
	seqQueue.enQueue(3);
	seqQueue.show();
	seqQueue.deQueue(x);
	seqQueue.getFront(x);
	cout<<"x:"<<x<<endl; 
	seqQueue.show();
	return 0;
}
SeqQueue::SeqQueue(int size){
	a=new int[size];
	maxSize=size;
	front=rear=0;
}
SeqQueue::~SeqQueue(){
	delete a;
}
bool SeqQueue::isFull(){
	if((rear+1)%maxSize==front){
		return true;
	}
	return false;
}
bool SeqQueue::isEmpty(){
	if((front+1)%maxSize==rear){
		return true;
	}
	return false;
}
bool SeqQueue::enQueue(int x){
//	cout<<"enQueue"<<endl;
	if(isFull()){
		return false;
	}
	a[rear]=x;
	rear=(rear+1)%maxSize;
	return true;
}
bool SeqQueue::deQueue(int&x){
	if(isEmpty()){
		return false;
	}
	x=a[front];
	front=(front+1)%maxSize;
	return true; 
}
bool SeqQueue::getFront(int&x){
	if(isEmpty()){
		return false;
	}
	x=a[front];
	return true;
}
void SeqQueue::show(){
	int temp=front;
	for(;front%maxSize!=rear;front=(front+1)%maxSize){
//		cout<<"front:"<<front<<endl;
		cout<<a[front]<<" ";
	}
	front=temp;
	cout<<endl;
}
