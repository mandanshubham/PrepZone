/*
Disjoint Union Set - Unoptimized code
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

/*
make - Add a new node (or we can say creates a new set containing only one node)
find - returns the root/parent of the set in which vertex v lise
Union - merges the two specified sets (the set in which the element a is located, and the set in which the element b is located)
*/

int parent[N];

void make(int v) {
    parent[v] = v;
}

int find(int v) {
    if(v == parent[v])
        return v;
    return find(parent[v]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    
    if(a != b) {
        // It means join tree of b under tree of a
        parent[b] = a;
    }
}

int main() {
    return 0;
}
