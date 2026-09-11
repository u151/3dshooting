#pragma once
#include "Engine/GameObject.h"
class Secret :
	public GameObject
{
public:
	Secret(GameObject* parent);
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	int hSecretPic_;
};

