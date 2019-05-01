#ifndef ALGOL_H
#define ALGOL_H
#include <vector>

using Viter = std::vector<int>::const_iterator;

class Algo{
  public:
  Algo(){}
  ~Algo(){}

  private:
  static void merge(std::vector<int>& v, int l, int m, int r);

  public:
  static Viter binarySearch(Viter begin, Viter end, int e);
  static void insertionSort(std::vector<int>& v);


  // Merge Sort
  static void mergeSort(std::vector<int>& v, int l, int r);


};

#endif
