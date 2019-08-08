//
//  main.cpp
//  Project_SEA
//
//  Created by Dhivyaan S Ramesh on 8/6/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//
/*
 Validate if a given string can be interpreted as a decimal number.
 
 Some examples:
 "0" => true
 " 0.1 " => true
 "abc" => false
 "1 a" => false
 "2e10" => true
 " -90e3   " => true
 " 1e" => false
 "e3" => false
 " 6e-1" => true
 " 99e2.5 " => false
 "53.5e93" => true
 " --6 " => false
 "-+3" => false
 "95a54e53" => false
 
 Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:
 
 Numbers 0-9
 Exponent - "e"
 Positive/negative sign - "+"/"-"
 Decimal point - "."
 Of course, the context of these characters also matters in the input.
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool sign_f = false,e_f =false,decimal_f = false,num_flag = false,reached_end = true,e_comp = true,dec_com = true,stop_c = false,only_space = false;
        
        unordered_set<char> dict = {'+','-','e','0','1','2','3','4','5','6','7','8','9','0','.'};
        for(auto i = 0;i <s.length();i++)
        {
            if(s[i] == ' ')
            {
                if(!sign_f && !e_f && !decimal_f && !num_flag) //skip through until all char
                {only_space = true;
                    continue;
                }
                else
                {
                    if(!reached_end) //still expecting char but hit space
                        return false;
                    else
                        stop_c = true; //accept no more char
                }
            }
            else if(stop_c == true)
                return false;
            else
            {
                only_space = false;
                auto it = dict.find(s[i]);
                if(it == dict.end())
                    return false;
                
                //handling . in the string
                if(*it == '.')
                {
                    if(decimal_f || e_f) //if already set return false and do not allow decimal after e
                    {
                        return false;
                    }
                    if((i != 0))
                    {
                        if(((s[i-1] == '+') || (s[i-1] == '-')) && num_flag) //check if its preceeding a + or - after a number
                            return false;
                    }
                    if(s.length() == 1) //if it is the only element
                        return false;
                    
                    decimal_f = true;
                    
                    
                    if(!num_flag)
                        dec_com = false;
                    
                }
                //handling e in the string
                else if(*it == 'e')
                {
                    if((!num_flag) || e_f)//if already set return false and do not allow without a number
                    {
                        return false;
                    }
                    if((i != 0))
                    {
                        if((s[i-1] == '+') || (s[i-1] == '-') || (i == s.length()-1) ) //check if there is a sign before it
                            return false;
                    }
                    if(s[i-1] == '.')
                        dec_com = true;
                    
                    if(s.length() == 1)
                        return false;
                    
                    e_f = true;
                    decimal_f = true;
                    
                    e_comp = false;
                    reached_end = false;
                }
                //handling +/- in the string
                else if((*it == '-') || (*it == '+'))
                {
                    if(i == 0)
                    {
                        sign_f = true;
                    }
                    else if((sign_f && (s[i-1] != 'e')) || !dec_com)
                    {
                        return false;
                    }
                    if(s.length() == 1)
                        return false;
                    if(num_flag && (s[i-1] != 'e'))
                        return false;
                    sign_f = true;
                }
                else
                {
                    num_flag = true;
                    reached_end = true;
                    if(dec_com == false)
                        dec_com = true;
                    if(e_comp == false)
                        e_comp = true;
                }
            }
        }
        if(((e_comp == true) && (dec_com == true)) && reached_end && !only_space)
            return true;
        else
            return false;
        
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    cout<<endl;
    vector<string> ip= {"46.e3","+.8",".-4","6+1"," "," .","0"," 0.1 ","abc","1 a","2e10"," -90e3   "," 1e","e3"," 6e-1"," 99e2.5 ","53.5e93"," --6 ","-+3","95a54e53"};
    vector<int> op = {1,1,0,0,0,0,1,1,0,0,1,1,0,0,1,0,1,0,0,0};
    int b = 1,count =0;
    for(auto i = 0; i < ip.size();i++)
    {
        
        cout<<endl<<"String : "<<ip[i]<<"->"<<sol.isNumber(ip[i]);
        if(op[i] != sol.isNumber(ip[i]))
        {b=0;
            cout<<" Failed";}
        else
            cout<<" Passed";
        
        count++;
    }
    cout<<endl<<endl<<"##########"<<endl;
    if(b == 0)
        cout<<count<<" Test cases failed";
    else
        cout<<count<<" Test cases passed";
    
    cout<<endl<<"##########"<<endl;
    cout<<endl;
    return 0;
}
