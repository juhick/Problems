class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> book;
        for(int i = 0; i < nums.size(); i++){
            auto it = book.find(target - nums[i]);
            if(it != book.end()){
                res.push_back(it->second);
                res.push_back(i);
            }
            book[nums[i]] = i;
        }
        return res;
    }
};