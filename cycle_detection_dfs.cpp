#include<iostream>
#include<vector>
using namespace std;
bool dfstrav(vector<int>adj[],int s,bool ans[],int parent)
{
    ans[s]=true;
    for(int x :adj[s])
    {
        if(ans[x]==false)
        {
            if(dfstrav(adj,x,ans,s)==true)
            return true;
        }
        else if(x!=parent)
        return true;
    }
    return false;
}
bool dfs(vector<int>adj[],int v)
{
    bool ans[v+1];
    for(int i=0;i<v;i++)
    {
        ans[i]=false;
    }
    for(int i=0;i<v;i++)
    {
        if(ans[i]==false)
        {
            if(dfstrav(adj,i,ans,-1)==true)
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
        vec[y].push_back(x);
    }
   bool a=dfs(vec,v);
  if(a==1)
  cout<<"cycle found"<<endl;
  else
  cout<<"no cycle"<<endl;
}