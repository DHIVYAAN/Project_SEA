//
//  149_hard_max_points_on_line.cpp
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
#include <math.h>
using namespace std;
class Solution {
public:
    
    unordered_map<double,int> slope;
    int max = 0;
    
    double slp(int x1,int y1,int x2,int y2)
    {
        double temp;
        temp = double(x1-x2)/double(y1-y2);
        return temp;
        
    }
    int updatestring(double s1)
    {
        if(slope.find(s1) == slope.end())
        {
            slope[s1] = 2;
            
            
        }
        else
        {
            slope[s1]++;
            
        }
//        if(max < slope[s1])
//            max = slope[s1];
        return slope[s1];
    }
    
    int updateslope(int x,int y,int x1,int y1)
    {
        double s; string str;
        if(x == x1 && y == y1)
            return -1;
        if(y == y1)
            return -2;
        s = slp(x, y, x1, y1);
        //str = to_string(s[0]) + to_string(s[1]);
        int op = updatestring(s);
        return op;
    }
    
    int maxPoints(vector<vector<int>>& points) {
        
        
        for(auto i = 0; i < points.size()-1;i++)
        {
            int count = 1,dup =0,hz = 1;
            for(auto j = i+1; j < points.size();j++)
            {
            int c = updateslope(points[i][0],points[i][1],points[j][0],points[j][1]);
                if(c == -1)
                    dup++;
                if(c == -2)
                hz++;
                if( c > count)
                    count = c;
                
            }
            count = std::max(count,hz);
            max = std::max(max,count+dup);
            slope.clear();
        }
        
        return max;
        
    }
};

//int main()
//{
//    Solution sol;
//    vector<vector<int>> v = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
//   int op = sol.maxPoints(v);
//    cout<<op<<endl;
//    return 0;
//}
