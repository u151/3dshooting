#include "ClearScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

int ClearScene::clearcount = 1;

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent,"ClearScene"),hClearPic_(-1)
{
}

void ClearScene::Initialize()
{
	timer = 60;
	hClearPic_ = Image::Load("clear_screen.jpg");
	assert(hClearPic_ >= 0);
}

void ClearScene::Update()
{

	timer--;
	if (timer <= 0) {
		clearcount += 1;
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void ClearScene::Draw()
{
	Image::SetTransform(hClearPic_, transform_);
	Image::Draw(hClearPic_);
}

void ClearScene::Release()
{
}
