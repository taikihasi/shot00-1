#include "DxLib.h"
#include "SceneMain.h"

SceneMain::SceneMain()
{
	m_hPlayerGraphic = -1;
	m_hShotGraphic = -1;
}
SceneMain::~SceneMain()
{

}

// 初期化
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/player.bmp");
	m_hShotGraphic = LoadGraph("data/shot.bmp");

	m_player.setMain(this);
	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();
	
	m_enemy.setHandle(m_hPlayerGraphic);
	m_enemy.init();

	for (auto& shot : m_shot)
	{
		shot.setHandle(m_hShotGraphic);
	}
}

// 終了処理
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);
}

// 毎フレームの処理
void SceneMain::update()
{
	m_player.update();
	m_enemy.update();
	for (auto& shot : m_shot)
	{
		shot.update();
	}

	// キー入力処理
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
	}
}

// 毎フレームの描画
void SceneMain::draw()
{
	m_player.draw();
	m_enemy.draw();

	for (auto& shot : m_shot)
	{
		shot.draw();
	}
}

bool SceneMain::createShot(Vec2 pos)
{
	for (auto& shot : m_shot)
	{
		if (!shot.isExist())
		{
			shot.start(pos);
			return true;
		}
	}
	return false;
}