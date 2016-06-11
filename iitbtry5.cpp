#include <iostream>
#include<cstdio>
using namespace std;

int main(){
  FILE *fp;
  int d= 0;
  fp = fopen("file.txt", "r");
  if (fp == NULL)
    cout<<"File not found";
  else{
    fseek(fp, 0, 2);
    d = ftell(fp);
    fclose(fp);
  }
  return 0;
}
