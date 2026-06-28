#include "Player.h"
 
using namespace std;

Player::Player(string name_in)
{
	name = name_in;
	wins = 0;
	losses = 0;
	draws = 0;
}

string Player::getname()
{
	return name;
}
void Player::addwins()
{
	wins++;
}
void Player::addlosses()
{
	losses++;
}
void Player::adddraw()
{
	draws++;
}
string Player::getThrow()
{
	int Throw;
	Throw = rand() % 3;
	if (Throw == 0)
	{
		return "Rock";
	}
	else if (Throw == 1)
	{
		return "Paper";
	}
	else if (Throw == 2)
	{
		return "Scissors";
	}
}

double Player::getRecord()
{
	if (wins+losses+draws == 0)
	{
		return 0;
	}
	else
	{
		return wins/(double)(wins+losses+draws);
	}
}
int Player::getwins()
{
	return wins;
}

int Player::getlosses()
{
	return losses;
}

int Player::getdraws()
{
	return draws;
}


string Player::tostring()
{
	stringstream ss;

	ss << "Name: " << name << endl;
	ss << "Wins: " << wins << endl;
	ss << "Losses: " << losses << endl;
	ss << "Draws: " << draws << endl;
	ss << "Win Record: " << getRecord();

	return ss.str();
}
