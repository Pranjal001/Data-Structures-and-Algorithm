#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
// KEYWORDS : BFS(shortest route),Parent array(for backtracking)
int main()
{
    int n,e;
    cin>>n>>e;
    int x,y;
    vector<vector<int>> adj(n+1);
    vector<int> parent(n+1,0);
    
    for(int i=0 ; i<e ;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        
    }
    queue<int> q;
    q.push(1);
    parent[1] = 1;
    while(!q.empty()){
        
        int node = q.front();
        q.pop();
        // cout<<node<<":";
        if(node == n){
            break;
        }
        
        for(auto it : adj[node])
        {
            if(parent[it] == 0)
            {
                parent[it] = node;
                q.push(it);
            }
        }
    }
    
    if(parent[n] == 0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    
    int node = n;
    int count=1;
    vector<int> ans;
    while(1 != node){
       ans.push_back(node);
       node = parent[node];
       count++;
    }
    ans.push_back(1);
    cout<<count<<endl;
    for(int i=ans.size()-1 ; i>=0 ; i--)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}