#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>

#include "game.h"

class Player
{

	private:
		std::string m_Name;
		unsigned int m_GameCount;
		Game** m_Games;

public:
	/* START CHANGE BLOCK */

//			Player() : m_Name(), m_Games(nullptr), m_GameCount(0)
	// , Game(nullptr)
//			{}

//---------------------------------------

	// Player::Player(const Player &addGame)
	// {
	// 	m_Games = new unsigned int;
	// 	*m_Games = *Game;
	// }

//---------------------------------------

// 	Player(const Player &m_Games) {
//    Game = new unsigned int;
//    **Game = **m_Games.Game; // copy the value
// }

//---------------------------------------
// Player& operator= (const Player&);

	~Player()
	{
		delete [] m_Games;
		// m_Name = "";
	}

//	const Game* getGame(unsigned int);
	// const Game getGame(unsigned int gameCount);
	// const Game getGameWithPlayer();
//	int *  m_Games;

	/* END CHANGE BLOCK */
public:
	void initialize(unsigned int gameCount)
	{
		m_GameCount = gameCount;
		m_Games = new Game*[gameCount];
	}

	std::string getName() const
	{
		return m_Name;
	}

	void setName(std::string name)
	{
		m_Name = name;
	}

	const Game* getGame(unsigned int i) const
	{
		// assume i is in range [0, gameCount)
		return m_Games[i];
	}

	void addGame(Game* g)
	{
		// assume all games added are unique
		for (unsigned int i = 0; i < m_GameCount; ++i)
		{
			if (m_Games[i] == nullptr)
			{
				m_Games[i] = g;
				break;
			}
		}
	}

	float getScore() const
	{
		float score = 0.0;
		for (unsigned int i = 0; i < m_GameCount; ++i)
		{
			if (m_Games[i] != nullptr)
			{
				score += m_Games[i]->getScoreForPlayer(m_Name);
			}
		}
		return score;
	}

	Game* getGameWithPlayer(std::string name) const
	{
		Game* result = nullptr;
		for (unsigned int i = 0; i < m_GameCount; ++i)
		{
            if (m_Games[i] != nullptr)
            {
                if (m_Games[i]->getWhitePlayer() == name || m_Games[i]->getBlackPlayer() == name)
                {
                    result = m_Games[i];
                }
			}
		}
		return result;
	}

// private:
// 	std::string m_Name;
// 	unsigned int m_GameCount;
// 	Game** m_Games;
};

#endif // __PLAYER_H__
