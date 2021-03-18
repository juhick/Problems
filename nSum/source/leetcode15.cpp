class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int start, int target){
        int lo = start, hi = nums.size() - 1;
        vector<vector<int>> res;
        while(lo < hi){
            int sum = nums[lo] + nums[hi];
            int left = nums[lo], right = nums[hi];
            if(sum < target){
                while(lo < hi && nums[lo] == left) lo++;
            } else if (sum > target){
                while(lo < hi && nums[hi] == right) hi--;
            }else{
                res.push_back({left, right});
                while(lo < hi && nums[lo] == left) lo++;
                while(lo < hi && nums[hi] == right) hi--;
            }
        }
        return res;
    }


    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            vector<vector<int>> tuples = twoSum(nums, i + 1, 0 - nums[i]);
            for(vector<int>& tuple:tuples){
                tuple.push_back(nums[i]);
                res.push_back(tuple);
            }
            while(i < n - 1 && nums[i] == nums[i + 1]) i++;
        }
        return res;
    }
};