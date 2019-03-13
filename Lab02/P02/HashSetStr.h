#ifndef HASHSETSTR_H
#define HASHSETSTR_H

#include <string>
#include <vector>

size_t defaultHashFunction(const std::string& s);
class HashSetStr{
  public:
    typedef size_t (*HashFunction)(const std::string&);
  private:

  struct Node{
    std::string data;
    Node* next;

    Node(const std::string& aData, Node* aNext)
    :data(aData), next(aNext)
    {
    }

  };

  std::vector<Node*> buckets;
  size_t length;
  HashFunction hashFunc;

  void rehash();
  public:

  HashSetStr()
  :buckets(2, nullptr), length(0), hashFunc(defaultHashFunction)
  {}

  HashSetStr(HashFunction hF)
  :buckets(2, nullptr), length(0), hashFunc(hF)
  {}


  std::size_t size() const{
    return length();
  }

  std::size_t bucketCount() const{
    return buckets.size();
  }
  bool insert(const std::string& s);
  bool erase(const std::string& s);
  bool find(const std::string& s);
  void print() const;
  void clear();


};

#endif
