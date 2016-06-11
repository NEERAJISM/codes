#include <bits/stdc++.h>
using namespace std;
struct node
{
    int cnt;
    struct node* ptrs[26];
};

struct node* initial()
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));

    tmp->cnt = 0;
    for(int i=0 ;i<26;i++)
        tmp->ptrs[i] = NULL;

    return tmp;
}

int main()
{
    int i,j,k,n,m,len,index;
    char t[10],a[30];
    scanf("%d",&n);
    struct node *root,*ptr;
    root = initial();

    while(n--)
    {
        scanf("%s",t);
        scanf("%s",a);
        if(strlen(t) == 3)
        {
            ptr = root;
            len = strlen(a);
            for(i=0;i<len;i++)
            {
                index = (int)a[i] - (int)'a';
                if(ptr->ptrs[index] == NULL)
                    ptr->ptrs[index] = initial();

                ptr->ptrs[index]->cnt+=1;
                ptr = ptr->ptrs[index];
            }
        }
        else
        {
            ptr = root;
            len = strlen(a);
            for(i=0;i<len;i++)
            {
                index = (int)a[i] - (int)'a';
                if(ptr->ptrs[index] == NULL)
                    break;

                ptr = ptr->ptrs[index];
            }

            if(i == len)
                printf("%d\n",ptr->cnt);
            else
                printf("0\n");
        }
    }
    return 0;
}
