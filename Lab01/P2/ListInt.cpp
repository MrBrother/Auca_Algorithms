
#include <string>
#include <sstream>
#include "ListInt.h"
using namespace std;

ListInt::ListInt()
:head(new Node(0, nullptr, nullptr)),
 tail(new Node(0, nullptr, nullptr)),
 length(0)
 {
   head->next = tail;
   tail->prev = head;
 }

ListInt::ListInt(const ListInt& other)
:head(new Node(0, nullptr, nullptr)),
 tail(new Node(0, nullptr, nullptr)),
 length(0)
{
  head->next = tail;
  tail->prev = head;

  for(Node* p = other.head->next; p != other.tail; p = p->next){
    pushBack(p->data);
  }
}


ListInt& ListInt::operator=(const ListInt& other){
  clear();
  for(Node* p = other.head->next; p != other.tail; p = p->next){
    pushBack(p->data);
  }
}

string ListInt::toStr() const{
  ostringstream sout;

  sout << "{";
  bool first = true;

  for(Node* p = head->next;p != tail;p = p->next){
    if(!first) sout << ", ";
    sout << p->data;
    first = false;
  }
  sout << "}";

  return sout.str();
}

void ListInt::insertNode(Node* p, int e){
  Node* t = new Node(e, p->prev, p);
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
    t->next->prev = head;
    delete t;
    --length;
  }
}

ListInt::Iter ListInt::insert(Iter pos, int e){
  insertNode(pos.p, e);
  return Iter(pos--);
}

ListInt::Iter ListInt::erase(Iter pos){
  Node* t = pos.p;
  Node* r = pos.p->next;
  t->next->prev = t->prev;
  t->prev->next = t->next;
  delete t;
  --length;
  return Iter(r);
}

void ListInt::clear(){
  Node* t = head->next;
  while(t!=tail){
    Node* tmp = t->next;
    delete t;
    t = tmp;
  }
  head->next = tail;
  tail->prev = head;
  length = 0;
}
