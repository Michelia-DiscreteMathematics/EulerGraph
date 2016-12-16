#include "Graph.h"
using namespace std;

void Graph::get_node(){
	cout<<"Please tell me how many nodes does it have:";
	cin>>node;
}

void Graph::init_matrix(){
	srand((unsigned int)time(NULL));
	matrix.resize(node);
	for (int i=0;i<node;++i){
		matrix[i].resize(node);
	}
	for (int i=0;i<node;++i){
		for (int j=i+1;j<node;++j){
			matrix[i][j]=rand()%2;
			matrix[j][i]=matrix[i][j];
		}
	}
}

void Graph::get_degree(){
	total_degree=0;
	degree.resize(matrix.size());
	for (int i=0;i<matrix.size();++i){
		for (int j=0;j<matrix[i].size();++j) degree[i]+=matrix[i][j];
	}
	for (int i=0;i<degree.size();++i) total_degree+=degree[i];
	total_degree/=2;
}

int Graph::check_path(){
	int count=0;
	for (int i=0;i<degree.size();++i){
		if (degree[i]==0){
			path=false;
			circuit=false;
			return 1;
		}
		if (degree[i]%2) ++count;
	}
	if (count==0||count==2) path=true;
	else path=false;
	if (count) circuit=false;
	else circuit=true;
	return 0;
}

void Graph::get_path(){
	if (path==true&&circuit==false){	//如果存在欧拉路且无欧拉回路，则寻找度为1或3的节点作为起点
		int start=0;
		for (int i=0;i<degree.size();++i){
			if (degree[i]==1||degree[i]==3){
				start=i;
				break;
			}
		}
		line.push_back(start);
		int now=start;
		while(degree[now]){	//循环，直到当前节点度为0(无路可走)
			if (degree[now]>1){
				for (int i=0;i<matrix[now].size();++i){
					if (matrix[now][i]==1&&degree[i]%2==0){
						--degree[now];
						--degree[i];
						--total_degree;
						matrix[now][i]=0;
						matrix[i][now]=0;
						now=i;
						line.push_back(now);
						break;
					}
				}
			}else{
				for (int i=0;i<matrix[now].size();++i){
					if (matrix[now][i]==1){
						--degree[now];
						--degree[i];
						--total_degree;
						matrix[now][i]=0;
						matrix[i][now]=0;
						now=i;
						line.push_back(now);
						break;
					}
				}
			}
		}
	}
	if (path==true&&circuit==true){
		int now=0;
		int next=0;
		int next_degree=0;
		line.push_back(now);
		while(degree[now]){
			for (int i=0;i<matrix[now].size();++i){
				if (matrix[now][i]==1&&degree[i]>next_degree){	//先走度最大的
					next=i;
					next_degree=degree[i];
				}
			}
			--degree[now];
			--degree[next];
			--total_degree;
			matrix[now][next]=0;
			matrix[next][now]=0;
			now=next;
			line.push_back(now);
			next_degree=0;
		}
	}
	if (circuit==true||path==true){
		cout<<"The path is: V"<<line[0];
		for (int i=1;i<line.size(); ++i){
			cout<<"->V"<<line[i];
		}
		cout<<endl;
	}
}

void Graph::print_info(){
	cout<<"This is the Graph\'s Adjacency-matrix:"<<endl;
	cout<<"┌";
	for (int i=0;i<matrix.size();++i) cout<<"  ";
	cout<<" ┐"<<endl;
	for (int i=0;i<matrix.size();++i){
		cout<<"│";
		for (int j=0;j<matrix[i].size();++j) cout<<" "<<matrix[i][j];
		cout<<" │"<<endl;
	}
	cout<<"└";
	for (int i=0;i<matrix.size();++i) cout<<"  ";
	cout<<" ┘"<<endl;
	cout<<"This Graph has "<<node<<" nodes, and the total number of degrees is "<<total_degree<<endl;
	cout<<"The degree of every nodes are: ";
	for (int i=0;i<degree.size();++i){
		cout<<degree[i]<<",";
	}
	cout<<"\b."<<endl;
	if (path) cout<<"Euler path: Yes"<<endl;
	else cout<<"Euler path: No"<<endl;
	if (circuit) cout<<"Euler circuit: yes"<<endl;
	else cout<<"Euler circuit: No"<<endl;
}