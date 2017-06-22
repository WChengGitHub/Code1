#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct LinkNode{
	int data;
	LinkNode * link;
};
class CircleList{
	public:
		CircleList(){
			first=new LinkNode;
			first->link=first;
		}
		~CircleList(){
			delete first;
		}
		bool insert(int position,int data);
		bool Delete(int position);
		void show(){
			LinkNode * current=first->link;
			while(current!=first){
				cout<<current->data<<" ";
				current=current->link; 
			}
			cout<<endl;
		}
		LinkNode * getFirst(){
			return first;
		} 
		
	private:
		LinkNode * first;
		LinkNode * locate(int position);
};
int getLast(int n,int m);
int main(int argc, char** argv) {
//	CircleList list;
//	list.insert(1,1);
//	list.insert(2,2);
//	list.show();
//	list.Delete(1);
//	list.show();
	cout<<getLast(8,3)<<endl;
	return 0;
}
LinkNode * CircleList::locate(int position){
	if(position<0){
		cout<<"²éÕÒÎ»ÖÃÊ§°Ü"<<endl;
		return NULL; 
	}
	LinkNode *current=first;
	for(int i=0;i<position;i++){
		current=current->link;
		if(current==first)
			break;
	}
	return current;
}
bool CircleList::insert(int position,int data){
	LinkNode * current=locate(position-1);
	if(current==NULL){
		cout<<"²åÈëÎ»ÖÃÓÐÎó"<<endl;
		return false;
	}
	
	LinkNode * newNode=new LinkNode;
	newNode->data=data;
	newNode->link=current->link;
	
	current->link=newNode;
	
	return true;
}
bool CircleList::Delete(int position){
	LinkNode * current=locate(position-1);
	if(current==NULL||current->link==first){
		cout<<"É¾³ýÎ»ÖÃÓÐÎó"<<endl;
		return false;
	}
	
	LinkNode * del=current->link;
	current->link=del->link;
	
	delete del;
	return true;
}

int getLast(int n,int m){
	CircleList list;
	LinkNode * first=list.getFirst();
	LinkNode * current=first->link; 
	for(int i=1;i<=n;i++){
		list.insert(i,i);
	}
	list.show();
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++){
			
			for(;current==first;current=current->link){
				if(current==first){
					cout<<"yes"<<endl;
				}
			}
			
			if(j==m-1)
				break;
			current=current->link;
		}
		
		LinkNode * del=current;
		current=current->link;
		cout<<del->data<<endl;
		list.Delete(del->data);
		list.show();
	}
	return first->link->data;
}
