#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

struct canh{
  int x, y, w;
};

vector<pair<int, int>> adj[1000];
int parent[1000], d[1000];
bool used[1000];
int n, m;

void nhap(){
  cin >> n >> m;
  for(int i =0; i < m; i++){
    int x, y, w;
    cin >> x >> y >> w;
    adj[x].push_back({y, w});
    adj[y].push_back({x, w});
  }
  memset(used, false, sizeof(used));
  for(int i = 1; i <= n; i++) d[i] = INT_MAX;
}

void prim(int u){
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
  int res = 0;
  vector<canh> MST;

  Q.push({0, u});
  
  while(!Q.empty()){
    pair<int, int> top = Q.top(); Q.pop();
    int dinh = top.second, trongso = top.first;

    if(used[dinh]) continue;
    res += trongso;
    used[dinh] = true;

    if(u != dinh){
      MST.push_back({dinh, parent[dinh], trongso});
    }

    for(auto it : adj[dinh]){
      int y = it.first, w = it.second;
      if(!used[y] && w<d[y]){
        Q.push({w, y});
        d[y] = w;
        parent[y] = dinh;
      }
    }
  }
  cout << res << endl;
  for(auto it : MST){
    cout << it.x << " " << it.y << " " << it.w << endl;
  }
}


int main(){
  nhap();
  prim(1);
  return 0;
}