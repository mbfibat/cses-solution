#include <bits/stdc++.h>
using namespace std;
int n; string s[300];
 
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    set<char> s1,s2;
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j||i==n-j-1)
                s1.insert(s[i][j]);
            else 
                s2.insert(s[i][j]);
        }
    }
    if(s1.size()==1 && s2.size()==1)
        cout<<"YES";
    else 
        cout<<"NO";
}