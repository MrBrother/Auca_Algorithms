#ifndef ALGOL_H
#define ALGOL_H
#include <vector>

using Viter = std::vector<int>::const_iterator;

class Algo{

  Algo(){}
  ~Algo(){}

  public:
  static Viter binarySearch(Viter begin, Viter end, int e);
  static void insertionSort(std::vector<int>& v);



};

#endif
