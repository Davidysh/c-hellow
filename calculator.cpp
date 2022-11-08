#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
struct OPTR{   //字符栈
    char signal[100];
    int top;
};

struct OPND{   //数字栈
    int number[100];
    int top;
};

void Cal(OPND Num,OPTR Sig)   //算数计算函数 用于判断优先级后压 入栈
{
    char x;
    x = Sig.signal[Sig.top--];

    if(x == '('||x==')')
    {
        return;
    }

    int a,b;
    a = Num.number[Num.top--];
    b = Num.number[Num.top--];
    cout<<a<<x<<b<<endl;
    switch(x)
    {
        case '+' :
        Num.number[++Num.top] = a + b;break;
        case '-' :
        Num.number[++Num.top] = a - b;break;
        case '*' :
        Num.number[++Num.top] = a * b;break;
        case '/' :
        Num.number[++Num.top] = a / b;break;
        case '^' :
        Num.number[++Num.top] = pow(a,b);break;
    }
    
}

int pro(char x)   //给符号赋值给予优先级
{
    switch (x)
    {
        case '=' :  return 1;

        case '(' :  return 2;

        case ')' :  return 3;

        case '+' :  return 4;

        case '-' :  return 4;
        
        case '*' :  return 5;
        
        case '/' :  return 5;

        case '^' :  return 6;

    }
}

bool Isdigit(char s)
{
    if(s >= 48 && s <= 57) return true;
    else return false;
}

bool Isoperator(char s)
{
    if(s == '+'||s == '-'||s == '*'||s == '/'||s == '^'||s == '='||s == '('||s == ')')
    return true;
    else return false;
}

int main() 
{  
    string s;
    getline(cin,s);     //要求形式末尾要有“=”
    int m;
    m = s.size();
    OPTR Sig;
    OPND Num;
    Num.top = -1;
    Sig.top = -1;
    string num ;
    int x;
    int a = 0,b;
    for(int i = 0;i <= m - 1;i++)
    {
        while(Isdigit(s[i]))
        {
            num += s[i++];
        }

        if(!num.empty())
        {
            Num.number[++Num.top] = stoi(num);
            num = "";
        }
       
        while(!Isoperator(s[i]))
        {
            i++;
        }
        
        
}