#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "round_robin.h"

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		std::cout << "Usage:  assignment01 [input file] [output file]" << std::endl;
		return 0;
	}

	std::ifstream fin(argv[1]);
	std::ofstream fout(argv[2]);

	RoundRobinTournament tournament;
	tournament.Load(fin);
	tournament.GenerateResults(fout);

	return 0;
}
