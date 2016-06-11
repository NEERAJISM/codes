#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAX 100
#define NIL -1
int  n;
struct edge
{
 int u;
 int v;
 int weight;
 struct edge *link;
}*front=NULL;

int isempty()
{
 if(front==NULL)
  return 1;
 else
  return 0;
}

void insert_sorted(int i,int j,int wt)
{
 struct edge *temp,*q;
 temp=(struct edge *)malloc(sizeof(struct edge));
 temp->u=i;
 temp->v=j;
 temp->weight=wt;
 if(front==NULL || temp->weight<front->weight)
 {
  temp->link=front;
  front=temp;
 }
 else
 {
  q=front;
  while(q->link!=NULL && q->link->weight<=temp->weight)
    q=q->link;
  temp->link=q->link;
  q->link=temp;
  if(q->link==NULL)
    temp->link=NULL;
 }
}

struct edge *delete_q()
{
 struct edge *temp;
 temp=front;
 front=front->link;
 return temp;
}

create_graph(int n)
{
 int dest,origin,i,max_edge,wt;

 max_edge=n*(n-1)/2;
 for(i=1;i<=max_edge;i++)
 {
  printf("Enter edge %d(-1 -1 for exit)",i);
  scanf("%d%d",&origin,&dest);
  scanf("%d",&wt);
  if(origin==-1 && dest==-1)
   break;
  if(origin>=n ||origin<0 || dest>=n || dest<0)
  {
   printf("wrong origin or destination\n");
   i--;
  }
  else
   insert_sorted(origin,dest,wt);
 }
}

display_link_list()
{
 struct edge *q=front;
 while(q!=NULL)
 {
  printf("%d--%d   %d\n",q->u,q->v,q->weight);
  q=q->link;
 }
 printf("\n\n");
}

void maketree(int tree[MAX][4],int n)
{
 struct edge *temp;
 int v1,v2,v1_root,v2_root;
 int i,count=0;
 int father[MAX];

 for(i=0;i<n;i++)
 {
  father[i]=NIL;

 }
 while(!isempty() && count<n-1)
 {

  temp=delete_q();
  v1=temp->u;
  v2=temp->v;
  while(v1!=NIL)
  {
   v1_root=v1;
   v1=father[v1];
  }
  while(v2!=NIL)
  {
   v2_root=v2;
   v2=father[v2];
  }
  if(v1_root!=v2_root)
  {
   count++;
   tree[count][1]=temp->u;
   tree[count][2]=temp->v;
   tree[count][3]=temp->weight;
   father[v2_root]=v1_root;
  }

 }
 if(count<n-1)
 {
  printf("graph incomplete,no spaning tree possible\n");
  exit(1);
 }

}

int main()
{
 int n,i,wt_of_tree=0;
 int tree[MAX][4]={0};
 printf("Enter no of vertices\n");
 scanf("%d",&n);
 create_graph(n);
 display_link_list();
 maketree(tree,n);
 printf("The path of spanning tree is:\n");
 for(i=1;i<=n-1;i++)
 {
  printf("%d->",tree[i][1]);
  printf("%d \n",tree[i][2]);
  wt_of_tree = wt_of_tree+tree[i][3];
 }
 printf("\nThe weight of minimum spanning tree is %d",wt_of_tree);
 return 0;

}


