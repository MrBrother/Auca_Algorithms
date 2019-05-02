#include <iostream>
#include <vector>
#include <algorithm>
#include "algol.h"

using namespace std;
using Viter = vector<int>::const_iterator;

int main(){
    vector<int> v = {1, -12, -112, 4, 2, 12, 32, 13, 14, 3};
    Algo::quickSort(v, 0, int(v.size())-1);
    for(int e : v){
      cout << e << " ";
    }
    cout << "\n";

}
