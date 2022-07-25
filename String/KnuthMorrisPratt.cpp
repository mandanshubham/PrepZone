//String matching algorithm

class Solution {
private:
    vector<int> generateLPS(string needle, int m) {
        vector<int> lps(m); 
        
        int prevLPS = 0, i = 1;
        lps[0] = 0;
        while(i<m) {
            if(needle[i]==needle[prevLPS]) {
                lps[i] = prevLPS+1;
                prevLPS += 1;
                i += 1;
            }
            else if(prevLPS==0) {
                lps[i] = 0;
                i += 1;
            }
            else
                prevLPS = lps[prevLPS-1];
        }
        return lps;
    }
public:
    int KMP(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        vector<int> lps = generateLPS(needle, m);
        
        int i=0, j=0;
        while(i<n and j<m) {
            if(haystack[i]==needle[j])
                i += 1, j += 1;
            else if(j==0)
                i += 1;
            else
                j = lps[j-1];
        }
        return (j==m) ? i-m : -1;
    }
};
