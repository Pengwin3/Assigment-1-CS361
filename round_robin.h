#ifndef __ROUND_ROBIN_H__
#define __ROUND_ROBIN_H__

#include <iostream>

#include "player.h"
#include "game.h"

class RoundRobinTournament
{
public:
	RoundRobinTournament() : m_PlayerCount(0), m_Players(nullptr), m_Games(nullptr)
	{}

	~RoundRobinTournament()
	{
		delete [] m_Players;
		delete [] m_Games;
	}

	void Load(std::istream& fin);
	void GenerateResults(std::ostream& fout);

	Player* getPlayerByName(std::string name);
private:
	unsigned int m_PlayerCount;
	Player* m_Players;
	Game* m_Games;

private:
	RoundRobinTournament(const RoundRobinTournament&); // make this non-copyable
	RoundRobinTournament& operator= (const RoundRobinTournament&);
};

#endif // __ROUND_ROBIN_H__
