#include <stdio.h>
#include <bits/stdc++.h>
 
using namespace std;
// KEYWORD : BFS (rotten oranges)
// Start by adding all monsters to the queue and at last the hero update the neighbours of monsters
// and for hero update the direction of possible cells
// do this until queue is empty or the hero reaches the border/dest backtrack the direction on the grid back to hero
char mat[1001][1001]={'#'};
vector<int> dirx = {1,0,-1,0};
vector<int> diry = {0,1,0,-1};
vector<char> direction = {'D','R','U','L'};


string find(int i,int j,vector<vector<char>> &mat1){
    string ans="";
    while(mat[i][j] != 'A'){
        ans.push_back(mat[i][j]);
        if(mat[i][j] == 'R') j--;
        else if(mat[i][j] == 'L') j++;
        else if(mat[i][j] == 'U') i++;
        else if(mat[i][j] == 'D') i--;
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
    
}
int main()
{
	int n,m;
	cin>>n>>m;
	int startx,starty;
    vector<vector<char>> mat1(n,vector<char>(n,'#'));
	queue<pair<int,int>> q;
	for(int i =0 ; i<n ; i++)
	{
	    string str;
	    cin>>str;
	    for(int j =0 ; j<m ; j++)
	    {
	        mat[i][j] = str[j];
	        if(str[j] == 'A'){
	            startx = i;
	            starty = j;
	        }
	        if(str[j] == 'M'){
	            q.push({i,j});
	        }
	    }
	}
	q.push({startx,starty});
	
	while(!q.empty()){
	    
	    int i = q.front().first;
	    int j = q.front().second;
	    
	    q.pop();
	    if((i==0 || j==0 || i==n-1 || j== m-1) && mat[i][j] != 'M' && mat[i][j] != '.'){
	        
	        cout<<"YES"<<endl;
	       // break;
	        string ans = find(i,j,mat1);
	        cout<<ans.size()<<endl;
	        cout<<ans;
	        
	        return 0;
	    }
	    if(mat[i][j] == 'M'){
	        
	        for(int k=0 ; k<4 ; k++)
	        {
	            int x = dirx[k] + i;
	            int y = diry[k] + j;
	            
	            if(x>=0 && x<n && y>=0 && y<m && mat[x][y] == '.'){
	                mat[x][y] = 'M';
	                q.push({x,y});
	            }
	        }
	    }
	    else{
	        for(int k=0 ; k<4 ; k++)
	        {
	            int x = dirx[k] + i;
	            int y = diry[k] + j;
	            
	            if(x>=0 && x<n && y>=0 && y<m && mat[x][y] == '.'){
	                mat[x][y] = direction[k];
	                q.push({x,y});
	            }
	        }
	    }
	    
	}
	
// 	for(int i=0 ; i<n ; i++)
// 	{
// 	    for(int j =0 ; j<m ; j++)
// 	    {
// 	        cout<<mat[i][j]<<" ";
// 	    }
// 	    cout<<endl;
// 	}
	
	
	
	cout<<"NO";
	return 0;

}