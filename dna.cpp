#include "dna.h"


DNA::DNA() {}

DNA::DNA(int genesLength, std::string target) {
	// set target
	this->target = target;
	for(int i = 0; i < genesLength; i++) {
		this->genes += (char) genRandom(32, 128);
	}
}

DNA::DNA(std::string target) {
	this->target = target;
}


DNA DNA::crossover(DNA parent1, DNA parent2) {
	DNA child = DNA(parent1.target);

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
		if (genes[i] == this->target[i]) {
			score++;
		}
	}

	this->fitness_value = float(score)/this->target.length();
	std::cout<<"Fitness value for "<< this->genes<<": "<<this->fitness_value<<std::endl;
}