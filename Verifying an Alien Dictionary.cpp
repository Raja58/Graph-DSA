// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        19 Dec 2021
//  @Detail  :        Verifying an Alien Dictionary (LeetCode)
//  ============================
//  -->

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string str) {
        vector<int> order(26);
        for(int i = 0; i < 26; i++)
            order[str[i] - 'a'] = i;
        
        for(int i = 0; i < words.size() - 1; i++)
        {
            string str1 = words[i], str2 = words[i + 1];
            for(int j = 0; j < str1.size(); j++)
            {
                if(j >= str2.size())
                    return false;
                if(order[str1[j] - 'a'] < order[str2[j] - 'a'])
                    break;
                if(order[str1[j] - 'a'] > order[str2[j] - 'a'])
                    return false;
            }
        }
        return true;
    }
};
