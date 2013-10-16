#ifndef _D_LIST_H_
#define _D_LIST_H_
#include<iostream>
using namespace std;


template<class Type> class  Dlist;

template<class Type>
class Node{
            friend class Dlist<Type>;
            private:
                    Type data;
                    Node<Type>* next;
                    Node<Type>* prev;
            public:
                    Node(Type d);
                    ~Node();
 };

template<class Type>
class Dlist{
        
            public:
                   void add(Node<Type>* n);
                   Type* get_front();
                   bool Is_empty();
                   Node<Type>* pop();
                   Dlist();
                   ~Dlist();
                   
           private:
                   Node<Type>* head;
};

#endif                        
                                
     
                  
               
                  
                      


          

