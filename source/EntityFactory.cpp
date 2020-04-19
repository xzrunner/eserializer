#include "es/EntityFactory.h"

#include <ee0/CompEntityEditor.h>

#include <SM_Rect.h>
#include <guard/check.h>
#include <entity0/CompStorageType.h>
#include <entity0/World.h>
#include <entity2/CompImage.h>
#include <entity2/CompBoundingBox.h>
#include <entity2/CompTransform.h>
#include <sx/ResFileHelper.h>
#include <facade/ResPool.h>
#include <facade/Image.h>

namespace es
{

e0::Entity EntityFactory::Create(const ur2::Device& dev, e0::World& world, const std::string& filepath)
{
	auto entity = world.CreateEntity();
	auto type = sx::ResFileHelper::Type(filepath);
	switch (type)
	{
	case sx::RES_FILE_IMAGE:
		CreateFromImage(dev, world, entity, filepath);
		break;
	default:
		GD_REPORT_ASSERT("err type");
	}

	// transform
	world.AddComponent<e2::CompLocalMat>(entity);

	// editor
	world.AddComponent<ee0::CompEntityEditor>(entity);

	return entity;
}

void EntityFactory::CreateFromImage(const ur2::Device& dev, e0::World& world, e0::Entity& entity, const std::string& filepath)
{
	// image
	auto img = facade::ResPool::Instance().Fetch<facade::Image>(filepath, &dev);
	world.SetCompStorage<e2::CompImage>(e0::COMP_STORAGE_SPARSE);
	auto& cimg = world.AddComponent<e2::CompImage>(entity);
	cimg.tex = img->GetTexture();

	// aabb
	sm::rect sz(img->GetWidth(), img->GetHeight());
	auto& caabb = world.AddComponent<e2::CompBoundingBox>(entity);
	caabb.rect = sz;
}

}