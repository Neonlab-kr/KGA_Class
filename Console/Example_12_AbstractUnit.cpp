#include "Example_12_AbstractUnit.h"

AbstractUnit::AbstractUnit(const std::string& n, const int h) :name(n), health(h) {}

AbstractUnit::~AbstractUnit()
{
}
