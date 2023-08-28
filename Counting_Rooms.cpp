#include <bits/stdc++.h>
using namespace std;
 

const int BN=1005;
int vis[BN][BN];
    int n,m;
    char a[BN][BN];
vector<pair<int,int>> path={{-1,0},{1,0}, {0,-1}, {0,1}};

bool isvalid(int ci, int cj)
{
        if(ci >= 0&& ci <n &&cj >= 0 && cj<m && a[ci][cj] == '.') return true;
        else return false;
}

void dfs(int si, int sj)
{
    vis[si][sj]= true;
    for (int i = 0; i < 4; i++)
    {
        pair<int,int> p=path[i];
        int ci= si+p.first;
        int cj=sj +p.second;

        if(isvalid(ci,cj) && !vis[ci][cj])
        {
            dfs(ci,cj);
        }
    }
    
}   


int main()
{
    cin>>n>>m;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
    }
    int cnt=0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if(!vis[i][j] && a[i][j]=='.')
            {
                cnt++;
                dfs(i,j);
            }
        }
        
    }
    cout<<cnt;
    
    
    return 0;
}