#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

vector<int> adj[1000];
int v, e;
bool dfs_visited[1000];
bool bfs_visited[1000];

void dfs(int u){
  cout << u << " ";
  dfs_visited[u] = true;
  for(int v : adj[u]){
    if(!dfs_visited[v]){
      dfs(v);
    }
  }
}

void bfs(int u){
  queue<int> q;
  q.push(u);
  bfs_visited[u] = true;

  while(!q.empty()){
    int v = q.front();
    q.pop();
    cout << v << " ";
    for(int x : adj[v]){
      if(!bfs_visited[x]){
        q.push(x);
        bfs_visited[x] = true;
      }
    }
  }
}

bool isPath(int start, int end){
  if(start == end){
    return true;
  }
  dfs_visited[start] = true;
  for(int x : adj[start]){
    if(!dfs_visited[x]){
      if(isPath(x, end)){
        return true;
      }
    }
  }
  return false;  
}

int count_ccp(){
  memset(dfs_visited, 0, sizeof(dfs_visited));
  int ccp_amount = 0; // So thanh phan lien thong

  // Duyet tung dinh, dinh nao chua tham thi DFS tu dinh do
  for(int i = 1; i <= v; i++){
    if(!dfs_visited[i]){
      dfs(i);
      ccp_amount++;
    }
  }
  return ccp_amount;
}

int main(){
  cin >> v >> e;
  memset(dfs_visited, 0, sizeof(dfs_visited));
  memset(bfs_visited, 0, sizeof(bfs_visited));
  for(int i = 0; i<e; i++){
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  for(int i = 1; i <= v; i++){
    cout << i << ": ";
    for(int x : adj[i]){
      cout << x << " ";
    }
    cout << endl;
  }
  dfs(1);
  cout << endl << "------------------" << endl;
  bfs(1);
  cout << endl << "------------------" << endl;
  memset(dfs_visited, false, sizeof(dfs_visited));
  if(isPath(1, 6)){
    cout << "Have path" << endl;
  } else {
    cout << "No path" << endl;
  }
  return 0;
}
