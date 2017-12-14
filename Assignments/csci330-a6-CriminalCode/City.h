#ifndef CITY_H
#define CITY_H

#include <string>

using namespace std;

class City
{
private:
	string m_name;
	City * m_north;
	City * m_south;
	City * m_east;
	City * m_west;
	
public:
	City(const string & name);
	virtual ~City();
	string getName() const;
	City * north() const;
	City * south() const;
	City * east() const;
	City * west() const;
	void setNorth(City * north);
	void setSouth(City * south);
	void setEast(City * east);
	void setWest(City * west);
};

#endif
