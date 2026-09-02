class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int left=0;

        long long sum=0;
        long long ans=0;
        
        unordered_set<int>st;
        for(int right=0;right<nums.size();right++)
        {
            while(st.find(nums[right])!=st.end())
            {
                st.erase(nums[left]);
                sum-=nums[left];
                left++;
            }
            st.insert(nums[right]);
            sum+=nums[right];

            if(right-left+1>k)
            {
                st.erase(nums[left]);
                sum-=nums[left];
                left++;
            }
            if(right-left+1==k)
            {
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};