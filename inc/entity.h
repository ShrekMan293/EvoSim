#pragma once
#include "gene.h"

class entity {
	gene genome[30];
	
public:
	double init_attractiveness;
	double init_fitness;
	double init_fertility;

	double attractiveness;
	double fitness;
	double fertility;
	double mutation_rate;
	entity();
	entity(entity father, entity mother);
	gene getGene(int index);
};