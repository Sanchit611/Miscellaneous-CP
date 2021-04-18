#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    stack<int>s;
    int left[n];
    int right[n];
    //increasing stack to the right: Finds just smaller element index at the right
    for(int i=0;i<n;i++){
       while(!s.empty() and a[s.top()]>a[i]){
           right[s.top()]=i;
           s.pop(); 
       } 
       s.push(i);
    }

    while(!s.empty()){
        right[s.top()]=n;
        s.pop();
    }
    //--------END----------//

     //increasing stack to the left: Finds just smaller element index at the left
    for(int i=n-1;i>=0;i--){
       while(!s.empty() and a[s.top()]>a[i]){
           left[s.top()]=i;
           s.pop(); 
       } 
       s.push(i);
    }
    while(!s.empty()){
        left[s.top()]=-1;
        s.pop();
    }
    //---------END-------//
    // for(int i=0;i<n;i++){
    //     cout<<left[i]<<" "<<right[i]<<endl;
    // }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,a[i]*(right[i]-left[i]-1));
    }
    cout<<ans;

}
