#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i, a, b) for (int i = a, end = b; i < end; i++)
#define ALL(s) s.begin(), s.end()
#define SZ(s) int(s.size())
#define pb push_back
#define FIN                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
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

    int s, l, n;
    cin >> s >> l >> n;
    map<string, int> indexOf;
    string animals[s];
    bool areFriends [s][s];
    memset(areFriends, false, sizeof areFriends);
    int total [s];
    int lastIndexes [s];
    memset(total, 0, sizeof total);
    memset(lastIndexes, 0, sizeof lastIndexes);
    fore(i, 0, s)
    {
        cin >> animals[i];
    }
    sort(animals, animals + s);
    fore (i,0,s)
        indexOf[animals[i]] = i;
    fore(i, 0, l)
    {
        string an1;
        cin >> an1;
        string an2;
        cin >> an2;
        int ia1 = indexOf[an1];
        int ia2 = indexOf[an2];
        areFriends[ia1][ia2] = areFriends[ia2][ia1] = true;
    }

    int theRow[n];
    fore(i, 0, n){
        string animal;
        cin >> animal;
        theRow[i] = indexOf[animal];
        total[theRow[i]]++;
    }

    string ans[n];

    fore(i, 0, n)
    {
        fore(j, 0, s)
        {
            if (total[j] == 0) continue;
            int &lastIdx = lastIndexes[j];
            bool foundAnimal = false;
            while (lastIdx < n)
            {
                if (theRow[lastIdx] == -1 || areFriends[j][theRow[lastIdx]])
                {
                    lastIdx++;
                    continue;
                }
                if (theRow[lastIdx] == j)
                {
                    ans[i] = animals[j];
                    theRow[lastIdx++] = -1;
                    foundAnimal = true;
                    total[j]--;
                    break;
                }
                break;
            }
            if (foundAnimal)
                break;
        }
    }
    cout << ans[0];
    fore(i, 1, n)
        cout<< " " << ans[i];
    cout << "\n";
    return 0;
}
