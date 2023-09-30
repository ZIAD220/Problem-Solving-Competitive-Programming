const int N = 100;
const ll OO = 1e9;
ll adj[N][N]; //Adj matrix 

void warshall() {
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}
 
int main() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            adj[i][j] = i == j ? 0 : OO;
}