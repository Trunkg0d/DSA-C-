#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

// 10 11
// 1 2
// 1 3
// 1 5
// 1 10
// 2 4
// 3 6
// 3 7
// 3 9
// 6 7
// 5 8
// 8 9
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
  // Khoi tao va danh dau
  queue<int> q;
  q.push(u);
  visited[u] = true;
  // Lap
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
  int v, e;
  bool visited[1000];
  memset(visited, false, sizeof(visited));
  inputGraph(adj, v, e);
  outputGraph(adj, v, e);
  bfs(1, adj, visited);
  return 0;
}