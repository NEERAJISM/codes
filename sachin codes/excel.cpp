#include <iostream> 
#include <fstream>
#include <string> 
using namespace std; 

int main() 
{ 
    string str;
     printf("Please input xls file name");
     cin>>str;
     ifstream ifs(str.c_str()); 
    
     if(!ifs) 
    {  cerr <<"input file name is incorrect" <<endl;   exit(1);     } 
   
     ofstream ofs("new.xls");  
      
   ofs<<ifs.rdbuf(); 
    if (!ofs) 
    {   cerr <<"error: can not open \"new.xls\" for output\n";  exit(1);}                               
      ifs.close();
    
    ofs.close();
    cout<<"copied one file!"; 
    cin.get();
     return 0; 
} 
