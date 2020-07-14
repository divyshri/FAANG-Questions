#include<bits/stdc++.h>

using namespace std;

#define inf 9999
int v;
void display(int dis[][100])
{
    cout<<"Shortest Distance is:"<<endl;

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(dis[i][j]==inf)
                cout<<"inf"<<" ";
            else
                cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
}

void floyd(int graph[][100])
{
    int dis[v][100],i,j,k;

    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            dis[i][j]=graph[i][j];

    for(k=0;k<v;k++)
    {
        for(i=0;i<v;i++)
        {
            for(j=0;j<v;j++)
            {
                if(dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
            }
        }
    }
    display(dis);
}

int main()
{
   cout<<"enter the vertices of the graph:";
   cin>>v;

   int graph[v][100];

   for(int i=0;i<v;i++)
   {
       for(int j=0;j<v;j++)
        cin>>graph[i][j];
   }
  /* input 0,5,inf,10
  inf,0,3,inf
  inf,inf,0,1
  inf,inf,inf,0
  */

   floyd(graph);
   return 0;
}