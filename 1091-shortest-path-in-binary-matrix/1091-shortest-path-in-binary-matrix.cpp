class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        // If source or destination is blocked
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        vector<vector<int>> dis(n, vector<int>(n, 1e9));

        queue<pair<pair<int,int>,int>> q;

        q.push({{0,0},1});
        dis[0][0] = 1;

        int drow[] = {-1,-1,-1,0,0,1,1,1};
        int dcol[] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            if(row == n-1 && col == n-1)
                return dist;

            for(int i=0;i<8;i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n &&
                   ncol>=0 && ncol<n &&
                   grid[nrow][ncol]==0 &&
                   dist+1 < dis[nrow][ncol])
                {
                    dis[nrow][ncol] = dist + 1;
                    q.push({{nrow,ncol},dist+1});
                }
            }
        }

        return -1;
    }
};