#include<bits/stdc++.h>
#define ll long long
#define high 900000
using namespace std;
class graph{
	vector<list<int>> g = vector <list<int>>(high+1);
	vector<list<int>> rg = vector <list<int>>(high+1);
	unordered_map <int,bool> presence;
	ll countVertex = 0;
	ll current;
	public:
		void addEdge(int i,int j){
			g[i].push_back(j);
			rg[j].push_back(i);
			if(!presence[i]){
				countVertex++;
			}
			if(!presence[j]){
				countVertex++;
			}
			presence[i] = true;
			presence[j] = true;
		}
		void dfsHelper(vector<list<int>> &cg,int s,unordered_map<int,bool> &visited,vector<int> &finished){
			visited[s] = true;
			for(auto n:cg[s]){
				if(!visited[n]){
					dfsHelper(cg,n,visited,finished);
				}
			}
			finished[current] = s;
			current++;
		}
		void iterativeDfsHelper(vector<list<int>> &cg,int s,unordered_map<int,int> &visited,vector<int> &finished){
			stack <int> st;
			st.push(s);
			visited[s] = 1;
			while(!st.empty()){
			//	cout<<current<<"  ";
				ll top = st.top();
			//	cout<<top<<"  ";
				if(visited[top] == 2){
					st.pop();
					finished[current] = top;
				//	cout<<top<<"------>"<<current<<endl;
					current++;
				}
				else if(visited[top] == 1){
					for(auto v:cg[top]){
						if(visited[v]==0){
							st.push(v);
							visited[v] = 1;
						}
					}
					visited[top] = 2;
			//		cout<<top<<endl;
				}		
			}
		}
		void dfs(vector<list<int>> &cg,vector<int> &finished){
			unordered_map <int,int> visited;
			for(int i=0;i<=high;i++){
				if(presence[i] && visited[i]==0){
					//dfsHelper(cg,i,visited,finished);
					iterativeDfsHelper(cg,i,visited,finished);
				}
			}
		}
		void dfsHelper1(int s,unordered_map <int,bool> &visited){
			visited[s] = true;
			for(auto n:g[s]){
				if(!visited[n]){
					dfsHelper1(n,visited);
				}
			}
			cout<<s<<", ";
			current++;
		}
		void iterativeDfsHelper1(int s,unordered_map <int,bool> &visited){
			stack <int> st;
			st.push(s);
			visited[s] = true;
			while(!st.empty()){
				ll u = st.top();
				st.pop();
				current++;
				for(auto v:g[u]){
					if(!visited[v]){
						st.push(v);
						visited[v] =true;	
					}
				}
			}
		}
		ll stronglyConnectedComponents(){
			vector<int> finished(countVertex);
			current = 0;
			//on reverse graph
			dfs(rg,finished);
//			 cout<<"finished->";
//			for(auto i:finished){
//				cout<<i<<" ";
//			} 
//			cout<<endl;
			//got finishpoints
			ll componentCount = 0;
			unordered_map <int,bool> visited;
			vector<int> sizes;
			for(ll i=countVertex-1;i>=0;i--){
				if(!visited[finished[i]]){
					componentCount+=1;
					current = 0;
//					cout<<"Component number "<<componentCount<<endl;
					iterativeDfsHelper1(finished[i],visited);
//					cout<<endl;
					sizes.push_back(current);
				}
			}
			sort(sizes.begin(),sizes.end());
			cout<<endl;
			cout<<"Starting the sizes"<<endl;
			for(auto i:sizes){
				cout<<i<<"  ";
			}
			cout<<endl<<"ending the sizes"<<endl;
			return componentCount;
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	graph g;
	int tail,head,count=0;
	
	ifstream myfile;
	myfile.open("scc1.txt");
	string word;
//	word = "12345678";
//	ll ans = stoi(word) + 1;
//	cout<<ans;
	while(myfile>>word){
	//	cout<<word<<" ";
		tail = stoi(word);
		myfile>>word;
		head = stoi(word);
	//	cout<<word<<endl;
		g.addEdge(tail,head);
	}
//	g.addEdge(1,7);
//	g.addEdge(7,4);
//	g.addEdge(4,1);
//	g.addEdge(7,9);
//	g.addEdge(9,6);
//	g.addEdge(6,3);
//	g.addEdge(3,9);
//	g.addEdge(6,8);
//	g.addEdge(8,2);
//	g.addEdge(2,5);
//	g.addEdge(5,8);
//	g.addEdge(3,4);
	cout<<g.stronglyConnectedComponents();
	return 0;
}
