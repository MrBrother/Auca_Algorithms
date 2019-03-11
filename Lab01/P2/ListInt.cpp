#include "ListInt.h"
#include <sstream>

using namespace std;


ListInt::ListInt()
: head(new Node(0, nullptr,  nullptr)),
  tail(new Node(0, nullptr,  nullptr)),
  length(0)
{
  head->next = tail;
  tail->prev = head;
}


string ListInt::toStr() const{
  ostringstream sout;

  bool first =  true;
  sout << "{";
  for(Node* p = head->next; p != tail; p = p->next){
    if(not first){
      sout << ", ";
    }
    sout << p->data;
    first = false;
  }

  sout << "}";
  return sout.str();
}


void ListInt::insertNode(Node* p, int a){
    Node* t = new Node(a, p->prev, p);
    t->next->prev = t;
    t->prev->next = t;

    ++length;
}


void ListInt::popBack(){
  if(length!=0){
    Node* t = tail->prev;
    t->prev->next = tail;
    tail->prev = t->prev;
    delete t;
    --length;
  }
}

void ListInt::popFront(){
  if(length!=0){
    Node* t = head->next;
    head->next = t->next;
    t->prev = head;
    delete t;
    --length;
  }
}
