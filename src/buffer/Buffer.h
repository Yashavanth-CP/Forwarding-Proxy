#ifndef _BUFFER_H_
#define _BUFFER_H_
#include<iostream>
#include<assert.h>
#include"Buffer_pool.h"
using namespace std;
#define INIT_SIZE 1024*1024

class Buffer{
             friend class Buffer_pool; 
             public:
                    int get_capacity(){ };//return this->capacity; };
                    int Is_empty(){ };//return (this->size == 0); };
                    int Is_full(){ };// return (this->size == this->capacity); };
                    int get_size(){ };//return this->size;};
                    ~Buffer();
             private:
                    int size, capacity;
                    char* buf;char* begin; char* tail; 
                    Buffer();

};
#endif

                     
