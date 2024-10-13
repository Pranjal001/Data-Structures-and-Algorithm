#include <stdio.h>
#include <bits/stdc++.h>
 
using namespace std;

// Similar to 2 colorable problem form striver sheet
// Generatlized version :  m - colorable graph recursion problem
// KEYWORDS : DFS , color vector (for storing color value and acting as visited) , currcolor changes after every call

bool dfs(int node, vector<int> &color , vector<vector<int>> &adj, int currcolor)
{
    color[node] = currcolor;
    
    for(auto it : adj[node])
    {
        if(color[it] == -1){
            if(!dfs(it,color,adj,!currcolor)) return false;
        }
        else{
            if(color[node] == color[it]) return false;
        }
    }
    return true;
}
 
int main()
{
	int n,e;
	cin>>n>>e;
	int x,y;
    vector<vector<int>> adj(n+1);
	for(int i=0 ; i<e ; i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	vector<int> color(n+1,-1);
	
	for(int i=1 ; i<=n ; i++)
	{
	    if(color[i] == -1)
	    {
	        if(!dfs(i,color,adj,0)){
	            cout<<"IMPOSSIBLE";
	            return 0;
	        }
	    }
	}
	
	for(int i = 1  ;i<=n ; i++) cout<<color[i]+1<<" ";
	
	
 
	return 0;
}