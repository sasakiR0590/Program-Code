#include"class/Player/ActorState/ActorState.h"
#include"class/Player/PlayerBase/PlayerBase.h"
#include"Base/dxtk.h"

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class DamageState : public ActorState {
public:
	DamageState(PlayerBase* player_base,D3D12_GPU_DESCRIPTOR_HANDLE& damage_hanble) : _player_base(player_base)
	{
		_damage_hanble = damage_hanble;
	};
	~DamageState() {
		//ë“ã@èÛë‘ÇÃèIóπèàóù
	};

	DamageState(DamageState&&) = default;
	DamageState& operator= (DamageState&&) = default;

	DamageState(DamageState const&) = delete;
	DamageState& operator= (DamageState const&) = delete;

	virtual int Update(const float deltaTime) override;
	virtual void OnDeviceLost() override;
	virtual void Render(SpriteBatch* spriteBatch, float player_positionX, float player_positionY) override;
private:
	PlayerBase* _player_base;

	D3D12_GPU_DESCRIPTOR_HANDLE _damage_hanble;
};