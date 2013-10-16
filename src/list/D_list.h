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
                   void add(Type n);
                   Type* get_front();
                   bool Is_empty();
                   Type pop();
                   Dlist();
                   ~Dlist();
                   
           private:
                   Node<Type>* head;
};


template<class Type>
Node<Type>::Node(Type d){
                 data = d;
                 next = NULL;
                 prev = NULL;
}

template<class Type>
Node<Type>::~Node(){
 }


template<class Type>
bool Dlist<Type>::Is_empty(){
              return (head == NULL);
}

template<class Type>
Dlist<Type>::Dlist(){
                    head = NULL;
}

template<class Type>
Dlist<Type>::~Dlist(){
           Node<Type>* toDel; 
           while(head != NULL){
                 toDel = head;
                 head = head ->next;
                 if(head != NULL)
                 head->prev = NULL;
                 delete toDel;
           }

}    

template<class Type>
void Dlist<Type>::add(Type n){
                  Node<Type>* toAdd = new Node<Type>(n); 
                 if(head == NULL){
                    head = toAdd;
                    }
                 else{
                     toAdd->next = head;
                     head->prev = toAdd;
                     head = toAdd;
                   }
}

template<class Type>
Type  Dlist<Type>::pop(){
                
                if(head ==NULL)
                   return -1;
                else{
                     Node<Type>* toRet = head;
                     head = head->next;
                     if(head != NULL)
                        head->prev = NULL;
                     toRet->next = NULL;
                     return toRet->data;
                  }
 }

#endif                        
                                
     
                  
               
                  
                      


          

