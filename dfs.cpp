#include<bits/stdc++.h>
#define ll long long
using namespace std;
class graph{
	unordered_map <int,list<pair<int,int>>> m;
	public:
		void addEdge(int u,int v,int wt=0,bool directed=false){
			m[u].push_back(make_pair(v,wt));
			if(!directed){
				m[v].push_back(make_pair(u,wt));	
			}
		}
		void dfsHelper(int s,unordered_map <int,bool> &visited){
			cout<<s<<endl;
			visited[s] = true;
			for(auto nb:m[s]){
				if(!visited[nb.first]){
					dfsHelper(nb.first,visited);
				}
			}
		}
		void dfs(int s){
			unordered_map <int,bool> visited;
			dfsHelper(s,visited);
		}
};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	graph g;
	g.addEdge(1,2,0,true);
	g.addEdge(3,1,0,true);
	g.addEdge(4,2,0,true);
	g.addEdge(5,3,0,true);
	g.addEdge(6,4,0,true);
	g.addEdge(5,6,0,true);
	g.addEdge(2,3,0,true);
	g.addEdge(3,4,0,true);
	g.addEdge(4,5,0,true);
	g.dfs(1);
	
	return 0;
}
