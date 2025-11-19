class Solution {
  public:
    int gcd(int a, int b) {
        // int res = min(a,b);
        // while(res>0){
        //     if(a%res==0 && b%res==0){
        //         break;
        //     }
        //     res--;
        // }
        
        // return res;
        
        return b==0 ? a : gcd(b,a%b);
    }
};
