#include <bits/stdc++.h>
using namespace std;

class DSU{
private:
    int *par;
    int *rank;
public:
    DSU(int n){
        par = new int[n];
        iota(par, par + n, 0);

        rank = new int[n];
        for(int i = 0; i < n; i++)
            rank[i] = 1;
    }

    int get_parent(int a){
        return par[a] == a ? a : par[a] = get_parent(par[a]);
    }

    bool same_set(int a, int b){
        return get_parent(a) == get_parent(b);
    }

    int size(int a){
        return rank[a];
    }

    bool join(int a, int b){
        a = get_parent(a);
        b = get_parent(b);

        if (same_set(a, b))
            return false;

        if (rank[a] < rank[b])
            swap(a, b);

        rank[a] += rank[b];
        par[b] = a;
        return true;
    }

};
