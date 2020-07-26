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

bool comp_inv(char &a, char &b){
    return b < a;
}

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif

    int n, q;
    string s;
    cin >> n >> q >> s;
    char converted [n];
    fore(i,0,n){
        converted[i] = s[i];
    }
    fore(a,0,q){
        int i,j,k;
        cin >> i >> j >> k;
        i--;
        if (k)
            sort(converted+i, converted+j);
        else
            sort(converted + i, converted + j, comp_inv);
    }
    cout << string(converted, n) << "\n";

    return 0;
}

