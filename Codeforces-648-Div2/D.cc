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
typedef vector<ii> vii;

char maze[55][55];
bool visited[55][55];
int n, m;
bool blockBad(ii idx)
{
    if (visited[idx.first][idx.second])
        return true;
    visited[idx.first][idx.second] = true;
    bool ans = true;
    if (idx.first != 0)
    {
        if (maze[idx.first - 1][idx.second] == 'G')
        {
            return false;
        }
        if (maze[idx.first - 1][idx.second] == 'B')
            ans &= blockBad({idx.first - 1, idx.second});
        else
        {
            maze[idx.first - 1][idx.second] = '#';
        }
    }

    if (idx.first != n - 1)
    {
        if (maze[idx.first + 1][idx.second] == 'G')
        {
            return false;
        }
        if (maze[idx.first + 1][idx.second] == 'B')
            ans &= blockBad({idx.first + 1, idx.second});
        else
        {
            maze[idx.first + 1][idx.second] = '#';
        }
    }

    if (idx.second != 0)
    {
        if (maze[idx.first][idx.second - 1] == 'G')
        {
            return false;
        }
        if (maze[idx.first][idx.second - 1] == 'B')
            ans &= blockBad({idx.first, idx.second - 1});
        else
        {
            maze[idx.first][idx.second - 1] = '#';
        }
    }

    if (idx.second != m - 1)
    {
        if (maze[idx.first][idx.second + 1] == 'G')
        {
            return false;
        }
        if (maze[idx.first][idx.second + 1] == 'B')
            ans &= blockBad({idx.first, idx.second + 1});
        else
        {
            maze[idx.first][idx.second + 1] = '#';
        }
    }
    return ans;
}

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vii posBads;
        int totGoods = 0;
        fore(i, 0, n)
        {
            cin >> maze[i];
            fore(j, 0, m)
            {
                if (maze[i][j] == 'G')
                    totGoods++;
                else if (maze[i][j] == 'B')
                    posBads.pb({i, j});
            }
        }
        bool canSolve = true;
        memset(visited, 0, sizeof visited);
        for (ii bad : posBads)
            canSolve &= blockBad(bad);
        int goodsReachable = 0;
        canSolve &= maze[n-1][m-1] != '#';
        if (canSolve)
        {
            memset(visited, 0, sizeof visited);
            queue<ii> theQueu;
            theQueu.push({n-1, m-1});
            visited[n-1][m-1] = true;
            while (SZ(theQueu))
            {
                ii pos = theQueu.front();
                theQueu.pop();
                if (maze[pos.first][pos.second] == 'G')
                {
                    goodsReachable++;
                }
   
                if (pos.first != 0 && !visited[pos.first - 1][pos.second] && maze[pos.first - 1][pos.second] != '#')
                {
                    theQueu.push({pos.first - 1, pos.second});
                    visited[pos.first - 1][pos.second] = true;
                }

                if (pos.first != n - 1 && !visited[pos.first + 1][pos.second] && maze[pos.first + 1][pos.second] != '#')
                {
                    theQueu.push({pos.first + 1, pos.second});
                    visited[pos.first + 1][pos.second] = true;
                }

                if (pos.second != 0 && !visited[pos.first][pos.second - 1] && maze[pos.first][pos.second - 1] != '#')
                {
                    theQueu.push({pos.first, pos.second - 1});
                    visited[pos.first][pos.second - 1] = true;
                }

                if (pos.second != m - 1 && !visited[pos.first][pos.second + 1] && maze[pos.first][pos.second + 1] != '#')
                {
                    theQueu.push({pos.first, pos.second + 1});
                    visited[pos.first][pos.second + 1] = true;
                }
            }
        }
    if (totGoods == goodsReachable)
        cout << "Yes\n";
    else
        cout << "No\n";
    }
    return 0;
}
