//
//  main.cpp
//  LonelyIsland
//
//  Created by Bharat Sarvan on 15/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//
/*
 There are many islands that are connected by one-way bridges, that is, if a bridge connects islands  and , then you can only use the bridge to go from  to  but you cannot travel back by using the same. If you are on island , then you select (uniformly and randomly) one of the islands that are directly reachable from  through the one-way bridge and move to that island. You are stuck on an island if you cannot move any further. It is guaranteed that after leaving any island it is not possible to come back to that island.

 Find the island that you are most likely to get stuck on. Two islands are considered equally likely if the absolute difference of the probabilities of ending up on them is .

 Input format

 First line: Three integers  (the number of islands),  (the number of one-way bridges), and  (the index of the island you are initially on)
 Next  lines: Two integers  and  representing a one-way bridge from island  to .
 Output format

 Print the index of the island that you are most likely to get stuck on. If there are multiple islands,then print them in the increasing order of indices (space separated values in a single line).

 Input Constraints


  

 SAMPLE INPUT
 5 7 1
 1 2
 1 3
 1 4
 1 5
 2 4
 2 5
 3 4
 SAMPLE OUTPUT
 4
 Explanation
 There are two islands on which you could get stuck- 4 and 5 with 4 being more probable.
 
 
 */
#include <iostream>
#include <vector>
using namespace std;
const int maxn=2e5+10;
vector<int>graph[maxn];
double val[maxn];
void dfs(int x,double p){
    double totalOutcomes=graph[x].size();
    for(auto it:graph[x]){
        val[it]+=(p/totalOutcomes);
        dfs(it,p/totalOutcomes);
    }
}
int main(){
    int n,m,r;
    cin>>n>>m>>r;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    val[r]=1.0;
    dfs(r,1.0);
    double maxProb=0.0;
    for(int i=1;i<=n;i++){
        if(graph[i].size()==0){
            maxProb=max(maxProb,val[i]);
        }
    }
    for(int i=1;i<=n;i++){
        if(graph[i].size()==0){
            if(maxProb==val[i])
                cout<<i<<" ";
        }
    }
    return 0;
}
