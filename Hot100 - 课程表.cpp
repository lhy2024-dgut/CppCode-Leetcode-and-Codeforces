//Leetcode 207. 课程表
//https://leetcode.cn/problems/course-schedule/?envType=problem-list-v2&envId=2cktkvj


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. 建立通讯录（邻接表）和 债务账本（入度数组）
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        // 遍历先决条件，填充图和入度
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            // 箭头方向：prerequisite -> course
            graph[prerequisite].push_back(course);
            inDegree[course]++; // 依赖别人，债务+1
        }
        
        // 2. 筛选 VIP，把所有入度为 0 的课放进队列
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        // 3. 开始 BFS 业务流转
        int learnedCount = 0; // 记录学完的课程数量
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            learnedCount++; // 学完一门课！
            
            // 通知所有依赖这门课的后续课程
            for (int nextCourse : graph[current]) {
                inDegree[nextCourse]--; // 你的前置课搞定了一门，债务-1
                // 如果债务清零，可以上了，入队！
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        
        // 4. 年底查账：学完的课数量等于总课程数吗？
        return learnedCount == numCourses;
    }
};



//先建立邻接表，graph[i] 表示上完课程 i 后可以上的课程列表；
//同时建立入度数组 inDegree，记录每门课程的前置课程数量。

//然后遍历课程列表，将所有入度为 0 的课程加入队列，这些课程可以立即学习；
//每次从队列中取出一个课程，将其对应的所有后续课程的入度减 1
//如果后续课程的入度变为 0，则将其加入队列；
//重复上述过程，直到队列为空；
//最后检查是否所有课程都被学习过，如果是则返回 true，否则返回 false。