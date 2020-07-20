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

    int n;
    cin >> n;
    ll tot = 0;
    if (n == 1)
        cin >> tot;
    else{
        ll arr [n];
        fore(i,0,n)
            cin >> arr[i];
        
        sort(arr, arr + n);

        fore(i,0,n){
            ll act = arr[n-i-1];
            if (i <= 1)
                tot += act*n;
            else
                tot += act*(n-i+1);
        }
    }
    cout << tot << "\n";

    return 0;
}
