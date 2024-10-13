// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long



// another idea is to use topological sort to get longest path



// bool dfs( ll i, vector<vector<ll>>& adj_list, vector<ll>& visit, vector<ll>& cycle, vector<ll>& res){
//     if(cycle[i] == 1) return false;
//     if(visit[i] == 1) return true;
    
//     visit[i] = 1;
//     cycle[i] = 1;
    
//     for(auto it : adj_list[i]){
//         if(!dfs(it, adj_list, visit, cycle, res)) {
//             return false; 
//         }
//     }
    
//     cycle[i] = 0;
//     res.push_back(i);
//     return true;
// }
 
int main() {
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>> adj_list(n + 1);
    vector<ll> indegree(n + 1, 0);
    vector<ll> par(n + 1, -1);
    vector<ll> dist(n + 1, LLONG_MIN);
    queue<ll> q;
    set<ll> visit;
    vector<ll> res;
    
    
    for (ll i = 0; i < m; i++){
        ll a, b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        indegree[b]++;
    }
    
    for(ll i = 1; i <= n; i++){
        if(indegree[i] == 0) q.push(i);
    }
    dist[1] = 0;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        visit.insert(u);
        for(auto v : adj_list[u]){
            if(dist[u] + 1 > dist[v]){
                dist[v] = dist[u] + 1;
                par[v] = u;
            }
            indegree[v]--;
            
            if(indegree[v] == 0) q.push(v);
        }
    }
    
    if(visit.size() != n) cout<<"IMPOSSIBLE";
    
    else{
        ll node = n;    
        do{
            res.push_back(node);
            node = par[node];
        }while(node != -1);
        reverse(res.begin(), res.end());
        if( res[0] != 1){
            cout<<"IMPOSSIBLE"; 
            return 0;
        }
        cout<<res.size()<<endl;
        for(auto it : res) cout<<it<<" ";
    }
    
    return 0;
}