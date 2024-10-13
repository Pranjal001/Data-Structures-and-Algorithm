#include <bits/stdc++.h>
#include <stdio.h>

// topo + cycle finding and then finally the node removed from topo need to be updated
using namespace std;
int dfs2(int node , vector<long long> &dp ,vector<long long> &adj )
{
    if(dp[node] != -1){  return dp[node];}

    dp[node] = 1 + dfs2(adj[node],dp,adj);
    return dp[node];
}
void dfs(long long node,long long prev , vector<long long> &path , vector<long long> &dp,vector<long long> &adj )    
{
    path[node] = 1+prev;
    
        if(!path[adj[node]]){
            dfs(adj[node],path[node],path,dp,adj);
        }
        else{
            dp[node] = path[node];
            return;
        }

    dp[node] = dp[adj[node]];
    return;
    
}

int main()
{
    long long n;
    cin>>n;
    
    vector<long long> adj(n,0);
    vector<long long> indeg(n,0);
    for( int i = 0 ; i<n ; i++)
    {
        cin>>adj[i];
        adj[i]--;
        indeg[adj[i]]++;
        
    }
    // cou<indeg[5];t<
    queue<int> q;
    for(int i=0 ; i<n ; i++)
    {
        if(indeg[i] == 0){ q.push(i);}
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        indeg[adj[node]]--;
        if(indeg[adj[node]] == 0) q.push(adj[node]);
    }
    // for(int i=0 ; i<n ; i++) cout<<indeg[i]<<" ";
    // cout<<endl;
    vector<long long> vis(n,0);
    vector<long long> dp(n,-1);
    vector<long long> path(n,0);
    
    for(int i=0 ; i<n ; i++)
    {
        if(dp[i] == -1 && indeg[i] != 0)
        {
            dfs(i,0,path,dp,adj);
        }
    }
    // dfs2(2,dp,adj);
    for(int i=0 ; i<n ; i++)
    {
        if(dp[i] == -1)
        {
            dfs2(i,dp,adj);
        }
    }
    for(auto it : dp) cout<<it<<" ";
    
    
    
    return 0;
    
}