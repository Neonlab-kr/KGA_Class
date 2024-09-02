#pragma once
//IWindowsMessageHandler
#include <Windows.h>

__interface IGameClass
{
public:
	virtual void idle() PURE;
	virtual void attack() PURE;
};

class CharacterChoices abstract : public IGameClass
{
private :

public:

};

class Warrior : public CharacterChoices
{
private :

public :
	virtual void idle() override;
	virtual void attack() override;
};