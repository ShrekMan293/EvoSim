#include "gene.h"
#include <random>

gene::gene() {
	srand(time(NULL));
	this->type = (geneType)(rand() % 16);
	this->value = rand() % 100 / (float)100;
}

gene::gene(geneType type, float value) {
	this->type = type;
	this->value = value;
}

void gene::mutate() {
	srand(time(NULL));
	int mutate = rand() % 2;	// Generates 1 or 0
	if (mutate) {
		this->type = (geneType)((int)this->type ^ (int)this->type);
	}
	else {
		int bitChange = rand() % 4;
		switch (bitChange) {
		case 0: this->type = (geneType)((int)this->type ^ 1); break;
		case 1: this->type = (geneType)((int)this->type ^ 2); break;
		case 2: this->type = (geneType)((int)this->type ^ 4); break;
		case 3: this->type = (geneType)((int)this->type ^ 8); break;
		default: break;
		}
	}
}

geneType gene::getType() {
	return this->type;
}

float gene::getValue() {
	return this->value;
}

void operator <<(std::ostream& o, const geneType& g) {
	switch ((int)g)
	{
	case 0: o << "Mutation"; break;
	case 1: o << "Fitness"; break;
	case 2: o << "Attractiveness"; break;
	case 3: o << "Intelligence"; break;
	case 4: o << "Size"; break;
	case 5: o << "Strength"; break;
	case 6: o << "Longevity"; break;
	case 7: o << "Speed"; break;
	case 8: o << "Resilience"; break;
	case 9: o << "Metabolism"; break;
	case 10: o << "Immune"; break;
	case 11: o << "Happiness"; break;
	case 12: o << "Disease"; break;
	case 13: o << "Fertility"; break;
	case 14: o << "Socialness"; break;
	case 15: o << "Color"; break;
	}
}