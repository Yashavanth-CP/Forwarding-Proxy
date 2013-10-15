#include<iostream>
#include<sstream>
#include"Server.h"
#include"Parser.h"
#include<assert.h>
#include<fstream>
#define CONNS_MAX 65536
#define CONNS_MIN 1
#define PORT_MAX 65536
#define PORT_MIN 10
#define DEFAULT_CONNS 1024
using namespace std;
extern string logfile;
extern int proxy_conns;

Parser::Parser(string path){
          
           this->conf_path = path;
           try{
                if(this->conf_path.empty()){
                   throw " Configuration path is null ";
                   }
                else{
                     this->file.open(this->conf_path.c_str(), std::fstream::in);
                     if(!this->file.is_open()){
                           std::cout<<"Config file  " << this->conf_path << " cannot be opened " << std::endl;
                       }
              }          
            }
          catch(string str) {
                       std::cout <<" Exception: " << str << std::endl;
           }
       }

Parser::~Parser(){
 
           this->file.close();
 }

void Parser::init(std::vector<Server*>* srv_list){
//void  Parser::init(){
            assert(this->file.is_open());  
            assert(srv_list != NULL); 
            string line;
            std::vector<string> tokens;
            string server("server");
            string port("port");
            string conns("conns");
            string Log_path("Log_path");
            string Max_conns("Max_conns");
            string closing("};");
            bool srv_blk = false;
            
            string srv_name;
            int  srv_port=0;
            int  srv_conns = DEFAULT_CONNS;
            
            while(getline(this->file, line)){

                  if(*line.c_str() != '#' && !line.empty()) { 
                     get_tokens(line, &tokens);
                     std::vector<string>::iterator i = tokens.begin();
                     if(tokens.size() > 0 )
                        {  
                           
  //                        for(std::vector<string>::iterator i = tokens.begin() ; i != tokens.end() ;i++)
//                              std::cout<< *i << std::endl; 
 
                           if(*i == server && srv_blk == false){
                              srv_blk = true;
                              i++;
                              string temp = *i;    
                              if(temp.at(temp.size()-1) != '{')
                                 std::cout<<" error in config file : No opening brace "<<std::endl;
                                 temp.erase(temp.size()-1);
                                 std::size_t found;
     				 found = temp.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    				if(found != std::string::npos){
        		           std::cout<<" Server name is invalid" <<std::endl;
                                   goto clear;
                                   }
                                 srv_name = temp;
//                                 std::cout<<" Server: " << srv_name << std::endl; 
                                 goto end; 
                             }                              
                                            
                           if(*i == port && srv_blk == true){
  //                             std::cout<<" Inside port block" << std::endl;
                               i++;
                                string temp = *i;
                              if(temp.at(temp.size()-1) != ';')
                                 std::cout<<" error in config file : No opening brace "<<std::endl;
                                 temp.erase(temp.size()-1);
                                 srv_port = std::atoi(temp.c_str());
  //                               std::cout<<" Port: " << srv_port << std::endl; 
                               if(srv_port <PORT_MIN && srv_port > PORT_MAX){
                                  std::cout<<" Invalid port "<< std::endl;
                                  goto clear;
                                 }
                                goto end;  
                               }
                          
                           if(*i == conns && srv_blk ==true){
//                              std::cout<<" Inside conns block" <<std::endl;
                                i++;
                                string temp = *i;
                                if(temp.at(temp.size()-1) != ';')
                                 std::cout<<" error in config file : No opening brace "<<std::endl;
                                 temp.erase(temp.size()-1);
                                 srv_conns = std::atoi(temp.c_str());
                               //  std::cout<<" Conns:" << srv_conns <<std::endl;
                               if(srv_conns < CONNS_MIN && srv_conns > CONNS_MAX){
                                  std::cout<<" Invalid number of connections" << std::endl;
                                  goto clear;
                                  }
                                  goto end;
                               }
                           if(*i == closing && srv_blk == true){
                               srv_blk = false; 
                               if(srv_name.empty() || srv_port ==0){
                                  std::cout<<" Invalid server block : name and port are mandatory " << std::endl;
                                  goto clear;
                                  }
                                 Server* toAdd = new Server(srv_name, srv_port, srv_conns);
                                 srv_list->push_back(toAdd); 
                               /*create the server object */
      //                         std::cout <<" Server object has to be created " << std::endl;
                               srv_name.clear();
                               srv_port = 0;
                               srv_conns = DEFAULT_CONNS;
                               goto end;
                              } 
               

                           if(*i == Log_path && srv_blk == false){
                               //std::cout << "Found" << Log_path << "in " << *i << std::endl;
                               i++;
                               string temp = *i;
                              if(temp.at(temp.size()-1) != ';'){
                                 std::cout<<" error in config file : Not ended with semicolon "<<std::endl;
                                 goto clear; 
                                 }
                                 temp.erase(temp.size()-1);
                                 logfile= temp;
                 //                std::cout<<"Path of the log file is: " << temp <<std::endl;
                                 goto end;
                              }  
         
                           if(*i == Max_conns && srv_blk ==false){
                               //std::cout << "Found" << Max_conns << "in " << *i << std::endl;
                               i++;
                               string temp = *i;
                              if(temp.at(temp.size()-1) != ';'){
                                 std::cout<<" error in config file : Not ended with semicolon "<<std::endl;
                                 goto clear;
                                 }
                                 temp.erase(temp.size()-1);
        //                         std::cout<<" Maximum Connections are: " << temp <<std::endl;
                                 proxy_conns = std::atoi(temp.c_str());
                               if(proxy_conns < CONNS_MIN && proxy_conns > CONNS_MAX) {
                                  std::cout<<" Invalid number of connections" << std::endl;
                                  goto clear; 
                                  }
                                  goto end;
                              }
                            std::cout<< "invalid entry "  << *i <<std::endl;
                            goto clear;
                            /* if reached here -- then invalid entry in the config file  */
                           end:
                           tokens.clear(); 
                      }

              }
         }
      return; 
      clear:
             std::cout<< "Error in log file :Clean up initiated " <<std::endl;
             for(std::vector<Server*>::iterator it = srv_list->begin(); it != srv_list->end() ; it++)
                  delete(*it);
      return;
 
}
            
 
void Parser::get_tokens(string line, std::vector<string>* tokens) {
    std::stringstream ss(line);
    std::string item;

    while(std::getline(ss,item,':')) {
        trim(&item);
        tokens->push_back(item);
    }
}
 
void Parser::trim(string *str) {

string::size_type pos = str->find_last_not_of(' ');

    if(std::string::npos != pos )
        str->erase(pos+1,str->length()-pos);

    pos = str->find_first_not_of(' ');
    if(pos != std::string::npos)
        str->erase(0,pos);

}

