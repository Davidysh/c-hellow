#include<bits/stdc++.h>
using namespace std;
struct plural{
    double real1;
    double unreal1;
    double real2;
    double unreal2;
    bool x;
    plural(double a1, double b1, double a2, double b2, bool x):real1(a1), unreal1(b1),real2(a2), unreal2(b2),x(x){}
    void res(){
        if(x) {
            if(unreal1+ unreal2 > 0)
            cout<<real1 + real2<<"+"<<unreal1 + unreal2<<"i";
            else  cout<<real1 + real2<<"-"<<unreal1 + unreal2<<"i";
        }
        else {
            if(unreal1+ unreal2 > 0)
            cout<<real1 + real2<<"+"<<unreal1 + unreal2<<"i";
            else cout<<real1 + real2<<"+"<<unreal1 + unreal2<<"i";
        }
    }
};
