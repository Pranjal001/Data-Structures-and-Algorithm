// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
 
bool dfs1(int node, int parent, vector<vector<int>>& adj_list, vector<int>& visit, int& res){
    visit[node] = 1;
    res = node;
    for(auto neigh : adj_list[node]){
        if(neigh == parent) continue;
        if(!visit[neigh]){
            if(dfs1(neigh, node, adj_list, visit, res)) return true;
        }
        else if(neigh != parent && visit[neigh]){
            res = neigh;
            return true;
        }
    }
    return false;
}
 
bool dfs2(int node, int parent, vector<vector<int>>& adj_list, vector<int>& ans, vector<int>& visit, int cnt){
    
    visit[node] = 1;
    ans.push_back(node);
    cnt++;
    for(auto child : adj_list[node]){
        if(!visit[child]){
            if(dfs2(child, parent, adj_list, ans, visit, cnt)) return true;
        }
        
        else if(cnt > 2 && child == parent){
            ans.push_back(child);
            return true;
        }
    }
    cnt--;
    ans.pop_back();
    return false;
}
 
int main() {
    long long n, m;
    cin>>n>>m;
    vector<vector<int>> adj_list(n + 1);
    
    for(int i = 0; i < m; i++){
        int x, y;
        cin>>x>>y;
        
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
        
    vector<int> visit(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if(!visit[i]){
            int res ;
            if(dfs1(i, -1, adj_list, visit, res)){ // cycle detect
                vector<int> ans;
                vector<int> visit1(n + 1, 0);
                int cnt = 0; // atleast 2 cities
            
                if(dfs2(res, res, adj_list, ans, visit1 ,cnt)){
            
                    cout<<ans.size()<<endl;
                    for(int i = 0; i < ans.size(); i++){
                        cout<<ans[i]<<" ";
                    }
            
                    return 0;
                } 
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}