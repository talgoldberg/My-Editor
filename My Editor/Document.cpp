#include "Document.h"
using namespace std;


bool Document::isnumber(string str)
{
        for(int i=0; i<str.length(); i++)
        {
            if(isdigit(str[i])==false)
                return false;
        } 


        return true;
        
}


bool Document::isnumber_from_index(string str)
{
    for(int i=1; i<str.length(); i++)
        {
            if(isdigit(str[i])==false)
                return false;
        }

        return true;
}

bool Document::istxtfile(string str)
{
   
    if(str.find(".txt")!= string::npos)
    return true;

    return false;

}



void Document::function_comands()
{
    int index=1;
    string line; 
    string comand;
    string ans;
    vector<string> help;


    while(getline(cin,comand))
    {
        
      
        if(comand.size()==1 && isnumber(comand))
        {
            index=stoi(comand);
            
        }

        if(comand.size()>=2 && (comand[0]=='+'|| comand[0]=='-') && isnumber_from_index(comand))
        {
            if(comand[0]=='+')
             index+=stoi(comand);
            if(comand[0]=='-')
             index+=stoi(comand);
        }

        if((index>vec.size() && !vec.empty()) || (index>1 && vec.empty()))
        {
            if(index>vec.size() && !vec.empty())
            {
                index=vec.size();
            }
            else 
            {
                index=1;
            }
            
        }


        
        if(comand=="a")
        {   
            while(getline(cin,ans))
            {   
                if(ans==".")
                    break;
               
                help.push_back(ans);
                
            }
            if(vec.empty())
            {
                vec.insert(vec.begin()+index-1,help.begin(),help.end());
                index=index-1+help.size();    
            }
            else 
            {
                vec.insert(vec.begin()+index,help.begin(),help.end());
                index=index+help.size();
            }
            

            help.clear();
            ans.clear();
            
        }

        if(comand=="i")
        {
            while(getline(cin,ans))
            {   
    
                if(ans==".")
                    break;
               
                help.push_back(ans);
                
            }

            vec.insert(vec.begin()+index-1,help.begin(),help.end());
            index=index-1+help.size();
            help.clear();
            ans.clear();
        }
        
        if(comand=="$")
        {
            index=vec.size();
        }
        
        if(comand=="c")
        {
            while(getline(cin,ans))
            {   
    
                if(ans==".")
                    break;
               
                help.push_back(ans);
                
            }
            vec[index-1]=help[0];
            help.erase(help.begin()); 
            if(!help.empty())
                vec.insert(vec.begin()+index,help.begin(),help.end());
            

            index=index+help.size();
            help.clear();
            ans.clear(); 

        }
        
        if(comand=="d")
        {
            vec.erase(vec.begin()+index-1);
            index=index-1;
        }
        
        if(comand[0]=='/' && comand[comand.size()-1]=='/')
        {
            bool round2=true;
            string cheack; 
            for(int i=1; i<=comand.size()-2; i++)
                cheack+=comand[i];
            
            if(!cheack.empty())
            {
                for(int i=index; i<vec.size(); i++)
                {
                    if(vec[i].find(cheack)!=string::npos)
                    {
                        index=i+1;
                        round2=false;
                         break;
                    }
                          
                }

                if(round2)
                {
                    for(int i=0; i<index; i++)
                    {
                        if(vec[i].find(cheack)!=string::npos)
                        {
                            index=i+1;
                            break;
                        }
                          
                     }
                }

                cheack.clear();
            }

        }

        if(comand[0]=='s' && comand[1]=='/' && comand[comand.size()-1]=='/')
        {
            int indexfornewstring;
            string sold; 
            string snew;
           
            
                for(int i=2; i<comand.size(); i++)
                {
                    
                    if(comand[i]=='/')
                    {
                        indexfornewstring=i;
                        break;
                    }
                    
                    
                    if(comand[i]!='/')
                        sold+=comand[i];
                }

                for(int i=indexfornewstring+1; i<comand.size(); i++)
                {
                    if(comand[i]!='/')
                        snew+=comand[i];
                }
                
                size_t found=vec[index-1].find(sold);
                if(found!= string::npos)
                    vec[index-1].replace(found,sold.size(),snew);

                sold.clear();
                snew.clear();

            
        }

        if(comand=="j")
        {
            vec[index-1]+=vec[index];
            vec.erase(vec.begin()+index);
        }

        if(comand[0]=='w' && istxtfile(comand))
        {
             
            string txt=comand.substr(2,comand.size()-1);
            ofstream newfile(txt);

            for(int i=0; i<vec.size(); i++)
                newfile<<vec[i]<<'\n';

            newfile.close();

        }

        if(comand=="q")
            break;
        
       
    }
}

void Document::editor_for_empty_file()
{
   
    function_comands();   

    
}

void Document::editor()
{
    string line;
    ifstream f(file);

    while (getline(f,line))
    {
        vec.push_back(line);
        
    }

    f.close();

    function_comands();

}
