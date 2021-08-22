#include"../DirectX12 MainProject/class/Player/ActorState/Counter/Counter.h"
#include"Data/HanbleData/HanbleData.h"

int CounterState::Update(const float deltaTime)
{
	if (!_counter_state)
	{
		_counter_animation++;
		if (_counter_animation == 8)
		{
			_counter_state = true;
		}
	}

	if (_counter_state)
	{
		_counter_animation--;
		if (_counter_animation == 0)
		{
			return 1;
		}
	}
	return 0;
}

void CounterState::OnDeviceLost()
{

}

void CounterState::Render(SpriteBatch* spriteBatch, float player_positionX, float player_positionY)
{
	spriteBatch->Draw(
		_counter_hanble,
		XMUINT2(2400, 300),
		SimpleMath::Vector2(player_positionX, player_positionY),
		&RectWH(_counter_animation * 300, 0, 300, 300)
	);
}