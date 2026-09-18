class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_set<int> st;
        int i=0,j=0;

        for(j=0;j<nums.size();j++)
        {
            if(abs(i-j)>k){
            st.erase(nums[i]);
            i++;}

            //past me dekha hai nums
            if(st.find(nums[j])!=st.end())
            {
                return true;
            }
            st.insert(nums[j]);
        }
        return false;
    }
};