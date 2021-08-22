#include"../DirectX12 MainProject/class/Player/ActorState/Damage/Damage.h"
#include"Data/HanbleData/HanbleData.h"

int DamageState::Update(const float deltaTime)
{
	return 0;
}

void DamageState::OnDeviceLost()
{
}

void DamageState::Render(SpriteBatch* spriteBatch, float player_positionX, float player_positionY)
{
	spriteBatch->Draw(
		_damage_hanble,
		XMUINT2(6000, 300),
		SimpleMath::Vector2(player_positionX, player_positionY),
		&RectWH(0, 0, 300, 300)
	);
}