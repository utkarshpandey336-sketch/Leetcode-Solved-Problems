class Solution {
public:
    bool isHappy(int n) {
        int ans=n;
        bool result=false;
        for(int i=0;i<=1e5;i++){
            int temp=ans;
            ans=0;
            while(temp!=0){
               int digit=temp%10;
               temp=temp/10;
               ans+=pow(digit,2);
            }
            if(ans==1){
                result=true;
                break;
            }
        }
        return result;
        
    }
};