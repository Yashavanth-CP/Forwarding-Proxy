#include<iostream>
#include"D_list.h"
using namespace std;

template<class Type>
Node<Type>::Node(Type d){
                 data = d;
                 next = NULL;
                 prev = NULL;
}

template<class Type>
Node<Type>::~Node(){
                delete this->data;
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
void Dlist<Type>::add(Node<Type>* n){

                 if(head == NULL){
                    head = n;
                    }
                 else{
                     n->next = head;
                     head->prev = n;
                     head = n;
                   }
}

template<class Type>
Node<Type>* Dlist<Type>::pop(){
                
                if(head ==NULL)
                   return NULL;
                else{
                     Node<Type>* toRet = head;
                     head = head->next;
                     if(head != NULL)
                        head->prev = NULL;
                     toRet->next = NULL;
                     return toRet;
                  }
 }
