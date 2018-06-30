////
////  oldCode.cpp
////  CS235_10_Map
////
////  Created by Mauricio Takashi Kiyama on 6/30/18.
////  Copyright © 2018 Marcio Kazuo Kiyama. All rights reserved.
////
//
//#include <stdio.h>
//
//
///***********************************************************************
// * Header:
// *    map
// * Summary:
// *
// *    This will contain the class definition of:
// *       map             : similar to std::map
// *       map :: mapIterator : an mapIterator through the map
// * Author
// *
// ************************************************************************/
//
//
//
//#ifndef map_H
//#define map_H
//#include <iostream>
//#include <cassert>  // because I am paranoid
//#include <string>
//#include "bst.h"    // for Stack
//
//// a little helper macro to write debug code
//#ifdef NDEBUG
//#define Debug(statement)
//#else
//#define Debug(statement) statement
//#endif // !NDEBUG
//namespace custom{
//    template <class T>
//    class mapIterator;
//
//    /************************************************
//     * map
//     * A class that holds stuff
//     ***********************************************/
//    template <class T>
//    class map
//    {
//    private:
//        int numElements;
//        BNode<T> *root;
//
//    public:
//
//        //Constructor
//        map(): numElements(0), root(NULL) {}
//
//
//        //Copy Constructor
//        map(const map <T> & rhs)        throw (const char *) {
//
//            numElements = rhs.numElements;
//            this->root= this->root->Rcopy(rhs.root);
//        }
//
//
//        //Destructor
//        ~map() {}
//
//
//        //operator=
//        map & operator = (const map & rhs) throw (const char *) {
//            numElements = rhs.numElements;
//            this->root= this->root->Rcopy(rhs.root);
//            return * this;
//
//        }
//
//
//        //empty()
//        bool empty() {
//            return(!numElements);
//        }
//
//
//        //size()
//        int  size()     const { return numElements;                 }
//
//
//        //clear()
//        void clear()
//        {
//            numElements = 0;
//            root = NULL;
//        }
//
//        //getRoot()
//        BNode<T> * getRoot()
//        {
//            return root;
//        }
//
//        //insert()
//        void insert(const T & t)  throw(const char *)
//        {
//            //This is waht I will change to make this a red black binary tree
//
//            BNode<T> *tempNew = new BNode<T>;
//
//            BNode<T> *tempCurrent;
//            tempNew->data = t;
//            if(root == NULL)
//            {
//                root = tempNew;
//                tempNew->isRed = false;
//                numElements++;
//                return;
//            }
//            else
//            {
//                tempCurrent = root;
//            }
//            // remember to do less then or equal too.
//            //std::cerr << "just before loop" << std::endl;
//            while(true)
//            {
//                //   std::cerr << "inside loop in insert" << std::endl;
//                if(tempNew->data <= tempCurrent->data)
//                {
//                    if(tempCurrent->pLeft == NULL)
//                    {
//                        tempCurrent->addLeft(tempNew);
//                        tempNew->balance();
//                        root->isRed = false;
//                        break;
//                    }
//                    else
//                    {
//                        tempCurrent = tempCurrent->pLeft;
//                    }
//                }
//                else if(tempNew->data > tempCurrent->data)
//                {
//                    if(tempCurrent->pRight == NULL)
//                    {
//                        tempCurrent->addRight(tempNew);
//                        tempNew->balance();
//                        root->isRed = false;
//                        break;
//                    }
//                    else
//                    {
//                        tempCurrent = tempCurrent->pRight;
//                    }
//                }
//            }
//            numElements++;
//        }
//
//
//
//        //erase()
//        void erase(mapIterator<T> & it)
//        {
//            // std::cerr << "in erase " << std::endl;
//            BNode<T> * temp = it.getNode();
//            // std::cerr << "This is the Node to be deleted  " << temp->data << std::endl;
//
//            if((temp->pLeft == NULL) && (temp->pRight == NULL))//Node has no Children
//            {
//                //std::cerr<<"  in NO CHILDREN  "<< std::endl;
//                if(it.getNode()->pParent != NULL && it.getNode()->pParent->pLeft == it.getNode())//check which child the node is
//                {
//                    //std::cerr << "in is left child" << std::endl;
//                    //BNnode<T> *temp = it.getNode()->pParent->pLeft
//                    it.getNode()->pParent->pLeft = NULL;
//                    delete it.getNode();
//                    //it.getNode() = NULL;
//                    //std::cerr<< "Node Should BE DELETED" << std::endl;
//                    return;
//                }
//                else
//                {
//                    //std::cerr << "in is Right Child" << std::endl;
//                    it.getNode()->pParent->pRight = NULL;
//                    delete it.getNode();
//                    //it.getNode() = NULL;
//                    //std::cerr<< "Node Should BE DELETED" << std::endl;
//                    return;
//                }
//            }
//            else if(it.getNode()->pLeft == NULL || it.getNode()->pRight == NULL)//Node has one Child
//            {
//                //std::cerr << " IN NODE HAS ONE CHILD    " << std::endl;
//                if(it.getNode()->pLeft == NULL)//check which child it is
//                {
//                    //std::cerr << "this  left child   ||." << temp->pRight->data << ".||" << std::endl;
//                    it.getNode()->pRight->pParent = it.getNode()->pParent;
//                    if((it.getNode()->pParent != NULL) && (it.getNode()->pParent->pRight == it.getNode()))
//                    {
//                        it.getNode()->pParent->pRight = it.getNode()->pRight;
//                    }
//                    if((it.getNode()->pParent != NULL) && (it.getNode()->pParent->pLeft == it.getNode()))
//                    {
//                        it.getNode()->pParent->pLeft = it.getNode()->pRight;
//                    }
//                    //std::cerr<< "Node Should BE DELETED" << std::endl;
//                }
//                else
//                {
//                    /*
//                     IF (it.pRight = NULL and it.pLeft ? NULL)
//                     {
//                     it.pLeft.pParent <- it.pParent
//                     IF it.pParent ? NULL AND it.pParent.pRight = it
//                     {
//                     it.pParent.pRight <- it.pLeft
//                     }
//                     IF it.pParent ? NULL A N D it.pParent.pLeft = it
//                     {
//                     it.pParent.pLeft <- it.pLeft
//                     }
//                     }
//                     */
//                    //std::cerr << "this is right child   ||." << temp->pLeft->data <<".||"<<std::endl;
//
//                    it.getNode()->pLeft->pParent = it.getNode()->pParent;
//                    if((it.getNode()->pParent != NULL) && (it.getNode()->pParent->pRight == it.getNode()))
//                    {
//                        it.getNode()->pParent->pRight = it.getNode()->pLeft;
//                    }
//                    if((it.getNode()->pParent != NULL) && (it.getNode()->pParent->pLeft == it.getNode()))
//                    {
//                        it.getNode()->pParent->pLeft = it.getNode()->pLeft;
//                    }
//                    //std::cerr<< "Node Should BE DELETED" << std::endl;
//                }
//            }
//            else if(it.getNode()->pLeft != NULL && it.getNode()->pRight != NULL)//Node has two Children
//            {
//                //std::cerr << "IN NODE HAS TWO CHILDREN" << std::endl;
//                //std::cerr << "these are the nodes children   ||." << temp->pLeft->data <<".||    ||." << temp->pRight->data << ".||" << std::endl;
//                //this one looks hard
//                BNode<T> *tempNew = it.getNode();//Save the Position of the Node that is being Erased
//                it++;//Get the Position of the nod that is taking it's spot ie the Next highest node
//                tempNew->data = it.getNode()->data; // Move the value of the moving node to address of the node being erased.
//                //std::cerr << "this means Erase is calling erase again" << std::endl;
//                erase(it);// some where down the line this spot , which was the spot of the node that got moved up, needs to get erased
//
//            }
//
//
//            if(it.getNode() == NULL)
//                delete it.getNode();
//
//        }
//
//        //find()
//        mapIterator<T> find(T t)
//        {
//
//            BNode<T> *temp = root;
//            //std::cerr<< "in find, Root is: "<<temp->data << std::endl;
//            while(temp != NULL)
//            {
//                //std::cerr << "in find loop, Current temp is:  " << temp->data << std::endl;
//                if(temp->data == t)
//                {
//                    mapIterator<T> it = temp;
//                    return it;
//                }
//                if(temp->data > t)
//                {
//                    //   std::cerr << "went left" << std::endl;
//                    temp = temp->pLeft;
//                }
//                else if(temp->data < t)
//                {
//                    //  std::cerr << "went right" << std::endl;
//                    temp = temp->pRight;
//                }
//            }
//            return end();
//        }
//
//        //begin(): mapIterator
//        mapIterator <T> begin() const {
//            Stack < BNode <T> * > nodes;
//
//            nodes.push(NULL);
//            nodes.push(root);
//            while (nodes.top() != NULL && nodes.top()->pLeft)
//                nodes.push(nodes.top()->pLeft);
//
//            return mapIterator<T>(nodes);
//
//        }
//
//        //end()
//        mapIterator <T> end() const  { return mapIterator <T> (NULL) ; }
//
//        //rbegin()
//
//        mapIterator <T> rbegin() const
//        {
//            Stack < BNode <T> * > nodes;
//
//            nodes.push(NULL);
//            nodes.push(root);
//            while (nodes.top() != NULL && nodes.top()->pRight)
//                nodes.push(nodes.top()->pRight);
//            return mapIterator<T>(nodes);
//
//        }
//
//        //rend()
//        mapIterator <T> rend() const  { return mapIterator <T> (NULL); }
//
//
//    };
//    //.....................................................................END OF map............................................................
//    //..........................................................................mapIterator........................................................
//    template <class T>
//    class mapIterator
//    {
//    public:
//        // constructors
//        mapIterator(BNode <T> * p = NULL)    { nodes.push(p);  }
//
//        mapIterator(Stack < BNode <T> *> & s) { nodes = s;         }
//
//        mapIterator(const mapIterator <T> & rhs)  {
//            nodes = rhs.nodes;
//
//        }
//
//        // assignment
//        mapIterator <T> & operator = (const mapIterator <T> & rhs) {
//            // need an assignment operator for the Stack class.
//            nodes = rhs.nodes;
//            return *this;
//        }
//
//        // compare
//        bool operator == (const mapIterator <T> & rhs) const
//        {
//            // only need to compare the leaf node
//            return rhs.nodes.const_top() == nodes.const_top();
//        }
//        bool operator != (const mapIterator <T> & rhs) const
//        {
//            // only need to compare the leaf node
//            return rhs.nodes.const_top() != nodes.const_top();
//        }
//
//        // de-reference. Cannot change because it will invalidate the map
//        T & operator * ()
//        {
//            return nodes.top()->data;
//        }
//
//        // mapIterators
//        mapIterator <T> & operator ++ () {
//            // do nothing if we have nothing
//            if (nodes.top() == NULL)
//                return *this;
//
//            // if there is a right node, take it
//            if (nodes.top()->pRight != NULL)
//            {
//                nodes.push(nodes.top()->pRight);
//
//                // there might be more left-most children
//                while (nodes.top()->pLeft)
//                    nodes.push(nodes.top()->pLeft);
//                return *this;
//            }
//
//            // there are no right children, the left are done
//            assert(nodes.top()->pRight == NULL);
//            BNode <T> * pSave = nodes.top();
//            nodes.pop();
//
//            // if the parent is the NULL, we are done!
//            if (NULL == nodes.top())
//                return *this;
//
//            // if we are the left-child, got to the parent.
//            if (pSave == nodes.top()->pLeft)
//                return *this;
//
//            // we are the right-child, go up as long as we are the right child!
//            while (nodes.top() != NULL && pSave == nodes.top()->pRight)
//            {
//                pSave = nodes.top();
//                nodes.pop();
//            }
//
//            return *this;
//
//        }
//
//        mapIterator <T>   operator ++ (int postfix) {
//            mapIterator <T> itReturn = *this;
//            ++(*this);
//            return itReturn;
//        }
//
//        mapIterator <T> & operator -- () {
//            // do nothing if we have nothing
//            if (nodes.top() == NULL)
//                return *this;
//
//            // if there is a left node, take it
//            if (nodes.top()->pLeft != NULL)
//            {
//                nodes.push(nodes.top()->pLeft);
//
//                // there might be more right-most children
//                while (nodes.top()->pRight)
//                    nodes.push(nodes.top()->pRight);
//                return *this;
//            }
//
//            // there are no left children, the right are done
//            assert(nodes.top()->pLeft == NULL);
//            BNode <T> * pSave = nodes.top();
//            nodes.pop();
//
//            // if the parent is the NULL, we are done!
//            if (NULL == nodes.top())
//                return *this;
//
//            // if we are the right-child, got to the parent.
//            if (pSave == nodes.top()->pRight)
//                return *this;
//
//            // we are the left-child, go up as long as we are the left child!
//            while (nodes.top() != NULL && pSave == nodes.top()->pLeft)
//            {
//                pSave = nodes.top();
//                nodes.pop();
//            }
//
//            return *this;
//        }
//
//        mapIterator <T>   operator -- (int postfix) {
//            mapIterator <T> itReturn = *this;
//            --(*this);
//            return itReturn;
//        }
//
//        // must give friend status to remove so it can call getNode() from it
//        friend void map <T> :: erase(mapIterator <T> & it);
//    private:
//
//        // get the node pointer
//        BNode <T> * getNode() { return nodes.top(); }
//
//        // the stack of nodes
//        Stack < BNode <T> * > nodes;
//    };
//
//};//ending namespace custom
//#endif // map_H
//
//
//
//
//
