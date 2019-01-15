#include "DoubleLinkedList.h"
#include <iostream>
 
// Interface choices
// The copy constructor
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList & l) throw (logic_error, bad_alloc) :
    _size(0),
    _back(NULL),
    _front(NULL)
{
    try
    {
    this->clone(l);
    }
    catch(logic_error e)
    {
        throw(e);
    }
    catch(bad_alloc e)
    {
        throw(e);
    }
}

// The assignment operator
DoubleLinkedList & DoubleLinkedList::operator=(const DoubleLinkedList & l) throw (logic_error, bad_alloc)
{
    if(&l == this) return (*this);
    
    this->clear();
    
    try
    {
        this->clone(l);
    }
    catch(logic_error e)
    {
        throw(e);
    }
    catch(bad_alloc e)
    {
        throw(e);
    }
} 

// The default constructor
DoubleLinkedList::DoubleLinkedList() :
    _size(0),
    _back(NULL),
    _front(NULL)
{
}

// destructor
DoubleLinkedList::~DoubleLinkedList()
{
    this->clear();
}

// Returns true if the List contains no elements, and false otherwise.
// Q.empty() is equivalent to Q.size() == 0
bool DoubleLinkedList::empty() const
{
    return this->size() == 0;
}
// Returns the number of elements contained in the list.
int DoubleLinkedList::size() const
{
    return this->_size;
}

// Returns a const reference to the element at the front of the list
// that is, the element least recently inserted. 
// Precondition: empty() is false.
const Item & DoubleLinkedList::front() const throw (logic_error)
{
    if(this->empty())
    {
        throw logic_error("ERROR : EMPTY LIST");
    }
    return this->_front->data;
}

// Returns a const reference to the element at the back of the list,
// that is, the element most recently inserted. 
// Precondition: empty() is false.
const Item & DoubleLinkedList::back() const throw (logic_error)
{
    if(this->empty())
    {
        throw logic_error("ERROR : EMPTY LIST");
    }
    return this->_back->data;
}

// Inserts x at the back of the list. 
// Precondition : search(Item.key) must be equal NULL
// Postconditions: size() will be incremented by 1, and back() will be equal to x.
void DoubleLinkedList::push(const Item & x) throw (logic_error, bad_alloc)
{
    if(this->search(x.key) != NULL)
    {
        throw logic_error("ERROR : KEY EXISTS");
    }
    Cellule * n = new Cellule;
    if(n == NULL)
    {
        throw bad_alloc();
    }
    n->data = x;
    n->next = NULL;
    n->prev = this->_back;
    if(this->_front == NULL) this->_front = n;
    if(this->_back != NULL) this->_back->next = n;
    this->_back = n;
    this->_size++;
}

// Removes the element at the front of the list. 
// Precondition: empty() is false. 
// Postcondition: size() will be decremented by 1.
void DoubleLinkedList::pop() throw (logic_error)
{
    if(this->empty())
    {
        throw logic_error("ERROR : EMPTY LIST");
    }
    Cellule * aux = this->_front;
    this->_front = this->_front->next;
    if(this->_back == aux) this->_back = NULL;
    delete aux;
    this->_size--;
}

// searchs if a key exists in the List.
// returns a pointer of the Item if exists
// else returns the value NULL
const Item * DoubleLinkedList::search(const string & key) const
{
    for(Cellule * c = this->_front; c != NULL; c = c->next)
    {
        if(c->data.key == key) return &(c->data);
    }
    return NULL;
}

// Removes the Item that Item.key == key from the list.
// Precondition : search(Item.key) must be not equal NULL
// Postcondition : size() will be decremented by 1.
void DoubleLinkedList::remove(const string & key) throw (logic_error)
{
    //if(this->search(key) == NULL)
    //{
    //    throw logic_error("ERROR : KEY NOT EXISTS");
    //}
    // Utiliser search oblige à parcourir la boucle deux fois, optimisation : voir plus loin
    
    Cellule * c;
    for(c = this->_front; c != NULL; c = c->next)
    {
        if(c->data.key == key) break;
    }
    
    // On optimise la vérification de présence de l'Item de clé key en ne parcourant la boucle qu'une fois
    if(c == NULL)
    {
        throw logic_error("ERROR : KEY NOT EXISTS");
    }
    
    if(c->prev != NULL) c->prev->next = c->next;
    else this->_front = c->next;
    
    if(c->next != NULL) c->next->prev = c->prev;
    else this->_back = c->prev;
    
    delete c;
    this->_size--;
}

// Removes all Item
// Postcondition : empty() is true
void DoubleLinkedList::clear()
{
    
    while(!this->empty()) this->pop();
}

// Adds all Item from l
// Postcondition : size() will be incremented by l.size()
void DoubleLinkedList::clone(const DoubleLinkedList & l) throw (logic_error, bad_alloc)
{
    Cellule * c = l._front;
    
    try
    {
        while(c != NULL)
        {
            this->push(c->data);
            c = c->next;
        }
    }
    catch(logic_error e)
    {
        throw(e);
    }
    catch(bad_alloc e)
    {
        throw(e);
    }
}
