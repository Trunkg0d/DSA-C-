#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

// input
// 9 9
// 1 2
// 1 3
// 1 5
// 2 4
// 3 6
// 3 7
// 3 9
// 5 8
// 8 9

int v, e;
vector<int> adj[1001];
bool visited[1001];

void dfs(int u){
  cout << u << " ";
  visited[u] = true;
  for(int v : adj[u]){
    if(!visited[v]){
      dfs(v);
    }
  }
}

int main(){
  cin >> v >> e;
  for (int i = 0; i < e; i++){
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  memset(visited, false, sizeof(visited));

  for (int i = 1; i <= v; i ++){
    cout << i << ": ";
    for(int j : adj[i]){
      cout << j << " ";
    }
    cout << endl;
  }

  dfs(1);
  return 0;
}