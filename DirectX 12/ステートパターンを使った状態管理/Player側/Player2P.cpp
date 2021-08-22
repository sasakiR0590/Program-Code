#include"class/Player/Player2P/Player2P.h"
#include"Data/HanbleData/HanbleData.h"
#include"class/Player/ActorState/Wait/Wait.h"
#include"class/Player/ActorState/SwingDown/SwingDown.h"
#include"class/Player/ActorState/Tackle/Tackle.h"
#include"class/Player/ActorState/Counter/Counter.h"

Player2P::Player2P()
{
	_player_positionX = 980.0f;
	_player_positionY = 270.0f;
	_move_speed       = 100.0f;
	_action_state     = false;
}

void Player2P::LoadAssets(std::vector<D3D12_GPU_DESCRIPTOR_HANDLE>& handle_path)
{
	_copy_handle_path = handle_path;
	ChangeState(new WaitState(this, _copy_handle_path[PLAYERBODY_2P], _copy_handle_path[BAMBOOSWORD_2P]));
}

void Player2P::Update(const float deltaTime)
{
	if (_state->Update(deltaTime) == 1)
	{
		ChangeState(new WaitState(this, _copy_handle_path[PLAYERBODY_2P], _copy_handle_path[BAMBOOSWORD_2P]));
		_action_state = false;
	}

	if (!_action_state)
	{
		if (dxtk::GetInstance()->KeyState->Right)
			_player_positionX += _move_speed * deltaTime;

		if (dxtk::GetInstance()->KeyState->Left)
			_player_positionX -= _move_speed * deltaTime;

		if (dxtk::GetInstance()->KeyState->L)
		{
			ChangeState(new SwingDownState(this, _copy_handle_path[PLAYERBODY_2P], _copy_handle_path[BAMBOOSWORD_2P]));
			_action_state = true;
		}

		if (dxtk::GetInstance()->KeyState->K)
		{
			ChangeState(new TackleState(this, _copy_handle_path[TACKLE_2P]));
			_action_state = true;
		}

		if (dxtk::GetInstance()->KeyState->J)
		{
			ChangeState(new CounterState(this, _copy_handle_path[COUNTER_2P]));
			_action_state = true;
		}
	}
}

void Player2P::OnDeviceLost()
{
	_state->OnDeviceLost();
}

void Player2P::Render(SpriteBatch* spriteBatch)
{
	_state->Render(spriteBatch, _player_positionX, _player_positionY);
}