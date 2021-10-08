//
// Created by 黄嘉强 on 2021/10/8.
//

#ifndef LEETCODERECORD_TREEARRAY_H
#define LEETCODERECORD_TREEARRAY_H



#define  lowbit(x) x&((~x)+1)


class NumArray {
public:
    vector<int> tree;
    vector<int> nums;
    int n;//4
    NumArray(vector<int> &_nums) {
        n = _nums.size();
        nums.resize(n);
        tree.resize(n + 1);
        for (int i = 0; i < n; i++) {
            add(i + 1, _nums[i]);
            nums[i] = _nums[i];
        }
    }

    int query(int x) {
        int res = 0;
        for (; x > 0; x -= lowbit(x)) { res += tree[x]; }
        return res;
    }

    void add(int x, int k) {
        for (; x <= n; x += lowbit(x)) { tree[x] += k; }
    }

    void update(int x, int k) {
        add(x + 1, k - nums[x]);
        nums[x] = k;
    }

    int sumRange(int l, int r) {
        return query(r + 1) - query(l);
    }
};

void test() {
    vector<int> nums = {1, 3, 5};
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    numArray.update(1, 2);
    cout << numArray.sumRange(0, 2) << endl;

    string s = "123";
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */



/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */



#endif //LEETCODERECORD_TREEARRAY_H
