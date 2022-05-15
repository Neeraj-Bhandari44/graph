#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void dfs(vector<int>adj[],int u,stack<int>&st,bool vist[]);
void topo_dfs(vector<int>adj[],int v)
{
    stack<int>st;
    bool vist[v];
    for(int i=0;i<v;i++)
    {
        vist[i]=false;
    }
    for(int i=0;i<v;i++)
    {
        if(vist[i]==false)
        dfs(adj,i,st,vist);
    }
    while(st.empty()==false)
    {
        int a=st.top();
        cout<<a<<" ";
        st.pop();
    }
}
void dfs(vector<int>adj[],int u,stack<int>&st,bool vist[])
{
    vist[u]=true;
    for(auto x:adj[u])
    {
        if(!vist[x])
        {
            dfs(adj,x,st,vist);
        }
    }
    st.push(u);
}
int main()
{
    int v,u;
    cin>>v>>u;
    vector<int>adj[v];
    for(int i=0;i<u;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    topo_dfs(adj,v);
}