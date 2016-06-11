#include <bits/stdc++.h>
using namespace std;
typedef struct {
    char s1[5];
}hop;

typedef struct {
    char s2[5];
}output;

void copystring(hop* hoparray1,output* outputarray)
{
    hop* ptr1 = hoparray1;
    output* ptr2 = outputarray;
    for(int i=0;i<3;i++)
    {
        strcpy(ptr2[i]->s2,ptr1[i]->s1);
        /*ptr2++;
        ptr1++;*/
    }

    ptr2= outputarray;
    for(int i=0;i<3;i++)
    {
        cout<<ptr2->s2<<endl;
        ptr2++;
    }
}

int main()
{
    int groupsize;
    cin>>groupsize;
    hop* hoparray =(hop*)malloc(groupsize*sizeof(hop));
    output* outputarray = (output*)malloc(groupsize*sizeof(output));

    hop* ptr = hoparray;0
    for(int i=0;i<groupsize;i++)
    {
        cin>>ptr->s1;
        ptr++;
    }
    ptr= hoparray;

    copystring(hoparray,outputarray);
return 0;
}
