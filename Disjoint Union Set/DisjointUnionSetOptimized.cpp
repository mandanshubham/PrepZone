/*
Disjoint Union Set - Optimized code
Optimizations - 
1. Union by size optimization
2. Path compression optimization
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
int Size[N]; // Union by size (Optimization)

void make(int v) {
    parent[v] = v;
    Size[v] = 1;
}

int find(int v) {
    if(v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    
    if(a != b) {
        // Join the bigger tree under smaller tree - Optimization
        if(Size[a] < Size[b])
            swap(a, b);
        // It means join tree of b under tree of a
        parent[b] = a;
        Size[a] += Size[b];
    }
}

int main() {
    return 0;
}
