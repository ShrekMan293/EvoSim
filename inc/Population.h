#pragma once
#include "common.h"
#include "gene.h"
#include "entity.h"

class Population
{
	entity* population;
	size_t year;
	size_t count;
	size_t maxSize;
public:
	Population(int count);
	void killEntity(size_t id);
	void addEntity(entity e);

	gene mostCommonGene();

	size_t getPopulationSize();
	size_t getYear();

	double getAverageFitness();
	double getAverageAttractiveness();
	double getAverageFertility();
	double getAverageMutationRate();

	void simYear();

	void deletePopulation();
};