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
    ///Prime seive: Prime numbers till n///
    int n;
    n=200;

    vector<bool> p(n+1,true);
    p[0]=p[1]=false;


    for(int i=2;i<=n;i++){

        if(p[i]==false) continue;
        cout<<i<<endl;
        for(int j=i*i;j<=n;j+=i){
            p[j]=false;
        } 
    }
    // Prime seive ends ///


    //Sum of divisors of every no till n

    int n=200;
    int p[n+1];
    memset(p,0,sizeof(p));

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            p[j]+=i;
        }
    }

   for(int i=0;i<n;i++){
    cout<<i<<" "<<p[i]<<endl;
   }

    
    return 0;
}