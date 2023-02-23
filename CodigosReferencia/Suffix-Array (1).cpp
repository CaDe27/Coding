// O(nlogn)
vector<int> suffix_array(string& s) {
    s.push_back('$');
    int N = s.size();
    vector<int> p(N), c(N);
    {  // k = 0
        vector<pair<char, int>> a(N);
        for (int i = 0; i < N; ++i)
            a[i] = {s[i], i};
        sort(a.begin(), a.end());
        for (int i = 0; i < N; ++i)
            p[i] = a[i].second;
        for (int i = 1; i < N; ++i)
            c[p[i]] = a[i].first == a[i - 1].first ? c[p[i - 1]] : c[p[i - 1]] + 1;
    }
    for (int k = 0; (1 << k) < N; ++k) {
        for (int i = 0; i < N; ++i)
            p[i] = (p[i] - (1 << k) + N) % N;
        {  // Counting sort
            vector<int> cnt(N), pos(N), p_new(N);
            for (auto x : c)
                cnt[x]++;
            for (int i = 1; i < N; ++i)
                pos[i] = pos[i - 1] + cnt[i - 1];
            for (auto x : p)
                p_new[pos[c[x]]++] = x;
            p = p_new;
        }
        vector<int> c_new(N);
        for (int i = 1; i < N; ++i) {
            pii prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % N]};
            pii now = {c[p[i]], c[(p[i] + (1 << k)) % N]};
            c_new[p[i]] = now == prev ? c_new[p[i - 1]] : c_new[p[i - 1]] + 1;
        }
        c = c_new;
    }
    s.pop_back();
    return vector<int>(p.begin() + 1, p.end());
}

// lcp[i] = lcp(i, i+1)
// lcp(x, y) = min(lcp[x], lcp[x+1], ... lcp[y-1])
vector<int> lcp_array(string& s, vector<int>& p) {
    int N = s.size();
    vector<int> c(N), lcp(N);
    for (int i = 0; i < N; ++i)
        c[p[i]] = i;
    int k = 0;
    for (int i = 0; i < N; ++i) {
        if (c[i] < N - 1) {
            int j = p[c[i] + 1];
            while (max(i, j) + k < N && s[i + k] == s[j + k])
                k++;
            lcp[c[i]] = k;
            k = max(k - 1, 0);
        }
    }
    return lcp;
}