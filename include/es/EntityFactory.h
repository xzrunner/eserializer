#pragma once

#include "ecsx/Entity.h"

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