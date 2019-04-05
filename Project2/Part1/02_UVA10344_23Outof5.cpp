#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> N(5);

bool f(int total, int pos){
  if (pos == 5)
      return total == 23;

  int num = N[pos];

  return f(total + num, pos + 1)
      || f(total - num, pos + 1)
      || f(total * num, pos + 1);
}

int main(){

  while(cin >> N[0] >> N[1] >> N[2] >> N[3] >>N[4]){
    if(!N[0] && !N[1] && !N[2] && !N[3] && !N[4])
      break;

    sort(N.begin(), N.end());
    bool p = false;
    do{
      p = f(N[0], 1);
      // cout << N[0] << " " << N[1] << " " << N[2] << " "<< N[3]<< " " << N[4] << endl;
      if(p)
        break;
    }while (next_permutation(N.begin(), N.end()));

    if(p){
      cout << "Possible" << endl;
    }else{
      cout << "Impossible" << endl;
    }
  }
  return 0;
}
