#include <bits/stdc++.h>

using namespace std;

struct SuffixAutomaton
{
    vector<map<char, int>> edges; // edges[i]  : the labeled edges from node i
    vector<int> lnik;             // link[i]   : the parent of i
    vector<int> length;           // length[i] : the length of the longest string in the ith class
    int last;                     // the index of the equivalence class of the whole string

    SuffixAutomaton(string s)
    {
        // add the initial node
        edges.push_back(map<char, int>());
        link.push_back(-1);
        length.push_back(0);
        last = 0;

        for (int i = 0; i < s.size(); i++)
        {
            // construct r
            edges.push_back(map<char, int>());
            length.push_back(i + 1);
            link.push_back(0);
            int r = edges.size() - 1;

            // add edges to r and find p with link to q
            int p = last;
            while (p >= 0 && edges[p].find(s[i]) == edges[p].end())
            {
                edges[p][s[i]] = r;
                p = link[p];
            }
            if (p != -1)
            {
                int q = edges[p][s[i]];
                if (length[p] + 1 == length[q])
                {
                    // we do not have to split q, just set the correct suffix link
                    link[r] = q;
                }
                else
                {
                    // we have to split, add q'
                    edges.push_back(edges[q]); // copy edges of q
                    length.push_back(length[p] + 1);
                    link.push_back(link[q]); // copy parent of q
                    int qq = edges.size() - 1;
                    // add qq as the new parent of q and r
                    link[q] = qq;
                    link[r] = qq;
                    // move short classes pointing to q to point to q'
                    while (p >= 0 && edges[p][s[i]] == q)
                    {
                        edges[p][s[i]] = qq;
                        p = link[p];
                    }
                }
            }
            last = r;
        }
        vector<bool> terminal (edges.size(),0);
        int p = last;
        while (p > 0)
        {
            terminals[p] = true;
            p = link[p];
        }
    }
};


int totSubs(SuffixAutomaton &sa, vector<int> &tot, int idx = 0){
    int &r = tot[idx];
    if (r != -1) return r;

    for(auto childs : sa.edges[idx])
        r += totSubs(sa, tot, childs.second);
    
    return ++r;
}

























//kth Substr


string kthSubstr (string s, int k){
    SuffixAutomaton sa (s);
    vector<int> totSubs(sa.edges.size(), -1);
    totSubs(sa, totSubs);
    String ans  = "";

    int idx = 0;
    --k;
    while (k != 0 && sa.edges[idx].size() != 0){
        for (auto child : sa.edges[idx]){
            if (totSubs[child.second] <= k){
                ans += child.first;
                k--;
                idx = child.second;
                break;
            }

            k -= totSubs[child.second];
        }
    }

    return k != 0? "$" : ans;
}


//Patrón P


int getTerminals (SuffixAutomaton sa, int idx, vector<int> &totTerminals){
    int &r = totTerminals[idx];
    if (r == -1){
        r++;
        if (sa.terminal[idx]) r++;
        for (auto child : sa.edges[i])
            r += getTerminals(child.second);
    }

    return r;
}

int times (string p, string t){
    SuffixAutomaton sa (t);

    int idx = 0;

    for (char next : p){
        if (!sa.edges[idx].count(p)) return 0;
        idx = sa.edges[idx][p];
    }

    return getTerminals(sa, idx, vector<int>(sa.edges.size()));

    

}
