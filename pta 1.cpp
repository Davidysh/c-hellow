#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool match(char S[],char s[])
{
    int len1 = strlen(S);
    int len2 = strlen(s);
    if(len1 == 0 || len2 == 0)
    return 0;
    int m = 0,z = 0;
        while(m < len1 && z < len2)
        {
            if(S[m] == s[z])
            {
                m++;
                z++;
            }
            else 
            {
                z = z-m+1;
                m = 0;
            }
        }
        if(m >= len1)
            return 1;            
        else
            return 0;
        
}

int main()
{
    int n;
    cin>>n;
    char S[500],s[500];
    
    for(int i = 1;i <= n;i++)
    {   
        cin>>S;
        cin>>s;
        int len2 = strlen(S);
        for(int j = 0;j < len2;++j)
        {
            S[len2] = S[0];
            for(int i = 0;i < len2;i++)
            {
                S[i]=S[i+1];
            }
            S[len2] = '\0';
            if(match(S,s))
            break;
        }
        if(match(S,s))
        cout<<"YES"<<endl;
        else 
        cout<<"NO"<<endl;
    }   
}

