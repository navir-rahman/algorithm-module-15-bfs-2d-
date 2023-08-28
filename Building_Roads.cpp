#include <bits/stdc++.h>
using namespace std;
const int BN=1e3+5;
vector<int > v[BN];
bool visited[BN];

void dfs(int a)
{
    visited[a]=true;
    for(int c:v[a]){
        if(visited[c]) continue;
        dfs(c);
    }
}

int main()
{
    int n,e;
    cin>>n>>e;
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int cc=0;
    vector<int> x;
    for (size_t i = 1; i <=n; i++)
    {
        if(visited[i]) continue;
        dfs(i);
        x.push_back(i);
        cc++;
    }

    cout<<cc<<endl;
    for(int c:x)
    {
        cout<<c<<" ";
    }
    
    
    return 0;
}