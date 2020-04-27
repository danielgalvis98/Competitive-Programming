#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3;
const long long MOD1 = 1e9+7;
const long long MOD2 = 1e9+9;

string s;
string bad;
int k;
int pre[MAXN+5];
int sz;
map<pair<long long, long long>, bool> mp;

long long powmod(long long a, long long b, long long MOD){
	long long res = 1;
	while(b>0){
		if(b&1) res = (res*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s >> bad >> k;
	sz = (int)s.length();

	for(int i=0; i<sz; i++){
		pre[i+1] = pre[i];
		if(bad[s[i]-'a']=='0'){
			pre[i+1]++;
		}
	}

	int ans = 0;
	long long ss, sss;

	for(int i=1; i<=sz; i++){
		ss = 0;
		sss = 0;
		for(int j=0; j<i; j++){
			ss *= 31;
			ss += 1ll*(s[j]-'a');
			ss %= MOD1;
			sss *= 137;
			sss += 1ll*(s[j]-'a');
			sss %= MOD2;
		}
		for(int j=1; j<=sz-i+1; j++){
			if(pre[j+i-1]-pre[j-1]<=k){
				if(!mp[{ss,sss}]) {ans++; mp[{ss,sss}]=true;}
			}
			if(j+i-1 < sz){
				ss = ss*31 + 1ll*(s[j+i-1]-'a') - 1ll*(s[j-1]-'a')*powmod(31,i,MOD1);
				ss = ((ss%MOD1)+MOD1)%MOD1;
				sss = sss*137 + 1ll*(s[j+i-1]-'a') - 1ll*(s[j-1]-'a')*powmod(137,i,MOD2);
				sss = ((sss%MOD2)+MOD2)%MOD2;
			}
		}
		mp.clear();
	}

	cout << ans;

}
