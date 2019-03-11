#include <iostream>
#include "ListInt.h"

using namespace std;

int main(){
  ListInt list;
  cout << list.toStr() << endl;
  for(int i = 0; i < 10; i++){
    list.pushBack(i);
  }

  cout << list.toStr() << endl;
  cout << list.size() << endl;

  list.popBack();
  cout << list.toStr() << endl;
  cout << list.size() << endl;

  list.popFront();
  cout << list.toStr() << endl;
  cout << list.size() << endl;

  list.pushFront(13);
  cout << list.toStr() << endl;
  cout << list.size() << endl;

  return 0;
}
