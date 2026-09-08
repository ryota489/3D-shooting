#include "Enemy.h"
#include "Engine\\Model.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy")
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0.0f, 0.0f, 20.0f };
	transform_.scale_ = { 0.5f, 0.5f, 0.5f };
	transform_.rotate_ = { 0.0f, 0.0f, 0.0f };
	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 1.0f);
	AddCollider(collider);
}

void Enemy::Update()
{
	static float time = 0.0f;
	//ot_.rotate_.y = time; //回転させる
	time += 0.025f;
	//transform_.position_.x = 6.0f * sin(
	float posx = 6.0 * sin(time);
	//float posy = cos(3.0f * time);
	transform_.position_.x = posx;
	//transform_.positon_.y = posy;
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet")
	{
		pTarget->KillMe(); //バレット消して
		KillMe(); //自分も消す
	}
}

void Enemy::ResetFormation()
{
}
