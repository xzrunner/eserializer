#pragma once

#include "entity0/Entity.h"

#include <string>

namespace e0 { class World; }

namespace es
{

class EntityFactory
{
public:
	static e0::Entity Create(e0::World& world, const std::string& filepath);

private:
	static void CreateFromImage(e0::World& world, e0::Entity& entity, const std::string& filepath);

}; // EntityFactory

}