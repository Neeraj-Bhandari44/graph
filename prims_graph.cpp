//minimum weight in any undirected graph
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int prims(vector<vector<int>>graph,int v)
{
    int parent[v];
    int key[v];
    bool mstSet[v];
    for(int i=0;i<v;i++)
    {
        key[i]=INT_MAX;
        mstSet[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    int res=0;
     for (int count = 0; count < v; count++)
    {
        int u=-1;
        for(int i=0;i<v;i++)
        {
            if(!mstSet[i]&&(u==-1 || key[i]<key[u]))
            u=i;
        }
        mstSet[u]=true;
        res=res+key[u];
        for(int j=0;j<v;j++)
        {
            if(graph[u][j]!=0 && !mstSet[j])
            key[j]=min(key[j],graph[u][j]);
        }
    }
  return res;
}
int main()
{
    int v;
    cin>>v;
    vector<vector<int>>graph;
    cout<<"enter the adjency matrix"<<endl;
    for(int i=0;i<v;i++)
    {
        vector<int>temp;
        for(int j=0;j<v;j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        graph.push_back(temp);
    }
    int a=prims(graph,v);
    cout<<a<<endl;
}
