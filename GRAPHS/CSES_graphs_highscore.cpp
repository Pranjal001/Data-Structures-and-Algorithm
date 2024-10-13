#include <stdio.h>
#include <bits/stdc++.h>

const long long MAX = 1e17;
const long long NINF = -1e17;

using namespace std;

// New concept of bellman ford
// First since we want to find max distance we will change the edge signs and find mini that will be MAX distance
// Second if there is -ve cycle in the graph...
//                  i. it can be detected in Nth cycle of bellman ford
//                  ii. However it cannot point out its location, we can propagate the effect of the -ve cycle
//                      by running the bellman ford once again for n-1 times it will propagate the -ve cycle effect to all
//                      nodes getting affected by it.
// TC : O(2*VE)

int main()
{
    int n,m;
    cin>>n>>m;
    bool flag =false;
    vector<pair<pair<int,int>,long long>> edges;
    for(int i=0; i<m ; i++)
    {
        long long u,v,wt;
        cin>>u>>v>>wt;
        if(u == v && u == 1 && wt >0){
            flag = true;
        }
        
        edges.push_back({{u,v},-1*wt});
    }
    if(flag){
        cout<<-1; return 0;
    }
    vector<long long> dist(n+1,MAX);
    dist[1] = 0;
    
    for(int i =0 ; i<n-1 ; i++)
    {
        for(int j =0 ; j<m ; j++)
        {
            long long u,v,wt;
            u = edges[j].first.first;
            v = edges[j].first.second;
            wt = edges[j].second;
            // cout<<u<<" "<<v<<" "<<dist[u]<<endl;
            if(dist[u] == MAX) continue;
            dist[v] = max(dist[v],NINF);
            if(dist[u]+wt < dist[v]){
                dist[v] = dist[u]+wt;

            }
        }
    }
    for(int i =0 ; i<n-1 ; i++)
    for(int j =0 ; j<m ; j++)
        {
            long long u,v,wt;
            u = edges[j].first.first;
            v = edges[j].first.second;
            wt = edges[j].second;
            
            if(dist[u] == MAX) continue;
            dist[v] = max(dist[v],NINF);
            if(dist[u]+wt < dist[v]){
                
                dist[v] = NINF;
                dist[u] = NINF;
            }
        }
    
    if(dist[n] == NINF || dist[n] == MAX) cout<<-1;
    else cout<<-1*dist[n];
    
    return 0;
}