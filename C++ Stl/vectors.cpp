#include<bits/stdc++.h>
using namespace std;
void explainVector(){
    vector<int>v;
    v.push_back(1);
    v.emplace_back(2);
    vector<pair<int,int>>vec;
    vec.push_back({1,2}); 
    vec.emplace_back(1,3);

    vector<int>v(5,200); //[200 5 times]
    vector<int>v(5);//create 5 spaces in arry with any garbage value
    vector<int>v1(5,20);
    vector<int>v2(v1);


}