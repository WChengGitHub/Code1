#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct LinkNode{
	int data;
	LinkNode*link;
};
class LinkList{
	private:
		LinkNode* first;
	public:
		bool insert(int position,int data);
		bool Delete(int position);
		void show(){
		   LinkNode * current=first;
		   while(current!=NULL){
		   		cout<<current->data<<" ";
		   		current=current->link;
		   }
		}
};
int main(int argc, char** argv) {
	LinkList linkList;
	linkList.insert(0,1);
	linkList.insert(1,2);
	linkList.show();
	cout<<endl;
	linkList.Delete(0);
	linkList.show();
	cout<<endl;
	return 0;
}
bool LinkList::insert(int position,int data) {
	if(position<0)
	{
		cout<<"插入位置不合理"<<endl;
		return false; 
	}
	if(first==NULL||position==0){
		LinkNode*newNode=new LinkNode;
		newNode->data=data;
		newNode->link=first;
		first=newNode;
		return true;
	}else{
		LinkNode*current=first;
		for(int i=1;i<position;i++){
			current=current->link;
			if(current==NULL)
				break;
		}
		if(current==NULL){
			cout<<"插入位置不合理"<<endl;
			return false; 
		}else{
			LinkNode*newNode=new LinkNode;
			newNode->data=data;
			newNode->link=current->link;
			current->link=newNode;
			return true;
		}
	}
}
bool LinkList::Delete(int position){
	if(first==NULL){
		cout<<"删除位置不合理"<<endl;
		return false;
	}
	if(position==0){
		LinkNode * temp=first;
		first=first->link;
		delete temp;
		return true;
	}else{
		LinkNode * current=first;
		for(int i=1;i<position;i++){
			current=current->link;
			if(current==NULL)
				break;
		}
		if(current==NULL||current->link==NULL){
			cout<<"删除位置不合理"<<endl;
			return false; 
		}
		LinkNode * temp=current->link;
		current->link=temp->link;
		return true;
	}
}
