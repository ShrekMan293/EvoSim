#pragma once
#include "gene.h"

class entity {
	gene genome[30];
	float attractiveness;
	float fitness;
	float fertility;
	float mutation_rate;
	
public:
	float init_attractiveness;
	float init_fitness;
	float init_fertility;

	entity();
	entity(entity father, entity mother);
	gene getGene(int index);
};