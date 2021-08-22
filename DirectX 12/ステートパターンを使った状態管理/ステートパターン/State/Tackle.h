#include"class/Player/ActorState/ActorState.h"
#include"class/Player/PlayerBase/PlayerBase.h"
#include"Base/dxtk.h"

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class TackleState : public ActorState {
public:
	TackleState(PlayerBase* player_base, D3D12_GPU_DESCRIPTOR_HANDLE& tackle_hanble) : _player_base(player_base)
	{
		_tackle_hanble    = tackle_hanble;
		_tackle_animation = 0;
		_tackle_state     = false;
	};
	~TackleState() {
		//ë“ã@èÛë‘ÇÃèIóπèàóù
	};

	TackleState(TackleState&&) = default;
	TackleState& operator= (TackleState&&) = default;

	TackleState(TackleState const&) = delete;
	TackleState& operator= (TackleState const&) = delete;

	virtual int Update(const float deltaTime) override;
	virtual void OnDeviceLost() override;
	virtual void Render(SpriteBatch* spriteBatch, float player_positionX, float player_positionY) override;
private:
	PlayerBase* _player_base;

	D3D12_GPU_DESCRIPTOR_HANDLE _tackle_hanble;
	int   _tackle_animation;
	bool  _tackle_state;
};