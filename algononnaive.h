#pragma once
#include "algorithm.h"
#include "grapher.hpp"
#include <numeric>
#ifdef OMPEnable
#include <omp.h>
#endif

/*
 * All credit for this idea goes to my amazing physics teacher
 * Thanks :)
 * */

class singleAlgo : public algo
{
private:
    int totalInfected;
    int count = 0;
	std::mt19937* random_ = nullptr;
	std::vector<std::vector<human*>> backup;
    std::vector<std::vector<human*>> getArray(std::vector<human>* humans);
    std::vector<int> infectPeople;
    int _x, _y;
    grapher* infectRate = nullptr;
    grapher* infectedPeople = nullptr;
public:
	void
    run(std::vector<human> *humans, int infectChance, int infectRadius, int x, int y, double immuneChance,
        int immuneLength,
        int immuneLengthVar, int timestep) override;
	~singleAlgo();
	void end() override;
};
