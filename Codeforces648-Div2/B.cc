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

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int arr [n];
        bool isOrdered = true;
        fore(i,0,n){
            cin >> arr[i];
            if (i > 0)
                isOrdered &= arr[i-1] <= arr[i];
        }
        bool has0 = false;
        bool has1 = false;

        fore(i,0,n){
            int num;
            cin >> num;
            if (num == 0)
                has0 = true;
            else
                has1 = true;
        }
        if (isOrdered || (has1 && has0))
            cout << "Yes\n";
        else
            cout << "No\n";
        
        
    }
    return 0;
}
