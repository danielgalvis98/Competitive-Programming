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

    int N;
    cin >> N;
    int id = 0;
    while (N--){
        string instr;
        cin >> instr;
        if (instr == "ISSUE"){
            string code;
            cin >> code;
        } else if (instr == "FIND"){

        } else {

        }
    }


    return 0;
}
