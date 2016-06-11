#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fp(i,s,e) for(i=s;i<=e;i++)
#define fm(i,s,e) for(i=e;i>=s;i--)

struct node
{
    int leaf;
    struct node* ptrs[26];
};

struct node* initialize()
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    int  i;
    tmp->leaf = 0;

    fp(i,0,25)
        tmp->ptrs[i] = NULL;

    return tmp;
}

int del(struct node **root, string s,int ind)
{
    if(ind == s.length())
        return 2;

    struct node *ptr = *(root),*par;
    int len = s.length(),j,index,flag;
    index = (int)s[ind] - (int)'a';

    if(ptr->ptrs[index] == NULL)
    {
        flag = 0;
        printf("String not found\n");
        return 0;
    }
    else
        flag = del(&ptr->ptrs[index],s,ind+1);

    if(flag >= 1)
    {
        if(flag == 2)
        {
            if(ptr->leaf == 1)
            {
                ptr->leaf = 0;
                int cnt = 0;

                for(int k=0;k<26;k++)
                    if(ptr->ptrs[index]->ptrs[k] != NULL)
                        cnt++;

                if(cnt == 0)
                {
                    ptr->ptrs[index] = NULL;
                    return 1;
                }
                else
                    return 0;
            }
            else
            {
                printf("string not found\n");
                return 0;
            }
        }
        else if(flag == 1)
        {
            int cnt = 0;
            for(int k=0;k<26;k++)
                if(ptr->ptrs[index]->ptrs[k] != NULL)
                    cnt++;

            if(cnt == 0)
            {
                ptr->ptrs[index] = NULL;
                return 1;
            }
            else
                return 0;
        }
    }
}



int main()
{
    int n,i,len,flag,j,k,index;
    string s;
    scanf("%d",&n);

    struct node *root,*ptr,*par;
    root = initialize();

    fp(i,0,n-1)
    {
        cin>>s;
        len = s.length();
        ptr = root;
        fp(j,0,len-1)
        {
            index = (int)s[j] - (int)'a';

            if(ptr->ptrs[index] == NULL)
                ptr->ptrs[index] = initialize();

            par = ptr;
            ptr = ptr->ptrs[index];
        }

        par->leaf = 1;
    }

    scanf("%d",&n);

    fp(i,0,n-1)
    {
        cin>>s;
        len = s.length();

        ptr = root;
        flag = 0;
        fp(j,0,len-1)
        {
            index = (int)s[j] - (int)'a';

            if(ptr->ptrs[index] == NULL)
                break;

            par = ptr;
            ptr = ptr->ptrs[index];
        }

        if((j == len) && (par->leaf == 1))
            cout<<"The string is present\n";
        else
            cout<<"The string not present\n";
    }

    cin>>s;

    int bul = del(&root,s,0);

    if(bul == 1)
        printf("string deleted\n");
    else
        printf("String not deleted\n");

    cin>>s;
    len = s.length();

    ptr = root;
    flag = 0;
    fp(j,0,len-1)
    {
        index = (int)s[j] - (int)'a';

        if(ptr->ptrs[index] == NULL)
            break;

        par = ptr;
        ptr = ptr->ptrs[index];
    }

    if((j == len) && (par->leaf == 1))
        cout<<"The string is present\n";
    else
        cout<<"The string not present\n";

return 0;
}

/*
4
batman
batwing
batkid
batwoman
3
*/
