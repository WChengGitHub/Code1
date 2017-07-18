#include <iostream>
#include <queue> 
int Grid[100][100];
int m,n;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
struct Position{
	int row;
	int col;
};
bool findPath(Position start,Position end,int &pathLen,Position*&path);
int main(int argc, char** argv) {
	cout<<"请输入行列数："<<endl;
	cin>>m;
	cout<<"请输入坐标图:" <<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cin>>Grid[i][j];
		}
	}
	int pathlen;
	Position start,end;
	start.row=3;
	start.col=2;
	end.row=4;
	end.col=6;
	Position * path;
	if(findPath(start,end,pathlen,path)){
		for(int i=0;i<pathlen;i++){
			cout<<"<"<<path[i].row<<","<<path[i].col<<">"<<" ";
		}
		cout<<endl;
	}
	return 0;
}
bool findPath(Position start,Position end,int &pathLen,Position*&path){
	if(start.row==end.row&&start.col==end.col){
		return false;
	}
	
	for(int i=0;i<=m+1;i++){
		Grid[i][0]=Grid[i][m+1]=1;
		Grid[0][i]=Grid[m+1][i]=1;
	}
	Grid[start.row][start.col]=2;
	Position offsets[4]={{-1,0},{0,-1},{0,1},{1,0}};
	
	Position here=start;
	Position nhere;
	queue<Position>q;
	do{
		for(int i=0;i<4;i++){
			nhere.row=here.row+offsets[i].row;
			nhere.col=here.col+offsets[i].col;
			if(Grid[nhere.row][nhere.col]==0){
				Grid[nhere.row][nhere.col]=Grid[here.row][here.col]+1;
				if(nhere.row==end.row&&nhere.col==end.col){
					break;
				}
				q.push(nhere);
			}
		}
		if(nhere.row==end.row&&nhere.col==end.col){
			break;
		}
		if(q.empty()){
			return false;
		}
		here=q.front();
		q.pop();	
	}while(true);
	here=nhere;
	pathLen=Grid[end.row][end.col]-2;
	cout<<"pathLen:"<<pathLen<<endl;
	path=new Position[pathLen];
	for(int j=pathLen-1;j>=0;j--){
		path[j]=here;
		for(int i=0;i<4;i++){
			nhere.row=here.row+offsets[i].row;
			nhere.col=here.col+offsets[i].col;
			if(Grid[nhere.row][nhere.col]==j+2)break;
		}
		here=nhere;
	}
	
	return true;
}
