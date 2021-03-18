class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < n; ++i){
            vector<vector<int>> tuples = threeSum(nums, i + 1, target - nums[i]);
            for(vector<int>& tuple:tuples){
                tuple.push_back(nums[i]);
                res.push_back(tuple);
            }
            while(i < n - 1 && nums[i] == nums[i + 1]) i++;
        }
        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums, int start,int target){
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = start; i < n; ++i){
            vector<vector<int>> tuples = twoSum(nums, i + 1, target - nums[i]);
            for(vector<int>& tuple:tuples){
                tuple.push_back(nums[i]);
                res.push_back(tuple);
            }
            while(i < n - 1 && nums[i] == nums[i + 1]) i++;
        }
        return res;
    }

    vector<vector<int>> twoSum(vector<int>& nums, int start,int target){
        int lo = start, hi = nums.size() - 1;
        vector<vector<int>> res;
        while(lo < hi){
            int sum = nums[lo] + nums[hi];
            int left = nums[lo], right = nums[hi];
            if(sum < target){
                while(lo < hi && left == nums[lo]) lo++;
            }else if(sum > target){
                while(lo < hi && right == nums[hi]) hi--;
            }else{
                res.push_back({left, right});
                while(lo < hi && left == nums[lo]) lo++;
                while(lo < hi && right == nums[hi]) hi--;
            }
        }
        return res;
    }
};