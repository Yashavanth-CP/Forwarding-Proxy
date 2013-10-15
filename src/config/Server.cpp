#include<iostream>
#include "Server.h"
using namespace std;

string Server::get_name(){
                    return this->name;
              }

int Server::get_port(){
                       return this->port;
                      }

int Server::get_conns(){
                  return this->conn;
         }

ostream& operator<<(std::ostream& os, Server* s)
         {   
            os <<"====================================" << '\n'; 
            os <<"Server Name:" <<  s->name <<'\n';
            os <<"Server Port:" <<  s->port <<'\n';
            os <<"Server Conn:" <<  s->conn <<'\n';
            return os;
       }
