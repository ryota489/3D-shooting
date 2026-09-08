#pragma once
#include "Engine\\GameObject.h"
class Enemy :
    public GameObject
{
public:
    Enemy(GameObject* parent);
    ~Enemy();
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
    void OnCollision(GameObject* pTarget); 
    static void ResetFormation();
private:
    int hModel_; //モデルのハンドル
};