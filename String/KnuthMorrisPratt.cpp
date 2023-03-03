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

/*
String matching algorithm
ALGO FOR LPS:
        if 
Examples:
        Note: In lps array, lps[0] = 0
1.
        i   j
        a   a   b   a   a   b   a   a   a
        0   1   2   3   4   5   6   7   8
        *********************************
        0
2.
        i   j
        a   a   b   a   a   b   a   a   a
        0   1   2   3   4   5   6   7   8
        *********************************
        0   1
        str[i] == str[j] => lps[j] = i+1; i = i+1; j = j+1;
 3.
            i   j
        a   a   b   a   a   b   a   a   a
        0   1   2   3   4   5   6   7   8
        *********************************
        0   1   
        str[i] != str[j] => i = lps[i-1];
 4.
        i       j
        a   a   b   a   a   b   a   a   a
        0   1   2   3   4   5   6   7   8
        *********************************
        0   1   0
        str[i] != str[j] and i==0 =>lps[j] = 0 and j = j+1;
  5.
        i           j
        a   a   b   a   a   b   a   a   a
        0   1   2   3   4   5   6   7   8
        *********************************
        0   1   0   1
        str[i] == str[j] => lps[j] = i+1; i = i+1; j = j+1;
  6.
            i           j
        a   a   b   a   a   b   a   a   a
        0   1   2   3   4   5   6   7   8
        *********************************
        0   1   0   1   2
        str[i] == str[j] => lps[j] = i+1; i = i+1; j = j+1;
  7.
                i           j
        a   a   b   a   a   b   a   a   a
        0   1   2   3   4   5   6   7   8
        *********************************
        0   1   0   1   2   3
        str[i] == str[j] => lps[j] = i+1; i = i+1; j = j+1;
  8.
                    i           j
        a   a   b   a   a   b   a   a   a
        0   1   2   3   4   5   6   7   8
        *********************************
        0   1   0   1   2   3   4
        str[i] == str[j] => lps[j] = i+1; i = i+1; j = j+1;
   9.
                        i           j
        a   a   b   a   a   b   a   a   a
        0   1   2   3   4   5   6   7   8
        *********************************
        0   1   0   1   2   3   4   5
        str[i] == str[j] => lps[j] = i+1; i = i+1; j = j+1;       
   10.
                            i           j
        a   a   b   a   a   b   a   a   a
        0   1   2   3   4   5   6   7   8
        *********************************
        0   1   0   1   2   3   4   5
        str[i] != str[j] => i = lps[i-1];
   11.
                i                       j
        a   a   b   a   a   b   a   a   a
        0   1   2   3   4   5   6   7   8
        *********************************
        0   1   0   1   2   3   4   5
        str[i] != str[j] => i = lps[i-1];
        
  12.
            i                           j
        a   a   b   a   a   b   a   a   a
        0   1   2   3   4   5   6   7   8
        *********************************
        0   1   0   1   2   3   4   5   2
        str[i] == str[j] => lps[j] = i+1; i = i+1; j = j+1;       
*/

