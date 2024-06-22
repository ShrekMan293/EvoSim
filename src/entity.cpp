#include "entity.h"

entity::entity() {
	srand(time(NULL));
	for (size_t i = 0; i < 30; i++)
	{
		this->genome[i] = gene();
	}

	float value = (rand() % 100) / static_cast<float>(100);

	srand(time(NULL));
	this->attractiveness = value;
	value = (rand() % 100) / static_cast<float>(100);
	srand(time(NULL));
	this->fertility = value;
	value = (rand() % 100) / static_cast<float>(100);
	srand(time(NULL));
	this->fitness = value;
	value = (rand() % 100) / static_cast<float>(100);
	this->mutation_rate = value;

	this->init_attractiveness = this->attractiveness;
	this->init_fertility = this->fertility;
	this->init_fitness = this->fitness;
}

entity::entity(entity father, entity mother) {
	int index = 0;
	int i = -1;

	while (++i < 30) {
		index = rand() % 2;

		if (index == 0) this->genome[i] = father.genome[i];
		else this->genome[i] = mother.genome[i];
	}

	this->fitness = (father.init_fitness + mother.init_fitness) / 2;
	this->fertility = (father.init_fertility + mother.init_fertility) / 2;
	this->attractiveness = (father.init_attractiveness + mother.init_attractiveness) / 2;
	this->mutation_rate = (father.mutation_rate + mother.mutation_rate) / 2;

	this->init_attractiveness = this->attractiveness;
	this->init_fertility = this->fertility;
	this->init_fitness = this->fitness;
}

gene entity::getGene(int index) {
	return this->genome[index];
}