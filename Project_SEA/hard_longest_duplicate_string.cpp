//
//  hard_longest_duplicate_string.cpp
//  Project_SEA
//
//  Created by Dhivyaan S Ramesh on 8/10/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//
/*
 Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)
 
 Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)
 
 
 
 Example 1:
 
 Input: "banana"
 Output: "ana"
 Example 2:
 
 Input: "abcd"
 Output: ""
 */
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
//method 1 using recursion:
//class Solution {
//public:
//    string op = "";
//    int longest = 0, freq = 2;
//
//    vector<unordered_set<int>> sub_cache;
//    unordered_map<string,int> cache;
//    string longestDupSubstring(string S) {
//        vector<unordered_set<int>> sub_cach1(S.length());
//        sub_cache = sub_cach1;
//        if(S.length() == 1)
//            return op;
//        if(S.length() == 2)
//        {
//            if(S[0] == S[1])
//            {
//                string s(1,S[0]);
//                return s;}
//            else
//                return op;
//        }
//        int len = S.length();
//
//        helper(S,0,len-1);
//
//        return op;
//    }
//    void helper(string str,int st,int en)
//    {
//        int l = en-st; string s1,s2;
//        if((l < 1) || (en >= str.length()))
//            return;
//
//        auto it = sub_cache[st].find(l);
//        if(it == sub_cache[st].end())
//        {
//            sub_cache[st].insert(l);
//            s1 = str.substr(st,l);
//            auto it2 = cache.find(s1);
//            if(it2 == cache.end())
//                cache[s1] = 1;
//            else
//            {
//                cache[s1]++;
//            }
//            if(s1.length() > longest)
//            {
//                if(cache[s1] >= freq)
//                {
//                    op = s1;
//                    longest = s1.length();
//                    freq = cache[s1];
//                }
//            }
//
//        }
//        it = sub_cache[st+1].find(l);
//        if(it == sub_cache[st].end())
//        {
//            sub_cache[st+1].insert(l);
//            s1 = str.substr(st+1,l);
//            auto it2 = cache.find(s1);
//            if(it2 == cache.end())
//                cache[s1] = 1;
//            else
//            {
//                cache[s1]++;
//            }
//            if(s1.length() > longest)
//            {
//                if(cache[s1] >= freq)
//                {
//                    op = s1;
//                    longest = s1.length();
//                    freq = cache[s1];
//                }
//            }
//
//        }
//        helper(str, st, en-1);
//        helper(str,st+1,en);
//
//
//    }
//};

//mehod 2
//class Solution {
//public:
//    string op = "";
//    int longest = 0, freq = 2;
//
//
//    unordered_map<string,int> cache;
//    string longestDupSubstring(string S) {
//
//        if(S.length() == 1)
//            return op;
//        if(S.length() == 2)
//        {
//            if(S[0] == S[1])
//            {
//                string s(1,S[0]);
//                return s;}
//            else
//                return op;
//        }
//
//        auto len = S.length();
//        vector<string> prev = {""};
//        for(auto i = 0 ;i < len; i ++)
//        {
//            vector<string> curr;
//
//            for(auto str : prev)
//            {
//                string s1;
//                if(str != "")
//                {
//                s1  = str+S[i];
//                curr.push_back(s1);
//                }
//                else
//                {
//                    string ss(1,S[i]);
//                    s1 = ss;
//                    curr.push_back(s1);
//                }
//
//                auto it2 = cache.find(s1);
//                if(it2 == cache.end())
//                    cache[s1] = 1;
//                else
//                {
//                    cache[s1]++;
//                }
//                if(s1.length() > longest)
//                {
//                    if(cache[s1] >= freq)
//                    {
//                        op = s1;
//                        longest = s1.length();
//                    }
//                }
//
//            }
//            prev = curr;
//            prev.push_back("");
//        }
//
//
//        return op;
//    }
//};
//mehod 3 Binary Search
//class Solution {
//public:
//    string op = "";
//    string str;
//    int len;
//    unordered_set<string> cache;
//    string longestDupSubstring(string S) {
//
//        if(S.length() == 1)
//            return op;
//        if(S.length() == 2)
//        {
//            if(S[0] == S[1])
//            {
//                string s(1,S[0]);
//                return s;}
//            else
//                return op;
//        }
//        str = S;
//        len = S.length();
//        int left = 0,right = len - 1;
//        while (left <= right)
//        {
//            int mid = (left + right)/2;
//            string res = binary_calc(mid);
//            if( res == "")
//                right = mid-1;
//            else
//            {
//                op = res;
//                left = mid+1;
//            }
//
//        }
//
//        return op;
//    }
//    string binary_calc(int lvl)
//    {
//
//        if(lvl == len)
//            return "";
//        int i = 0;
//        while(i <= len-lvl+1)
//        {
//            string s1 = str.substr(i,lvl);
//            auto it2 = cache.find(s1);
//            if(it2 == cache.end())
//                cache.insert(s1);
//            else
//            {
//                return s1;
//            }
//            i++;
//        }
//        cache.clear();
//        //return binary_calc(lvl+1);
//        return "";
//
//        }
//
//};

