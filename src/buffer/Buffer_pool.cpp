#include<iostream>
#include "Buffer_pool.h"
#include"Buffer.h"
#include<mutex>
using namespace std;

std::mutex pool_s;
std::mutex ele;
Buffer_pool* Buffer_pool::instance = 0;
Buffer_pool* Buffer_pool::get_pool(){
              /* Needs to be tested in multithreading scenario */               
               pool_s.lock(); 
               if(Buffer_pool::instance == NULL) 
                  {
                     Buffer_pool::instance = new Buffer_pool();
                     std::cout<<" New Buffer pool created  "<< std::endl;
                  }
               else{
                     std::cout<<"Moron this is singleton  " << std::endl;
                    }
               pool_s.unlock();
               return Buffer_pool::instance;

}


Buffer_pool::Buffer_pool(){};
Buffer* Buffer_pool::get_buffer(){
                
               ele.lock(); 
                Buffer* toRet;
                if(!this->pool.empty()){
                   toRet = pool.front();
                   pool.pop_front();
                   std::cout<<" Given Buffer from the pool: " << toRet <<std::endl;
                  }
                else{
                   toRet = new Buffer();
                   std::cout<<" Created a new buffer"<< toRet << std::endl;
                   }
                ele.unlock();
                return toRet;
}

void  Buffer_pool::ret_buffer(Buffer* toAdd){
                assert(toAdd != NULL); 
                this->pool.push_back(toAdd);
                std::cout<<" Added back to the pool " << toAdd << std::endl;
 }
                                 
Buffer_pool::~Buffer_pool(){
              std::cout<< " Pool destructor called Size: " << pool.size()<< std::endl;
              Buffer* toDel;
              while(!pool.empty()){
      
                    toDel = this->pool.front();
                     std::cout<<" Deleting in pool " << toDel <<std::endl;
                    assert(toDel!= NULL);
                    this->pool.pop_front();
                    delete(toDel->buf);
                    std::cout<< " Deleteing the Buffer in pool "<< std::endl;
                  }

 }


 
               
