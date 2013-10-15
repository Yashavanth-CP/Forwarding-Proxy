#include<iostream>
#include "Buffer_pool.h"
#include "Buffer.h"

extern Buffer_pool* mem_pool;
using namespace std;

 
Buffer::Buffer(){
                 this->buf = new char[INIT_SIZE];
                 assert(this->buf != NULL);
                 this->begin = this->buf;
                 this->tail = this->buf;
               }
              
Buffer::~Buffer(){ 
                //  std::cout<< "Adding back in destructor " << std::endl;
                  mem_pool->ret_buffer(this);
               }
