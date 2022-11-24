#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Ma tran ke
int vertex, edge;
int a[1000][1000];
int main(){
  cin >> vertex >> edge;
  for(int i=0;i<edge;i++){
    int x, y;
    cin >> x >> y;
    a[x][y] = a[y][x] = 1;
  }

  for(int i=1;i<=vertex;i++){
    for(int j = 1; j <= vertex; j++){
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}