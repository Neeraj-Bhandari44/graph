#include<iostream>
#include<vector>
using namespace std;
void dfs_tra(vector<int>adj[],int s,bool vis[])
{
    vis[s]=true;
    cout<<s<<" ";
    for(int x:adj[s])
    {
        if(vis[x]==false)
        {
            dfs_tra(adj,x,vis);
        }
    }
}
void dfs(vector<int>adj[],int v,int s)
{
    bool visited[v+1];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
        dfs_tra(adj,s,visited);
}
int main()
{
    int v,u;
    cout<<"enter no of vertices"<<endl;
    cin>>v;
    cout<<"enter no of edges"<<endl;
    cin>>u;
    vector<int>vec[v];
    for(int i=0;i<u;i++)
    {
        int x,y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    int s;
    cout<<"enter the source node"<<endl;
    cin>>s;
    dfs(vec,v,s);
}