#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,end=b;i<end;i++)
#define ALL(s) s.begin(),s.end()
#define SZ(s) int(s.size())
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

bool compareStrings(const string &first, const string &second)
{
    if (SZ(first) != SZ(second))
        return SZ(first) > SZ(second);
    return first < second;
}

vector<vector<int>> generatePosibilites(vector<vector<int>> actPos, int toAdd, vector<string> &dict, set<pair<string, string>> &pairs){
    if (toAdd == 0) return actPos;
    vector<vector<int>> toReturn;
    fore(i,0,SZ(actPos) - 1){
        vector<int> act = actPos[i];
        int lastIdx = act[SZ(act)-1];
        fore(j,lastIdx+1, SZ(dict)){
            bool possible = true;
            int comparing = 0;
            while (possible && comparing < SZ(act)){
                possible = !pairs.count({dict[act[comparing]], dict[j]});
                comparing++;
            }
            if (possible){
                toReturn.pb(act);
                toReturn[SZ(toReturn) - 1].pb(j);
            }
        }
    }
    return generatePosibilites(toReturn, --toAdd, dict, pairs);

}

int main()
{FIN;
    int n;
    cin >> n;
    int setNumber = 0;
    while(n--){
        setNumber++;
        set<pair<string, string>> pairs;
        int t, p, s;
        cin >> t >> p >> s;
        vector<string> topics (t);
        fore(i,0,t){
            string act;
            cin >> act;
            transform(act.begin(), act.end(), act.begin(), ::toupper);
            topics[i] = act;
        }
        sort(topics.begin(), topics.end(), compareStrings);
        fore(i,0, p){
            string first, second;
            cin >> first >> second;
            transform(first.begin(), first.end(), first.begin(), ::toupper);
            transform(second.begin(), second.end(), second.begin(), ::toupper);
            pairs.insert({first, second});
            pairs.insert({second, first});
        }
        vector<vector<int>> possibilites (t);
        fore(i,0,t)
            possibilites[i].pb(i);

        possibilites = generatePosibilites(possibilites, s-1, topics, pairs);
        cout << "Set " << setNumber << ":\n";
        fore(i,0,SZ(possibilites)){
            vector<int> act = possibilites[i];
            fore(j,0,SZ(act) - 1)
                cout << topics[act[j]] << " ";
            cout << topics[act[SZ(act) -1]] << "\n";
        }
        cout << "\n";

    }
    return 0;
}
