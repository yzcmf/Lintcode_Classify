/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/interleaving-string
@Language: C++
@Datetime: 16-08-21 00:59
*/

class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        
        int len1 =s1.size();
        int len2 =s2.size();
        int len3 =s3.size();
        
        if(len3!=len1+len2) return false;
        
    vector<vector<bool>>f(1+len1,vector<bool>(1+len2,true));
    //s1[i1-1] == s3[i1+i2-1] && f[i1-1][i2]
    for(int i=1;i<=len1;i++)
      f[i][0] = s1[i-1]==s3[i-1] && f[i-1][0];
      
    //s2[i2-1] == s3[i1+i2-1] && f[i1][i2-1]
    for(int i=1;i<=len2;i++)
      f[0][i] = s2[i-1]==s3[i-1] && f[0][i-1];
    
    // i1>=1,i2>=1
    for(int i1=1;i1<=len1;i1++)
    {
        for(int i2=1;i2<=len2;i2++)
        {
            bool case1 = s1[i1-1]==s3[i1+i2-1] && f[i1-1][i2];
            bool case2 = s2[i2-1]==s3[i1+i2-1] && f[i1][i2-1];
            f[i1][i2] = case1||case2;
        }
        
    }
    return f[len1][len2];
    }
};

/*
f[i1][i2] = (s1[i1 - 1] == s3[i1 + i2 - 1] && f[i1 - 1][i2]) ||
            (s2[i2 - 1] == s3[i1 + i2 - 1] && f[i1][i2 - 1])
*/

//A good reference: http://www.kancloud.cn/kancloud/data-structure-and-algorithm-notes/73085

// class Solution {
// public:
//     /**
//      * Determine whether s3 is formed by interleaving of s1 and s2.
//      * @param s1, s2, s3: As description.
//      * @return: true of false.
//      */
//     bool isInterleave(string s1, string s2, string s3) {
//         int len1 = s1.size();
//         int len2 = s2.size();
//         int len3 = s3.size();

//         if (len3 != len1 + len2) return false;

//         vector<vector<bool> > f(1 + len1, vector<bool>(1 + len2, true));
//         // s1[i1 - 1] == s3[i1 + i2 - 1] && f[i1 - 1][i2]
//         for (int i = 1; i <= len1; ++i) {
//             f[i][0] = s1[i - 1] == s3[i - 1] && f[i - 1][0];
//         }
//         // s2[i2 - 1] == s3[i1 + i2 - 1] && f[i1][i2 - 1]
//         for (int i = 1; i <= len2; ++i) {
//             f[0][i] = s2[i - 1] == s3[i - 1] && f[0][i - 1];
//         }
//         // i1 >= 1, i2 >= 1
//         for (int i1 = 1; i1 <= len1; ++i1) {
//             for (int i2 = 1; i2 <= len2; ++i2) {
//                 bool case1 = s1[i1 - 1] == s3[i1 + i2 - 1] && f[i1 - 1][i2];
//                 bool case2 = s2[i2 - 1] == s3[i1 + i2 - 1] && f[i1][i2 - 1];
//                 f[i1][i2] = case1 || case2;
//             }
//         }

//         return f[len1][len2];
//     }
// };