
//- Input, string/vector where you want to find the longest palindrome in each index
//- Output: (can be modified to the needs) size and start indx of the maximum palindrome
//- ans will operate over g. If ans[i]=k, the size of the palindrome centered at g[i] is 2*k-1
//- converting to the original input vector,
//  - the size of the original palindrome is k-1; its start is at indx (i-(k-1))/2
//  - the odd palindromes will be stored in elements different from -1
//  - the even palindrome will be stored in elements with center in -1
pair<int,int> manacher(vector<int> &a) {
    int res = 0;
    vector<int> g(2*a.size()+1);
    for(int i = 0; i < a.size(); ++i){
        g[2*i] = -1; g[2*i+1] = a[i];
    }
    g[2*a.size()] = -1;
    vector<int> ans(g.size(), 0);
    int indxMaxPalindrome = 0;
    for (int i = 0, l = 0, r = -1; i < ans.size(); i++) {
        int &k = ans[i];
        k = (i < r) ? min(r - i, ans[l + r - i]) : 1;
        while (i - k >= 0 && i + k < ans.size() && g[i - k] == g[i + k])
            k++;
        if (i + k > r) {
            l = i - k; r = i + k;
        }
        if(ans[indxMaxPalindrome] < ans[i])
            indxMaxPalindrome = i;
    }
    int i = indxMaxPalindrome, k = ans[indxMaxPalindrome];
    return pair<int, int>(k-1, (i-k+1)/2);
}
