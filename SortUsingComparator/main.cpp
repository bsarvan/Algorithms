//
//  main.cpp
//  SortUsingComparator
//
//  Created by Bharat Sarvan on 08/08/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Student {
    string name;
    int gpa;
    
    bool operator<(const struct Student &that) const {
        cout<<"Comparing "<<that.gpa<<" and "<<gpa<<endl;
        return gpa < that.gpa;
    }
};


int main(int argc, const char * argv[]) {
    vector<struct Student> students;
    
    students.emplace_back(Student{"Bharat", 10});
    students.emplace_back(Student{"Amit", 8});
    students.emplace_back(Student{"Tavish", 7});
    students.emplace_back(Student{"Rupal", 6});
    students.emplace_back(Student{"Jai", 9});
    
    sort(students.begin(), students.end());
    
    for (auto s:students) {
        cout<<s.name<<" "<<s.gpa<<endl;
    }
    
    cout<<"====================="<<endl;
    
//    sort(students.begin(), students.end(), [] (const Student &a, const Student &b) -> bool { return a.gpa < b.gpa;});
//
//    for (auto s:students) {
//        cout<<s.name<<" "<<s.gpa<<endl;
//    }
    
    
    return 0;
}
