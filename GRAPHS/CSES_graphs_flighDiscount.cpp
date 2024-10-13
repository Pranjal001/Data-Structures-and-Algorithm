#include <stdio.h>
#include <bits/stdc++.h>

const long long MAX = 1e15;
// This  problem is standard Dijkstra but with a twist of discount of 50% on one ticket
// For this Do dijkstra from 1 to n and another from n to 1;
// for each eadge u to v , take min of min 1 to u + edge wt (50%) + v to n
using namespace std;
void dijkstra(int node,vector<vector<pair<int,long long>>> &adj , int n , int m, vector<long long> &dis)
{
    priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>> pq;
	dis[node] = 0;
	pq.push({0,node});
	
	while(!pq.empty()){
	    int node = pq.top().second;
	    long long dist = pq.top().first;
	    pq.pop();
	    if(dist > dis[node]) continue;
	    for(auto it : adj[node])
	    {
	        int adjnode = it.first;
	        long long adjdist=  it.second;
	        
	        if(dist+adjdist < dis[adjnode]){
	            dis[adjnode] = dist+adjdist;
	            pq.push({dis[adjnode],adjnode});
	        }
	        
	    }
	}
    return;
}
int main()
{
    int n,m;
    cin>>n>>m;
    bool flag =false;
    vector<vector<pair<int,long long>>> adj(n+1),adjrev(n+1);
    vector<pair<pair<int,int>,long long>> edges;
    for(int i=0; i<m ; i++)
    {
        long long x,y,z;
        cin>>x>>y>>z;
        edges.push_back({{x,y},z});
        adj[x].push_back({y,z});
		adjrev[y].push_back({x,z});
    }
    
    vector<long long> dist1(n+1,MAX),distn(n+1,MAX);
    dijkstra(1,adj, n , m , dist1);
    dijkstra(n,adjrev, n , m , distn);
    
    long long mincost = MAX;
    // for(int i =1 ;i<=n ; i++) cout<<dist1[i]<<" ";
    // cout<<endl;
    // for(int i =1 ;i<=n ; i++) cout<<distn[i]<<" ";
    // cout<<endl;
    
    for(int j =0 ; j<m ; j++)
        {
            long long u,v,wt;
            u = edges[j].first.first;
            v = edges[j].first.second;
            wt = edges[j].second;
            mincost = min(mincost , dist1[u]+(wt/2)+distn[v]);
        }
        
    cout<<mincost;
    
    return 0;
}