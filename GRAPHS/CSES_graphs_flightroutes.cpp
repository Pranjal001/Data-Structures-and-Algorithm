#include <stdio.h>
#include <bits/stdc++.h>

const long long MAX = 1e17;
const long long NINF = -1e17;

// idea is to maintain a 2d distance vector ofsize n*k
// while iterating through dijkstra we compare the k-1 element of the node and update its distance and pass that value
// then we sort the entire distances of length k for that node so that the max goes at the end and we can compare that valus for updation
 
using namespace std;
 
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,long long>>> adj(n+1);
    for(int i=0; i<m ; i++)
    {
        long long u,v,wt;
        cin>>u>>v>>wt;
        
        adj[u].push_back({v,wt});
        
    }
    vector<vector<long long>> dist(n+1,vector<long long>(k,MAX));
    dist[1][0] = 0;
    
    priority_queue<pair<long long, int> , vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> ans;
    
    pq.push({0,1});
    
    while(!pq.empty())
    {
        long long wt = pq.top().first;
        int node = pq.top().second;
        
        pq.pop();
        if(wt > dist[node][k-1]) continue;
        
        for(auto it : adj[node]){
            
            int adjnode = it.first;
            long long adjwt = it.second;
            
            if(wt + adjwt < dist[adjnode][k-1]){
                
                dist[adjnode][k-1] = wt + adjwt;
                pq.push({dist[adjnode][k-1],adjnode});// sort after pushing is imp;
                sort(dist[adjnode].begin() , dist[adjnode].end());
                
            }
        }
    }
    for(auto it : dist[n]) cout<<it<<" ";
    return 0;
}
