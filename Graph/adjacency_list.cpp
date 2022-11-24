#include<iostream>
#include<vector>
using namespace std;

// Danh sach ke
vector<int> adj[1000];

int main(){
  int vertex, edge;
  cin >> vertex >> edge;
  for(int i=0;i<edge;i++){
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  for(int i=1;i<= vertex; i++){
    cout << i << ": ";
    for(int x : adj[i]){
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}