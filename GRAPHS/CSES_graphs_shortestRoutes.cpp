#include <stdio.h>
#include <bits/stdc++.h>
 
using namespace std;
// KEYWORD : basic Dijkstra implementation
int main()
{
	long long n,e;
	cin>>n>>e;
	long long x,y,z;
    vector<vector<pair<int,long long>>> adj(n+1);
	for(int i=0 ; i<e ; i++)
	{
		cin>>x>>y>>z;
		adj[x].push_back({y,z});
// 		adj[y].push_back({x,z});
	}
	
	vector<long long> dis(n+1,LLONG_MAX);
	
	priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>> pq;
	dis[1] = 0;
	pq.push({0,1});
	
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
	for(int i = 1; i<=n ; i++) cout<<dis[i]<<" ";
// 	cout<<"IMPOSSIBLE";
	return 0;
}
