#ifndef _BUFFER_POOL_H
#define _BUFFER_POOL_H
#include "Buffer.h"
#include<iostream>
#include<list>

using namespace std;

/* This file is an implementation of the object-pool pattren for 
   maintaining a pool of buffers, this avoids the cost of creating
   a new buffer for every new connection  */

/* TODO -- needs to be shared among multiple threads.  */
class Buffer;
class Buffer_pool{

                  public:
                         static Buffer_pool* get_pool();/* Should be singelton */   
                         Buffer*  get_buffer();
                         void     ret_buffer(Buffer*);
                         ~Buffer_pool();
                  private:
                         Buffer_pool();
                         static Buffer_pool* instance;
                         std::list<Buffer*> pool;
};

#endif
