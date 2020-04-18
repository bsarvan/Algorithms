//
//  main.cpp
//  BicyclePart
//
//  Created by bsarvan on 25/05/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

// Complex class involving dynamic aggregation
#ifndef BICYCLE_H
#define BICYCLE_H
#include <vector>
#include <string>
#include <iostream>
#include <typeinfo>

class LeakChecker {
    int count;
public:
    LeakChecker() : count(0) {}
    void print() {
        std::cout << count << std::endl;
    }
    ~LeakChecker() { print(); }
    void operator++(int) { count++; }
    void operator--(int) { count--; }
};

class BicyclePart {
    static LeakChecker lc;
public:
    BicyclePart() { lc++; }
    virtual BicyclePart* clone() = 0;
    virtual ~BicyclePart() { lc--; }
    friend std::ostream&
    operator<<(std::ostream& os, BicyclePart* bp) {
        return os << typeid(*bp).name();
    }
    friend class Bicycle;
};
enum BPart {
    Frame, Wheel, Seat, HandleBar,
    Sprocket, Deraileur,
};

template<BPart id>
class Part : public BicyclePart {
public:
    BicyclePart* clone() { return new Part<id>;}
};

class Bicycle {
public:
    typedef std::vector<BicyclePart*> VBP; Bicycle();
    Bicycle(const Bicycle& old);
    Bicycle& operator=(const Bicycle& old);
    ~Bicycle() { purge(); }
    VBP& bikeParts() { return parts; }
    friend std::ostream& operator<<(std::ostream& os, Bicycle* b); static void print(std::vector<Bicycle*>& vb,
                                                                                     std::ostream& os = std::cout);
private:
    static int counter;
    int id;
    VBP parts;
    void purge();
};

// Both the Bicycle and the generator should
// provide more variety than this. But this gives // you the idea.
struct BicycleGenerator {
    Bicycle* operator()() {
        return new Bicycle;
    } };
#endif // BICYCLE_H //






    int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
