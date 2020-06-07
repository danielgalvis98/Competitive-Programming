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

int trie(string &s){
    int totZeroes = 0;
        int totOnes = 0;
        char firstCoso = s[0];
        int toIndex = 1;
        while( toIndex < SZ(s) && s[toIndex] == firstCoso)
            toIndex++;
        
        char lastCoso = s[SZ(s)-1];
        int backIndex = SZ(s) - 2;
        while( backIndex >= 0 && s[backIndex] == lastCoso)
            backIndex--;
        

        fore(i,toIndex, backIndex + 1){ 
            if (s[i] == '0'){
                totZeroes++;
            }
            else 
                totOnes++;
        }
        if (s[0] == s[SZ(s)-1]){
            if (s[0] == '0')
                totZeroes+= min(toIndex, SZ(s) - backIndex - 1);
            else 
                totOnes+= min(toIndex, SZ(s) - backIndex - 1);
        }

        return min(totOnes, totZeroes);
}

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
        string s;
        cin >> s;

        int result = trie(s);
        
        

        cout << result << "\n";
    }

    return 0;
}
