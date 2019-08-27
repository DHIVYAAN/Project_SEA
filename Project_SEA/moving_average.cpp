//
//  moving_average.cpp
//  Project_SEA
//
//  Created by Dhivyaan S Ramesh on 8/25/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
//#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        if(dominoes.size() < 1 || dominoes.size() > 40000)
            return 0;
        unordered_map<string,int> hash;
        int res = 0;
        for(auto dom : dominoes)
        {
            string string_z = to_string(dom[0]),string_o = to_string(dom[1]);
            string h;
            if(dom[0] > dom[1])
                h = string_o + string_z;
            else
                h = string_z + string_o;
            
            if(hash.find(h) == hash.end())
            {
                hash[h] = 1;
            }
            else
            {
                hash[h]++;
                res = res + (hash[h] - 1);
            }
                
        }
        
        return res;
    }
};

class MovingAverage {
public:
    /** Initialize your data structure here. */
    vector<double> arr;int avg_size;
    int sum = 0, start =0,end=0;
    MovingAverage(int size) {
        avg_size = size;
    }
    
    double next(int val) {
        arr.push_back(val);
        
        if(arr.size() <= avg_size)
        {
            sum += val;
            end = arr.size()-1;
            return sum/arr.size();
        }
        else
        {
            sum = sum - arr[start];
            start++;end++;
            sum = sum + arr[end];
            return sum/avg_size;
        }
        
    }
};
//int main()
//{
//
//    MovingAverage *m = new MovingAverage(3);
//    double op = m->next(1);
//     op = m->next(10);
//    op = m->next(3);
//    op = m->next(5);
//    
//    Solution sol;
//    vector<vector<int>> v = {{1,2},{1,2},{1,1},{1,2},{2,2}};
//    int op2 = sol.numEquivDominoPairs(v);
//
//    cout<<op2<<endl;
//    return 0;
//}
