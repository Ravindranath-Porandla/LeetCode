class Solution {
public:
    int maxScore(string s) {
        int left=0;
        int right=0;
        int ans=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0')   left++;
            right=0;
            for(int j=i+1;j<s.size();j++){
                if(s[j]=='1')   right++;
            }
            if((left+right)>ans)    ans=left+right;
        }
        return ans;
    }
};