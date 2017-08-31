#include <algorithm>
#include <iostream>
#include <fstream>

#include "round_robin.h"
#include "game.h"
#include "player.h"

void RoundRobinTournament::Load(std::istream& is)
{
	is >> m_PlayerCount;
	unsigned int gameCount = ((m_PlayerCount * m_PlayerCount) - m_PlayerCount) / 2;
	unsigned int playerGameCount = m_PlayerCount - 1;
	m_Players = new Player[m_PlayerCount];
	m_Games = new Game[gameCount];
	for (unsigned int i = 0; i < m_PlayerCount; ++i)
	{
		std::string name;
		is >> name;
		m_Players[i].initialize(playerGameCount);
		m_Players[i].setName(name);
	}
	for (unsigned int i = 0; i < gameCount; ++i)
	{
		std::string white, black, result;
		is >> white >> result >> black;
		float score = 0.0;
		if (result == "1-0")
		{
			score = 1.0;
		}
		else if (result == "0-1")
		{
			score = -1.0;
		}
		else
		{
			score = 0.5;
		}
		m_Games[i].initialize(white, black, score);
		Player* wPlayer = getPlayerByName(white);
		Player* bPlayer = getPlayerByName(black);
		if (wPlayer != nullptr)
		{
			wPlayer->addGame(&m_Games[i]);
		}
		if (bPlayer != nullptr)
		{
			bPlayer->addGame(&m_Games[i]);
		}
	}
}

void RoundRobinTournament::GenerateResults(std::ostream& os)
{
	std::sort(m_Players, m_Players + m_PlayerCount, [](const Player& a, const Player& b) -> bool {
		if (a.getScore() == b.getScore())
		{
			return a.getName() < b.getName();
		}
		else
		{
			return a.getScore() > b.getScore();
		}
	});

	// write top header
	os << "\t\t\t";
	for (unsigned int i = 0; i < m_PlayerCount; ++i)
	{
		os << (i + 1) << "\t";
	}

	os << "Total\n";

	// write out each row
	for (unsigned int i = 0; i < m_PlayerCount;  ++i)
	{
		os << (i + 1) << "\t" << m_Players[i].getName() << "\t";
		if (m_Players[i].getName().length() < 8)
		{
			os << "\t";
		}

		for (unsigned int j = 0; j < m_PlayerCount; ++j)
		{
			if (i == j)
			{
				os << "X\t";
			}
			else
			{
				Game* g = m_Players[i].getGameWithPlayer(m_Players[j].getName());
				if (g != nullptr)
				{
					float score = g->getScoreForPlayer(m_Players[i].getName());
					os << score << "\t";
				}
				else
				{
					os << "P\t";
				}
			}
		}
		os << m_Players[i].getScore() << std::endl;
	}
}

Player* RoundRobinTournament::getPlayerByName(std::string name)
{
	Player* result = nullptr;
	for (unsigned int i = 0; i < m_PlayerCount; ++i)
	{
		if (m_Players[i].getName() == name)
		{
			result = &m_Players[i];
			break;
		}
	}
	return result;
}
