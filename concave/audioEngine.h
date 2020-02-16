#pragma once
#define WIN32_LEAN_AND_MEAN

#include <xact3.h>
#include "iostream"
#include "constants.h"

class AudioEngine
{
private:
    IXACT3Engine* xactEngine;   // pointer to XACT sound engine
    IXACT3WaveBank* waveBank;   // pointer to XACT wave bank
    IXACT3SoundBank* soundBank; // pointer to XACT sound bank
    XACTINDEX cueI;             // XACT sound index
    void* mapWaveBank;          // call UnmapViewOfFile() to release file
    void* soundBankData;
    bool coInitialized;         // set true if coInitialize is successful
public:
    AudioEngine();
    ~AudioEngine();
    HRESULT initialize();

    void run();
    void play(const char cue[]);
    void stop(const char cue[]);
    void setVolume();
};
