//Topological Sort
// Presesnt only in directed acyclic graph
// can be used to detect cycle in graph
#include<bits/stdc++.h>
using namespace std;
 
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
  
    int n,m;
    cin>>n>>m;
    int cnt=0;
    vector<vector<int>> adj(n);
    vector<int> indeg(n,0);
    for(int i=0;i<m;i++){  //Take the edges as input
       int u,v;
       cin>>u>>v;
       //u-->v
       adj[u].push_back(v);
       indeg[v]++;
    }

    queue<int> pq;
    for(int i=0;i<n;i++)
       if(indeg[i]==0) pq.push(i);

   while(!pq.empty()){
      cnt++;
      int x=pq.front();
      pq.pop();
      cout<<x<<" ";
      for(auto it: adj[x]){
        indeg[it]--;
        if(indeg[it]==0) pq.push(it);
      }
   }
    cout<<endl;
    cout<<cnt;  //if count != n then cycle is present in it
    return 0;
}