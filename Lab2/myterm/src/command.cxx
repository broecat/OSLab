#include "command.h"
#include <iostream>
#include <boost/xpressive/xpressive.hpp>
#include <vector>
#include <sstream>
using namespace std;
using namespace boost::xpressive;
command::command()
    
    :exit_requested_(false)
    {}

bool command::is_valid_command_line(const string &line) const
{
    vector<string> res;
    istringstream ss(line);
    string temp;
    while(getline(ss,temp,' ')){res.push_back(temp);}

    
    if(res[0]=="list"&&res.size()==1){return true;}
    else if(res[0]=="show"&&res.size()==1){return true;}
    else if(res[0]=="copy"&&res.size()==3){return true;}
    else if(res[0]=="remove"&&res.size()==2){return true;}
    else if(res[0]=="now"&&res.size()==1){return true;}

    
    return false;

}
bool command::parse_line(const string &line) 
{
    this->parameters.clear();
    istringstream ss(line);
    string temp;
    while(getline(ss,temp,' ')){this->parameters.push_back(temp);}

    if(this->parameters[0]=="list"){this->parameters[0]="ls";}
    else if(this->parameters[0]=="show"){this->parameters[0]="top";}
    else if(this->parameters[0]=="copy"){this->parameters[0]="cp";}
    else if(this->parameters[0]=="remove"){this->parameters[0]="rm";;}
    else if(this->parameters[0]=="now"){this->parameters[0]="date";}
}
bool command::readline()
{
    //readLine
    string input;
    cout<<"Next Input: ";
    getline(cin,input);
    if(is_valid_command_line(input))
    {
        parse_line(input);
        return true;
    }
    return false;
}
void command::print_usage() const
{
    cout<<"Incorrect Use: Use like this!\n";
    cout<<"list\n";
    cout<<"show\n";
    cout<<"copy <file1> <file2>\n";
    cout<<"remove <file1>\n";
    cout<<"now\n";
}
void command::execute()
{
    string cmd = this->parameters[0];
    if(cmd=="exit")
    {this->exit_requested_=true;}
    else{
        const size_t array_size = this->parameters.size();
       char** arg_array = new char*[array_size+1];
       for(int i=0;i<array_size;i++)
       {
           arg_array[i] = strdup(this->parameters[i].c_str());
       }
       arg_array[array_size]=0;
       execvp(arg_array[0], arg_array);

    }
}