#include <bits/stdc++.h>
using namespace std;
int a[20];
int n, m;

void f(int v = 0, int c = 0){
  if(v==4){
    for(int i = 0; i < n; i++){
      cout << a[i];
    }
    cout << endl;
  }else{
    if(n - v > m - c){
      a[v]=0;
      f(v+1, c);
    }
    if(c < m){
      a[v] = 1;
      f(v+1,c+1);
    }
  }
}
int main(){
  int x;cin >>x;
  while (x--) {
    cin >> n >> m;
    f();
  }
  return 0;
}
