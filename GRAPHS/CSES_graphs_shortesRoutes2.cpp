#include <stdio.h>
#include <bits/stdc++.h>
 
using namespace std;
// KEYWORD : Floyd warshall
// note : multi graph so while making adj list make sure to push min dist from A to B
// make unreachable dist MAX and then -1 after algorithm execution
int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	vector<vector<long long>> arr(n+1,vector<long long>(n+1,1e15));
	
	long long x,y,z;
	for(int i=0 ; i<m ; i++)
	{
	   cin>>x>>y>>z;
	   z= min(z,arr[x][y]);
	   arr[x][y] = z;
	   arr[y][x] = z;
	   
	}
	
	for(int via =1 ; via<=n ; via++)
	{
	    for(int i=1 ; i<=n ; i++)
	    {
	        for(int j=1 ; j<=n ; j++)
	        {
	            arr[i][j] = min(arr[i][j],arr[i][via]+arr[via][j]);
	        }
	    }
	}
	
	for(int i =0 ; i<q; i++)
	{
	    cin>>x>>y;
	    if(x==y) cout<<0<<endl;
	    else{
	        long long ans = (arr[x][y] == 1e15)? -1 : arr[x][y];
	        cout<<ans<<endl;
	        
	    }
	}
	
	return 0;
}
