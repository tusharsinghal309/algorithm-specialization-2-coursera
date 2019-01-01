#include<bits/stdc++.h>
#define ll long long
#define max_nodes 100
using namespace std;
class graph{
	vector <list<pair<int,int>>> m = vector <list<pair<int,int>>>(max_nodes);
	unordered_map <int,bool> presence;
	public:
		void addEdge(int u,int v,int wt=0,bool directed=true){
			m[u].push_back(make_pair(v,wt));
			if(!directed){
				m[v].push_back(make_pair(u,wt));	
			}
			presence[u] = true;
			presence[v] = true;
		}
		void dfsHelper(int s,unordered_map<int,bool> &visited,list<int> &mylist){
			visited[s] = true;
			for(auto nb:m[s]){
				if(!visited[nb.first]){
					dfsHelper(nb.first,visited,mylist);					
				}
			}
			mylist.push_front(s);
		}
		void topologicalSort(){
			unordered_map <int,bool> visited;
			list <int> mylist;
			for(int i=0;i<max_nodes;i++){
				if(presence[i] && !visited[i]){
					dfsHelper(i,visited,mylist);
				}
			}
			cout<<"Topological ordering is";
			for(auto i:mylist){
				cout<<i<<" ----> ";
			}
		}
};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	graph g;
	g.addEdge(1,2);
	
	g.addEdge(4,2);
	g.addEdge(5,3);
	g.addEdge(6,4);
	
	g.addEdge(2,3);
	
	g.addEdge(4,5);
	g.addEdge(7,8);
	g.addEdge(9,10);
	g.topologicalSort();
	return 0;
}
