/***********************************************************************
 * Header:
 *    map
 * Summary:
 *
 *    This will contain the class definition of:
 *       map             : similar to std::map
 *       map :: mapIterator : an mapIterator through the map
 * Author
 *
 ************************************************************************/



#ifndef map_H
#define map_H
#include <iostream>
#include <cassert>  // because I am paranoid
#include <string>
#include "bst.h"    // for Stack
#include "pair.h"

// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG
namespace custom{
    
/************************************************
 * map
 * A class that holds stuff
 ***********************************************/
template <class T1, class T2>
class map
{
private:
    BST<pair<T1, T2> > data;
    
public:
    
    //Constructor
    map() {
        
    }
    
    //Copy Constructor
    map(const map <T1, T2> & rhs)        throw (const char *) {
    
    }
    
    //Destructor
    ~map() {}
    
    //operator=
    map & operator = (const map & rhs) throw (const char *) {
    
        
        return * this;
    }
    
    //empty()
    bool empty() {
        return true;
    }
    
    //size()
    int  size()     const {
        return data.size();
    }
    
    //clear()
    void clear() {
        
    }
    
    //insert()
    void insert(const T1 & t, T2)  throw(const char *) { //???
        
    }
    
    class iterator {
        
    };
    
    //find()
    iterator find(T1 t) {
    
    }
    
    //begin()
    iterator begin() {
        return iterator (NULL) ;
    }
    
    //end()
    iterator end() {
        return iterator (NULL) ;
    }
    
    
    
    
};

};//ending namespace custom
#endif // map_H





