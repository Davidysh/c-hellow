#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

struct Triple{
    int row,col;
    int e;
};

struct TsMateix{
    Triple data[1000];
    int m,n,len;//矩阵的行列，个数；
};

void TransTsmateix(TsMateix A,TsMateix *B){
    int col,t,p,q;
    int num[1000]={0},position[1000]={0};
    B->len = A.len;
    B->n = A.m;
    B->m = A.n;
    for(col = 1; col < A.n;++col)
    {
        num[col] = 0;
    }
    for(t = 1;t <= A.len;t++)
    {
        num[A.data[t].col]++;
    }
    position[1] = 1;
    for(col = 2;col <= A.n;col++)
    {
        position[col] = position[col-1]+num[col-1];
    }
    for(p = 1; p <= A.len;p++)
    {
        col = A.data[p].col;
        q = position[col];
        B->data[q].row = A.data[p].col;
        B->data[q].col = A.data[p].row;
        B->data[q].e = A.data[p].e;
        position[col]++;
    }
}

int main(){
    int m,n,len;
    TsMateix A;
    TsMateix *B;
    B = new TsMateix;
    cin>>A.m>>A.n>>A.len;
    for(int i = 1;i <= A.len;i++){
        cin>>A.data[i].row;
        cin>>A.data[i].col;
        cin>>A.data[i].e;
    }
    TransTsmateix(A,B);
    for(int i = 0;i < A.len;i++)
    {
        cout<<B->data[i].row<<" "<<B->data[i].col<<" "<<B->data[i].e<<endl;
    }
}