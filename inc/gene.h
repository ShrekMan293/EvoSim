#pragma once
#include "common.h"
#include <random>

enum class geneType {
	Mutation,
	Fitness,
	Attractiveness,
	Intelligence,
	Size,
	Strength,
	Longevity,
	Speed,
	Resilience,
	Metabolism,
	Immune,
	Happiness,
	Disease,
	Fertility,
	Socialness,
	Color
};

void operator <<(std::ostream& o, const geneType& g);

class gene {
	geneType type;
	double value;
public:
	gene();
	gene(geneType type, double value);
	void mutate();
	geneType getType();
	double getValue();
};