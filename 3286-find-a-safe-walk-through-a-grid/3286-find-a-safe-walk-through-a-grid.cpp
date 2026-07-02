class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> best(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        best[0][0] = startHealth;
        q.push({0, 0});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int rem = best[r][c] - grid[nr][nc];

                if (rem > 0 && rem > best[nr][nc]) {
                    best[nr][nc] = rem;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }
};