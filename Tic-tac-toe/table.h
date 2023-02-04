#include <vector>

const int TABLE_SIZE = 3;
using Reach = std::tuple<int, int>;


enum class Elem {
	Empty,
	X,
	O,
};

class Table {
private:
	std::vector<std::vector<Elem>> table;
	void playerPos(int);
	void cpuPos(int);
	int act_after_third();
	Reach get_reach(int);
	
public:
	void resetTable();
	void printTable();
	void playerSetValue(int);
	void cpuSetValue();
	int checkTable(int);
	int winDecision();
	Table();
};