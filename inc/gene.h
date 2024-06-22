#pragma once
#include "common.h"

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

void operator <<(const std::ostream& o, const geneType& g);

class gene {
	geneType type;
	float value;
public:
	gene();
	gene(geneType type, float value);
	void mutate();
	geneType getType();
	float getValue();
};