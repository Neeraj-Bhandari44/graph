#include<iostream>
#include<vector>
using namespace std;
void dfstrav(vector<int>adj[],int s,bool vis[])
{
vis[s]=true;
//cout<<s<<" ";
for(int x:adj[s])
{
if(vis[x]==false)
{
    vis[x]=true;
    dfstrav(adj,x,vis);
}
}
}
void dfs(vector<int>vec[],int v)
{
    bool vis[v+1];
    for(int i=0;i<v;i++)
    {
        vis[i]=false;
    }
    
    int count=0;
    for(int i=0;i<v;i++)
    {
        if(vis[i]==false)
        {
            dfstrav(vec,i,vis);
            count++;
        }
    }
    cout<<count<<endl;
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
        vec[y].push_back(x);
    }
    dfs(vec,v);
}