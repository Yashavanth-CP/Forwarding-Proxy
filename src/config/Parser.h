#ifndef _PARSER_H_
#define _PARSER_H_
#include<fstream>
#include "Server.h"
#include<vector>
using namespace std;
/* make the config file path to be given , during compilation */
class Parser{
 
             private: 
                    string conf_path;
                    fstream file;
             public:
                  // std::vector<Server *> init();
                   void init(std::vector<Server*>* s_list );
                   Parser(string path);
                   void get_tokens(string s, std::vector<string> * t);
                   void trim(std::string*);
                   ~Parser();
};

#endif

        
                     
