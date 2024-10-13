#include <bits/stdc++.h>
#include <stdio.h>


using namespace std;

const long long MOD = 1e9+7;

int main()
{
   
   long long n,m;
   cin>>n>>m;
   
   vector<vector<pair<int,long long>>> adj(n+1);
   
   for(int i=0 ; i<m ; i++)
   {
       int u,v,wt;
       cin>>u>>v>>wt;
       
       adj[u].push_back({v,wt});
   }
   
   priority_queue<pair<long long, int> , vector<pair<long long, int>> , greater<pair<long long, int>>> pq;
   
   pq.push({0,1});
   vector<long long> dist(n+1,INT_MAX);
   vector<long long> ways(n+1,0);
   vector<long long> mini(n+1,0);
   vector<long long> maxi(n+1,0);
   
   dist[1] = 0;
   ways[1] = 1;
   
   while(!pq.empty())
   {
        int node = pq.top().second;
        long long wt = pq.top().first;
        
        pq.pop();
        if(dist[node] < wt) continue;
        // if(node == n && wt == dist[n]){
            
            
        // }
        
        for(auto it : adj[node])
        {
            int adjnode = it.first;
            long long adjwt = it.second;
            
            if(wt + adjwt < dist[adjnode])
            {
                dist[adjnode] = wt + adjwt;
                ways[adjnode] = ways[node];
                mini[adjnode] = 1+mini[node];
                maxi[adjnode] = 1+maxi[node];
                pq.push({dist[adjnode] , adjnode});
            }
            else if(wt + adjwt == dist[adjnode])
            {
                ways[adjnode] = (ways[adjnode]+ways[node])%MOD;
                mini[adjnode] = min(mini[adjnode],1+mini[node]);
                maxi[adjnode] = max(maxi[adjnode],1+maxi[node]);
            }
        }
   }
//   for(int i=1 ; i<=n ; i++) cout<<ways[i]<<" ";
//   cout<<endl;
   cout<<dist[n]<<" "<<ways[n]<<" "<<mini[n]<<" "<<maxi[n];
    
    
    

    return 0;
}