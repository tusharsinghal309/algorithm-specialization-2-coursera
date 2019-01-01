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
		void bfs(int s){
			unordered_map <int,bool> visited;
			queue <int> q;
			visited[s]=true;
			q.push(s);
			while(!q.empty()){
				int u = q.front();
				q.pop();
				cout<<u<<endl;
				for(auto v:m[u]){
					if(!visited[v.first]){
						q.push(v.first);
						visited[v.first]=true;
					}
				}	
			}
		}
		int shortestPath(int u,int v){
			unordered_map <int,int> d;
			unordered_map <int,bool> visited;
			d[u] = 0;
			visited[u] = true;
			queue <int> q;
			q.push(u);
			while(!q.empty()){
				int p = q.front();
				q.pop();
				if(p==v){
					return d[p];
				}
				for(auto neighbour:m[p]){
					if(!visited[neighbour.first]){
						visited[neighbour.first] = true;
						d[neighbour.first] = d[p]+1;
						q.push(neighbour.first);
					}
				}
			}
			return d[v];
		}
		int numberOfComponentsUndirected(){
			
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
	cout<<g.shortestPath(1,6);
	
	return 0;
}
