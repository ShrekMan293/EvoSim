#include "common.h"
#include "Population.h"

using std::cout;

int main(int argc, char** argv) {
	Population p = Population(8);

	do
	{
		cout << "\nYear " << p.getYear() << ":\n";
		p.simYear();
		cout << "Population: " << p.getPopulationSize() << '\n';
		cout << "Male Population: " << p.getMales() << '\n';
		cout << "Female Population: " << p.getFemales() << '\n';
		cout << "New Births: " << p.getBirths() << '\n';
		cout << "Deaths: " << p.getDeaths() << '\n';
		if (p.getYear() != 0) cout << "Growth Rate: " << p.growthRate().growth_double * 100 << "% (" << p.growthRate().growth_int << ")\n";
		cout << "Oldest Entity: " << p.getOldest() << '\n';
		cout << "Average Fitness: " << p.getAverageFitness() << '\n';
		cout << "Average Attractiveness: " << p.getAverageAttractiveness() << '\n';
		cout << "Average Fertility: " << p.getAverageFertility() << '\n';
		cout << "Average Mutation Rate: " << p.getAverageMutationRate() << '\n';
		cout << "Most Common Gene: ";
		cout << p.mostCommonGene().getType();
		cout << "(" << p.mostCommonGene().getValue() << ")\n";


	} while (p.getPopulationSize() > 0 && p.getYear() < 500);
	
	if (p.getPopulationSize() == 0) {
		cout << "\n\nPopulation died out in year " << p.getYear() << ".\n";
	}

	p.deletePopulation();

	return 0;
}