class Solution {
public:
    string op = "";
    string str;
    int len,prime = pow(2,63) - 1;
    unordered_set<char> cache;
    string find_dup(string str,int sub_l,int factor,vector<int> hash)
    {
        unordered_set<int> tracker;
        int x = 1,h=1;
        while( x<=sub_l)
        {
            h = (h*factor)%prime;
            x++;}
        int y = len - sub_l+1;
        for(auto i = 0; i < (y);i++)
        {
            int g;
            if( i > 0)
            g = (hash[i+sub_l-1] - hash[i-1]*h)%prime;
            else
                g = hash[i+sub_l-1]%prime;
            
            if (g < 0)
                g += prime;
            if(tracker.find(g) == tracker.end())
                tracker.insert(g);
            else
            {
                string res = str.substr(i,sub_l);
                return res;
            }
        }
        return "";
    }
    
    string longestDupSubstring(string S) {

        if(S.length() == 1)
            return op;
        if(S.length() == 2)
        {
            if(S[0] == S[1])
            {
                string s(1,S[0]);
                return s;}
            else
                return op;
        }
        str = S;
        len = S.length();
        vector<int> hash(len);
        for(auto i = 0; i < S.length(); i++)
            cache.insert(S[i]);
        
        int factor = cache.size();
        for(auto i = 0; i < S.length(); i++)
        {
            int c = S[i];
            if( i == 0)
                hash[i] = c;
            else
                hash[i] = factor*hash[i-1] + c;
        }
        
        int left = 0,right = len - 1;
        while (left <= right)
        {
            int mid = (left + right)/2;
            string res = find_dup(S,mid,factor,hash);
            if( res == "")
                right = mid-1;
            else
            {
                op = res;
                left = mid+1;
            }

        }

        return op;
    }
};
int main(int argc, const char * argv[]) {
    Solution sol;
   //string op = sol.longestDupSubstring("moplvidmaagmsiyyrkchbyhivlqwqsjcgtumqscmxrxrvwsnjjvygrelcbjgbpounhuyealllginkitfaiviraqcycjmskrozcdqylbuejrgfnquercvghppljmojfvylcxakyjxnampmakyjbqgwbyokaybcuklkaqzawageypfqhhasetugatdaxpvtevrigynxbqodiyioapgxqkndujeranxgebnpgsukybyowbxhgpkwjfdywfkpufcxzzqiuglkakibbkobonunnzwbjktykebfcbobxdflnyzngheatpcvnhdwkkhnlwnjdnrmjaevqopvinnzgacjkbhvsdsvuuwwhwesgtdzuctshytyfugdqswvxisyxcxoihfgzxnidnfadphwumtgdfmhjkaryjxvfquucltmuoosamjwqqzeleaiplwcbbxjxxvgsnonoivbnmiwbnijkzgoenohqncjqnckxbhpvreasdyvffrolobxzrmrbvwkpdbfvbwwyibydhndmpvqyfmqjwosclwxhgxmwjiksjvsnwupraojuatksjfqkvvfroqxsraskbdbgtppjrnzpfzabmcczlwynwomebvrihxugvjmtrkzdwuafozjcfqacenabmmxzcueyqwvbtslhjeiopgbrbvfbnpmvlnyexopoahgmwplwxnxqzhucdieyvbgtkfmdeocamzenecqlbhqmdfrvpsqyxvkkyfrbyolzvcpcbkdprttijkzcrgciidavsmrczbollxbkytqjwbiupvsorvkorfriajdtsowenhpmdtvamkoqacwwlkqfdzorjtepwlemunyrghwlvjgaxbzawmikfhtaniwviqiaeinbsqidetfsdbgsydkxgwoqyztaqmyeefaihmgrbxzyheoegawthcsyyrpyvnhysynoaikwtvmwathsomddhltxpeuxettpbeftmmyrqclnzwljlpxazrzzdosemwmthcvgwtxtinffopqxbufjwsvhqamxpydcnpekqhsovvqugqhbgweaiheeicmkdtxltkalexbeftuxvwnxmqqjeyourvbdfikqnzdipmmmiltjapovlhkpunxljeutwhenrxyfeufmzipqvergdkwptkilwzdxlydxbjoxjzxwcfmznfqgoaemrrxuwpfkftwejubxkgjlizljoynvidqwxnvhngqakmmehtvykbjwrrrjvwnrteeoxmtygiiygynedvfzwkvmffghuduspyyrnftyvsvjstfohwwyxhmlfmwguxxzgwdzwlnnltpjvnzswhmbzgdwzhvbgkiddhirgljbflgvyksxgnsvztcywpvutqryzdeerlildbzmtsgnebvsjetdnfgikrbsktbrdamfccvcptfaaklmcaqmglneebpdxkvcwwpndrjqnpqgbgihsfeotgggkdbvcdwfjanvafvxsvvhzyncwlmqqsmledzfnxxfyvcmhtjreykqlrfiqlsqzraqgtmocijejneeezqxbtomkwugapwesrinfiaxwxradnuvbyssqkznwwpsbgatlsxfhpcidfgzrc");
    string op = sol.longestDupSubstring("abcd");
    cout<<endl;
    cout<<"Output most duplicate string : "<<op;
    cout<<endl;
    return 0;
}
