#include<iostream>
#include "Config.h"
#include<assert.h>
using namespace std;

Config* Config::instance = NULL;
string conf_path("/home/yash/repo/Proxy/src/Conf/config.txt");
/*no need of mutex here -- since its  used only by one thread */
Config* Config::get_instance(){
                            
                          if(Config::instance == NULL){
                             Config::instance = new Config();
                             assert(Config::instance != NULL);
                             /* Call the Parser here */
                             }
                          return Config::instance;
}

/* Hardcoded if the paths are not present */
Config::Config(): Log_path(""),Max_conns(1024){
                    
                   psr = new Parser(conf_path);
                   psr->init( &this->Servers);
                   assert(psr!= NULL);
                   
}              
                       
               

