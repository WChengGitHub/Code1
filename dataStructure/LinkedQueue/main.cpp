#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
struct Node{
	int data;
	Node*link;
};
class LinkedQueue{
	public:
		LinkedQueue();
		~LinkedQueue();
		bool enQueue(int x);
		bool deQueue(int&x);
		bool getFront(int&x);
		void makeEmpty();
		void show();
	private: 
		Node*front,*rear;
};
void YANGVI(int n);
int main(int argc, char** argv) {
//	LinkedQueue queue;
//	int x;
//	queue.enQueue(1);
//	queue.enQueue(2);
//	queue.enQueue(3);
//	queue.show();
//	queue.deQueue(x);
//	cout<<"x:"<<x<<endl;
//	queue.getFront(x);
//	cout<<"top:"<<x<<endl;
//	
	YANGVI(6);
	return 0;
}
LinkedQueue::LinkedQueue(){
	front=rear=NULL;
}
LinkedQueue::~LinkedQueue(){
	makeEmpty();
}
bool LinkedQueue::enQueue(int x){
	Node * newNode=new Node;
	newNode->data=x;
	newNode->link=NULL;
	if(front==NULL){
		rear=front=newNode;
	}
	rear->link=newNode; 
	rear=rear->link;
	return true;
}
bool LinkedQueue::deQueue(int&x){
	if(front==NULL){
		return false;
	}
	Node*temp=front;
	x=front->data;
	front=front->link;
	delete temp;
	return true;
}
bool LinkedQueue::getFront(int&x) {
	if(front==NULL){
		return false;
	}
	x=front->data;
	return true;
}
void LinkedQueue::makeEmpty(){
	Node*del;
	while(front!=NULL){
		del=front;
		front=front->link;
		delete del;
	}
}
void LinkedQueue::show(){
	Node*current=front;
	while(current!=NULL){
		cout<<current->data<<" ";
		current=current->link;
	}
	cout<<endl;
}
void YANGVI(int n){
	LinkedQueue queue;
	int s,t;
	int u;
	queue.enQueue(1);
	queue.enQueue(1);
	s=0;
	for(int i=1;i<=n;i++){
		queue.enQueue(0);
		for(int j=1;j<=i+2;j++){
			queue.deQueue(t);
			u=s+t;
			queue.enQueue(u);
			s=t;
			if(j!=i+2)cout<<s<<" ";
		}
		cout<<endl;
	}
}
