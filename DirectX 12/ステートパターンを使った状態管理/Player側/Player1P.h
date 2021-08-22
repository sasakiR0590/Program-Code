#pragma once

#include"Base/pch.h"
#include"Base/dxtk.h"
#include"class/Player/PlayerBase/PlayerBase.h"

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class Player1P : public PlayerBase {
public:
	Player1P();
	virtual ~Player1P() {
		Terminate();
	}

	Player1P(Player1P&&) = default;
	Player1P& operator= (Player1P&&) = default;

	Player1P(Player1P const&) = delete;
	Player1P& operator= (Player1P const&) = delete;

	void LoadAssets(std::vector<D3D12_GPU_DESCRIPTOR_HANDLE>& handle_path);
	void OnDeviceLost();
	void Render(SpriteBatch* spriteBatch);
	void Update(const float deltaTime);

private:
	std::vector<D3D12_GPU_DESCRIPTOR_HANDLE> _copy_handle_path;
};