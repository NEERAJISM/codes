//bellman ford by neeraj patidar (O(VE)
#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

// graph Edge  --> struct
// Graph

struct Edge
{
  int src,dst,wt;
};

struct graph
{
  int v, e;
  struct Edge * edge;
};


struct graph* create(int V,int E)
{
  struct graph* g =(struct graph*)malloc(sizeof(struct graph));
  g->v = V;
  g->e = E;
  g->edge = (struct Edge*)malloc(E*sizeof(struct Edge));

  return g;
}

void bellmanford(struct graph * Graph , int src)
{
    int V = Graph->v, E = Graph->e;
    int d[V],pi[V];

    for (int i = 0; i < E; ++i)
        d[i] =  INT_MAX;

    d[0] = 0;

    for (int i = 1; i < V-1 ; ++i)
    {
      for (int j = 0; j < E; ++j)
      {
          int a = Graph->edge[j].src;
          int b = Graph->edge[j].dst;
          int weight = Graph->edge[j].wt;

          if(d[a] != INT_MAX && weight + d[a] < d[b])
              d[b] =weight + d[a];
      }
    }

    for (int j = 0; j < E; ++j)
      {
          int a = Graph->edge[j].src;
          int b = Graph->edge[j].dst;
          int weight = Graph->edge[j].wt;

          if(d[a] != INT_MAX && weight + d[a] < d[b])
              cout<<"Graph contains negetive weight cycle \n";
      }


      for (int i = 0; i < V; ++i)
          cout<<i<<" "<<d[i]<<endl;

}

int main()
{
  int v1,e1;
  cin>>v1>>e1;

  struct graph* Graph = create(v1,e1);

  for(int i= 0;i<e1;i++)
  {
    cout<<"enter the source , destination, weight of "<<i+1<<" edge :";
    cin>> Graph->edge[i].src >>Graph->edge[i].dst >>Graph->edge[i].wt;
  }

  bellmanford(Graph ,0);
return 0;
}
