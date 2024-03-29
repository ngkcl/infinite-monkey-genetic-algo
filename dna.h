#ifndef _DNA_H_
#define _DNA_H_

#include <iostream>
#include "randomgen.h"
#include "config.h"
#include <vector>

class DNA {
	private: 
		std::string genes;
		float fitness_value;
		std::string target;
	public:	
		DNA();
		DNA(int genesLength);

		static DNA crossover(DNA parent1, DNA parent2);

		void fitness();
		void mutate(float mutationRate);

		// Getters
		std::string getGenes() {
			return this->genes;
		};

		float getFitness() {
			return this->fitness_value;
		};
		// ------
};

#endif
