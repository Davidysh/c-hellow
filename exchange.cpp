#include<bits/stdc++.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct arr{
    int length;
    int data[10000];
};
int main(){
    int a,b;
    arr m,n,q;
    
    cin>>a;
    m.length = a;
    for(int i = 0;i < m.length;++i){
        int x;
        cin>>x;
        q.data[q.length++] = x;
    }
    
    cin>>b;
    n.length = b;
    for(int i = 0;i < n.length;++i){
        int x;
        cin>>x;
        q.data[q.length++] = x;
    }
    
    sort(q.data.begin(),q.data[q.length]);
    for(int i:q.data)
    {
        cout<<i<<" ";
    }
}