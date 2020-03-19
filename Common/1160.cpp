/*
给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。

假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。

注意：每次拼写（指拼写词汇表中的一个单词）时，chars 中的每个字母都只能用一次。

返回词汇表 words 中你掌握的所有单词的 长度之和。

 

示例 1：

输入：words = ["cat","bt","hat","tree"], chars = "atach"
输出：6
解释： 
可以形成字符串 "cat" 和 "hat"，所以答案是 3 + 3 = 6。
示例 2：

输入：words = ["hello","world","leetcode"], chars = "welldonehoneyr"
输出：10
解释：
可以形成字符串 "hello" 和 "world"，所以答案是 5 + 5 = 10。
*/
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
            int a[26];
            int length=0;
            for(int l(0);l<26;l++)
            {
                a[l]=0;
            }
            for(int i(0);i<chars.size();i++)
            {
                a[chars[i]-'a']++;
            }
            for(int i(0);i<words.size();i++)
            {
                int b[26];
                for(int l(0);l<26;l++)
                {
                    b[l]=0;
                }
                for(int j(0);j<words[i].size();j++)
                {
                    b[words[i][j]-'a']++;
                }
                int flag=1;
                for(int l(0);l<26;l++)
                {
                    if(a[l]<b[l])
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                {
                    length+=words[i].size();
                }
            }
            return length;
    }
};