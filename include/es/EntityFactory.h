#pragma once

#include "ecsx/Entity.h"

#include <string>

namespace ecsx { class World; }

namespace es
{

class EntityFactory
{
public:
	static ecsx::Entity Create(ecsx::World& world, const std::string& filepath);

private:
	static void CreateFromImage(ecsx::World& world, ecsx::Entity& entity, const std::string& filepath);

}; // EntityFactory

}