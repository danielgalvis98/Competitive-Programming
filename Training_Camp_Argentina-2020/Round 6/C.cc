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

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif

    int n;
    string s;
    cin >> n >> s;
    int act_depth = 0;
    int max_depth = 0;
    int totCols = 0;
    bool advancing = true;
    fore(i,0,n){
        char act = s[i];
        if (act == '['){
            advancing = true;
            totCols += 2;
            act_depth++;
        }
        else {
            max_depth = max(max_depth, act_depth);
            act_depth--;
            if (advancing){
                totCols+=3;
                advancing = false;
            }
        }
    }
    int rows = 3 + 2*max_depth;
    char symbols [rows][totCols];
    fore(i,0,rows)
        fore(j,0,totCols)
            symbols[i][j] = ' ';
    advancing = true;
    int actCol = 0;
    fore(i,0,n){
        char act = s[i];
        if (act == '['){
            if (!advancing){
                advancing = true;
                actCol++;
            }
            int tot_vert = 1 + 2*(max_depth - act_depth - 1);
            symbols[act_depth][actCol] = symbols[act_depth + tot_vert + 1][actCol] = '+';
            symbols[act_depth][actCol+1] = symbols[act_depth+tot_vert + 1][actCol+1] = '-';
            fore(j,act_depth+1,act_depth + tot_vert + 1)
                symbols[j][actCol] = '|';
            act_depth++;
            actCol++;
        }
        else {
            if (advancing){
                actCol+=2;
                advancing = false;
            }
            act_depth--;
            int tot_vert = 1 + 2*(max_depth - act_depth - 1);
            symbols[act_depth][actCol] = symbols[act_depth + tot_vert + 1][actCol] = '-';
            symbols[act_depth][actCol+1] = symbols[act_depth+tot_vert + 1][actCol+1] = '+';
            fore(j,act_depth+1, act_depth + tot_vert + 1)
                symbols[j][actCol+1] = '|';
            actCol++;
        }
    }

    fore(i,0,rows){
        fore(j,0,totCols)
            cout << symbols[i][j];
        cout << "\n";
    }


    return 0;
}
