#include "node.h"
#include <iostream>

using namespace std;

template <typename T>
class LinkedList {

private:
  int size;
  Node<T> *head;

public:
  LinkedList() {
    head = NULL;
    size = 0;
  }

  void AddFirst(T value) {
    Node<T>* new_node = new Node<T>(value);
    new_node->next = head;
    head = new_node;
  }

  void Display() {
    Node<T>* current = head;

    while (current != nullptr) {
      cout << current->data << " -> ";
      current = current->next;
    }

    cout << "nullptr" << endl;
  }

  void AddLast(T value) {
    Node<T>* new_node = new Node<T>(value);
    
    if (head == nullptr) {
      head = new_node;
      return;
    }
    
    Node<T>* current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    
    current->next = new_node;
  }
  
  int Size() {
    // your-code-here
    return 0;
  }

  void Delete(T value) {
    // your-code-here
  }
};

int main() {

  LinkedList<int> int_list;

  cout << "\n>> Int List" << endl;
  int_list.AddFirst(1);
  int_list.AddFirst(2);
  int_list.AddFirst(3);
  int_list.AddLast(5);
  int_list.Display();
  cout << "Size: " << int_list.Size() << endl;
  int_list.Delete(2);
  int_list.Display();
  cout << "Size: " << int_list.Size() << endl;

  LinkedList<string> string_list;

  cout << "\n>> String List" << endl;
  string_list.AddFirst("First");
  string_list.AddFirst("Second");
  string_list.AddFirst("Third");
  string_list.AddLast("last");
  string_list.Display();
  cout << "Size: " << string_list.Size() << endl;
  string_list.Delete("First");
  string_list.Display();
  cout << "Size: " << string_list.Size() << endl;

  return 0;
}
