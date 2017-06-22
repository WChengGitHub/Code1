#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node{
	int data;
	Node *lLink;
	Node *rLink;
};
class doublyLinkedList{
	public:
		
	 	doublyLinkedList(){
			first=new Node;
			first->lLink=first;
			first->rLink=first;
		}
		~doublyLinkedList(){
			DeleteAll();
		}
		bool insert(int i,int d,int data);
		bool Delete(int i,int d);
		void show(int d){
			if(d==0){
				Node * current=first;
				while(current->rLink!=first){
					current=current->rLink;
					cout<<current->data<<" ";
				}
			}else{
				Node * current=first;
				while(current->lLink!=first){
					current=current->lLink;
					cout<<current->data<<" ";
				}
			}
			cout<<endl<<endl; 
		}
		
	private:
		Node * first;
		Node * locate(int i,int d);
		void DeleteAll();
};
int main(int argc, char** argv) {
	doublyLinkedList d;
	d.insert(0,0,1);
	d.insert(1,0,2);
	d.Delete(0,1);
	d.show(1);
	return 0;
}
Node * doublyLinkedList::locate(int i,int d){
	if(i<0){
		cout<<"²éÕÒÎ»ÖÃÓÐÎó"<<endl;
		return NULL;
	}
	if(first->rLink==first||i==0)
		return first;
		
	Node * current;
	
	if(d==0){
		current=first->rLink;
	}else{
		current=first->lLink;
	}
	
	if(d==0){
		for(int j=1;j<i;j++){
				current=current->rLink;
				if(current==first){
					break;
				}
		}
	}else{
			for(int j=1;j<i;j++){
				current=current->lLink;
				if(current==first){
					break;
				}
		}
	}
	
	if(current==first){
		return NULL;
	}
	
	return current;
}
void doublyLinkedList::DeleteAll(){
	Node * current=first->rLink;
	while(current!=first){
		Node * del=current;
		current=current->rLink;
		delete del;
	}
	delete current; 
}
bool doublyLinkedList::insert(int i,int d,int data){
	Node * current=locate(i,d);
	if(current==NULL){
		return false;
	}
	
	Node *newNode=new Node;
	newNode->data=data;
	
	if(d==0){
		current->rLink->lLink=newNode;
		newNode->rLink=current->rLink;
		current->rLink=newNode;
		newNode->lLink=current;
	}else{
		current->lLink->rLink=newNode;
		newNode->lLink=current->lLink;
		current->lLink=newNode;
		newNode->rLink=current;
	}
	return true;
}
bool doublyLinkedList::Delete(int i,int d){
	Node * current=locate(i,d);
	if(current==NULL){
		return false;
	}
	
	Node * del;
	if(d==0){
		del=current->rLink;
		current->rLink=del->rLink;
		del->rLink->lLink=current;
	}else{
		del=current->lLink;
		current->lLink=del->lLink;
		del->lLink->rLink=current; 
	}
	return true;
}
