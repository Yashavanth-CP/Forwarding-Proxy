#ifndef _SERVER_H_
#define _SERVER_H_
#include<iostream>
using namespace std;

class Server{
             
             private:
                     string name;
                     int port;
                     int conn;
                     
             public: 
                     Server(string srv, int prt, int ctns):name(srv), port(prt), conn(ctns){};
                     friend class Config;
                     friend std::ostream& operator<<(std::ostream&, Server* s);
                     string get_name();
                     int get_port( );
                     int get_conns();
};

#endif
