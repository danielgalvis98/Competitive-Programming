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


class EllysPronunciation 
{
private:
    /* data */
public:
    int getGood(vector<string> words){
        int totBeatifulWords = 0;
        for(string word: words){
            int dif = 0;
            for (char theChar: word){
                if (theChar == 'a' || theChar == 'e' || theChar == 'i' || theChar == 'o' || theChar == 'u')
                    dif++;
                else
                    dif--;
            }
            if (dif == 0)
                totBeatifulWords++;
        }
        return totBeatifulWords;
    }
};





int main(){
    vector<string> a = {"hearing", "vision", "smell", "touch", "taste", "denial", "anger", "bargaining", "depression", "acceptance", "war", "famine", "plague", "death", "pog", "story", "sarah", "gender", "baleen", "posh", "sporty", "scary", "ginger", "baby", "spice"};
    EllysPronunciation b;
    cout << b.getGood(a) << endl;

    return 0;
}
