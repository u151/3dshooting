#include "PlayScene.h"
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
	hSecretPic_= Image::Load("clear.jpg");
	Instantiate<Player>(this);//Playerのインスタンス＝プレイヤーオブジェクトを作る
	Instantiate<Bullet>(this);//Playerのインスタンス＝プレイヤーオブジェクトを作る
	Instantiate<Enemy>(this);
	//Camera::SetPosition(XMFLOAT3(0.0f, 5.0f, -10.0f));
	//Camera::SetTarget(XMFLOAT3(0.0f, 0.0f, 0.0f));
}

void PlayScene::Update()
{
	if (FindObject("Enemy")==nullptr) {
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
	if (Input::IsKey(DIK_I)) {
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_SECRET);
	}
}

void PlayScene::Draw()
{	

}

void PlayScene::Release()
{
}
