#pragma once

#include"Base/pch.h"
#include"Base/dxtk.h"
#include"class/Player/PlayerBase/PlayerBase.h"

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class Player2P : public PlayerBase {
public:
	Player2P();
	virtual ~Player2P() {
		Terminate();
	}

	Player2P(Player2P&&) = default;
	Player2P& operator= (Player2P&&) = default;

	Player2P(Player2P const&) = delete;
	Player2P& operator= (Player2P const&) = delete;

	void LoadAssets(std::vector<D3D12_GPU_DESCRIPTOR_HANDLE>& handle_path);
	void OnDeviceLost();
	void Render(SpriteBatch* spriteBatch);
	void Update(const float deltaTime);

private:
	std::vector<D3D12_GPU_DESCRIPTOR_HANDLE> _copy_handle_path;
};