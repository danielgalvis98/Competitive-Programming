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
{FIN;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    int N;
    cin >> N;
    vector<string> passingTeams;
    map<string, int> totTeams;

    fore(i,0,N){
        string university, teamName;
        cin >> university >> teamName;
        if (university == "SCH")
            continue;
        if (totTeams.count(university)){
            int &totTeamsInThis = totTeams[university];
            if ((totTeamsInThis == 4 && university == "MSU") ||
                (totTeamsInThis == 2 && university != "MSU"))
                continue;
            totTeamsInThis++;
        } else {
            totTeams[university] = 1;
        }
        passingTeams.push_back(university + " " +teamName);
        if (SZ(passingTeams) == 10) break; 
    }
    cout << SZ(passingTeams) << "\n";
    fore(i,0,SZ(passingTeams))
        cout << passingTeams[i] << "\n";

    return 0;
}
