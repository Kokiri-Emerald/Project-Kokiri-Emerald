#include "global.h"

void Setup_InitImpl(SetupState* this) {
    osSyncPrintf("ゼルダ共通データ初期化\n"); // "Zelda common data initalization"
    SaveContext_Init();


    // vanilla
    this->state.running = false;
    SET_NEXT_GAMESTATE(&this->state, ConsoleLogo_Init, ConsoleLogoState);


    this->state.running = false;
    gSaveContext.gameMode = GAMEMODE_NORMAL;
    gSaveContext.linkAge = LINK_AGE_ADULT;
    Sram_InitDebugSave();
    gSaveContext.dayTime = CLOCK_TIME(20, 0);
    gSaveContext.entranceIndex = ENTR_SPOT07_0_2;
    gSaveContext.respawnFlag = 0;
    gSaveContext.respawn[RESPAWN_MODE_DOWN].entranceIndex = ENTR_LOAD_OPENING;
    SET_NEXT_GAMESTATE(&this->state, Play_Init, PlayState);
}

void Setup_Destroy(GameState* thisx) {
}

void Setup_Init(GameState* thisx) {
    SetupState* this = (SetupState*)thisx;

    this->state.destroy = Setup_Destroy;
    Setup_InitImpl(this);
}
