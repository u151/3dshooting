#include "Player.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h"
#include "Bullet.h"

Player::Player(GameObject* parent)
//親のポインタ、オブジェクトの名前
	:GameObject(parent, "Player"), hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("hontai.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0.0f,-4.0f,0.0f };
}

void Player::Update()
{
	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A))
	{
		//左に移動
		transform_.position_.x = transform_.position_.x - 0.1f;
	}
	if (Input::IsKey(DIK_RIGHT) || Input::IsKey(DIK_D))
	{
		//右に移動
		transform_.position_.x = transform_.position_.x + 0.1f;
	}
	if (Input::IsKey(DIK_UP) || Input::IsKey(DIK_W))
	{
		//右に移動
		transform_.position_.y = transform_.position_.y + 0.1f;
	}
	if (Input::IsKey(DIK_DOWN) || Input::IsKey(DIK_S))
	{
		//右に移動
		transform_.position_.y = transform_.position_.y - 0.1f;
	}
	if (Input::IsKey(DIK_SPACE))
	{
		//何らかの処理
		Bullet* pBullet = Instantiate<Bullet>(this->GetParent());
		pBullet->SetPosition(transform_.position_);
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
