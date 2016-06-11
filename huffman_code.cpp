#include<bits/stdc++.h>
using namespace std;

typedef struct letter
{
    struct letter *left=0;
    char c;
    int count;
    struct letter *right=0;
}letter;

letter h[150];
int hn=0,map2[150],n[10];
letter L1[150],*first;

void inorder(letter *ptr,int p)
{
    int t;
    if(ptr->left==0)
    {
        int i;
        printf("%c ",ptr->c);
        for(i=0;i<=p;i++)
        printf("%d",n[i]);
        printf("\n");
        return;
    }

    //printf("%c=%d\n",ptr->c,ptr->count);
    //printf("left ");
    p++;
    n[p]=0;
    inorder(ptr->left,p);
    //printf("right ");
    n[p]=1;
    inorder(ptr->right,p);
}
void heapify(int n)
{
    //printf("heapify %c\n",h[n].c);
    if(n>hn)
        return;
    letter temp;
    int min1=hn;
    //printf("%c %c\n",h[2*n].c,h[2*n+1].c);
    if(2*n<hn && h[n].count>h[2*n].count)
    {
      min1 = 2*n;
    }
    if(2*n+1<hn && h[min1].count>h[2*n+1].count)
    {
        min1 = 2*n+1;
    }
    if(min1!=n)
    {
        temp = h[min1];
        h[min1] = h[n];
        h[n] = temp;
        heapify(min1);
    }
}

void makeheap(letter lt)
{
    //printf("make heap %c %d\n",lt.c,lt.count);
    letter temp;
    hn++;
    h[hn] = lt;
    //printf("%d %c\n",hn,h[hn].c);
    int n=hn;
    while(n)
    {
       // printf("%c %c\n",h[n].c,h[n/2].c);
        if(h[n].count<h[n/2].count)
        {
         //   printf("change\n");
            temp = h[n];
            h[n] = h[n/2];
            h[n/2] = temp;
        }
        n = n/2;
    }
}
void print_code(letter *ptr,int *n,int p);
void build_tree()
{
    //printf("build_tree %d\n",h[1].count);
    if(hn>1)
    {
        letter l1,l2;first = (letter*) malloc(sizeof(letter));
        l1 = h[1];
        h[1]=h[hn];
        hn--;
        heapify(1);
        l2 = h[1];
        h[1]= h[hn];
        hn--;
        heapify(1);
        //printf("l1 left=%d l1 right=%d l2 left=%d l2 right =%d\n",l1.left,l1.right,l2.left,l2.right);
        first->left = &l1;
        first->right = &l2;
        first->count = l1.count+l2.count;
        first->c = '*';
        //inorder(first);
       // printf("\n");
      //  printf("%d\n",first->count);
        makeheap(*first);
        first = 0;
        build_tree();
    }
    else
    {
        first = &h[1];
        int n[10];
        inorder(first,-1);

    }
}

int main()
{
    int len,k,i;
    letter l1;
    char c[200],l;

    l1.left = l1.right=0;
    gets(c);
    len = strlen(c);

    for(k=0;k<len;k++)
    {
        map2[c[k]] = map2[c[k]]+1;
       // printf("%c %d\n",c[k],map2[c[k]]);
    }

    for(k = 0;k <150; k++)
    {
       // printf("going to check");
        if(map2[k]!=0)
        {
            //printf("in\n");
            //printf("%c %d %d\n",k,map2[k],k);
            l1.c=k;
            l1.count=map2[k];
            makeheap(l1);
           // printf("returned safely\n");
        }
    }

    build_tree();

    letter *ptr = first;
    int n[10];
    //inorder(ptr);
    //print_code(ptr,n,-1);
}

