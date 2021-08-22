#pragma once

#include"Base/pch.h"
#include"Base/dxtk.h"

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class ActorState{
public:
	ActorState() {};
	virtual ~ActorState() {};

	ActorState(ActorState&&) = default;
	ActorState& operator= (ActorState&&) = default;

	ActorState(ActorState const&) = delete;
	ActorState& operator= (ActorState const&) = delete;

	virtual int Update(const float deltaTime) = 0;
	virtual void OnDeviceLost() = 0;
	virtual void Render(SpriteBatch* spriteBatch, float player_positionX, float player_positionY) = 0;
};