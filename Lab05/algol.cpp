#include "algol.h"
#include <vector>
#include <algorithm>

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


// Insertion Sort O(n^2)
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


// Merge Sort O(n log n)

void Algo::merge(vector<int>& v, int l, int m, int r){
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  vector<int> L(n1);
  vector<int> R(n2);

  for(i = 0; i < n1; i++)
    L[i] = v[l + i];


  for(i = 0; i < n2; i++)
    R[i] = v[m + i + 1];

  i = j = 0;
  k = l;

  while(i < n1 && j < n2){
    if(L[i] <= R[j]){
      v[k] = L[i];
      i++;
    }else{
      v[k] = R[j];
      j++;
    }
    k++;
  }

  while(i < n1){
    v[k] = L[i];
    i++; k++;
  }
  while(j < n2){
    v[k] = R[j];
    j++; k++;
  }

}

void Algo::mergeSort(vector<int>& v, int l, int r){
  if(l < r){
    int m = l + (r - l) / 2;
    mergeSort(v, l, m);
    mergeSort(v, m + 1, r);

    merge(v, l, m, r);
  }
}


// Quick sort worst case n^2 and average  of n log n

int Algo::partition(std::vector<int>& v, int low, int high){
  int pivot = v[high];
  int i = (low - 1);
  for(int j = low; j <= high - 1; j++){
    if(v[j] <= pivot){
      i++;
      swap(v[i], v[j]);
    }
  }
  swap(v[i+1], v[high]);
  return i + 1;
}

void Algo::quickSort(std::vector<int>& v, int low, int high){
  if(low < high){

    int pivot = partition(v, low, high);
    quickSort(v, low, pivot - 1);
    quickSort(v, pivot + 1, high);

  }
}
