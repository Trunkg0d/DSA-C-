#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

// 6 8
// 0 1
// 0 3
// 1 2
// 1 3
// 1 5
// 2 5
// 3 4
// 3 5

void inputGraph(vector<int> adj[], int &v, int &e){
  cin >> v >> e;
  for(int i = 0; i < e; i++){
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
}

void outputGraph(vector<int> adj[], int v, int e){
  for(int i = 0; i < v; i++){
    cout << i << ": ";
    for(int x : adj[i]){
      cout << x << " ";
    }
    cout << endl;
  }
}

void bfs(int u, vector<int> adj[], bool visited[]){
  queue<int> q;
  q.push(u);
  visited[u] = true;
  while(!q.empty()){
    int v = q.front();
    q.pop();
    cout << v << " ";
    for(int x : adj[v]){
      if(!visited[x]){
        q.push(x);
        visited[x] = true;
      }
    }
  }
}

int main(){
  vector<int> adj[1000];
  bool visited[1000];
  memset(visited, false, sizeof(visited));
  int v, e;
  inputGraph(adj, v, e);
  outputGraph(adj, v, e);
  bfs(1, adj, visited);
  return 0;
}