#include <bits/stdc++.h>
#define ff first
#define ss second
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

    int n, q;
    cin >> n >> q;
    queue<int> poss [n];
    vector<pair<int, bool>> notifications;
    int totUnread = 0;
    int lastDeleted = 0;
    fore(i,0,q){
        int t, x;
        cin >> t >> x;
        if (t == 1){
            notifications.pb({--x,0});
            poss[x].push(SZ(notifications)-1);
            totUnread++;
        } else if (t == 2){
            x--;
            while (SZ(poss[x])){
                int numberNot = poss[x].front();
                poss[x].pop();
                notifications[numberNot].second = 1;
                totUnread--;
            }
        } else {
            fore(noti, lastDeleted, x){
                if (!notifications[noti].ss){
                    notifications[noti].ss = 1;
                    poss[notifications[noti].ff].pop();
                    totUnread--;
                }
            }
            lastDeleted = x;
        }
        cout << totUnread << "\n";
    }

    return 0;
}
