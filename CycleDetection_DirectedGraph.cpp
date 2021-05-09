#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5;

vector<int >gr[N];
int vis[N];
bool cycle=0;

void dfs(int cur,int par){

    vis[cur]=1;

    for(auto x:gr[cur]){
        if(!vis[x]) dfs(x,cur);

        else if(vis[x]==1)
            cycle=1;
    }
     vis[cur]=2;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
#endif
}
int32_t main() {
    c_p_c();
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i,0);
    }

    if(cycle) cout<<"YES";
    else cout<<"NO";
    return 0;
}
