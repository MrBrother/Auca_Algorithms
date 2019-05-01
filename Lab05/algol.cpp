#include "algol.h"
#include <vector>

using namespace std;
using Viter = vector<int>::const_iterator;

Viter Algo::binarySearch(Viter aBegin, Viter aEnd, int e){
  Viter begin = aBegin;
  Viter end = aEnd - 1;

  while(begin <= end){
    Viter mid = begin + (end - begin) / 2;
    if(*mid == e){
      return mid;
    }

    if(*mid > e){
      end = mid - 1;
    }else{
      begin = mid + 1;
    }
  }
  return aEnd;
}

void Algo::insertionSort(vector<int>& v){
  int key, j;
  for(int i = 1; i < int(v.size()); i++){
    key = v[i];
    j = i - 1;
    while(j >= 0 and key <= v[j]){
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key;
  }
}
