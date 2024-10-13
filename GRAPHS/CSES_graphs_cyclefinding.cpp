#include <stdio.h>
#include <bits/stdc++.h>
// takeaways
// bellman working at finest
// adding pseudo edge to address all components of the graph A' with vertex 0 to all n nodes with 0 distance
// making parents while traversing the bellman ford algorithm
// if neg cycle exists keep on updating parent and an maintain a node startv in it
// traverse for n-1 iterations of parent[v] back track to gaurantee that the node is in the negative cycle
// print it
const long long MAX = 1e17;
const long long NINF = -1e17;
 
using namespace std;
 
int main()
{
    int n,m;
    cin>>n>>m;
    int flag = false,selfloop;
    vector<pair<pair<int,int>,long long>> edges;
    for(int i=0; i<m ; i++)
    {
        long long u,v,wt;
        cin>>u>>v>>wt;
        if(u==v && wt<0){
            flag = true;
            selfloop = u;
        }
        edges.push_back({{u,v},wt});
    }
    
    if(flag){
        cout<<"YES"<<endl;
        cout<<selfloop<<" "<<selfloop;
        return 0;
    }
    for(int i = 1 ; i<n ; i++)
    {
        edges.push_back({{0,i},0});
    
    }
    vector<long long> dist(n+1,MAX),parent(n+1,MAX);
    dist[0] = 0;
    
    for(int i =0 ; i<n ; i++)
    {
        for(int j =0 ; j<m+n ; j++)
        {
            long long u,v,wt;
            u = edges[j].first.first;
            v = edges[j].first.second;
            wt = edges[j].second;
            // cout<<u<<" "<<v<<" "<<dist[u]<<endl;
            if(dist[u] == MAX) continue;
            if(dist[u]+wt < dist[v]){
                dist[v] = dist[u]+wt;
                parent[v] = u;
 
            }
        }
    }
    
    // for(int i =1 ; i<=n ; i++) cout<<parent[i]<<" ";
    // cout<<endl;
    int startu=-1 , startv=-1;
    
    for(int i =0 ; i<n ; i++)
    for(int j =0 ; j<m+n ; j++)
        {
            long long u,v,wt;
            u = edges[j].first.first;
            v = edges[j].first.second;
            wt = edges[j].second;
            
            if(dist[u] == MAX) continue;
            if(dist[u]+wt < dist[v]){
                parent[v] = u;
                startv = v;
            }
        }
        
    if(startv == -1)
    {
        cout<<"NO";
        return 0;
    }
    
    for(int i =1 ; i<=n ; i++)
    {

        startv = parent[startv];
    }
    
    cout<<"YES"<<endl;
    vector<int> ans;
    // cout<<startu<<" "<<startv<<endl;
    ans.push_back(startv);
    startu= parent[startv];
    while(startu!=startv){
        ans.push_back(startu);
        startu = parent[startu];
    }
    ans.push_back(startv);
    
    reverse(ans.begin(),ans.end());
    
    for(auto it : ans) cout<<it<<" ";
    return 0;
}
