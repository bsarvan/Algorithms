//
//  main.cpp
//  GroupByAge
//
//  Created by bsarvan on 15/03/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

typedef struct person_ {
    int age;
    string name;
} Person;


void print(vector<Person> person)
{
    for (auto &p:person){
        cout<<"Name - "<<p.name<<",    Age - "<<p.age<<endl;
    }
}

void GroupByAge(vector<Person> person){
    unordered_map<int, int> age_to_count;
    
    for(const auto &p:person){
        ++age_to_count[p.age];
    }
    cout<<"=============================="<<endl;
    cout<<"age_to_count hash - "<<endl;
    for (auto &m:age_to_count){
        cout<<"key - "<<m.first<<", Count - "<<m.second<<endl;
    }
    
    unordered_map<int, int> age_to_offset;
    int offset = 0;
    
    for (const auto &q:age_to_count){
        age_to_offset[q.first] = offset;
        offset += q.second;
    }
    cout<<"=============================="<<endl;
    cout<<"age_to_offset hash - "<<endl;
    for (auto &m:age_to_offset){
        cout<<"key - "<<m.first<<", Offset - "<<m.second<<endl;
    }
    
    cout<<"=============================="<<endl;
    
    while(age_to_offset.size()){
        auto from = age_to_offset.begin();
        cout<<"from->first - "<<from->first<<", from->second - "<<from->second<<endl;
        auto to = age_to_offset.find(person[from->second].age);
        cout<<"to->first - "<<to->first<<", to->second - "<<to->second<<endl;
        cout<<"Swappng - Person[from->second] - "<<person[from->second].name<< ", Person[to->second] - "<<person[to->second].name<<endl;
        swap(person[from->second], person[to->second]);
        print(person);
        cout<<endl;
        --age_to_count[to->first];
        if (age_to_count[to->first] > 0){
            ++to->second;
        }else {
            age_to_offset.erase(to);
        }
    }
}



int main(int argc, const char * argv[]) {
    vector<Person> person;
    
    person.emplace_back(Person{12,"John"});
    person.emplace_back(Person{14,"Sam"});
    person.emplace_back(Person{11,"Ron"});
    person.emplace_back(Person{12,"Rob"});
    person.emplace_back(Person{14,"Jack"});
//    person.emplace_back(Person{13,"Jill"});

    print(person);
    
    GroupByAge(person);
    
    print(person);
    return 0;
    
}
