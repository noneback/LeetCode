/*
	拓扑排序
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(numCourses,vector<int>{}); // shore class depents on i
        int inDegree[numCourses];
        memset(inDegree,0,sizeof(inDegree));

        for (auto &p : prerequisites) {
            inDegree[p[0]]++;
            G[p[1]].push_back(p[0]);
        }

        queue<int> q;
        for (int i = 0;i < numCourses;i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        int cnt = 0;

        while (!q.empty()) {
            int selected = q.front();
            q.pop();
            cnt++;

            auto &depClasses = G[selected];
            for (auto &c : depClasses) {
                inDegree[c]--;
                if (inDegree[c] == 0) {
                    // 0 mean to all preClass has been finished
                    q.push(c);
                }
            }
        }

        return cnt == numCourses;
    }
};
