#include "Enemy.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h"
#include "Engine/SphereCollider.h"
#include <cstdlib>
#include <ctime>

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1)
{}

void Enemy::Initialize()
{
	hModel_ = Model::Load("teki.fbx");
	assert(hModel_ >= 0);

	// ランダムの初期化
	static bool initialized = false;

	if (!initialized)
	{
		srand(static_cast<unsigned int>(time(nullptr)));
		initialized = true;
	}

	// 出現位置をランダムにする
	float randomX =
		static_cast<float>((rand() % 21) - 10);

	float randomZ =
		static_cast<float>((rand() % 16) + 5);

	transform_.position_ =
	{ randomX, 0.0f, randomZ };

	transform_.scale_ =
	{ 0.25f, 0.25f, 0.25f };

	transform_.rotate_ =
	{ 0.0f, 180.0f, 0.0f };

	SphereCollider* collider =
		new SphereCollider(
			XMFLOAT3(0.0f, 0.0f, 0.0f),
			1.0f);

	AddCollider(collider);
}

void Enemy::Update()
{
	static float time = 0.0f;

	time += 0.025f;

	float posx = 6.0f * sin(time);

	transform_.position_.x = posx;
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet")
	{
		pTarget->KillMe();
		KillMe();
	}
}