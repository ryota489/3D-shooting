#include "PlayScene.h"
#include "Engine\\Model.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"),hModel_(-1)
{
}

void PlayScene::Initialize()
{
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
	//static Transform ot;//おでん用のトランスフォーム
	ot_.position_.x += speed_ * dir_;
	if (ot_.position_.x > 5.0f)
	{

		ot_.position_.x = 5.0f;
		dir_ = -1;
	} 
	else if (ot_.position_.x < 5.0f)
	{
		ot_.position_.x = -5.0f;
		dir_ = -1;
	}

	ot_.scale_ = { 1.0f, 1.0f, 2.0f };
	ot_.rotate_.y += 0.1f; //回転させる

	Model::SetTransform(hModel_, ot_);
	Model::Draw(hModel_);
}

void PlayScene::Release()
{
}
