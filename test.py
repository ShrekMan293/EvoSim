import csv

# Parameters
initial_population = 4
average_offspring_per_pair = 2
generations = 128
lifespan = 12
fertility_start_age = 5
fertility_end_age = 10
male_no_mate_rate = 0.02  # 2% of males do not get a mate
general_death_rate = 0.05  # 5% general mortality rate across all ages

# Initialize population age structure for males and females
population_males = [0] * lifespan
population_females = [0] * lifespan
# Assume an even split of initial population
population_males[0] = initial_population // 2
population_females[0] = initial_population // 2

# Function to simulate a single generation
def simulate_generation(population_males, population_females):
    new_population_males = [0] * lifespan
    new_population_females = [0] * lifespan
    
    # Age the population and apply general mortality rate
    for age in range(lifespan - 1, 0, -1):
        new_population_males[age] = int(population_males[age - 1] * (1 - general_death_rate))  # Convert to int
        new_population_females[age] = int(population_females[age - 1] * (1 - general_death_rate))  # Convert to int
    
    # Calculate new births from fertile pairs
    fertile_males = sum(new_population_males[age] for age in range(fertility_start_age, fertility_end_age + 1))
    fertile_females = sum(new_population_females[age] for age in range(fertility_start_age, fertility_end_age + 1))
    
    # 2
