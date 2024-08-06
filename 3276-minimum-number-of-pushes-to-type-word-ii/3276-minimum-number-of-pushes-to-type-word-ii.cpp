class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        int ans=0;
        vector<int> map(26,0);
        for(int i=0;i<n;i++){
            map[word[i]-'a']++;
        }
        sort(map.begin(),map.end(),greater<int>());
        for(int i=0;i<26;i++){
            if(map[i]!=0){
                ans=ans+(map[i]*((i/8)+1));
            }
            else
                break;
        }
        return ans;
    }
};