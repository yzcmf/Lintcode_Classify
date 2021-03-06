/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/single-number-iii
@Language: C++
@Datetime: 16-08-17 21:29
*/

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
vector<int>singleNumberIII(vector<int> &A){
        // write your code here
        
        int t = 0;
        
        for(const auto v : A)
            t ^= v;
        
        int mask = t & ~(t-1);
        
        int x = 0;
        int y = 0;
        
        for(const auto v : A)
        {
            if(v & mask) 
                x^=v;
            else
                y^=v;
        }
        
        return vector<int>{x,y};
}

};