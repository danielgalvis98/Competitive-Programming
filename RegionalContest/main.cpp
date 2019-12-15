#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i, a, b) for(int i=a, end=b; i < end; i++)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main()
{
    FIN;
    int t;
    cin>>t;
    while(t-- > 0){
        int n;
        cin>>n;
        vi scores;
        int last = -1;
        int sze = n;
        while (sze-- > 0){
            int act;
            cin>>act;
            if (act == last)
                scores.back()++;
            else {
                scores.pb(1);
                last = act;
            }
        }
        int limit = n / 2;
        int gold;
        int silver = 0;
        int bronce = 0;

        int index = 0;
        gold = scores[index++];
        while(gold >= silver && index < n)
            silver += scores[index++];

        limit -= (gold + silver);
        while (index < n && (bronce + scores[index]) <= limit)
            bronce += scores[index++];

        if (gold >= silver || gold >= bronce)
            gold = silver = bronce = 0;
        cout << gold << " " << silver << " " << bronce << "\n";
    }
    return 0;
}
