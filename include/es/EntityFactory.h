#pragma once

#include "entity0/Entity.h"

#include <string>

namespace ur2 { class Device; }
namespace e0 { class World; }

namespace es
{

class EntityFactory
{
public:
	static e0::Entity Create(const ur2::Device& dev,
        e0::World& world, const std::string& filepath);

private:
	static void CreateFromImage(const ur2::Device& dev, e0::World& world,
        e0::Entity& entity, const std::string& filepath);

}; // EntityFactory

}