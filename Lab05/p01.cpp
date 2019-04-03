#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

void dfs(const Graph& g, vector<int>& v, int u){
  v[u]=1;
  for(int i = 0; i < g[u].size(); i++){
    if(v[g[u][i]]){
      dfs(g, v, g[u][i]);
    }
  }
}

int main(){
  string l;
  getline(cin, l);
  int n = stoi(l);
  Graph g(n);

  for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);
    for(int j = 0; j < n; j++){
      if(line[j]=='1'){
        g[i].push_back(j);
      }
    }
  }
  int c=0;
  vector<int> visited(n);
  for (size_t i = 0; i < n; i++) {
    if(! visited[i]){
      c++;
      dfs(g, visited, i);
    }
  }

  return 0;
}
