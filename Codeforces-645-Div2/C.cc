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
    while(t--){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >>  x2 >> y2;
        ll rows = x2 - x1 + 1;
        ll cols = y2 - y1 + 1;
        if (rows > cols)
            swap(rows, cols);
        if (rows == 1)
            cout << "1\n";
        else
            cout << (rows-1)*cols << "\n";
    }

    return 0;
}
