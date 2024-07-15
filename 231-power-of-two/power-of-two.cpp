class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if ((n & (n - 1)) == 0) return true;
        return false;
    }
};
/* class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count=0;
        while(n>0){
            if(n%2==1){
            count++;
            }
            n=n/2;
        }
       return count==1;
    }
}; */