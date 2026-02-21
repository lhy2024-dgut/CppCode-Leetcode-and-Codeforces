//Leetcode 739. 每日温度
//https://leetcode.cn/problems/daily-temperatures/?envType=problem-list-v2&envId=2cktkvj

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> tem;
        vector<int> ans(temperatures.size(), 0);
        for(long i = 0; i<temperatures.size(); i++){
            while(!tem.empty() &&temperatures[tem.top()] <temperatures[i]){
                ans[tem.top()] = i - tem.top();
                tem.pop();
            }
            tem.push(i);
        }
        
        return ans;
    }
};

/*
使用单调栈解题
当栈为空时入栈
当栈非空时，比较栈顶元素和当前元素的大小关系：
如果当前元素小于等于栈顶元素，则入栈。
如果当前元素大于栈顶元素，
则说明找到了一个比栈顶元素更大的温度。此时需要将栈顶元素出栈，
并计算出它与当前元素之间的距离（即天数差），将结果存储在答案数组中。
然后继续比较新的栈顶元素和当前元素，直到栈为空或当前元素不再大于栈顶元素。
遍历结束时，栈中剩余的元素表示没有找到比它们更大的温度，因此它们在答案数组中的值保持为0。
*/