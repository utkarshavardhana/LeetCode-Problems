// Problem: https://leetcode.com/problems/trapping-rain-water-ii/
//
// Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.
//
// Example:
// Given the following 3x6 height map:
// [
//   [1,4,3,1,3,2],
//   [3,2,1,3,2,4],
//   [2,3,3,2,3,1]
// ]
// Return 4.
//
// Constraints:
//
// 1 <= m, n <= 110
// 0 <= heightMap[i][j] <= 20000

class Solution {
    struct HeapNode {
        int height;
        int i;
        int j;
    };

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        auto compare = [](HeapNode &a, HeapNode &b) {
            return a.height > b.height;
        };
        int m = heightMap.size();
        int n = m==0 ? 0 : heightMap.front().size();
        if(m < 2 || n < 2) {
            return 0;
        }
        vector<vector<bool> > visted(m, vector<bool>(n, 0));
        priority_queue<HeapNode, vector<HeapNode>, decltype(compare)> heights(compare);
        for(int i=0; i<n; ++i) {
            visted[0][i] = true;
            visted[m-1][i] = true;
            heights.push({heightMap[0][i], 0, i});
            heights.push({heightMap[m-1][i], m-1, i});
        }
        for(int j=1; j<m-1; ++j) {
            visted[j][0] = true;
            visted[j][n-1] = true;
            heights.push({heightMap[j][0], j, 0});
            heights.push({heightMap[j][n-1], j, n-1});
        }
        int water_num = 0;
        auto judge = [&](int i, int j) {
            if(i<0 || i>=m || j<0 || j>=n) return false; 
            if(visted[i][j]) {
                return false;
            }
            visted[i][j] = true;
            return true;
        };
        auto handle = [&](const HeapNode &top, HeapNode target) {
            if (target.height < top.height) {
                water_num += (top.height-target.height);
            }
            target.height = max(top.height, target.height);
            heights.push(target);
        };
        vector< pair<int, int> > directions = {{1, 0}, {-1, 0}, {0,1}, {0,-1}};
        while(!heights.empty()) {
            auto top = heights.top();
            heights.pop();
            for(auto &dir: directions) {
                if(judge(top.i+dir.first, top.j+dir.second)) {
                    handle(top, {heightMap[top.i+dir.first][top.j+dir.second], top.i+dir.first, top.j+dir.second});
                }
            }
        }
        return water_num;
    }
};
