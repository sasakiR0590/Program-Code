#include"../DirectX12 MainProject/class/Player/ActorState/Tackle/Tackle.h"
#include"Data/HanbleData/HanbleData.h"

int TackleState::Update(const float deltaTime)
{
	if (!_tackle_state)
	{
		_tackle_animation++;
		if (_tackle_animation == 9)
		{
			_tackle_state = true;
		}
	}

	if (_tackle_state)
	{
		_tackle_animation--;
		if (_tackle_animation == 0)
		{
			return 1;
		}
	}
	return 0;
}

void TackleState::OnDeviceLost()
{

}

void TackleState::Render(SpriteBatch* spriteBatch, float player_positionX, float player_positionY)
{
	spriteBatch->Draw(
		_tackle_hanble,
		XMUINT2(2700, 300),
		SimpleMath::Vector2(player_positionX, player_positionY),
		&RectWH(_tackle_animation * 300, 0, 300, 300)
	);
}