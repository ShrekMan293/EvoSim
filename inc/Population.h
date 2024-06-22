#pragma once
#include "common.h"
#include "gene.h"
#include "entity.h"

class Population
{
	entity* population;
	size_t generation;
	size_t count;
public:
	Population(int count);
	void killEntity(size_t id);
	void addEntity(entity e);

	gene mostCommonGene();
	gene leastCommonGene();

	size_t getPopulationSize();
	size_t getGeneration();

	float getAverageFitness();
	float getAverageAttractiveness();
	float getAverageFertility();
	float getAverageMutationRate();
};