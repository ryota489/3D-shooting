#include "ClearScene.h"
#include "Engine\Image.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent, "ClearScene"), hClearPic_(-1)
{
}

void ClearScene::Initialize()
{
	hClearPic_ = Image::Load("clear.png");
	assert (hClearPic_ >= 0);
}

void ClearScene::Update()
{
}

void ClearScene::Draw()
{
	transform_.scale_ = { 1.5f, 1.5f, 1.0f };//画像の大きさを変更
	Image::SetTransform(hClearPic_, transform_);//画像の位置や向きなどを設定
	Image::Draw(hClearPic_);//画像を表示
}

void ClearScene::Release()
{
}
