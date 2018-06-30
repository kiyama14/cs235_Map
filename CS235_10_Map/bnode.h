//
//  Node.cpp
//  CS235_07_List
//
//  Created by Mauricio Takashi Kiyama on 6/1/18.
//  Copyright © 2018 Marcio Kazuo Kiyama. All rights reserved.
//

#include <stdio.h>

template <class T>
class BNode {
        
public:
    T data;
    BNode<T>* pLeft;
    BNode<T>* pRight;
    BNode<T>* pParent;
    bool isRed;
    
    // default constructor
    BNode() : data(T()), pLeft(NULL), pRight(NULL), pParent(NULL), isRed(true) {}
        
    //non-default constructor
    BNode(T nData): pLeft(NULL), pRight(NULL), pParent(NULL), isRed(true) {
        data = nData;
    }
  
    
    void addLeft(BNode<T>* pNode)
    {
       pLeft = pNode;
       
       if(pNode != NULL)
         pLeft->pParent = this;
    }
    
    void addRight(BNode<T> * pNode)
    {
       pRight = pNode;
       
       if(pNode != NULL)
         pRight->pParent = this;
    }
    
    
    void addLeft(const T & t) throw(const char *)
    {
       try
       {
          pLeft = new BNode<T>;
          
          pLeft->data = t;
          
          pLeft->pParent = this;
       }
       catch (std::bad_alloc)
       {
          throw "ERROR STUFF";
       }
    }
    
     void addRight(const T & t) throw(const char *)
    {
       try
       {
          pRight = new BNode<T>;
          
          pRight->data = t;
          
          pRight->pParent = this;
       }
       catch (std::bad_alloc)
       {
          throw "ERROR STUFF";
       }
    }
    
      
    BNode<T>* Rcopy(BNode<T>* rhs , BNode<T>* parent = NULL)
    {
       if(rhs== NULL)
       return NULL;
       
       else
       {
          BNode<T> * newNode = new BNode<T>(rhs->data);
          
          newNode->addLeft(Rcopy(rhs->pLeft, newNode));
          
          newNode->addRight(Rcopy(rhs->pRight, newNode));
          
          return newNode;
       }
    } 
    
    
    //verifyRB(depth: integer)
    
    //verifyBST
    
    void balance()
    {

       if(pParent != NULL)
       {
           if(!pParent->isRed)
           {
             isRed = true;
           }
       
       
          if(pParent->pParent != NULL)  
          {
                 if((pParent->pParent->pLeft != NULL)&&(pParent->pParent->pRight != NULL))
                 {
                     if((pParent->pParent->pLeft->isRed) &&(pParent->pParent->pRight->isRed) && (!pParent->pParent->isRed))
                     {
                        isRed = true;
                        pParent->pParent->pLeft->isRed = false;
                        pParent->pParent->pRight->isRed = false; 
                        pParent->pParent->isRed = true;
                     }
                 }
          }
       }    
    }
    
    
};
