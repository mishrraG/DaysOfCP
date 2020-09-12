class Solution {
public:

void helper(vector<vector<int>> &ans,vector<int> current,int n,int k,int start)
{
    if(n==0 and k==0)
    {
        ans.push_back(current);
        return;
    }
    
    if(k==0)
    {
        return;
    }
    
    for(int i=start;i<=9;i++)
    {
        current.push_back(i);
        helper(ans,current,n-i,k-1,i+1);
        current.pop_back();
    }
    
    return;
}

vector<vector<int>> combinationSum3(int k, int n) {
    
    
    vector<vector<int>> ans;
    
    vector<int> current;
    
    helper(ans,current,n,k,1);
    
    return ans;
    
}
};