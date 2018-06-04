//
//  main.cpp
//  CopyCon
//
//  Created by bsarvan on 02/05/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;


class Name {
    char *name;
public:
    Name():name(NULL){}
    Name(char *s):name(new char(strlen(s)+1)){
        strcpy(name,s);
    }
    
    Name(const Name& n):name(new char(strlen(n.name)+1)){
        cout<<"Copy Constructor"<<endl;
        strcpy(name, n.name);
    }
    
    void display(){
        cout<<"Name - "<<name<<", Address - "<<&name<<endl;
    }
};

int main(int argc, const char * argv[]) {
    cout<<"Program to test Copy Constructor"<<endl<<endl;
    Name obj("Bharat Sarvan");
   
    obj.display();
    Name obj2 = obj;
    obj2.display();
    
    return 0;
}
