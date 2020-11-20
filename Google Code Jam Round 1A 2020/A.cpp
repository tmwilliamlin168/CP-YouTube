#include <bits/stdc++.h>
using namespace std;

const int mxN=50;
int n;
string p[mxN], pre[mxN], suf[mxN];

void solve() {
	//input
	cin >> n;
	//longest prefix & suffix
	int lp=0, ls=0;
	for(int i=0; i<n; ++i) {
		cin >> p[i];
		//remove prefix and suffix of p[i] without '*'
		pre[i]=suf[i]="";
		for(; p[i][0]!='*'; p[i].erase(p[i].begin()))
			pre[i]+=p[i][0];
		for(; p[i].back()!='*'; p[i].pop_back())
			suf[i]=p[i].back()+suf[i];
		if(pre[i].size()>pre[lp].size())
			lp=i;
		if(suf[i].size()>suf[ls].size())
			ls=i;
	}

	//make sure all prefixes & suffixes match
	for(int i=0; i<n; ++i) {
		if(pre[lp].substr(0, pre[i].size())!=pre[i]) {
			cout << "*";
			return;
		}
		if(suf[ls].substr(suf[ls].size()-suf[i].size())!=suf[i]) {
			cout << "*";
			return;
		}
	}

	//build ans
	string ans=pre[lp];
	for(int i=0; i<n; ++i)
		for(char c : p[i])
			if(c!='*')
				ans+=c;
	ans+=suf[ls];
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for(int i=1; i<=t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
		cout << "\n";
	}
}
pp
