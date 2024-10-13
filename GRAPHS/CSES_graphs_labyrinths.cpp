#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

vector<int> dirx = {1,0,-1,0};
vector<int> diry = {0,1,0,-1};
vector<char> direction = {'D','R','U','L'};
int main()
{
    int n,m;
    cin>>n>>m;
    string str;
    vector<vector<char>> arr(n,vector<char>(m,'#'));
    queue<pair<int,int>> q;
    int tarx=-1,tary=-1;
    for(int i =0 ; i< n ; i++)
    {
        cin>>str;
        for(int j=0 ; j<m ; j++)
        {
            if(str[j] == '.'){
                arr[i][j] = '.';
            }
            if(str[j] == 'A'){
                arr[i][j] = 'A';
                q.push({i,j});
            }
            if(str[j] == 'B'){
                arr[i][j] = 'B';
                tarx = i;
                tary = j;
            }
        }
    }
    
    // for(int i = 0 ;i<n ; i++)
    // {
    //     for(int j =0 ; j<m ; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    bool found = false;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if(i == tarx && j == tary){ found = true ; break;}

        for(int k=0 ; k<4 ; k++)
        {
            int x = dirx[k]+i;
            int y =diry[k]+j;
            
            if(x<0 || y<0 || x>=n || y>= m || arr[x][y]=='#' || arr[x][y]=='L' || arr[x][y]=='D'|| arr[x][y]=='R' || arr[x][y]=='U' || arr[x][y] == 'A') continue;
            arr[x][y] = direction[k];
            q.push({x,y});
        }
    }
    if(found == false){
        cout<<"NO"<<endl; return 0;
    }
    
    // for(int i = 0 ;i<n ; i++)
    // {
    //     for(int j =0 ; j<m ; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    string ans="";
    while(arr[tarx][tary] != 'A'){
        ans.push_back(arr[tarx][tary]);
        if(arr[tarx][tary] == 'U') tarx++;
        else if(arr[tarx][tary] == 'D') tarx--;
        else if(arr[tarx][tary] == 'L') tary++;
        else if(arr[tarx][tary] == 'R') tary--;
    }
    reverse(ans.begin(),ans.end());
    cout<<"YES"<<endl<<ans.size()<<endl<<ans;
    

    return 0;
}