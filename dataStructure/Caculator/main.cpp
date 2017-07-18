#include <iostream>
#include<stack>
#include<map>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
class Calculator{
	public:
		Calculator(){
		}
		void run();
		~Calculator(){
		}
		void run1(); 
	private:
		stack<double>s;
		void addOperand(double value);
		bool get2Operands(double&left,double&right);
		bool doOperator(char op);
};
int main(int argc, char** argv) {
	Calculator calculator;
	calculator.run1(); 
	return 0;
}
void Calculator::addOperand(double value){
//	cout<<"addOperand"<<endl;
//	cout<<"value:"<<value<<endl;
	s.push(value);
//	cout<<"s.top()"<<s.top()<<endl;
}
bool Calculator::get2Operands(double & left,double&right){
//	cout<<"get2Operands"<<endl;
	if(s.empty()){
		return false;
	}
	left=s.top();
	s.pop();
//	cout<<"s.top()"<<s.top()<<endl;
//	cout<<left<<endl;
	if(s.empty()){
		return false;
	}
	right=s.top();
	s.pop();
	return true;
}
bool Calculator::doOperator(char op){
//	cout<<"doOperator"<<endl;
	double left,right;
//	cout<<"left:"<<left<<endl;
//	cout<<"right:"<<right<<endl;
	if(!get2Operands(left,right)){
		return false;
	}
	switch(op){
		case '+':s.push(left+right);break;
		case '-':s.push(left-right);break;
		case '*':s.push(left*right);break;
		case '/':if(right==0)return false;s.push(left/right);break;
	}
	return true;
}
void Calculator::run(){ 
//	cout<<"run"<<endl;
	char ch;
	double newOperand; 
	cin>>ch;
	while(ch!='#'){
		switch(ch){
				case '+':
				case '-':
				case '*':
				case '/':doOperator(ch);break;
				default:cin.putback(ch);cin>>newOperand;addOperand(newOperand);break;
		}
		cin>>ch;
	}

	if(!s.empty()){
		cout<<"运算结果："<<s.top()<<endl;
	}
}
void Calculator::run1(){ 
	double newOperand;
	map<char,int>instack;
	map<char,int>outstack;
	instack.insert(pair <char, int>('=',0));
	instack.insert(pair <char, int>('(',1));
	instack.insert(pair <char, int>(')',6));
	instack.insert(pair <char, int>('*',5));
	instack.insert(pair <char, int>('/',5));
	instack.insert(pair <char, int>('+',3));
	instack.insert(pair <char, int>('-',3));
	
	outstack.insert(pair <char, int>('=',0));
	outstack.insert(pair <char, int>('(',6));
	outstack.insert(pair <char, int>(')',1));
	outstack.insert(pair <char, int>('*',4));
	outstack.insert(pair <char, int>('/',4));
	outstack.insert(pair <char, int>('+',2));
	outstack.insert(pair <char, int>('-',2));
	
	stack<int>numbers;
	
	stack<char>temp;
	temp.push('=');
	
	char ch;
	while(cin>>ch){
		if(isdigit(ch)){
//			cout<<"ch:"<<ch<<endl;
			switch(ch){
				case '0':numbers.push(0);break;
				case '1':numbers.push(1);break;
				case '2':numbers.push(2);break;
				case '3':numbers.push(3);break;
				case '4':numbers.push(4);break;
				case '5':numbers.push(5);break;
				case '6':numbers.push(6);break;
				case '7':numbers.push(7);break;
				case '8':numbers.push(8);break;
				case '9':numbers.push(9);break;
			}
		}else{
			if(!numbers.empty()){
				newOperand=0;
				for(int i=1;!numbers.empty();i=i*10){
					newOperand=numbers.top()*i+newOperand;
					numbers.pop();
				}
				s.push(newOperand);
//				cout<<"newOperand:"<<newOperand<<endl;
			}
			if(instack[temp.top()]<outstack[ch]){
				temp.push(ch);
			}else if(instack[temp.top()]>outstack[ch]){
					if(!doOperator(temp.top())){
						cout<<"表达式输入有误"<<endl;
						break;
					}
					temp.pop();
					cin.putback(ch);
			}else if(instack[temp.top()]==outstack[ch]){
				if(temp.top()=='=')
					break;
				temp.pop();
			}
		}
	}
	//cout<<"准备输出结果。。。"<<endl;
	if(!s.empty()){
		cout<<s.top()<<endl;
	}
}
