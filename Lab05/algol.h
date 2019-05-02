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
  static int partition(std::vector<int>& v, int l, int m);

  public:
  static Viter binarySearch(Viter begin, Viter end, int e);
  static void insertionSort(std::vector<int>& v);


  // Merge Sort
  static void mergeSort(std::vector<int>& v, int l, int r);
  // Quick
  static void quickSort(std::vector<int>& v, int low, int high);

};

#endif
