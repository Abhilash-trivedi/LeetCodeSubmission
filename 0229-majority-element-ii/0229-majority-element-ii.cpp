class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>mp;
        set<int>s;
        vector<int>ans;
        int n=nums.size();
        for(auto i:nums){
            mp[i]++;
            if(mp[i]>(n/3)){
                s.insert(i);
            }
        }
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};