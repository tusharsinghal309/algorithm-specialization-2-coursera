#include<bits/stdc++.h>
#define ll long long
#define max_nodes 100
using namespace std;
class graph{
	vector <list<pair<int,int>>> m = vector <list<pair<int,int>>>(max_nodes);
	unordered_map <int,bool> presence;
	public:
		void addEdge(int u,int v,int wt=0,bool directed=false){
			m[u].push_back(make_pair(v,wt));
			if(!directed){
				m[v].push_back(make_pair(u,wt));	
			}
			presence[u] = true;
			presence[v] = true;
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
			unordered_map <int,bool> visited;
			int ans = 0;
			for(int i=0;i<max_nodes;i++){
				if(presence[i] && !visited[i]){
					ans++;
					visited[i]=true;
					queue <int> q;
					q.push(i);
					cout<<"component--->"<<ans<<endl;
					while(!q.empty()){
						int v = q.front();
						q.pop();
						cout<<v<<",";
						for(auto n:m[v]){
							if(!visited[n.first]){
							visited[n.first]=true;
							q.push(n.first);	
							}
						}
					}
				}
			}
			return ans;
		}
};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	graph g;
	g.addEdge(1,2);
	g.addEdge(3,1);
	g.addEdge(4,2);
	g.addEdge(5,3);
	g.addEdge(6,4);
	g.addEdge(5,6);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(7,8);
	g.addEdge(9,10);
	cout<<g.shortestPath(1,6);
	cout<<endl<<g.numberOfComponentsUndirected();
	
	return 0;
}
