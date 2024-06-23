 #include "Population.h"

Population::Population(int count) {
	this->count = 0;
	this->year = 0;
	this->population = static_cast<entity*>(std::calloc(1048576, sizeof(entity)));
	this->maxSize = 1024;

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

size_t Population::getPopulationSize() {
	return this->count;
}

size_t Population::getYear() {
	return this->year;
}

double Population::getAverageFitness()
{
	double averageFitness = 0;

	for (size_t i = 0; i < this->count; i++)
	{
		averageFitness += this->population[i].fitness;
	}

	return averageFitness / this->count;
}

double Population::getAverageAttractiveness()
{
	double averageAttr = 0;

	for (size_t i = 0; i < this->count; i++)
	{
		averageAttr += this->population[i].attractiveness;
	}

	return averageAttr / this->count;
}

double Population::getAverageFertility()
{
	double averageFertility = 0;

	for (size_t i = 0; i < this->count; i++)
	{
		averageFertility += this->population[i].fertility;
	}

	return averageFertility / this->count;
}

double Population::getAverageMutationRate()
{
	double averageMut = 0;

	for (size_t i = 0; i < this->count; i++)
	{
		averageMut += this->population[i].mutation_rate;
	}

	return averageMut / this->count;
}

static bool attractivenessTest(entity male, entity female) {
	double att_score0 = ((male.attractiveness * male.fitness) + male.attractiveness) / 5;
	double att_score1 = ((female.attractiveness * female.fitness) + female.attractiveness) / 5;

	return att_score0 > att_score1 || att_score1 - att_score0 < 0.1;
}

int Population::getOldest() {
	int oldest = 0;
	for (size_t i = 0; i < this->count; i++)
	{
		if (this->population[i].age > oldest) oldest = this->population[i].age;
	}
	return oldest;
}

size_t Population::getBirths() {
	return this->newBabies;
}

size_t Population::getDeaths() {
	return this->deaths;
}

growth_t Population::growthRate() {
	growth_t g;
	g.growth_double = ((double)this->newBabies - (double)this->deaths) / (double)this->lastPopulation;
	g.growth_int = this->newBabies - this->deaths;
	return g;
}

void Population::simYear() {
	this->year++;
	this->lastPopulation = this->count;
	this->newBabies = 0;
	this->deaths = 0;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> rand{ 0.00, 0.40 };
	std::uniform_real_distribution<double> rand2{ 0.00, 0.30 };
	std::uniform_real_distribution<double> rand3{ 0.00, 0.60 };
	std::uniform_real_distribution<double> rand4{ 0.00, 2.00 };
	std::uniform_real_distribution<double> rand5{ 0.00, 1.00 };

	std::uniform_real_distribution<double> extinction{ 0.000000, 1.000000 };

	double fitnessThreshold = (rand(gen) + rand2(gen) + rand3(gen) + rand4(gen)) / 4;
	double mass_extinction = extinction(gen);

	if (mass_extinction < 0.02) {
		const double death_rate = 0.85;	// 85% of the population will be killed

		for (size_t i = 0; i < this->count * death_rate; i++)
		{
			killEntity(i);
		}
		for (size_t i = 0; i < this->count; i++)
		{
			double value = rand5(gen);
			if (this->population[i].fitness < value) this->population[i].fitness = 0;
			else this->population[i].fitness -= value;

			value = rand5(gen);
			if (this->population[i].fertility < value) this->population[i].fertility = 0;
			else this->population[i].fertility -= value;
		}

		std::cout << "Mass Extinction Event in year " << this->year << '\n';
	}

	for (size_t i = 0; i < this->count; i++)
	{

	}

	for (size_t i = 0; i < this->count; i++)
	{
		if (this->population[i].fitness < fitnessThreshold) {
			this->deaths++;
			killEntity(i);
			continue;
		}
		if (this->population[i].age++ == 20) {
			this->deaths++;
			killEntity(i);
			continue;
		}
	}
	for (size_t i = 0; i < this->count; i++)
	{
		int female = 0;
		if (this->population[i].gender || this->population[i].age < 5) continue;

		for (size_t j = 0; j < this->count; j++)
		{
			if (!this->population[j].gender || this->population[j].age < 5) continue;
			female = j; break;
		}

		for (size_t j = 0; j < 3; j++)
		{
			if (attractivenessTest(this->population[i], this->population[female])) {
				for (size_t k = 0; k < 3; k++)
				{
					double value = rand4(gen);
					if (this->population[i].fertility >= value && this->population[female].fitness >= value) {
						addEntity(entity(this->population[i], this->population[female]));
						this->newBabies++;
						break;
					}
				}
				if (this->population[i].fitness < 0.05) this->population[i].fitness = 0;
				else this->population[i].fitness -= 0.05;
			}
		}
	}

}

void Population::deletePopulation() {
	std::free((void*)this->population);
}

size_t Population::getMales() const {
	size_t count = 0;

	for (size_t i = 0; i < this->count; i++)
	{
		if (!this->population[i].gender) count++;
	}

	return count;
}
size_t Population::getFemales() const {
	size_t count = 0;

	for (size_t i = 0; i < this->count; i++)
	{
		if (this->population[i].gender) count++;
	}

	return count;
}