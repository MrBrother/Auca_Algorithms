#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n; cin >> n;
  int x, y; cin >> x >> y;
  string a = string(x-y,'0') + string(y,'1');
  do{
    cout << a << endl;
  }while(next_permutation(a.begin(), a.end()));
}
