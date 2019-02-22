#include <iostream>

using namespace std;

struct Node{
  int data;
  Node* prev;
  Node* next;

  Node(int aData, Node* aNext, Node* aPrev)
  : data(aData), next(aNext), prev(aPrev)
  {
  }

};

void pushBack(Node*& head, Node*& tail, int e);
void printInDirectOrder(Node* head);
void printInReversedOrder(Node* tail);
void insert(Node*& head, Node* cur, int elem);
Node* erase(Node*& head, Node*& tail, Node *curr);
void clear(Node*& head, Node*& tail);


int main(){

  Node* head = nullptr;
  Node* tail = nullptr;

  int z;
  while (cin >> z) {
    pushBack(head, tail, z);
  }
  printInDirectOrder(head);
  printInReversedOrder(tail);

  for (Node* p = head; p; p = p->next)
   {
       if (p->data % 2 == 0)
       {
           insert(head, p, 0);
       }
   }

   printInDirectOrder(head);
   printInReversedOrder(tail);

   for (Node* p = head; p;)
   {
       if (p->data % 2 == 0)
       {
           p = erase(head, tail, p);
       }
       else
       {
           p = p->next;
       }
   }

   printInDirectOrder(head);
   printInReversedOrder(tail);


   clear(head, tail);


  return 0;
}

void pushBack(Node*& head, Node*& tail, int e){

  if(head == nullptr){
    head = tail = new Node(e, nullptr, nullptr);
  }else{
    tail->next = new Node(e, nullptr, tail);
    tail = tail->next;
  }

}

void insert(Node*& head, Node* cur, int elem){
  if(cur != head){
    Node* t = new Node(elem, cur, cur->prev);
    t->prev->next = t;
    t->next->prev = t;
  }else{
    head->prev = new Node(elem, cur, nullptr);
    head = head->prev;
  }
}

void printInDirectOrder(Node* head){
  for(Node* p = head; p; p = p->next){
    cout << p->data << " ";
  }
  cout << endl;
}

void printInReversedOrder(Node* tail){
  for(Node* p = tail; p; p = p->prev){
    cout << p->data << " ";
  }
  cout << endl;
}

Node* erase(Node*& head, Node*& tail, Node *curr){
  if(curr == head and curr == tail){
    delete curr;
    head = tail = nullptr;
    return nullptr;
  }else if(curr == head){
    head = head->next;
    delete curr;
    return head;
  }else if(curr == tail){
    tail = tail->prev;
    delete curr;
    return nullptr;
  }else{
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    Node* t = curr->next;
    delete curr;
    return t;
  }


}

void clear(Node*& head, Node*& tail){
  while(head){
        cout << "Delete node: " << head->data << endl;
        Node* tmp = head->next;
        delete head;
        head = tmp;
  }

  head = tail = nullptr;
}
