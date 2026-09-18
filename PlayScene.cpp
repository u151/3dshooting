#include "PlayScene.h"
#include "ClearScene.h"
#include "Engine\\Model.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "Engine/Image.h"
//#include ""

namespace {
	Player* player_ = nullptr;
}
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"), hModel_(-1)
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);//Playerのインスタンス＝プレイヤーオブジェクトを作る
	Instantiate<Bullet>(this);//Playerのインスタンス＝プレイヤーオブジェクトを作る
	for (int i = 0;i < ClearScene::clearcount;i++)
	{
		Instantiate<Enemy>(this);
	}
	//Camera::SetPosition(XMFLOAT3(0.0f, 5.0f, -10.0f));
	//Camera::SetTarget(XMFLOAT3(0.0f, 0.0f, 0.0f));
}

void PlayScene::Update()
{
	if (FindObject("Enemy") == nullptr) {
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{	

}

void PlayScene::Release()
{
}
