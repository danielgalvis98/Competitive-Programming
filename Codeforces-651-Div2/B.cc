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
    cin  >> t;
    while (t--){
        int n;
        cin >> n;
        vi odds;
        vi evens;
        fore(i,0,2*n){
            int new_numb;
            cin >> new_numb;
            if (new_numb%2 == 0)
                odds.pb(i+1);
            else
                evens.pb(i+1);
        }
        if (SZ(evens) % 2 == 0){
            if(SZ(odds) > 1){
                for(int i = 3; i < SZ(odds); i+=2)
                    cout << odds[i-1] << " " << odds[i] << "\n";
                for (int i = 1; i < SZ(evens); i+=2)
                    cout << evens[i-1] << " " << evens[i] << "\n";
            } else {
                for(int i = 1; i < SZ(odds); i+=2)
                    cout << odds[i-1] << " " << odds[i] << "\n";
                for (int i = 3; i < SZ(evens); i+=2)
                    cout << evens[i-1] << " " << evens[i] << "\n";
            }
        } else {
            for(int i = 2; i < SZ(odds); i+=2)
                cout << odds[i-1] << " " << odds[i] << "\n";
            for (int i = 2; i < SZ(evens); i+=2)
                cout << evens[i-1] << " " << evens[i] << "\n";
        }
    }

    return 0;
}
