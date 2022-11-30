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

void printAllPaths(int s, int d){
  bool* visited = new bool[1000];
  int *path = new int[1000];

  for(int i = 0; i < v; i++){
    visited[i] = false;
  }
  printAllPathsUtil(s, d, visited, path, path_index);
}

void printAllPathsUtil(int u, int d, bool visited[], int path[], int& path_index)
{
	// Mark the current node and store it in path[]
	visited[u] = true;
	path[path_index] = u;
	path_index++;

	// If current vertex is same as destination, then print
	// current path[]
	if (u == d) {
		for (int i = 0; i < path_index; i++)
			cout << path[i] << " ";
		cout << endl;
	}
	else // If current vertex is not destination
	{
		// Recur for all the vertices adjacent to current
		// vertex
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
			if (!visited[*i])
				printAllPathsUtil(*i, d, visited, path,
								path_index);
	}
	// Remove current vertex from path[] and mark it as
	// unvisited
	path_index--;
	visited[u] = false;
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