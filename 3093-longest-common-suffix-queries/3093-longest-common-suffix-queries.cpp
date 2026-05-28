class Solution {
public:
    struct Node {
        int nxt[26];
        int best;

        Node() {
            memset(nxt, -1, sizeof(nxt));
            best = -1;
        }
    };

    vector<Node> trie;

    bool better(int a, int b, vector<string>& w) {
        if (b == -1)
            return true;

        if (w[a].size() == w[b].size())
            return a < b;

        return w[a].size() < w[b].size();
    }

    void insert(string& s, int idx, vector<string>& w) {
        int node = 0;

        if (better(idx, trie[node].best, w))
            trie[node].best = idx;

        for (int i = s.size() - 1; i >= 0; i--) {
            int c = s[i] - 'a';

            if (trie[node].nxt[c] == -1) {
                trie[node].nxt[c] = trie.size();
                trie.push_back(Node());
            }

            node = trie[node].nxt[c];

            if (better(idx, trie[node].best, w))
                trie[node].best = idx;
        }
    }

    int query(string& s) {
        int node = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            int c = s[i] - 'a';

            if (trie[node].nxt[c] == -1)
                break;

            node = trie[node].nxt[c];
        }

        return trie[node].best;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        trie.push_back(Node());

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;

        for (auto& q : wordsQuery) {
            ans.push_back(query(q));
        }

        return ans;
    }
};