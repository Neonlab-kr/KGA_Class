#include <iostream>

enum class eClassColor
{
	Red, Green, White
};

enum class SkillType
{
	Fire, Ice, Lighting
};

void main()
{
	eClassColor color = eClassColor::Red;

	int num = static_cast<int>(eClassColor::Red);

	SkillType skill = SkillType::Fire;

	switch (skill)
	{
	case SkillType::Fire:
		break;
	case SkillType::Ice:
		break;
	case SkillType::Lighting:
		break;
	default:
		break;
	}

}