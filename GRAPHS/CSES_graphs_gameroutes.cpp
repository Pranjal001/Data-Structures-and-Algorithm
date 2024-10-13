#include <bits/stdc++.h>
#include <iostream>

// use topological sort and DP
// catch fot the testcase which removes the node 1 from the indeg and gives wrong ans
using namespace std;
const long long MOD = 1e9+7;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<long long> indeg(n+1,0);
    for(int i=0 ; i<m ; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int> q;
    for(int i =2 ; i<n ; i++)
    {
        if(indeg[i] == 0) q.push(i);
    }
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it : adj[node])
        {
            indeg[it]--;
            if(indeg[it] == 0 && it != 1) q.push(it);
        }
    }
    
    queue<int> qe;
    vector<long long> count(n+1,0);
    count[1] = 1;
    qe.push(1);
    while(!qe.empty())
    {
        int node = qe.front();
        // long long way = q.top().second;
        qe.pop();
        for(auto it : adj[node])
        {
            indeg[it]--;
            count[it] = (count[it]+count[node])%MOD;
            if(indeg[it] == 0) qe.push(it);
        }
    }
    
    
    // for(int i =0 ; i<=n ; i++) cout<<count[i]<<" ";
    cout<<count[n];
    return 0;
}