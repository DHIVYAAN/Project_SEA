//
//  hackerrank_week_prob2.cpp
//  Project_SEA
//
//  Created by Dhivyaan S Ramesh on 8/19/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
//#include <bits/stdc++.h>
using namespace std;
/*
 * Complete the 'maximumDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts UNWEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i].
 *
 */

int maximumDifference(int g_nodes, vector<int> g_from, vector<int> g_to) {
    unordered_map<int, int> cache;
    int index = 0, biggest = 0;
    vector<int> v = {};
    vector<vector<int>> set(g_nodes,v);
    for(auto i = 0;i < g_from.size();i++)
    {
        int left = g_from[i];
        int right = g_to[i];
        int no;
        if(cache.find(left) != cache.end())
        {
            no = cache[left];
            if(cache.find(right) == cache.end())
            {
                cache[right] = no;
                set[no].push_back(right);
            }
            else {
                int merge = cache[right];
                if(merge != no)
                {
                    set[no].insert(set[no].end(), set[merge].begin(),set[merge].end());
                   // merge
                }
            }
        }
        else if(cache.find(right) != cache.end())
        {
            no = cache[right];
            if(cache.find(left) == cache.end())
            {
                cache[left] = no;
            }
            else {
                int merge = cache[left];
                if(merge != no)
                {
                for(auto i : cache)
                {
                    if(i.second == merge)
                    {
                        i.second = cache[right];
                    }
                }
                }
            }
        }
        else {
            cache[left] = index;
            cache[right] = index;
            index++;
        }
    }
    vector<int> max(index+1,INT_MIN),min(index+1,INT_MAX);
    for(auto i : cache)
    {
        auto j = i.second;
        auto val = i.first;
        if(val < min[j])
            min[j] = val;
        if(val > max[j])
            max[j] = val;
        if(biggest < (max[j]-min[j]))
            biggest = max[j]-min[j];
    }
    return biggest;
}
//int main()
//{
//    
//    vector<int> i1 = {1,1,2,2,3,4};
//    vector<int> i2 = {2,3,3,4,4,5};
//    int op = maximumDifference(0, i1, i2);
//    
//    cout<<op<<endl;
//    return 0;
//}
