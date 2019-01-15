#ifndef _DOUBLE_LINKED_LIST_H
#define _DOUBLE_LINKED_LIST_H
#include <stdexcept>
#include <string>

using namespace std;

// Ce qui est contenu par une cellule
struct Item
{
       string key;         // Clef d'accès à une donnée
       string definition;  // Une définition correspondant à la clef   
       // constructeur d'Item
       bool operator == (const Item & item) const
       {
          return (this->key == item.key && this->definition == item.definition);  
       }
};
              
class DoubleLinkedList
{
      private :
                            
              struct Cellule
              {
                     Item data;       // une donnée est composée de sa clef et d'une donnée
                     Cellule * next;  // suivant dans la liste
                     Cellule * prev;  // précédent dans la liste
              };
              // Implementation choices
              int _size;
              Cellule * _back;
              Cellule * _front;  
              
              // Adds all Item from l
              // Postcondition : size() will be incremented by l.size()
              void clone(const DoubleLinkedList & l) throw (logic_error, bad_alloc);
      public :
              // The default constructor
              DoubleLinkedList();
              // The copy constructor
              DoubleLinkedList(const DoubleLinkedList & l) throw (logic_error, bad_alloc);
              // The assignment operator
              DoubleLinkedList & operator=(const DoubleLinkedList & l) throw (logic_error, bad_alloc);
              // destructor
              ~DoubleLinkedList();
              // Returns true if the List contains no elements, and false otherwise.
              // Q.empty() is equivalent to Q.size() == 0
              bool empty() const;
              // Returns the number of elements contained in the list.
              int size() const;
              // Returns a const reference to the element at the front of the list
              // that is, the element least recently inserted. 
              // Precondition: empty() is false.
              const Item & front() const throw (logic_error);
              // Returns a const reference to the element at the back of the list,
              // that is, the element most recently inserted. 
              // Precondition: empty() is false.
              const Item & back() const throw (logic_error);
              // Inserts x at the back of the list. 
              // Precondition : search(Item.key) must be equal NULL
              // Postconditions: size() will be incremented by 1, and back() will be equal to x.
              void push(const Item & x) throw (logic_error, bad_alloc); 
              // Removes the element at the front of the list. 
              // Precondition: empty() is false. 
              // Postcondition: size() will be decremented by 1.
              void pop() throw (logic_error); 
              // searchs if a key exists in the List.
              // returns a pointer of the Item if exists
              // else returns the value NULL
              const Item * search(const string & key) const;
              // Removes the Item that Item.key == key from the list.
              // Precondition : search(Item.key) must be not equal NULL
              // Postcondition : size() will be decremented by 1.
              void remove(const string & key) throw (logic_error);
              // Removes all Item
              // Postcondition : empty() is true
              void clear();
};    
#endif 	
