#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Document{

    public:
     vector<string> vec; 
     string file; 
     
     
    
     Document(){}
     Document(string s){this->file=s;}

     void editor(); 
     void editor_for_empty_file();
     void function_comands();
     bool isnumber(string);
     bool isnumber_from_index(string);
     bool istxtfile(string);

};