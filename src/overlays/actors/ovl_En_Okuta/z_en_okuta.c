/*
 * File: z_en_okuta.c
 * Overlay: ovl_En_Okuta
 * Description: Octorok
 */

#include "z_en_okuta.h"

#include "objects/object_okuta/object_okuta.h"

#define FLAGS (ACTOR_FLAG_TARGETABLE | ACTOR_FLAG_UNFRIENDLY)

#define THIS ((EnOkuta*)thisx)

void EnOkuta_Init(Actor* thisx, PlayState* play);
void EnOkuta_Destroy(Actor* thisx, PlayState* play);
void EnOkuta_Update(Actor* thisx, PlayState* play);
void EnOkuta_Draw(Actor* thisx, PlayState* play);

void func_8086E52C(EnOkuta* this, PlayState* play);
void func_8086E5E8(EnOkuta* this, PlayState* play);
void func_8086E658(EnOkuta* this, PlayState* play);
void func_8086E7E8(EnOkuta* this, PlayState* play);
void func_8086E948(EnOkuta* this, PlayState* play);
void func_8086EC00(EnOkuta* this, PlayState* play);
void func_8086EF14(EnOkuta* this, PlayState* play);
void func_8086EFE8(EnOkuta* this, PlayState* play);
void func_8086F434(EnOkuta* this, PlayState* play);
void func_8086F4B0(EnOkuta* this, PlayState* play);
void func_8086F57C(EnOkuta* this, PlayState* play);
void func_8086F694(EnOkuta* this, PlayState* play);


#if 0
ActorInit En_Okuta_InitVars = {
    /**/ ACTOR_EN_OKUTA,
    /**/ ACTORCAT_ENEMY,
    /**/ FLAGS,
    /**/ OBJECT_OKUTA,
    /**/ sizeof(EnOkuta),
    /**/ EnOkuta_Init,
    /**/ EnOkuta_Destroy,
    /**/ EnOkuta_Update,
    /**/ EnOkuta_Draw,
};

