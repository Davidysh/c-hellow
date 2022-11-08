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

if(B->len){ 
		int q = 0;
		int c;
		int p;
		for(c=0 ; c<=A.m ; c++){ 
			for(p=0 ; p<A.len ; p++){
				if(A.data[p].col == c){
					B->data[q].row = A.data[p].col;
                    B->data[q].col = A.data[p].row;
                    B->data[q].e = A.data[p].e;
				} 
			}