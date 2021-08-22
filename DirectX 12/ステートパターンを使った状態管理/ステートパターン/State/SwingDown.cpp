#include"../DirectX12 MainProject/class/Player/ActorState/SwingDown/SwingDown.h"
#include"Data/HanbleData/HanbleData.h"

int SwingDownState::Update(const float deltaTime)
{
	if (!_bamboo_sword_state) {
		_bamboo_sword_animation++;
		if (_bamboo_sword_animation == 9) {
			_bamboo_sword_animation = 9;
			_bamboo_sword_state = true;
		}
	}
	else {
		_bamboo_sword_animation--;
		if (_bamboo_sword_animation == 0) {
			_bamboo_sword_animation = 0;
			return 1;
		}
	}
	return 0;
}

void SwingDownState::OnDeviceLost()
{

}

void SwingDownState::Render(SpriteBatch* spriteBatch, float player_positionX, float player_positionY)
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
		&RectWH(_bamboo_sword_animation * 300, 0, 300, 300)
	);
}