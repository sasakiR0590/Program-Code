#include"class/Player/ActorState/ActorState.h"
#include"class/Player/PlayerBase/PlayerBase.h"
#include"Base/dxtk.h"

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class WaitState : public ActorState {
public:
	WaitState(PlayerBase* player_base, D3D12_GPU_DESCRIPTOR_HANDLE& body_hanble, D3D12_GPU_DESCRIPTOR_HANDLE& bamboosword_hanble) : _player_base(player_base)
	{
		_body_hanble        = body_hanble;
		_bamboosword_hanble = bamboosword_hanble;
	};
	~WaitState() {
		//ë“ã@èÛë‘ÇÃèIóπèàóù
	};

	WaitState(WaitState&&) = default;
	WaitState& operator= (WaitState&&) = default;

	WaitState(WaitState const&) = delete;
	WaitState& operator= (WaitState const&) = delete;

	virtual int Update(const float deltaTime) override;
	virtual void OnDeviceLost() override;
	virtual void Render(SpriteBatch* spriteBatch, float player_positionX, float player_positionY) override;
private:
	PlayerBase* _player_base;

	D3D12_GPU_DESCRIPTOR_HANDLE _body_hanble;
	D3D12_GPU_DESCRIPTOR_HANDLE _bamboosword_hanble;
};