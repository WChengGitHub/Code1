#include <iostream>
#include<cstring> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void printMatchedPairs(char*c);
struct Node{
	int data;
	Node *link;
};
class LinkedStack{
	public:
		LinkedStack(){
			top=NULL;
		}
		~LinkedStack(){
			makeEmpty();
		}
		bool push(int x);
		bool pop(int&x);
		bool getTop(int&x);
		void show(){
			while(top!=NULL){
				cout<<top->data<<" ";
				top=top->link;
			}
			cout<<endl;
		}
	private:
		Node* top;
		void makeEmpty();
};
int main(int argc, char** argv) {
	char c[100];
	cout<<"�������ַ���(�������)��"<<endl;
	cin>>c;
	printMatchedPairs(c);
	return 0;
}
void LinkedStack::makeEmpty(){
	while(top!=NULL){
		Node * del=top;
		top=top->link;
		delete del;
	}
}
bool LinkedStack::push(int x) {
	Node * newNode=new Node;
	newNode->data=x;
	newNode->link=top;
	top=newNode;
	return true;
}
bool LinkedStack::pop(int &x){
	if(top==NULL){
		return false;
	}
	x=top->data;
	top=top->link;
	return true;
}
bool LinkedStack::getTop(int &x){
	if(top==NULL){
		return false;
	}
	x=top->data;
	return true;
}
void printMatchedPairs(char*c){
	int length=strlen(c);
	int x;
	LinkedStack stack;
	cout<<endl;
	for(int i=0;i<length;i++){ 
		if(c[i]=='('){
			stack.push(i);
		}else if(c[i]==')'){
			if(stack.getTop(x)){
				cout<<"��"<<x+1<<"���������"<<i+1<<"���������"<<endl<<endl; 
				stack.pop(x);
			}else{
				cout<<"û�����"<<i+1<<"��������Ե�����"<<endl<<endl;
			}
		}
	}
	while(stack.getTop(x)){
		cout<<"û�����"<<x+1<<"��������Ե�����"<<endl<<endl;
		stack.pop(x);
	}
}
