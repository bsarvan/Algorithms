//
//  main.cpp
//  FindUnreachableNode
//
//  Created by bsarvan on 11/06/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

/* Sample input
 
 10 10
 8 1
 8 3
 7 4
 7 5
 2 6
 10 7
 2 8
 10 9
 2 10
 5 10
 2
 
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define N_MAX 100000
vector<int> g[N_MAX];
bool visited[N_MAX] = {false};


int ans = 0;

void dfs_interative(int n){
    stack<int> s;
    visited[n] = true;
    s.push(n);
    
    while(!s.empty()) {
        ans++;
        int m = s.top();
        s.pop();
        for(int i = 0;i<g[m].size();i++){
            if(visited[g[m][i]] == false) {
                s.push(g[m][i]);
                visited[g[m][i]] = true;
            }
        }
    }
}


void dfs(int s){
    visited[s] = true;
    ans++;
    for(int i = 0; i < g[s].size(); ++i) {
        if(visited[g[s][i]] == false)
            dfs(g[s][i]);
    }
}

void printGraph() {
    vector<int>::iterator iter;
    
    for(int i=0;i<N_MAX;i++){
        if(g[i].size() != 0) {
            cout<<i<<" -> ";
            
            for(iter = g[i].begin();iter != g[i].end();iter++) {
                cout<<*iter<<" ";
            }
            cout<<endl;
            
        }
    }
}

int main(){
    int N,M;
    
    cin>>N>>M;
    
    for(int i=0;i<M;i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout<<endl<<"The adjacency list of the graph is - "<<endl;
    printGraph();
    cout<<endl;
    
    int x;
    cin>>x;
    dfs_interative(x);
    int unreachable_count = N - ans;
    
    cout<<unreachable_count<<endl;
    
    return 0;
    
}
