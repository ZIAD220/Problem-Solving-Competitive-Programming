#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define f first
#define s second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

/*
 *  Key idea: We can use backtracking to solve the problem.
 *            For each cell we will try to put a queen in it. When we do that, all diagonals and
 *            row related to this cell will not be available to assign queen on them.
 *            We will start from column 1 till we finish all columns. This will also ensure that
 *            the solutions are printed in lexicographical order.
 */


bool vis[9][9], visR[9]; // vis[][] array for diagonals and visR[] is for rows.
int cnt = 0; // Count of solutions.
int xs, ys; // x-start and y-start (Input).
vector<int> queens; // Vector of solution.

// Function to loop on diagonals and set them visited.
void setDiagonals(int x, int y, vector<pair<int, int>> &used)
{
    vis[x][y] = true;
    used.emplace_back(x, y);
    for(int i = x + 1, j = y + 1; i < 9 && j < 9; i++, j++)
        if (!vis[i][j])
            vis[i][j] = true, used.emplace_back(i, j);
    for(int i = x + 1, j = y - 1; i < 9 && j > 0; i++, j--)
        if (!vis[i][j])
            vis[i][j] = true, used.emplace_back(i, j);
    for(int i = x - 1, j = y + 1; i > 0 && j < 9; i--, j++)
        if (!vis[i][j])
            vis[i][j] = true, used.emplace_back(i, j);
    for(int i = x - 1, j = y - 1; i > 0 && j > 0; i--, j--)
        if (!vis[i][j])
            vis[i][j] = true, used.emplace_back(i, j);
}

void go(int idx)
{
    // Base case.
    if (idx == 9){
        cnt++;
        cout << setw(2) << cnt << "     ";
        for(int i : queens)
            cout << ' ' << i;
        cout << '\n';
        return;
    }

    // If this is the column given in the input, just add x-start and keep going.
    if (idx == ys){
        queens.push_back(xs);
        go(idx + 1);
        queens.pop_back();
        return;
    }

    for(int i = 1; i < 9; i++){
        // If we can't assign queen here, continue.
        if (visR[i] || vis[i][idx]) continue;

        // Otherwise, add this queen to our answer and let's go to the next column.
        queens.push_back(i);
        visR[i] = true;
        vector<pair<int, int>> used; // Cells that affected assigning a queen to this cell.
        setDiagonals(i, idx, used);

        go(idx + 1);

        visR[i] = false;
        for(auto &p : used)
            vis[p.f][p.s] = false;
        queens.pop_back();
    }
}

int main()
{
    fast
    int t;
    cin >> t;
    bool first_time = true;
    while(t--)
    {
        cin >> xs >> ys;
        if (!first_time)
            cout << '\n';
        first_time = false;
        cnt = 0;
        visR[xs] = true;
        vector<pair<int, int>> tmp;
        setDiagonals(xs, ys, tmp);
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        go(1);
        for(int i = 0; i < 9; i++){
            visR[i] = false;
            for(int j = 0; j < 9; j++)
                vis[i][j] = false;
        }
        queens.clear();
    }
}