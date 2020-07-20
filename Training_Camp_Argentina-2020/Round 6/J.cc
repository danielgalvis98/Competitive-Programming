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

int changes [30][30];

void floyd(){ // O(n^3) . Replaces g with min distances
    fore(k,0,30)fore(i,0,30)if(changes[i][k]<1e9)fore(j,0,30)if(changes[k][j]<1e9)
        changes[i][j]=min(changes[i][j],changes[i][k]+changes[k][j]);
}

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    string s, t;
    cin >> s >> t;
    int n;
    cin >> n;
    fore(i,0,30)
        fore(j,0,30){
            if (i == j)
                changes [i][j] = 0;
            else
                changes[i][j] = 1e9;
        }
    fore(i,0,n){
        char a,b;int w;
        cin >> a >> b >> w;
        changes[a-'a'][b-'a'] = min(changes[a-'a'][b-'a'], w);
    }

    floyd();

    bool possible = true;
    string ans = "";
    int sum_cost = 0;
    if (SZ(s) == SZ(t)){
        fore(i,0,SZ(s)){
            if (s[i] == t[i]){
                ans.pb(s[i]);
                continue;
            }
            int min_cost = 1e9;
            char letter = 'a';
            fore(j,0,30){
                if (s[i] - 'a' == j){
                    if (changes[t[i] - 'a'] [j] < min_cost){
                        min_cost = changes[t[i] - 'a'] [j];
                        letter = j + 'a';
                    }
                } else if (t[i] - 'a' == j){
                    if (changes[s[i] - 'a'] [j] < min_cost){
                        min_cost = changes[s[i] - 'a'] [j];
                        letter = j + 'a';
                    }
                } else if (changes[s[i] - 'a'][j] != 1e9 && changes[t[i] - 'a'][j] != 1e9){
                    int pos_cost = changes[s[i] - 'a'][j] + changes[t[i] - 'a'][j];
                    if (pos_cost < min_cost){
                        min_cost = pos_cost;
                        letter = j + 'a';
                    }
                }
            }
            if (min_cost == 1e9){
                possible = false;
                break;
            } else {
                sum_cost += min_cost;
                ans.pb(letter);
            }

        }

        if (possible){
            cout << sum_cost << "\n";
            cout << ans << "\n";
        }
        else
            cout << "-1\n";
    } else {
        cout << "-1\n";
    }
        

    return 0;
}
