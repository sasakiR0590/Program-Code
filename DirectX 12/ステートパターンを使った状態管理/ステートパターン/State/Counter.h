#include"class/Player/ActorState/ActorState.h"
#include"class/Player/PlayerBase/PlayerBase.h"
#include"Base/dxtk.h"

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class CounterState : public ActorState {
public:
	CounterState(PlayerBase* player_base, D3D12_GPU_DESCRIPTOR_HANDLE& counter_hanble) : _player_base(player_base)
	{
		_counter_hanble = counter_hanble;
		_counter_animation = 0;
		_counter_state     = false;
	};
	~CounterState() {
		//ë“ã@èÛë‘ÇÃèIóπèàóù
	};

	CounterState(CounterState&&) = default;
	CounterState& operator= (CounterState&&) = default;

	CounterState(CounterState const&) = delete;
	CounterState& operator= (CounterState const&) = delete;

	virtual int Update(const float deltaTime) override;
	virtual void OnDeviceLost() override;
	virtual void Render(SpriteBatch* spriteBatch, float player_positionX, float player_positionY) override;
private:
	PlayerBase* _player_base;

	D3D12_GPU_DESCRIPTOR_HANDLE _counter_hanble;

	int   _counter_animation;
	bool  _counter_state;
};