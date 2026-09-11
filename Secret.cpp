#include "Secret.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"


Secret::Secret(GameObject* parent)
{
}

void Secret::Initialize()
{
	hSecretPic_ = Image::Load("clear.jpg");
	assert(hSecretPic_ >= 0);
}

void Secret::Update()
{
	if (Input::IsKey(DIK_O)) {
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void Secret::Draw()
{
	Image::SetTransform(hSecretPic_, transform_);
	Image::Draw(hSecretPic_);
}

void Secret::Release()
{
}
