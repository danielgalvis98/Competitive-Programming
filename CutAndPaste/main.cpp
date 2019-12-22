#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, end=b;i<end;i++)
#define SZ(s) int(s.size())
#define ALL(s) s.begin(),s.end()
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

static int MOD = 1e9 + 7;
int main()
{FIN;
    int t;
    cin>>t;
    while(t--){
        int x;
        string s;
        cin>>x>>s;
        int l = 0;
        ll orSize = SZ(s);
        while(l < x && SZ(s) < x){
            int times = s[l] -'0'-1;
            string t = s.substr(l+1);
            for (int i=0; i < times && SZ(s) < x; i++)
                s.append(t);
            l++;
        }
        l = 0;
        while (l < x){
            int times = s[l] - '0' - 1;
            orSize += ((1L*times)*((orSize - (l+1) + MOD )%MOD))%MOD;
            orSize %= MOD;
            l++;
        }
        cout << orSize << "\n";
    }
    return 0;
}
