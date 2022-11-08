#include <iostream>
#include <cmath> 
#include <queue>
#include <vector>
#include <algorithm>
#define ll long long 
using namespace std; 
 
struct node { 
	ll val; 
	int l,r; 
	node(){} 
	node(ll a,int b,int c){ 
		val = a; 		 
		l = b; 			 
		r = c; 			
	} 
	bool operator < (const node &a) const
	{ return val < a.val; } 
}; 

const int maxn = 2e5+5; 
int n,ans; 
ll a[maxn]; 
priority_queue<node> s; 

int main () { 
	cin >> n; 
	for(int i = 1; i <= n; ++i) { 
		scanf("%lld",&a[i]); 
		if(a[i] > 1LL) 
			s.push(node(a[i],i,i)); 
	} 
	while(!s.empty()) { 
		node now = s.top(); 
		s.pop(); 
		vector<node> v; 
		v.push_back(now);
		while(s.size() && s.top().val == now.val) {
			v.push_back(s.top());
			s.pop(); 
		}
			
		sort(v.begin(),v.end(),[](node x,node y)
			{ return x.l < y.l; });  
		ll tmp = sqrt(now.val/2+1);  

		int l=v[0].l,r=v[0].r; 
		for(int i = 1; i < v.size(); ++i){ 
			if(v[i].l == r+1) 	 
				r = v[i].r; 
			else { 
				ans++; 
				if(tmp > 1LL) 
					s.push(node(tmp,l,r)); 
				l = v[i].l; r = v[i].r; 
			} 
		} 
		ans++; 
		if(tmp > 1LL) 
			s.push(node(tmp,l,r)); 
	} 
	printf("%d",ans);
	return 0;
}

