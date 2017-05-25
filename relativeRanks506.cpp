//
//  main.cpp
//  506. Relative Ranks
//
//  Created by CHI-CHUN LU on 2017/5/18.
//  Copyright © 2017年 CHI-CHUN LU. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        
        vector<int> rank;
        
        for(int i=0; i<nums.size(); i++) rank.push_back(i);
        
        sort(rank.begin(), rank.end(), [&](int a, int b) {return nums[a] > nums[b];});
        
        vector<string> ans(nums.size());
        
        for(int i=3; i<nums.size(); i++){
            ans[rank[i]] = to_string(i+1);
        }
        
        if(nums.size() > 0) ans[rank[0]] = "Gold Medal";
        if(nums.size() > 1) ans[rank[1]] = "Silver Medal";
        if(nums.size() > 2) ans[rank[2]] = "Bronze Medal";
        
        return ans;
        
        /*
        vector<int> rank;
        for(int i=0; i<nums.size(); ++i) rank.push_back(i);
        for(auto r:rank) cout<<r<<" ";
        cout<<endl;
        
        sort(rank.begin(), rank.end(), [&](int a, int b){return nums[a] > nums[b];});
        for(auto r:rank) cout<<r<<" ";
        cout<<endl;
        
        vector<string> ranks(nums.size());
        
        for(int i=3; i<nums.size(); ++i){
            ranks[rank[i]] = to_string(i+1);
        }
        
        if(nums.size() > 0) ranks[rank[0]] = "Gold Medal";
        if(nums.size() > 1) ranks[rank[1]] = "Silver Medal";
        if(nums.size() > 2) ranks[rank[2]] = "Bronze Medal";
        
        return ranks;
        */
         
        /* my
        vector<int> temp;
        vector<string> ans;
        int index1 = 0, index4 = 0;
        
        for(int i = 0; i<nums.size(); i++){
            ans.push_back(to_string(nums[i]));
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>nums[index1]){
                index1 = i;
            }
        }
        index4 = nums[index1] + 1;
        
        for(int i=0; i<nums.size(); i++){
            
            nums[i] = abs(nums[i] - index4);
            
        }
        
        //for(auto n:nums) cout<<n<<" ";
        //cout<<endl;
        
        for(int i=0; i<nums.size(); i++){
            temp.push_back(nums[i]);
        }
        sort(temp.begin(), temp.end());
        //for(auto n:temp) cout<<n<<" ";
        //cout<<endl;
        
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if(nums[i] == temp[j]){
                    nums[i]= j+1;
                }
            }
        }
        //for(auto n:nums) cout<<n<<" ";
        //cout<<endl;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                ans[i] = "Gold Medal";
            }else if(nums[i] == 2){
                ans[i] = "Silver Medal";
            }else if(nums[i] == 3){
                ans[i] = "Bronze Medal";
            }else{
                ans[i] = to_string(nums[i]);
            }
            
        }
        
        return ans;
        */
        
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {10,3,8,9,4};
    vector<string> ans;
    
    Solution rel;
    
    ans = rel.findRelativeRanks(nums);
    
    for(auto a:ans) cout<<a<<" ";
    cout<<endl;
    
    return 0;
}
