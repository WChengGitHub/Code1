#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct LinkNode{
	int data;
	LinkNode*link;
};
class List{
	public:
		bool insert(int loaction,int data);
		bool Delete(int loaction);
		void inputFront();
		void inputAfter();
		void show(){
			LinkNode*current=first;
			while(current->link!=NULL){
				current=current->link;
				cout<<current->data<<" "; 
			}
			cout<<endl;
		}
		List(){
			first=new LinkNode;
			first->link=NULL;
		}
		~List(){
			delete first;
		}
	private:
		LinkNode * locate(int i);
		void empty();
		LinkNode* first;
};
int main(int argc, char** argv) {
	List list;
	list.inputFront(); 
	list.show();
	list.inputAfter(); 
	list.show();
	return 0;
}
LinkNode * List::locate(int location){
	if(location<0){
		return NULL;
	}
	LinkNode * current=first;
	for(int i=0;i<location;i++){
		current=current->link;
		if(current==NULL){
			break;
		}
	}
	return current;
} 
bool List::insert(int location,int data){
	LinkNode * current=locate(location-1);
	if(current==NULL){
		cout<<"插入位置有误,插入失败"<<endl; 
		return false;
	}
	
	LinkNode * newNode=new LinkNode;
	newNode->data=data;
	
	newNode->link=current->link;
	current->link=newNode;
	
	return true;
	
}
bool List::Delete(int location){
	LinkNode * current=locate(location-1);
	if(current==NULL||current->link==NULL){
		cout<<"删除位置有误，删除失败"<<endl;
		return false; 
	}
	
	LinkNode * del=current->link;
	current->link=del->link;
	delete del;
	
	return true;
}
void List::inputFront(){
	int tag;
	empty();
	cout<<"请输入结束的标志:"<<endl;
	cin>>tag;
	int data;
	cout<<"请输入数据:"<<endl;
	cin>>data;
	while(data!=tag) {
		LinkNode * newNode=new LinkNode;
		newNode->data=data;
		newNode->link=first->link;
		first->link=newNode;
		cin>>data;
	}
}
void List::inputAfter(){
	empty();
	LinkNode * current=first;
	int tag;
	cout<<"请输入结束的标志:"<<endl;
	cin>>tag;
	int data;
	cout<<"请输入数据:"<<endl;
	cin>>data;
	while(data!=tag){
		LinkNode * newNode=new LinkNode;
		newNode->data=data;
		newNode->link=NULL;
		current->link=newNode;
		current=newNode;
		cin>>data; 
	}
	
}
void List::empty(){
	LinkNode*current=first->link;
	while(current!=NULL){
		LinkNode * del=current;
		current=current->link;
		delete del;
	}
	
}
