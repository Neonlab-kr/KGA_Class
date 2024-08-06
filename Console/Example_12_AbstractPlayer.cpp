#include "Example_12_AbstractPlayer.h"

AbstractPlayer::AbstractPlayer(const std::string& n, const int h) : AbstractUnit(n, h) {}

AbstractPlayer::~AbstractPlayer()
{
}

void AbstractPlayer::Attack() const
{
	std::cout << name << "АјАн" << std::endl;
}

void AbstractPlayer::TakeDamage(int damage)
{
	health -= damage;
	std::cout << health << std::endl;
}
