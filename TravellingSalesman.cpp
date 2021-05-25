//Travelling salesman problem
#include<bits/stdc++.h>
using namespace std;
#define INF 999999

int n=4;
int dp[16][4];
int dist[10][10]={

     {0,20,42,25},
     {20,0,30,34},
     {42,30,0,10},
     {25,34,10,0}

};
//if all cities have been visited
int VISTED_ALL=(1<<n)-1;

int tsp(int mask,int pos){

     if(mask==VISTED_ALL){
        return dist[pos][0];
     }
     //check
     if(dp[mask][pos]!=-1)
        return dp[mask][pos];
     int ans=INF;
     //try to go to all unvisited cities
     for(int city=0;city<n;city++){
           if((mask&(1<<city))==0){
            int newAns=dist[pos][city]+tsp(mask|(1<<city),city);
            ans=min(ans,newAns);
           }
     }

   return dp[mask][pos]=ans;
}


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


    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++)
            dp[i][j]=-1;
    }
    
    cout<<tsp(1,0)<<endl;
  
    return 0;
}