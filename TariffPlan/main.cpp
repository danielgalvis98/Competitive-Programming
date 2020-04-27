#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,end=b;i<end;i++)
#define ALL(s) s.begin(),s.end()
#define SZ(s) int(s.size())
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main()
{
    int T;
    cin >> T;
    int cas = 0;
    while (T--){
        cas++;
        int N;
        cin >> N;
        int costA = 0;
        int costB = 0;
        fore(i,0,N){
            int secs;
            cin >> secs;
            int opA = floor(secs / 30.0) + 1;
            costA += opA*10;
            int opB = floor(secs / 60.0) + 1;
            costB += opB*15;
        }

        if (costA < costB)
            cout <<"Case " << cas << ": Mile " << costA << "\n";
        else if (costA > costB)
            cout <<"Case " << cas << ": Juice " << costB << "\n";
        else
            cout <<"Case " << cas << ": Mile Juice " << costA << "\n";
    }
    return 0;
}
