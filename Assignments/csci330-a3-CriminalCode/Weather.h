#ifndef Weather_H
#define Weather_H

//#include <vector>

using namespace std;

struct HighLow
{
	int high;
	int low;
};

const int CHART_LENGTH = 5;
void populate(vector<HighLow> &temps);
void chart(const vector<HighLow> &temps);
vector<string> makeCharts(const vector<HighLow> &temps);

#endif

