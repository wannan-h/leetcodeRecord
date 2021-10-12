//Given a data stream input of non-negative integers a1, a2, ..., an, summarize 
//the numbers seen so far as a list of disjoint intervals. 
//
// Implement the SummaryRanges class: 
//
// 
// SummaryRanges() Initializes the object with an empty stream. 
// void addNum(int val) Adds the integer val to the stream. 
// int[][] getIntervals() Returns a summary of the integers in the stream curren
//tly as a list of disjoint intervals [starti, endi]. 
// 
//
// 
// Example 1: 
//
// 
//Input
//["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum"
//, "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
//[[], [1], [], [3], [], [7], [], [2], [], [6], []]
//Output
//[null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]],
// null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]
//
//Explanation
//SummaryRanges summaryRanges = new SummaryRanges();
//summaryRanges.addNum(1);      // arr = [1]
//summaryRanges.getIntervals(); // return [[1, 1]]
//summaryRanges.addNum(3);      // arr = [1, 3]
//summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
//summaryRanges.addNum(7);      // arr = [1, 3, 7]
//summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
//summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
//summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
//summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
//summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]
// 
//
// 
// Constraints: 
//
// 
// 0 <= val <= 104 
// At most 3 * 104 calls will be made to addNum and getIntervals. 
// 
//
// 


#include "../bits/stdc++.h"

//leetcode submit region begin(Prohibit modification and deletion)
class SummaryRanges {
public:
    vector<vector<int>> its;
    SummaryRanges() {
    }
    
    void addNum(int v) {
        int n = its.size();
        if(n == 0){
            its.push_back({v, v});
        }
        int l = 0, r = n - 1;
        int m;
        while(l < r){
            m = (r + l + 1) >> 1;
            if(its[m] <= val){
                l = m;
            }else{
                r = m - 1;
            }
        }
        int pre = r, next = r + 1;
        if((pre[0] >= v && pre[1] <= v)||(next[0] >= v && next[1] <= v)){
            //元素已存在
        }else if(pre[1] + 1 == v && next[0] - 1 == v){
            its[pre][1] = 0;
        }

        if(its[pre][1] == its[pre][0]){

        }else if(its[next][1])


    }
    
    vector<vector<int>> getIntervals() {

    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
//leetcode submit region end(Prohibit modification and deletion)
