#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, t;
vector<pair<int, int>> adj[1000];
const int INF = 1e9;
int pre[maxn];

void nhap(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    int x, y, w;
    cin >> x >> y >> w;
    adj[x].push_back({y, w});
    adj[y].push_back({x, w});
  }
}

void dijkstra(int s){
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
  vector<long long> d(n + 1, INF)

  Q.push({0, s});
  while(!Q.empty()){
    pair<int, int> top = Q.top(); Q.pop();
    int u = top.second;
    int kc = top.first;
    
    if(kc > d[u]) continue;
  }
}

int main(){
  return 0;
}