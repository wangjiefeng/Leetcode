/**比较基础的一道题  Runtime:75ms!!!
**就是有点慢
**/
class Solution {
public:
    bool isPalindrome(int x) 
    {
        if( x < 0) return false;
        if( x / 10  == 0) 
            return true;
        int base = 1;
        while(x/base >= 10)
        {
            base = base*10;
        }
        int left;
        int right;
        while(x > 0)
        {
            right = x%10;
            left = x/base;
            if(right != left) 
                return false;
            x = (x - left*base)/10;
            base /= 100;
        }
        return true;
    }
};