#include"class/Player/ActorState/ActorState.h"
#include"class/Player/PlayerBase/PlayerBase.h"
#include"Base/dxtk.h"

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class SwingDownState : public ActorState {
public:
	SwingDownState(PlayerBase* player_base, D3D12_GPU_DESCRIPTOR_HANDLE& body_hanble, D3D12_GPU_DESCRIPTOR_HANDLE& bamboosword_hanble) : _player_base(player_base)
	{
		_body_hanble            = body_hanble;
		_bamboosword_hanble     = bamboosword_hanble;
		_bamboo_sword_animation = 0;
		_bamboo_sword_state     = false;
	};
	~SwingDownState() {
		//ë“ã@èÛë‘ÇÃèIóπèàóù
	};

	SwingDownState(SwingDownState&&) = default;
	SwingDownState& operator= (SwingDownState&&) = default;

	SwingDownState(SwingDownState const&) = delete;
	SwingDownState& operator= (SwingDownState const&) = delete;

	virtual int Update(const float deltaTime) override;
	virtual void OnDeviceLost() override;
	virtual void Render(SpriteBatch* spriteBatch, float player_positionX, float player_positionY) override;
private:
	PlayerBase* _player_base;

	D3D12_GPU_DESCRIPTOR_HANDLE _body_hanble;
	D3D12_GPU_DESCRIPTOR_HANDLE _bamboosword_hanble;

	int   _bamboo_sword_animation;
	bool  _bamboo_sword_state;
};