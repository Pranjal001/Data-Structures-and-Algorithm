#include <stdio.h>
#include <bits/stdc++.h>

const long long MAX = 1e17;
const long long NINF = -1e17;

// topological sort

using namespace std;
vector<vector<int>> adj(100000);

bool dfs(int node , int par ,vector<vector<int>> &adj, vector<int> &path, vector<int> &vis){
    
    vis[node] = 1;
    path[node] = 1;
    for(auto it  : adj[node])
    {
        if(!path[it]){
            if(dfs(it,node,adj,path,vis)) return true;
        }
        else{
            return true;
        }
    }
    path[node] = 0;
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> indeg(n+1,0);
    for(int i=0; i<m ; i++)
    {
        long long u,v,wt;
        cin>>u>>v;
        
        adj[u].push_back(v);
        indeg[v]++;
        
    }

    vector<int> vis(n+1,0);
    // bool flag = 0;
    // for(int i = 1 ; i<=n ; i++)
    // {
    //     if(!vis[i]){
    //         vector<int> path(n+1,0);
    //         if(dfs(i,-1,adj,path,vis)){ cout<<"IMPOSSIBLE"; return 0;}
    //     }
    // }
    
    queue<int> q;
    vector<int> ans;
    for(int i = 1 ;i<=n ; i++) if(indeg[i] == 0){ q.push(i);};
    
    while(!q.empty()){
        
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for(auto it : adj[node])
        {
            indeg[it]--;
            if(indeg[it] == 0) q.push(it);
        }
    }
    for(int i=1; i<=n ; i++) if(indeg[i] >0){
        cout<<"IMPOSSIBLE"; return 0;
    }
    for(auto it : ans) cout<<it<<" ";
    return 0;
}
