#include <bits/stdc++.h>

using namespace std;

struct state {
    int len, link;
    map<char, int> next;
};

const int MAXLEN = 1505;
state st[MAXLEN * 2];
bool isGood [26];
int sz, last;

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int ans(state act, int k2){

    int anss = 1;
    for (auto it=act.next.begin(); it != act.next.end(); it++){
        if (!isGood[it -> first - 'a']){
            if (k2)
                anss += ans(st[it->second],k2-1);

            continue;
        }
        anss += ans(st[it->second],k2);
    }
    return anss;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sa_init();
    string s;
    string definition;
    int k;
    cin >> s >> definition >> k;
    //cout << definition << "\n";
    for (int i = 0; i < 26; i++)
        isGood[i] = definition[i] - '0';


    for (int i = 0; i < s.size(); i++)
        sa_extend(s[i]);

    //for (auto it=st[0].next.begin(); it != st[0].next.end(); it++)
      //  cout << "key " << it -> first << " value " << it -> second << endl;

    int anss = ans(st[0], k) - 1;

    cout << anss << "\n";
    return 0;
}
