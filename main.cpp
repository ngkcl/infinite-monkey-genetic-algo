#include <iostream>
#include "dna.h"
#include <vector>
#include <string>

const int POPULATION_LIMIT = 200;
const float MUTATION_RATE = 0.05;
const std::string TARGET_PHRASE = "pomodoro";

float bestFitness;
DNA bestPhrase;
int generation = 0;

void displayGenerationResults();

int main() {
    std::vector<DNA> population;
    std::vector<DNA> mating_pool;

    std::cout<<"target is: "<<TARGET_PHRASE<<std::endl<<std::endl;

    // Fill population list
    for (int i=0; i < POPULATION_LIMIT; i++) {
        DNA testDNA = DNA(TARGET_PHRASE.length(), TARGET_PHRASE);
        population.push_back(testDNA);
    }


REGEN:
    bestFitness = -1;
    generation++;

    // Calculate fitness for population
    for (int i=0; i < population.size(); i++) {
        population[i].fitness();
    }

    // Clear mating pool
    mating_pool.clear();

    // Fill mating pool
    for (int i=0; i < population.size(); i++) {
        int n = int(population[i].getFitness() * 100);
        std::cout<<"genes "<<population[i].getGenes()<<" have a fitness of "<<population[i].getFitness()<<std::endl;

        if (population[i].getFitness() > bestFitness) {
            bestFitness = population[i].getFitness();
            bestPhrase = population[i];
        }

        for (int j=0; j<n; j++) {
            mating_pool.push_back(population[i]);
        }
    }
    std::cout<<std::endl;

    std::cout<<"best phrase is: "<<bestPhrase.getGenes()<<std::endl;

    // Check for end condition
    if (bestPhrase.getGenes().compare(TARGET_PHRASE) == 0) {
        std::cout<<"found target"<<std::endl;
        displayGenerationResults();
        return 0;
    };

    // TODO: Check if mating_pool is actually > 0, else goto start
    std::cout<<"mating pool size is: "<<mating_pool.size()<<std::endl;

    for (int i=0; i < population.size(); i++) {
        int a = genRandom(0, mating_pool.size());
        std::cout<<a<<std::endl;
        int b = genRandom(0, mating_pool.size());

        DNA parentA = mating_pool[a];
        DNA parentB = mating_pool[b];

        DNA child = DNA::crossover(parentA, parentB);
        child.mutate(MUTATION_RATE);

        population[i] = child;
    }
    
    displayGenerationResults();
    goto REGEN;
}

void displayGenerationResults() {
    std::cout<<std::endl<<"CURRENT GENERATION: "<<generation<<std::endl;
    std::cout<<"BEST PHRASE: "<<bestPhrase.getGenes()<<std::endl;
    std::cout<<"FITNESS SCORE: "<<bestPhrase.getFitness()<<std::endl<<std::endl;
}