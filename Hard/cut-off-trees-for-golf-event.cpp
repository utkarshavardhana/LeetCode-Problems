// Problem: https://leetcode.com/problems/cut-off-trees-for-golf-event/
//
// You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:
//
// 0 represents the obstacle can't be reached.
// 1 represents the ground can be walked through.
// The place with number bigger than 1 represents a tree can be walked through, 
// and this positive number represents the tree's height.
// In one step you can walk in any of the four directions top, bottom, left and right 
// also when standing in a point which is a tree you can decide whether or not to cut off the tree.
//
// You are asked to cut off all the trees in this forest in the order of tree's height
// - always cut off the tree with lowest height first. 
// And after cutting, the original place has the tree will become a grass (value 1).
//
// You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees. 
// If you can't cut off all the trees, output -1 in that situation.
//
// You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.
//
// Example 1:
// Input: 
// [
//  [1,2,3],
//  [0,0,4],
//  [7,6,5]
// ]
// Output: 6
//
// Example 2:
// Input: 
// [
//  [1,2,3],
//  [0,0,0],
//  [7,6,5]
// ]
// Output: -1
// 
// Example 3:
// Input: 
// [
//  [2,3,4],
//  [0,0,5],
//  [8,7,6]
// ]
// Output: 6
// Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.
//  
// Constraints:
//
// 1 <= forest.length <= 50
// 1 <= forest[i].length <= 50
// 0 <= forest[i][j] <= 10^9

struct Node{
        int r, c, d;
        bool operator<(const Node& n) const{
            return (d < n.d);
        }
    };

int direct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

Node* dq=new Node[3000];
Node* dqf,*dqb;
vector<Node> v;
char mask[2500];

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        R = forest.size(); C = forest[0].size();
        v.clear();
        for (int i = 0; i < forest.size(); i++) {
            for (int j = 0; j < forest[i].size(); j++) {
                if (forest[i][j] > 1) {
                    Node n={i, j, forest[i][j]}; 
                    v.push_back(n);
                }                
            }
        }
        sort(v.begin(), v.end());
        int ans = 0;
        Node cur={0, 0, 1};
        for (int i = 0; i < v.size(); i++) {
            int step = hadlock(forest, cur.r, cur.c, v[i].r, v[i].c);
            if (step < 0) {
                return -1;
            }
            
            ans += step;
            cur = v[i];
        }
        return ans;
    }
private:
    int R, C;
    int hadlock(vector<vector<int>>& forest, int sr, int sc, int tr, int tc) {    
        dqf=dqb=dq+500;
        Node cur={sr, sc, 0};
        *dqb=cur;
        ++dqb;
        memset(mask,0,R*C);
        while (dqf!=dqb) {
            Node n = *dqf;
            ++dqf;
            if (mask[n.r*C+n.c]) {
                continue;
            }
            mask[n.r*C+n.c] = true;
            if (n.r == tr && n.c == tc) {
                return abs(sr - tr) + abs(sc - tc) + 2*n.d;
            }
            for (int i = 0; i < 4; i++) {
                int nr = n.r + direct[i][0];
                int nc = n.c + direct[i][1];
                if (nr >= 0 && nr < R && nc >= 0 && nc < C && forest[nr][nc] > 0) {
                    bool closer = abs(n.r - tr) > abs(nr - tr) || abs(n.c - tc) > abs(nc - tc);
                    if (closer) {
                        *(--dqf)={nr, nc, n.d};
                    }
                    else {
                        *(dqb++)={nr, nc, n.d+1};
                    }
                }
            }
        }
        
        return -1;
    }
};
