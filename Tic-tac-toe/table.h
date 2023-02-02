#include <vector>

const int TABLE_SIZE = 3;


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
public:
	void resetTable();
	void printTable();
	void playerSetValue(int);
	void cpuSetValue();
	int checkTable(int);
	Table();
};