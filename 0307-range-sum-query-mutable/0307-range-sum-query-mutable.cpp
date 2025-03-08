class NumArray {
public:
    vector<int> segTree;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4 * n, 0);
        buildSegementTree(0, 0, n - 1, nums);
    }

    void buildSegementTree(int i, int left, int right, vector<int>& nums) {
        if (left == right) {
            segTree[i] = nums[left];
            return;
        }
        int mid = (left + right) / 2;

        buildSegementTree(2 * i + 1, left, mid, nums);
        buildSegementTree(2 * i + 2, mid + 1, right, nums);

        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    void updateSegTree(int i, int idx, int val, int left, int right) {
        if (left == right) {
            segTree[i] = val;
            return;
        }
        int mid = (left + right) / 2;

          if (idx <= mid)
            updateSegTree(2 * i + 1, idx, val, left, mid);  
        else
            updateSegTree(2 * i + 2, idx, val, mid + 1, right);

        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    void update(int index, int val) { updateSegTree(0, index, val, 0, n - 1); }

    int rangeSum(int i, int left, int right, int start, int end) {
        if (right < start || left > end) {
            return 0;
        } else if (left >= start && right <= end) {
            return segTree[i];
        }

        int mid = (left + right) / 2;

        return rangeSum(2 * i + 1, left, mid, start, end) +
               rangeSum(2 * i + 2, mid + 1, right, start, end);
    }

    int sumRange(int start, int end) {
        return rangeSum(0, 0, n - 1, start, end);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */