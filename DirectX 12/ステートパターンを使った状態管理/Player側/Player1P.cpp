#include"class/Player/Player1P/Player1P.h"
#include"Data/HanbleData/HanbleData.h"
#include"class/Player/ActorState/Wait/Wait.h"
#include"class/Player/ActorState/SwingDown/SwingDown.h"
#include"class/Player/ActorState/Tackle/Tackle.h"
#include"class/Player/ActorState/Counter/Counter.h"

Player1P::Player1P()
{
	_player_positionX = 0.0f;
	_player_positionY = 270.0f;
	_move_speed       = 100.0f;
	_action_state     = false;
}

void Player1P::LoadAssets(std::vector<D3D12_GPU_DESCRIPTOR_HANDLE>& handle_path)
{
	_copy_handle_path = handle_path;
	ChangeState(new WaitState(this, _copy_handle_path[PLAYERBODY_1P], _copy_handle_path[BAMBOOSWORD_1P]));
}

void Player1P::Update(const float deltaTime)
{
	if (_state->Update(deltaTime) == 1)
	{
		ChangeState(new WaitState(this, _copy_handle_path[PLAYERBODY_1P], _copy_handle_path[BAMBOOSWORD_1P]));
		_action_state = false;
	}

	if (!_action_state)
	{
		if (dxtk::GetInstance()->KeyState->S)
			_player_positionX += _move_speed * deltaTime;

		if (dxtk::GetInstance()->KeyState->A)
			_player_positionX -= _move_speed * deltaTime;

		if (dxtk::GetInstance()->KeyState->C)
		{
			ChangeState(new SwingDownState(this, _copy_handle_path[PLAYERBODY_1P], _copy_handle_path[BAMBOOSWORD_1P]));
			_action_state = true;
		}

		if (dxtk::GetInstance()->KeyState->V)
		{
			ChangeState(new TackleState(this, _copy_handle_path[TACKLE_1P]));
			_action_state = true;
		}

		if (dxtk::GetInstance()->KeyState->B)
		{
			ChangeState(new CounterState(this, _copy_handle_path[COUNTER_1P]));
			_action_state = true;
		}
	}
}

void Player1P::OnDeviceLost()
{
	_state->OnDeviceLost();
}

void Player1P::Render(SpriteBatch* spriteBatch)
{
	_state->Render(spriteBatch, _player_positionX, _player_positionY);
}