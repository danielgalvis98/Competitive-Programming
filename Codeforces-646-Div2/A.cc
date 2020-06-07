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

    int t;
    cin >> t;
    while (t--){
        int x, n;
        cin >> n >> x;
        int totOdd = 0;
        int totEven = 0;
        fore(i,0,n){
            int act;
            cin >> act;
            if (act % 2 == 0) totEven++;
            else totOdd++;
        }
        if (totOdd == 0){
            cout << "No\n";
            continue;
        }
        
        if (x == n){
            if (totOdd % 2 == 0)
                cout << "No\n";
            else
                cout << "Yes\n";
            
            continue;
        }

        if (x % 2 == 0){
            if (totEven == 0){
                cout << "No\n";
                continue;
            }
        }

        cout << "Yes\n";

    }

    return 0;
}
