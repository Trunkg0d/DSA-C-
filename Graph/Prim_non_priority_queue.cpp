#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct canh{
  int x, y, z;
};

void inputGraph(vector<pair<int, int>> adj[], int &n, int &m){
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int x, y, z;
    cin >> x >> y >> z;
    adj[x].push_back({y, z});
    adj[y].push_back({x, z});
  }
}

void prim(vector<pair<int, int>> adj[], bool used[], int u, int n, int m){
  vector<canh> MST;
  int d = 0; // Chieu dau cay khung
  used[u] = true;

  // Lap
  while(MST.size() < n - 1){
    int min_z = INT_MAX; // Luu canh co trong so nho nhat
    int X, Y; // Luu hai dinh
    for(int i = 1; i <= n; i++){
      if(used[i]){
        // Duyt danh sach ke cua dinh i
        for(pair<int, int> it : adj[i]){
          int j = it.first; // Dinh ke voi dinh i
          int trongso = it.second;  // Trong so
          if(!used[j] && trongso < min_z){
            min_z = trongso;
            X = j;
            Y = i;
          }
        }
      }
    }
    MST.push_back({X, Y, min_z});
    d+=min_z;
    used[X] = true; // Cho dinh X vao V(MST) va loai X khoi tap V;
  }
  cout << "Chieu dai cuc tieu: " << d << endl;
  for (canh e : MST){
    cout << e.x << " " << e.y << " " << e.z << endl;
  }
}

int main(){
  int n, m; // n: So luong dinh, m: So luong canh
  vector<pair<int, int>> adj[1000];
  bool used[1000];  //used[i] = true, i: thuoc tap V(MST)
  memset(used, false, sizeof(used));
  inputGraph(adj, n, m);
  prim(adj, used, 1, n, m);
  return 0;
} 
