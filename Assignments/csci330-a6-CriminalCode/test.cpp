#include <string>
#include <iostream>

#include "City.h"

using namespace std;

void test1();
void test2();
City * makeCity(const string& name);
void travel1(const City * start);
void travel2(const City * start);
void cleanUp(const City * start);

int main()
{
    test1();
    test2();
    
    return 0;
}

void test1()
{
    City * me = makeCity("Maine");
    City * nh = makeCity("New Hampshire");
    City * vt = makeCity("Vermont");
    City * ma = makeCity("Massachusetts");
    City * ct = makeCity("Connectitcut");
    City * ri = makeCity("Rhode Island");
    
    me->setWest(nh);
    nh->setWest(vt);
    vt->setSouth(ma);
    ma->setSouth(ct);
    ct->setEast(ri);
    
    cout << endl << "Maine to Rhode Island..." << endl << endl;
    travel1(me);
    cout << endl << "Rhode Island to Maine..." << endl << endl;
    travel2(ri);
    cout << endl << "Deleting cities..." << endl << endl;
    cleanUp(me);
}

void test2()
{
    City * me = makeCity("Maine");
    City * nh = makeCity("New Hampshire");
    City * vt = makeCity("Vermont");
    City * ct = makeCity("Connectitcut");
    City * ri = makeCity("Rhode Island");
    
    me->setWest(nh);
    nh->setWest(vt);
    vt->setSouth(ct);
    ct->setEast(ri);
    
    cout << endl << "Maine to Rhode Island..." << endl << endl;
    travel1(me);
    cout << endl << "Rhode Island to Maine..." << endl << endl;
    travel2(ri);
    cout << endl << "Deleting cities..." << endl << endl;
    cleanUp(me);
}


City * makeCity(const string& name)
{
    return new City(name);
}

void travel1(const City * start)
{
    // print cities to the west as far as possible...
    
    // then print cities to the south as far as possible...
    
    // then print cities to the east as far as possible...
}

void travel2(const City * start)
{
    // print cities to the west as far as possible...
    
    // then print cities to the north as far as possible...
    
    // then print cities to the east as far as possible...
}

void cleanUp(const City * start)
{
    // delete cities to the west as far as possible...
    
    // then delete cities to the south as far as possible...
    
    // then delete cities to the east as far as possible...
}