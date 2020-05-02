#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

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
typedef vector<ll> vl;
typedef pair<int, int> ii;


ll totalPos (string &num, vl &dp, int i = 0){
    if (i >= SZ(num)) return 1;
    ll &r = dp[i];
    if (num[i] == '0') return r = 0;
    if (r != -1) return r;

    r = 0;
    r += totalPos(num, dp, i + 1);

    if (i < SZ(num) - 1 && (num[i] - '0')*10 + (num[i+1] - '0') <= 26)  
        r += totalPos(num, dp, i+2);


    return r;
}


int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif

    string num;
    cin >> num;
    while (num != "0")
    {
        vl dp (SZ(num), -1);

        // dp[0] = dp[1] = 1;
        // fore(i,2,SZ(dp)){
        //     if (num[i-1] != 0) dp[i] = dp[i-1];
        //     if (((num[i-2] - '0')*10 + (num[i-1] - '0')) <= 26 && num[i-2] != '0') 
        //         dp [i] = ((dp[i] % 1000000007) + (dp[i-2] % 1000000007)) % 1000000007;
        // }

        cout << totalPos(num, dp) << "\n",
        cin >> num;
    }
    
    return 0;
}
