#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int>  adj[1000];
bool visited[1000];

void dfs(int u){
  cout << u << " ";
  visited[u] = true;
  for(int x : adj[u]){
    if(!visited[x]){
      dfs(x);
    }
  }
}

int main(){
  memset(visited, false, sizeof(visited));
  int v, e;
  cin >> v >> e;
  for(int i = 0; i < e; i++){
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for(int i = 0; i < v; i++){
    cout << i << ": ";
    for(int j : adj[i]){
      cout << j << " ";
    }
    cout << endl;
  }
  dfs(0);
  return 0;
}