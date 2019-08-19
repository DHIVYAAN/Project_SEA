//
//  medium_basic_claculator_2.cpp
//  Project_SEA
//
//  Created by Dhivyaan S Ramesh on 8/18/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    
    bool isNum(char c){
        int num = c - '0';
        if(num <= 9 && num >=0)
            return true;
        else
            return false;
    }
    int calculate(string s) {
        long long int res = 0;
        int md = -1;
        long long int prev;
        int sign = 1;
        unordered_set<char> op= {'+','-','*','/'};

        for(auto i = 0; i < s.length();i++)
        {
            while(s[i] == ' ')
                i++;
            
            if(isNum(s[i]))
            {
                long long int num = s[i] - '0';
                while(isNum(s[i+1]))
                {
                    i++;
                    num = num*10 + s[i] - '0';
                }
                if(md == 1)
                {
                    prev = prev/num;
                    md = -1;
                }
                else if(md == 0)
                {
                    prev = prev*num;
                    md = -1;
                }
                else
                    prev = num;
            }
            else
            {
                if(s[i] == '/')
                    md = 1;
                else if(s[i] == '*')
                    md = 0;
                else if(s[i] == '+')
                {
                    res = res + sign*prev;
                    sign = 1;
                }
                else if(s[i] == '-')
                {
                    res = res + sign*prev;
                    sign = -1;
                }
               
            
        }
        }
        res = res + sign*prev;
        return res;
    }
};ß
//int main()
//{
//    Solution sol;
//
//    int op = sol.calculate(" 3+5 / 2 ");
//    cout<<endl;
//    cout<<"Ans : "<<op;
//    cout<<endl;
//    return 0;
//}
