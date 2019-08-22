//
//  hackkerrank_week4.cpp
//  Project_SEA
//
//  Created by Dhivyaan S Ramesh on 8/19/19.
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
/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY a as parameter.
 //trial 1
 vector<int> helper(vector<int> v,int st,int en)
 {
 vector<int> temp = {};
 if(st > en)
 return temp;
 if(st == en)
 {
 temp.push_back(v[st]);
 return temp;
 }
 int root = v[st];
 int i = st;
 while(v[i+1] <= root && i < (v.size()-1))
 i++;
 vector<int> left,right;
 if(i != st)
 left = helper(v,st+1,i);
 int j = i+1;
 if(j <= en)
 {
 if(j == en)
 right.push_back(v[j]);
 else {
 right = helper(v,j,en);
 }
 }
 left.push_back(root);
 left.insert(left.end(), right.begin(), right.end());
 
 
 return left;
 
 }
 
 string isValid(vector<int> a) {
 if(a.size() == 0 )
 return "NO";
 if(a.size() == 1)
 return "YES";
 
 
 vector<int> op = helper(a,0,a.size()-1);
 string res = "YES";
 int curr = op[0];
 for(auto i : op)
 {
 if(curr > i)
 {
 res = "NO";
 break;
 }
 else
 curr = i;
 }
 return res;
 }
 
 
 */
bool helper(vector<int> v,int st,int en,int max,int min)
{
    if(st > en)
        return true;
    int root = v[st];
    if(root > max && root < min)
        return false;

    if(st == en)
    {
            return true;
    }
    int j = st +1;
        while(v[j] <= root && j < en)
        {
            
            j++;
        }
    return (helper(v, st+1, j, root, min) && helper(v, j+1, en, max, root));
    
    
}

string isValid(vector<int> a) {
    if(a.size() == 0 )
        return "NO";
    if(a.size() == 1)
        return "YES";
    
    bool b = helper(a, 0, a.size()-1,INT_MAX,INT_MIN);
    
    //vector<int> op = helper(a,0,a.size()-1);
   
    return (b ? "YES" : "NO");
}
//int main(){
//    string op = isValid({3,1,2,4,5,6});
//    cout<<op<<endl;
//
//
//    return 0;
//}
//int main()
//{
//    ofstream fout(getenv("OUTPUT_PATH"));
//    
//    string q_temp;
//    getline(cin, q_temp);
//    
//    int q = stoi(ltrim(rtrim(q_temp)));
//    
//    for (int q_itr = 0; q_itr < q; q_itr++) {
//        string a_count_temp;
//        getline(cin, a_count_temp);
//        
//        int a_count = stoi(ltrim(rtrim(a_count_temp)));
//        
//        string a_temp_temp;
//        getline(cin, a_temp_temp);
//        
//        vector<string> a_temp = split(rtrim(a_temp_temp));
//        
//        vector<int> a(a_count);
//        
//        for (int i = 0; i < a_count; i++) {
//            int a_item = stoi(a_temp[i]);
//            
//            a[i] = a_item;
//        }
//        
//        string result = isValid(a);
//        
//        fout << result << "\n";
//    }
//    
//    fout.close();
//    
//    return 0;
//}
//
//string ltrim(const string &str) {
//    string s(str);
//    
//    s.erase(
//            s.begin(),
//            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//            );
//    
//    return s;
//}
//
//string rtrim(const string &str) {
//    string s(str);
//    
//    s.erase(
//            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//            s.end()
//            );
//    
//    return s;
//}
//
//vector<string> split(const string &str) {
//    vector<string> tokens;
//    
//    string::size_type start = 0;
//    string::size_type end = 0;
//    
//    while ((end = str.find(" ", start)) != string::npos) {
//        tokens.push_back(str.substr(start, end - start));
//        
//        start = end + 1;
//    }
//    
//    tokens.push_back(str.substr(start));
//    
//    return tokens;
//}

