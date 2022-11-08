#include<stack>
#include<string>
#include<unordered_map>
#include<cmath>
#ifndef COMPUTE_H
#define COMPUTE_H
class Compute{
public:
    int entrance(std::string v){
        return compute(v);
    }
private:
    void calculate(char a, std::stack<int> &n){
    if(a == ')' || a == '('){
        return;
    }
    int x, y;
    x = n.top();
    n.pop();
    y = n.top();
    n.pop();
    if(a == '+'){
        n.emplace(x + y);
        return;
    }
    else if(a == '-'){
        n.emplace(y - x );
        return;
    }
    else if(a == '*'){
        n.emplace(y * x);
        return;
    }
    else if(a == '/'){
        n.emplace(y / x);
        return;
    }
    else if(a == '^'){
        n.emplace(int(pow(y,x)));
        return;
    }
}
    int compute(std::string v){
        std::unordered_map<char, int>
            alphayet = {{'=', 0},
                        {'(', 1},
                        {')', 2},
                        {'+', 3},
                        {'-', 3},
                        {'*', 4},
                        {'/', 4},
                        {'^', 5}}; 
        std::stack<int> num;
        std::stack<char> sym;
        int n = v.size();
        std::string number;
        for(int i = 0; i < n; ++i){
            if(isdigit(v[i])){
                number += v[i];
                continue;
            }
            else if(!number.empty()){
                num.emplace(std::stoi(number));
                number = "";
            }
            if(alphayet.find(v[i]) != alphayet.end()){
                int a = alphayet[v[i]];
                if(a == 1){
                    sym.emplace(v[i]);
                    continue;
                }
                while(!sym.empty() && a < alphayet[sym.top()]){
                    calculate(sym.top(), num);
                    sym.pop();
                }
                sym.emplace(v[i]);
            }
        }
        return num.top();
    }
};
int compute(std::string formula){
    Compute n;
    return n.entrance(formula);
}
#endif