// static ColliderCylinderInit sCylinderInit = {
static ColliderCylinderInit D_808708A0 = {
    { COLTYPE_NONE, AT_ON | AT_TYPE_ENEMY, AC_ON | AC_TYPE_PLAYER, OC1_ON | OC1_TYPE_ALL, OC2_TYPE_2, COLSHAPE_CYLINDER, },
    { ELEMTYPE_UNK4, { 0xF7CFFFFF, 0x00, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_HARD, BUMP_ON, OCELEM_ON, },
    { 13, 20, 0, { 0, 0, 0 } },
};

// static ColliderCylinderInit sCylinderInit = {
static ColliderCylinderInit D_808708CC = {
    { COLTYPE_HIT0, AT_ON | AT_TYPE_ENEMY, AC_ON | AC_TYPE_PLAYER, OC1_ON | OC1_TYPE_ALL, OC2_TYPE_1, COLSHAPE_CYLINDER, },
    { ELEMTYPE_UNK1, { 0xF7CFFFFF, 0x00, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_HARD, BUMP_ON, OCELEM_ON, },
    { 20, 40, -30, { 0, 0, 0 } },
};

// sColChkInfoInit
static CollisionCheckInfoInit D_808708F8 = { 4, 15, 60, 100 };

// static DamageTable sDamageTable = {
static DamageTable D_80870900 = {
    /* Deku Nut       */ DMG_ENTRY(0, 0x0),
    /* Deku Stick     */ DMG_ENTRY(1, 0x0),
    /* Horse trample  */ DMG_ENTRY(0, 0x0),
    /* Explosives     */ DMG_ENTRY(1, 0x0),
    /* Zora boomerang */ DMG_ENTRY(1, 0x0),
    /* Normal arrow   */ DMG_ENTRY(1, 0x0),
    /* UNK_DMG_0x06   */ DMG_ENTRY(0, 0x0),
    /* Hookshot       */ DMG_ENTRY(1, 0x0),
    /* Goron punch    */ DMG_ENTRY(1, 0x0),
    /* Sword          */ DMG_ENTRY(1, 0x0),
    /* Goron pound    */ DMG_ENTRY(0, 0x0),
    /* Fire arrow     */ DMG_ENTRY(1, 0x0),
    /* Ice arrow      */ DMG_ENTRY(2, 0x3),
    /* Light arrow    */ DMG_ENTRY(2, 0x4),
    /* Goron spikes   */ DMG_ENTRY(1, 0x0),
    /* Deku spin      */ DMG_ENTRY(1, 0x0),
    /* Deku bubble    */ DMG_ENTRY(1, 0x0),
    /* Deku launch    */ DMG_ENTRY(2, 0x0),
    /* UNK_DMG_0x12   */ DMG_ENTRY(0, 0x0),
    /* Zora barrier   */ DMG_ENTRY(0, 0x0),
    /* Normal shield  */ DMG_ENTRY(0, 0x0),
    /* Light ray      */ DMG_ENTRY(0, 0x0),
    /* Thrown object  */ DMG_ENTRY(1, 0x0),
    /* Zora punch     */ DMG_ENTRY(1, 0x0),
    /* Spin attack    */ DMG_ENTRY(1, 0x0),
    /* Sword beam     */ DMG_ENTRY(0, 0x0),
    /* Normal Roll    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1B   */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1C   */ DMG_ENTRY(0, 0x0),
    /* Unblockable    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1E   */ DMG_ENTRY(0, 0x0),
    /* Powder Keg     */ DMG_ENTRY(1, 0x0),
};

// static InitChainEntry sInitChain[] = {
static InitChainEntry D_80870920[] = {
    ICHAIN_S8(hintId, TATL_HINT_ID_OCTOROK, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 6500, ICHAIN_STOP),
};

#endif

extern ColliderCylinderInit D_808708A0;
extern ColliderCylinderInit D_808708CC;
extern CollisionCheckInfoInit D_808708F8;
extern DamageTable D_80870900;
extern InitChainEntry D_80870920[];

extern UNK_TYPE D_0600044C;
extern UNK_TYPE D_06003250;
extern UNK_TYPE D_06003958;
extern UNK_TYPE D_06003B24;
extern UNK_TYPE D_06003EE4;
extern UNK_TYPE D_06004204;
extern AnimationHeader D_0600466C;

void func_8086E4FC(EnOkuta*);                     /* extern */
void func_808700C0(Actor* this, PlayState* play); /* extern */

extern SkeletonHeader D_060033D0;

void EnOkuta_Init(Actor* thisx, PlayState* play2) {
    EnOkuta* this = (EnOkuta*)thisx;
    PlayState* play = play2;
    WaterBox* sp3C;
    f32 sp38;
    s32 sp34;

    Actor_ProcessInitChain(&this->actor, D_80870920);
    this->unk190 = (this->actor.params >> 8) & 0xFF;
    thisx->params &= 0xFF;
    if ((this->actor.params == 0) || (this->actor.params == 1)) {
        SkelAnime_Init(play, &this->skelAnime, &D_060033D0, &D_0600466C, this->jointTable, this->morphTable, 16);
        Collider_InitAndSetCylinder(play, &this->collider, &this->actor, &D_808708CC);
        CollisionCheck_SetInfo(&this->actor.colChkInfo, &D_80870900, &D_808708F8);
        if ((this->unk190 == 0xFF) || (this->unk190 == 0)) {
            this->unk190 = 1;
        }
        this->actor.floorHeight = BgCheck_EntityRaycastFloor5(&play->colCtx, &this->actor.floorPoly, &sp34,
                                                              &this->actor, &this->actor.world.pos);
        if ((!WaterBox_GetSurface1_2(play, &play->colCtx, this->actor.world.pos.x, this->actor.world.pos.z, &sp38,
                                     &sp3C)) ||
            (sp38 <= this->actor.floorHeight)) {
            Actor_Kill(&this->actor);
        } else {
            this->actor.home.pos.y = sp38;
        }
        if (this->actor.params == 1) {
            this->collider.base.colType = 0xC;
            this->collider.base.acFlags |= 4;
        }
        this->actor.targetMode = 5;
        func_8086E4FC(this);
    } else {
        ActorShape_Init(&this->actor.shape, 1100.0f, ActorShadow_DrawCircle, 18.0f);
        this->actor.flags &= ~1;
        this->actor.flags |= 0x10;
        Collider_InitAndSetCylinder(play, &this->collider, &this->actor, &D_808708A0);
        func_800BC154(play, &play->actorCtx, &this->actor, 6);
        this->unk18E = 0x16;
        this->actor.shape.rot.y = 0;
        this->actor.world.rot.x = -this->actor.shape.rot.x;
        this->actor.shape.rot.x = 0;
        this->actionFunc = func_8086F694;
        this->actor.update = func_808700C0;
        this->actor.speed = 10.0f;
    }
}
/* Warning: struct EnTorch2 is not defined (only forward-declared) */

// #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/EnOkuta_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/EnOkuta_Destroy.s")

void func_8086E084(EnOkuta* this) {
    this->unk18C = 0xA;
    this->unk258 = 0.6f;
    this->unk25C = 0.90000004f;
    this->unk18E = 0x50;
    this->collider.base.colType = 3;
    this->unk254 = 1.0f;
    Actor_SetColorFilter(&this->actor, COLORFILTER_COLORFLAG_RED, 255, COLORFILTER_BUFFLAG_OPA, 80);
}

void func_8086E0F0(EnOkuta* this, PlayState* arg1) {
    if (this->unk18C == 10) {
        this->unk18C = 0;
        this->unk254 = 0.0f;
        Actor_SpawnIceEffects(arg1, &this->actor, this->bodyPartsPos, 0xA, 2, 0.3f, 0.2f);
        this->collider.base.colType = 0;
    }
}

void func_8086E168(EnOkuta* this, PlayState* play) {
    s32 i;

    for (i = 0; i < 10; i++) {
        EffectSsBubble_Spawn(play, &this->actor.world.pos, -10.0f, 10.0f, 30.0f, 0.25f);
    }
}

// static Color_RGBA8 D_80870928 = {255, 255, 255, 255};
// static Color_RGBA8 D_8087092C = {150, 150, 150, 255};

extern Color_RGBA8 D_80870928;
extern Color_RGBA8 D_8087092C;

void func_8086E214(Vec3f* pos, Vec3f* velocity, s16 scaleStep, PlayState* play) {
    func_800B0DE0(play, pos, velocity, &gZeroVec3f, &D_80870928, &D_8087092C, 400, scaleStep);
}

void func_8086E27C(EnOkuta* this, PlayState* play) {
    EffectSsGSplash_Spawn(play, &this->actor.home.pos, NULL, NULL, 0, 1300);
}

void func_8086E2C0(EnOkuta* this, PlayState* play) {
    f32 temp_fv0;
    Vec3f sp28;

    temp_fv0 = this->actor.world.pos.y - this->actor.home.pos.y;
    if (((play->gameplayFrames % 7) == 0) && (temp_fv0 < 50.0f) && (temp_fv0 >= -20.0f)) {
        sp28.x = this->actor.world.pos.x;
        sp28.y = this->actor.home.pos.y;
        sp28.z = this->actor.world.pos.z;
        EffectSsGRipple_Spawn(play, &sp28, 250, 650, 0);
    }
}

f32 func_8086E378(EnOkuta* this) {
    f32 temp_fa0;
    f32 temp_fv1;

    temp_fv1 = this->actor.world.pos.y + this->actor.playerHeightRel + 60.0f;
    temp_fa0 = this->actor.home.pos.y;
    if (temp_fa0 < temp_fv1) {
        return temp_fa0;
    }
    return temp_fv1;
}

void func_8086E3B8(EnOkuta* this, PlayState* play) {
    Vec3f pos;
    Vec3f velocity;
    f32 sp3C;
    f32 sp38;

    sp3C = Math_SinS(this->actor.shape.rot.y);
    sp38 = Math_CosS(this->actor.shape.rot.y);
    pos.x = this->actor.world.pos.x + (25.0f * sp3C);
    pos.y = this->actor.world.pos.y - 6.0f;
    pos.z = this->actor.world.pos.z + (25.0f * sp38);
    if (Actor_Spawn(&play->actorCtx, play, 8, pos.x, pos.y, pos.z, this->actor.shape.rot.x, this->actor.shape.rot.y,
                    this->actor.shape.rot.z, this->actor.params + 0x10) != NULL) {
        pos.x = this->actor.world.pos.x + (40.0f * sp3C);
        pos.z = this->actor.world.pos.z + (40.0f * sp38);
        pos.y = this->actor.world.pos.y;
        velocity.x = 1.5f * sp3C;
        velocity.y = 0.0f;
        velocity.z = 1.5f * sp38;
        func_8086E214(&pos, &velocity, 0x14, play);
    }
    Actor_PlaySfx(&this->actor, 0x387E);
}

void func_8086E4FC(EnOkuta* this) {
    this->actor.draw = NULL;
    this->actor.flags &= ~1;
    this->actionFunc = func_8086E52C;
    this->actor.world.pos.y = this->actor.home.pos.y;
}

void func_8086E52C(EnOkuta* this, PlayState* play) {
    s32 angle;

    this->actor.world.pos.y = this->actor.home.pos.y;

    if ((this->actor.xzDistToPlayer < 480.0f) && (this->actor.xzDistToPlayer > 200.0f)) {
        if (this->actor.params == 0) {
            func_8086E5E8(this, play);
            return;
        }
        angle = ABS_ALT((s16) (this->actor.yawTowardsPlayer - this->actor.world.rot.y));

        if ((angle < 0x4000) && (play->bButtonAmmoPlusOne == 0)) {
            func_8086E5E8(this, play);
        }
    }
}

void func_8086E5E8(EnOkuta* this, PlayState* play) {
    this->actor.draw = EnOkuta_Draw;
    this->actor.shape.rot.y = this->actor.yawTowardsPlayer;
    this->actor.flags |= 1;
    Animation_PlayOnce(&this->skelAnime, &D_0600466C);
    func_8086E168(this, play);
    this->actionFunc = func_8086E658;
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_8086E658.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_8086E7A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_8086E7E8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_8086E8E8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_8086E948.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_8086EAE0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_8086EC00.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_8086EE8C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_8086EF14.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_8086EF90.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_8086EFE8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_8086F2FC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_8086F434.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_8086F4B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_8086F4F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_8086F57C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_8086F694.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_8086F8FC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_8086FCA4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/EnOkuta_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_808700C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_80870254.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_808704DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/func_808705C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Okuta/EnOkuta_Draw.s")
