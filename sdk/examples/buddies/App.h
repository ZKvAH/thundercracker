/* -*- mode: C; c-basic-offset: 4; intent-tabs-mode: nil -*-
 *
 * Copyright <c> 2012 Sifteo, Inc. All rights reserved.
 */

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SIFTEO_BUDDIES_APP_H_
#define SIFTEO_BUDDIES_APP_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <sifteo/audio.h>
#include "Config.h"
#include "CubeWrapper.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

namespace Buddies {

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

class App
{
public:
    App();
    
    void Init();
    void Reset();
    void Update(float dt);
    void Draw();
    
    CubeWrapper &GetCubeWrapper(Sifteo::Cube::ID cubeId);
    
    void OnNeighborAdd(Sifteo::Cube::ID cubeId0, Sifteo::Cube::Side cubeSide0, Sifteo::Cube::ID cubeId1, Sifteo::Cube::Side cubeSide1);
    void OnTilt(Sifteo::Cube::ID cubeId);
    void OnShake(Sifteo::Cube::ID cubeId);
    
private:
    void AddCube(Sifteo::Cube::ID cubeId);
    void RemoveCube(Sifteo::Cube::ID cubeId);
    
    void StartShuffleState(ShuffleState shuffleState);
    void UpdateShuffle(float dt);
    void ShufflePieces();
    
    void UpdateSwap(float dt);
    void OnSwapBegin(unsigned int swapPiece0, unsigned int swapPiece1);
    void OnSwapExchange();
    void OnSwapFinish();
    
    CubeWrapper mCubeWrappers[kNumCubes];
    Sifteo::AudioChannel mChannel;
    float mResetTimer;
    
    ShuffleState mShuffleState;
    float mShuffleScoreTime;
    float mShuffleDelayTimer;
    bool mShufflePiecesMoved[NUM_SIDES * kNumCubes];
    
    SwapState mSwapState;
    unsigned int mSwapPiece0;
    unsigned int mSwapPiece1;
    int mSwapAnimationCounter;
};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
