#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

vector<int> dirx = {1,0,-1,0};
vector<int> diry = {0,1,0,-1};
void dfs(int i, int j, int n, int m, vector<vector<int>> &arr)
{
    arr[i][j] = 0;
    
    for(int k=0; k<4 ; k++)
    {
        int x = dirx[k]+i;
        int y = diry[k]+j;
        
        if(x<0 || y<0 || x>=n || y>=m || arr[x][y] == 0) continue;
        dfs(x,y,n,m,arr);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    string str;
    vector<vector<int>> arr(n,vector<int>(m,0));
    for(int i =0 ; i< n ; i++)
    {
        cin>>str;
        for(int j=0 ; j<m ; j++)
        {
            if(str[j] == '.'){
                arr[i][j] = 1;
            }
        }
    }
    int count=0;
    for(int i=0 ; i<n ; i++)
    {
        for(int j= 0; j<m ; j++)
        {
            if(arr[i][j]){
                count++;
                dfs(i,j,n,m,arr);
            }
        }
    }
    
    cout<<count;

    return 0;
}