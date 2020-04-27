#include <bits/stdc++.h>
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(i,a,b) for(int i = a, end=b; i < end; i++)
#define push_back pb

using namespace std;

int main()
{
    int T;
    cin >> T;
    int x = 0;
    while (T--){
        x++;
        int N;
        cin >> N;
        string words [N];
        fore(i,0,N)
            cin >> words[i];
        vector<string> prefixs;
        fore(i,0,N){
            if (words[i][0] == '*') continue;
            string prefix;
            int j = 0;
            while (j < size(words[i]) && words[i][j] != '*'){
                prefix += words[i][j];
                j++;
            }
            prefixs.pb(prefix);
        }
        sort(prefixs.begin(), prefixs.end());
        string ans = "";
        bool possible = true;
        if (size(prefixs) > 0){
            fore(i,1,size(prefixs))
        }

    }
    return 0;
}
