#include "common.h"
#include "Population.h"

using std::cout;

int main(int argc, char** argv) {
	Population p();
	entity e = entity();

	cout << e.getGene(0).getValue() << " + " << (int)e.getGene(0).getType() << '\n';

	return 0;
}