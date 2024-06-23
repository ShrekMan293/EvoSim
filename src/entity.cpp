#include "entity.h"

entity::entity() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> rand{ 0.00, 1.00 };

	for (size_t i = 0; i < 30; i++)
	{
		this->genome[i] = gene();
	}

	double value = rand(gen);

	this->attractiveness = value;
	value = rand(gen);
	this->fertility = value;
	value = rand(gen);
	this->fitness = value;
	value = rand(gen);
	std::uniform_real_distribution<double> nrand{ 0.00, 1.00 };
	this->mutation_rate = value / 100;

	this->init_attractiveness = this->attractiveness;
	this->init_fertility = this->fertility;
	this->init_fitness = this->fitness;
}

entity::entity(entity father, entity mother) {
	int index = 0;
	int i = -1;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> rand{ 0, 1 };

	while (++i < 30) {
		index = rand(gen);

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