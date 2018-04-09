#include "es/EntityFactory.h"

#include <SM_Rect.h>
#include <ecsx/CompStorageType.h>
#include <sx/ResFileHelper.h>
#include <facade/ResPool.h>
#include <facade/Image.h>
#include <facade/Texture.h>
#include <entity2/CompImage.h>
#include <entity2/CompBoundingBox.h>

namespace es
{

ecsx::Entity EntityFactory::Create(ecsx::World& world, const std::string& filepath)
{
	auto entity = world.CreateEntity();
	auto type = sx::ResFileHelper::Type(filepath);
	switch (type)
	{
	case sx::FILE_IMAGE:
		CreateFromImage(world, entity, filepath);
		break;
	}
	return entity;
}

void EntityFactory::CreateFromImage(ecsx::World& world, ecsx::Entity& entity, const std::string& filepath)
{
	// image
	auto img = facade::ResPool::Instance().Fetch<facade::Image>(filepath);
	world.SetCompStorage<e2::CompImage>(ecsx::COMP_STORAGE_SPARSE);
	auto& cimg = entity.AddComponent<e2::CompImage>();
	cimg.tex = img->GetTexture();

	// aabb
	sm::rect sz(img->GetWidth(), img->GetHeight());
	auto& caabb = entity.AddComponent<e2::CompBoundingBox>();
	caabb.aabb.Build(sz);
}

}