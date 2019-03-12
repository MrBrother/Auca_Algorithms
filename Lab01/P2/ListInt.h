#ifndef LISTINT_H
#define LISTINT_H

class ListInt{

  public:

  private:
    struct Node{

      int data;
      Node* prev;
      Node* next;

      Node(int aData, Node* aPrev, Node* aNext)
      :data(aData), prev(aPrev), next(aNext)
      {
      }
    };


  Node* head;
  Node* tail;
  int length;

  void insertNode(Node* p, int e);
  public:
  //Constructors
  ListInt();
  //Destructor
  ~ListInt(){
    clear();
  }

  //Copy Constructor
  ListInt(const ListInt& other);
  //Asignmetn operator=
  ListInt& operator=(const ListInt&);
  int size() const{
     return length;
  }

  std::string toStr() const;

  void pushBack(int e){
    insertNode(tail, e);
  }

  void pushFront(int e){
    insertNode(head->next, e);
  }

  void popBack();
  void popFront();

  class Iter{
    friend class ListInt;
    private:

    Node* p;
    Iter(Node* aP): p(aP){}
    public:
    Iter& operator++(int){
      p = p->next;
      return *this;
    }

    Iter& operator--(int){
      p = p->prev;
      return *this;
    }

    int& operator*() const{
      return p->data;
    }

    bool operator==(const Iter& other) const{
      return (*this).p == other.p;
    }
    bool operator!=(const Iter& other) const{
      return not (*this == other);
    }
  };
  class RIter{
    friend class ListInt;
    private:
    Node* p;
    RIter(Node* aP):p(aP){}
    public:
    RIter& operator++(int){
      p = p->prev;
      return *this;
    }

    RIter& operator--(int){
      p = p->next;
      return *this;
    }

    int& operator*() const{
      return p->data;
    }

    bool operator==(const Iter& other) const{
      return (*this).p == other.p;
    }
    bool operator!=(const Iter& other) const{
      return not (*this == other);
    }
  };
  Iter begin(){
    return Iter(head->next);
  }

  Iter end(){
    return Iter(tail);
  }

  RIter rbegin(){
    return RIter(tail->prev);
  }

  RIter rend(){
    return RIter(head);
  }

  Iter insert(Iter pos, int e);

  Iter erase(Iter pos);

  void clear();
};



#endif
