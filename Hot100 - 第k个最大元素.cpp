//Leetcode 215. 第k个最大元素
//https://leetcode.cn/problems/kth-largest-element-in-an-array/?envType=problem-list-v2&envId=2cktkvj

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int num : nums){
            minHeap.push(num);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};


/*
如果数组中的元素范围较小且密集，使用桶排序
例如题目里限制了元素的范围在[-10^4, 10^4]，我们可以创建一个大小为20001的桶数组来统计每个元素出现的次数。
然后从桶数组的末尾开始遍历，累加出现的元素数量，直到累加的数量达到k，此时对应的元素就是第k大的元素。



对于跨度极大且数据海量分布的数据，使用小顶堆来排序

创建小顶堆的语法：
priority_queue<int, vector<int>, greater<int>> minHeap;
其中greater<int>是一个比较器，表示小顶堆的排序方式。它会将较小的元素放在堆顶。

小顶堆在内存里是一棵树，只比较上下级的大小，不比较兄弟之间的大小
当向小顶堆里push一个元素时，首先将该元素添加到堆的末尾，然后通过比较该元素与其父节点的大小关系来调整堆的结构。
如果新元素比父节点小，就交换它们的位置，继续向上比较，直到满足小顶堆的性质（即每个节点都不大于其子节点）。
这样新增一个元素的时间复杂度就为O(log k)，其中k是堆的大小。

当小顶堆的大小超过k时，我们需要将堆顶元素（即当前堆中最小的元素）弹出，以保持堆的大小为k。
这样，堆中始终保留着当前最大的k个元素，而堆顶元素就是第k大的元素。



创建大顶堆的语法：
priority_queue<int> maxHeap;
大顶堆的top：第k个大的元素/第k个最小的元素

大顶堆的pop方式：
弹出堆顶元素，然后将最后一个节点放到堆顶，如果堆顶元素比两个节点都小，则与两节点中较大的元素交换位置，然后层层比较，直到满足大顶堆的性质（即每个节点都不小于其子节点）。
*/