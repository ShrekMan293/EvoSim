#include "common.h"
#include "Population.h"

using std::cout;

int main(int argc, char** argv) {
	Population p = Population(8);
	
	while (p.getPopulationSize() > 0 && p.getYear() < 5) {
		p.simYear();

		cout << "Year " << p.getYear() << ":\n";
		cout << "Population: " << p.getPopulationSize() << '\n';
		cout << "Average Fitness: " << p.getAverageFitness() << '\n';
		cout << "Average Attractiveness: " << p.getAverageAttractiveness() << '\n';
		cout << "Average Fertility: " << p.getAverageFertility() << '\n';
		cout << "Average Mutation Rate: " << p.getAverageMutationRate() << '\n';
		cout << "Most Common Gene: ";
		cout << p.mostCommonGene().getType();
		cout << "(" << p.mostCommonGene().getValue() << ")\n";
	}

	p.deletePopulation();

	return 0;
}