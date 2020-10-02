class Solution {

public:

void helper(vector<vector<int>> &ans,vector<int> v,vector<int> &candidates,int target,int idx)
{
    // base cases
    
    if(target==0)
    {
        ans.push_back(v);
        return;
    }
    
    if(target<0)
    {
        return;
    }
    
    // body of recursion
    
    for(int i=idx;i<candidates.size();i++)
    {
        if(candidates[i]<=target)
        {
            v.push_back(candidates[i]);
            helper(ans,v,candidates,target-candidates[i],i);
            v.pop_back();
        }
        else
        {
            break;
        }
        
    }
    
    return;
    
    
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    
    
    vector<vector<int>> ans;
    
    vector<int> v;
    
    sort(candidates.begin(),candidates.end());
    
    helper(ans,v,candidates,target,0);
    
    return ans;
    
    
}
};
