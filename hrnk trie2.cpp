#include <bits/stdc++.h>
using namespace std;
struct node
{
    int leaf;
    struct node* ptrs[10];
};

struct node* initial()
{
    struct node*  tmp = (struct node*)malloc(sizeof(struct node));

    tmp->leaf = 0;
    for(int i=0;i<10;i++)
        tmp->ptrs[i] = 0;

    return tmp;
}

int main()
{
    int i,j,n,kn,len,index,flag,flagm = 0;
    char s[65],str[65];
    scanf("%d",&n);

    struct node *root,*ptr;
    root = initial();

    while(n--)
    {
        scanf("%s",s);

        if(flagm == 0)
        {
            len = strlen(s);
            ptr = root;
            flag = 0;

            for(i=0;i<len;i++)
            {
                index = (int)s[i] -(int)'a';

                if(ptr->ptrs[index] == NULL)
                {
                    flag = 1;
                    ptr->ptrs[index] = initial();
                }

                ptr = ptr->ptrs[index];

                if(ptr->leaf == 1)
                {
                    strcpy(str,s);
                    flagm = 1;
                    break;
                }
            }

            if(flagm == 0 && flag == 0)
            {
                flagm = 1;
                strcpy(str,s);
            }

            ptr->leaf = 1;
        }
    }

    if(flagm == 1)
    {
        printf("BAD SET\n");
        printf("%s",str);
    }
    else
        printf("GOOD SET");

    return 0;
}
