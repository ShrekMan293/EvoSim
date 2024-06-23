#pragma once
#include "common.h"
#include "gene.h"
#include "entity.h"
#include <thread>

struct growth_t {
	double growth_double;
	int64_t growth_int;
};

class Population
{
	size_t year;
	size_t count;
	size_t maxSize;
	int64_t newBabies;
	int64_t deaths;
	size_t lastPopulation;
public:
	entity* population;
	Population(int count);
	void killEntity(size_t id);
	void addEntity(entity e);

	gene mostCommonGene();

	size_t getPopulationSize();
	size_t getMales() const;
	size_t getFemales() const;
	size_t getYear();

	double getAverageFitness();
	double getAverageAttractiveness();
	double getAverageFertility();
	double getAverageMutationRate();

	int getOldest();
	size_t getBirths();
	size_t getDeaths();
	growth_t growthRate();

	void simYear();

	void deletePopulation();
};