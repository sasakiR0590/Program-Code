#include"../DirectX12 MainProject/class/Player/ActorState/Wait/Wait.h"
#include"Data/HanbleData/HanbleData.h"

int WaitState::Update(const float deltaTime)
{
	return 0;
}

void WaitState::OnDeviceLost()
{
}

void WaitState::Render(SpriteBatch* spriteBatch, float player_positionX, float player_positionY)
{
	spriteBatch->Draw(
		_body_hanble,
		XMUINT2(300, 300),
		SimpleMath::Vector2(player_positionX, player_positionY)
	);

	spriteBatch->Draw(
		_bamboosword_hanble,
		XMUINT2(6000, 300),
		SimpleMath::Vector2(player_positionX, player_positionY),
		&RectWH(0, 0, 300, 300)
	);
}