#include<iostream>
#include<vector>
using namespace std;
bool dfstra(vector<int>adj[],int s,int vis[],int recst[])
{
    vis[s]=true;
    recst[s]=true;
    for(int x:adj[s])
    {
        if(vis[x]==false&&dfstra(adj,x,vis,recst))
        return true;
        else if(recst[s]==true)
        return true;
    }
    recst[s]=false;
    return false;
}
bool dfs(vector<int>adj[],int v)
{
    int vis[v];
    int recst[v];
    for(int i=0;i<v;i++)
    {
        recst[i]=false;
        vis[i]=false;
    }
    for(int i=0;i<v;i++)
    {
        if(vis[i]==false)
        {
            if(dfstra(adj,i,vis,recst)==true)
            return true;
        }
    }
    return false;
}
int main()
{
    int v,u;
    cin>>v;
    cin>>u;
    vector<int>vec[v];
    for(int i=0;i<u;i++)
    {
        int x,y;
        cin>>x>>y;
        vec[x].push_back(y);
    }
    int a=dfs(vec,v);
    if(a==1)
    cout<<"cycle found"<<endl;
    else
    cout<<"no cycle"<<endl;
}
