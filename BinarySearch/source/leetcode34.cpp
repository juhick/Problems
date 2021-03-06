class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = searchLeft(nums, target);
        int right = searchRight(nums, target);
        vector<int> res;
        res.push_back(left);
        res.push_back(right);
        return res;
    }

    int searchLeft(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                right = mid - 1;
            }else if (nums[mid] > target){
                right = mid - 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }
        }
        if( left >= nums.size() || nums[left] != target){
            return -1;
        }
        return left;
    }

    int searchRight(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                left = mid + 1;
            }else if (nums[mid] > target){
                right = mid - 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }
        }
        if( right < 0 || nums[right] != target){
            return -1;
        }
        return right;
    }
};