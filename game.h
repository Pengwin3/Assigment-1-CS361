#ifndef __GAME_H__
#define __GAME_H__

#include <string>

class Game
{
private:
	std::string m_WhitePlayer;
	std::string m_BlackPlayer;
	float m_Score;

public:
	void initialize(std::string white, std::string black, float score)
	{
		m_WhitePlayer = white;
		m_BlackPlayer = black;
		m_Score = score;
	}

	std::string getWhitePlayer() const
	{
		return m_WhitePlayer;
	}

	std::string getBlackPlayer() const
	{
		return m_BlackPlayer;
	}

	float getScoreForPlayer(std::string name)
	{
		if (m_WhitePlayer == name && m_Score == 1.0)
		{
			return 1.0;
		}

		if (m_BlackPlayer == name && m_Score == -1.0)
		{
			return 1.0;
		}

		if (m_Score == 0.5)
		{
			return 0.5;
		}

		return 0.0;
	}
};

#endif // __GAME_H__
