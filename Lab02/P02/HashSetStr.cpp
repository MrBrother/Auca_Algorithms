#include <iostream>
#include <string>
#include <iomanip>
#include "HashSetStr.h"
using namespace std;

size_t defaultHashFunction(const std::string& s){
    size_t hash = 5381;
    for(char c:s){
      hash = (hash * 32 + hash) + c;
    }
    return hash;
}

void HashSetStr::print() const{
  for(size_t i = 0; i < buckets.size(); i++){
    cout << setw(4) << ": ";
    for(Node* p = buckets[i]; p ; p = p->next){
      cout << " " << p->data;
    }
    cout << endl;
  }
}

bool HashSetStr::insert(const string& s){
  if(buckets.size() == length){

  }

  size_t index = hashFunc(s) % buckets.size();

  for (Node* p = buckets[index]; p; p = p->next)
    {
        if (p->data == s)
        {
            return false;
        }
    }

  buckets[index] = new Node(s, buckets[index]);
  ++length;
  return true;

}

bool HashSetStr::find(const string& s){
  size_t index = hashFunc(s) % buckets.size();

  for (Node* p = buckets[index]; p; p = p->next)
    {
        if (p->data == s)
        {
            return true;
        }
    }
  return false;
}

bool HashSetStr::erase(const string& s){
  size_t index = hashFunc(s) % buckets.size();

  Node* q=nullptr;
  for(Node* p = buckets[index]; p; q=p,p=p->next){
    if(p->data == s){
      if(q == nullptr){
        buckets[index] = p->next;
      }else{
        q->next = p->next;
      }
      delete p;
      --length;
      return true;

    }
  }
  return false;
}

void HashSetStr::rehash(){
  std::vector<Node*> newBuckets(buckets.size()*2, nullptr);
  for(size_t i = 0; i <  buckets.size(); i++){
    while(buckets[i]){
      Node* t = buckets[i];
      buckets[i] = buckets[i]->next;
      size_t index = hashFunc(t->data) % newBuckets.size();
      t->next = newBuckets[index];
      newBuckets[index] = t;
    }
  }
  buckets.swap(newBuckets);
}
