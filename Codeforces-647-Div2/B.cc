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
{FIN;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif

    int T;
    cin >> T;
    while (T--){
        int totSet;
        cin >> totSet;
        int elems [totSet];
        fore (i,0,totSet)
            cin >> elems[i];
        
        sort(elems, elems + totSet);
        int realK = 1e9;
        fore(k, 1, 1025){
            int toTest [totSet];
            fore(i,0,totSet)
                toTest[i] = elems[i]^k;
            sort(toTest, toTest + totSet);
            bool areEqual = true;
            fore(i,0,totSet)
                areEqual &= toTest[i] == elems[i];
            if(areEqual){
                realK = k;
                break;
            }
        }
        int ans = realK != 1e9 ? realK : -1;
        cout << ans << "\n";
    }

    return 0;
}
