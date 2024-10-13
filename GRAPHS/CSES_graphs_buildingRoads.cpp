#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

class dsu{
    public:
    vector<int> sz;
    vector<int> parent;
    
    dsu(int n){
        sz.resize(n+1,1);
        parent.resize(n+1,0);
        
        for(int i=1 ; i<=n ; i++){
            parent[i] = i;
            
        }
        return;
    }
    
    int findultp(int x){
        if(parent[x] == x) return x;
        return parent[x] = findultp(parent[x]);
    }
    
    void unions(int u , int v)
    {
        int ultpu = findultp(u);
        int ultpv = findultp(v);
        
        if(ultpv == ultpu) return;
        
        if(sz[ultpu] <= sz[ultpv]){
            parent[ultpu] = parent[ultpv];
            sz[ultpv] += sz[ultpu];
        }
        else{
            parent[ultpv] = parent[ultpu];
            sz[ultpu] += sz[ultpv];
            
        }
    }
};

int main()
{
    int n,e;
    cin>>n>>e;
    int x,y;
    dsu ds(n);
    for(int i=0 ; i<e ;i++)
    {
        cin>>x>>y;
        ds.unions(x,y);
        
    }
    set<int> st;
    vector<int> ans;
    for(int i=1 ; i<=n ; i++){
        if(st.find(ds.findultp(i)) == st.end()){
            
            st.insert(ds.findultp(i));
            ans.push_back(ds.findultp(i));
            
        }
    }
    
    cout<<st.size()-1<<endl;
    for(int i=1 ; i<ans.size() ; i++)
    {
        cout<<ans[i-1]<<" "<<ans[i]<<endl;
    }
    

    return 0;
}