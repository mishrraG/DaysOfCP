class Solution {
	
	public:
	
	int bitwiseComplement(int n) {
    
    if(n==0) return 1;
    
    int power=1;
    
    int ans=0;
    
    while(n>0)
    {
        int bit=n&1;
        
        if(bit==0)
        {
            ans+=(1*power);
        }
        
        n=n>>1;
        
        power=power*2;
        
    }
    
    return ans;
    
    
}
};
