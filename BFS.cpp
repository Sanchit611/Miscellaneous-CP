#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
bool vis[N];
vector<int> adj[N];
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
#endif
}

int32_t main()
{
    c_p_c();
    
    memset(vis , 0, sizeof(vis));

    int n,m;
    cin>>n>>m;

    int x,y;
    for(int i=0;i<n;i++){

        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    queue<int>q;
    q.push(1);
    vis[1]=true;

    while(!q.empty()){

       int node=q.front();
       q.pop();
       cout<<node<<endl;

       vector<int> :: iterator it;

       for(it=adj[node].begin();it!=adj[node].end();it++){

          if(!vis[*it]){
          vis[*it]=1;
          q.push(*it);
         }



       }

    }

    return 0;
}