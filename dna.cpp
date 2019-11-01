#include "dna.h"

Config config;

DNA::DNA() {
	this->target = config.TARGET_PHRASE;
}

DNA::DNA(int genesLength) {
	this->target = config.TARGET_PHRASE;
	for(int i = 0; i < genesLength; i++) {
		this->genes += (char) genRandom(32, 128);
	}
}

DNA DNA::crossover(DNA parent1, DNA parent2) {
	DNA child;

	int midpt = int(genRandom(0, parent1.genes.length()));

	for (int i=0; i < parent1.genes.length(); i++) {
		if (i > midpt) {
			child.genes += parent1.genes[i];
		} else {
			child.genes += parent2.genes[i];
		}	

	}

	std::cout<<"produced child with genes "<<child.getGenes()<<std::endl;

	return child;
}

void DNA::mutate(float mutationRate) {
	for (int i=0; i< this->genes.length(); i++) {
		if (genRandom(0, 100) < int(mutationRate * 100)) {
			this->genes[i] = (char) genRandom(32, 128);
			std::cout<<"mutating to: "<<this->genes<<std::endl;
		}
	}
}

void DNA::fitness() {
	int score = 0;

	for (int i=0; i< this->genes.length(); i++) {
		if (this->genes[i] == this->target[i]) {
			score++;
		}
	}

	this->fitness_value = float(score)/(this->target.length());
	std::cout<<"Fitness value for "<< this->genes<<": "<<this->fitness_value<<std::endl;
}