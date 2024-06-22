#include "Population.h"

Population::Population(int count) {
	this->count = 0;
	this->generation = 1;
	this->population = new entity[8];

	for (size_t i = 0; i < count; i++)
	{
		addEntity(entity());
	}
}

void Population::killEntity(size_t id) {
	for (size_t i = id + 1; i < this->count; i++)
	{
		this->population[i - 1] = this->population[i];
	}
	this->count--;
}

void Population::addEntity(entity e) {
	this->population[this->count++] = e;
}

gene Population::mostCommonGene() {
	int app_0 = 0;	// How many times geneType 0 appeared, I know its a bad name
	int app_1 = 0;
	int app_2 = 0;
	int app_3 = 0;
	int app_4 = 0;
	int app_5 = 0;
	int app_6 = 0;
	int app_7 = 0;
	int app_8 = 0;
	int app_9 = 0;
	int app_10 = 0;
	int app_11 = 0;
	int app_12 = 0;
	int app_13 = 0;
	int app_14 = 0;
	int app_15 = 0;

	for (size_t i = 0; i < this->count; i++) {
		for (size_t j = 0; j < 30; j++) {
			switch (this->population[i].getGene(j).getType()) {
				case geneType::Mutation: app_0++; break;
				case geneType::Fitness: app_1++; break;
				case geneType::Attractiveness: app_2++; break;
				case geneType::Intelligence: app_3++; break;
				case geneType::Size: app_4++; break;
				case geneType::Strength: app_5++; break;
				case geneType::Longevity: app_6++; break;
				case geneType::Speed: app_7++; break;
				case geneType::Resilience: app_8++; break;
				case geneType::Metabolism: app_9++; break;
				case geneType::Immune: app_10++; break;
				case geneType::Happiness: app_11++; break;
				case geneType::Disease: app_12++; break;
				case geneType::Fertility: app_13++; break;
				case geneType::Socialness: app_14++; break;
				case geneType::Color: app_15++; break;
			}
		}
	}

	geneType mostCommon = (geneType)0;
	int max_value = app_0;

	if (app_1 > max_value) mostCommon = (geneType)1;
	if (app_2 > max_value) mostCommon = (geneType)2;
	if (app_3 > max_value) mostCommon = (geneType)3;
	if (app_4 > max_value) mostCommon = (geneType)4;
	if (app_5 > max_value) mostCommon = (geneType)5;
	if (app_6 > max_value) mostCommon = (geneType)6;
	if (app_7 > max_value) mostCommon = (geneType)7;
	if (app_8 > max_value) mostCommon = (geneType)8;
	if (app_9 > max_value) mostCommon = (geneType)9;
	if (app_10 > max_value) mostCommon = (geneType)10;
	if (app_11 > max_value) mostCommon = (geneType)11;
	if (app_12 > max_value) mostCommon = (geneType)12;
	if (app_13 > max_value) mostCommon = (geneType)13;
	if (app_14 > max_value) mostCommon = (geneType)14;
	if (app_15 > max_value) mostCommon = (geneType)15;

	double average = 0;
	int count = 0;
	

	for (size_t i = 0; i < this->count; i++) {
		for (size_t j = 0; j < 30; j++) {
			if (this->population[i].getGene(j).getType() == mostCommon) {
				average += this->population[i].getGene(j).getValue();
				count++;
			}
		}
	}

	average /= count;

	return gene(mostCommon, average);
}