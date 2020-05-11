#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,end=b;i<end;i++)
#define ALL(s) s.begin(),s.end()
#define SZ(s) int(s.size())
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif

    string s;
    cin >> s;
    vi endGroups;

    endGroups.pb(-1);
    fore (i, 1, SZ(s)){
        if (s[i] != s[i-1]) endGroups.pb(i-1);
    }
    endGroups.pb(SZ(s) - 1);

    if (SZ(endGroups) % 2 == 1) cout << "0\n";
    else {
        int mid = SZ(endGroups) / 2;
        int ans = endGroups[mid] - endGroups[mid-1];
        bool pos = ans >= 2;
        fore(i,1, mid){
            pos &= (s[endGroups[i]] == s[endGroups[SZ(endGroups) - i]]) && 
                (endGroups[i] - endGroups[i-1] + endGroups[SZ(endGroups) - i] - endGroups[SZ(endGroups) - i - 1] >= 3); 
        }
        if (pos) cout << ans+1 << "\n";
        else cout << "0\n";
    }

    return 0;
}
