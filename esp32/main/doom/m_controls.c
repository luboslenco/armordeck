//
// Copyright(C) 1993-1996 Id Software, Inc.
// Copyright(C) 1993-2008 Raven Software
// Copyright(C) 2005-2014 Simon Howard
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//

#include <stdio.h>

#include "doomtype.h"
#include "doomkeys.h"

#include "m_config.h"
#include "m_misc.h"

//
// Keyboard controls
//

short key_right = KEY_RIGHTARROW;
short key_left = KEY_LEFTARROW;
short key_up = KEY_UPARROW;
short key_down = KEY_DOWNARROW;
short key_strafeleft = KEY_STRAFE_L;
short key_straferight = KEY_STRAFE_R;
short key_fire = KEY_FIRE;
short key_use = KEY_USE;
short key_strafe = KEY_RALT;
short key_speed = KEY_RSHIFT;

//
// Heretic keyboard controls
//

short key_flyup = KEY_PGUP;
short key_flydown = KEY_INS;
short key_flycenter = KEY_HOME;

short key_lookup = KEY_PGDN;
short key_lookdown = KEY_DEL;
short key_lookcenter = KEY_END;

short key_invleft = '[';
short key_invright = ']';
short key_useartifact = KEY_ENTER;

//
// Hexen key controls
//

short key_jump = '/';

short key_arti_all             = KEY_BACKSPACE;
short key_arti_health          = '\\';
short key_arti_poisonbag       = '0';
short key_arti_blastradius     = '9';
short key_arti_teleport        = '8';
short key_arti_teleportother   = '7';
short key_arti_egg             = '6';
short key_arti_invulnerability = '5';

//
// Strife key controls
//
// haleyjd 09/01/10
//

// Note: Strife also uses key_invleft, key_invright, key_jump, key_lookup, and
// key_lookdown, but with different default values.

short key_usehealth = 'h';
short key_invquery  = 'q';
short key_mission   = 'w';
short key_invpop    = 'z';
short key_invkey    = 'k';
short key_invhome   = KEY_HOME;
short key_invend    = KEY_END;
short key_invuse    = KEY_ENTER;
short key_invdrop   = KEY_BACKSPACE;


//
// Mouse controls
//

short mousebfire = 0;
short mousebstrafe = 1;
short mousebforward = 2;

short mousebjump = -1;

short mousebstrafeleft = -1;
short mousebstraferight = -1;
short mousebbackward = -1;
short mousebuse = -1;

short mousebprevweapon = -1;
short mousebnextweapon = -1;


short key_message_refresh = KEY_ENTER;
short key_pause = KEY_PAUSE;
short key_demo_quit = 'q';
short key_spy = KEY_F12;

// Multiplayer chat keys:

short key_multi_msg = 't';
short key_multi_msgplayer[8];

// Weapon selection keys:

short key_weapon1 = '1';
short key_weapon2 = '2';
short key_weapon3 = '3';
short key_weapon4 = '4';
short key_weapon5 = '5';
short key_weapon6 = '6';
short key_weapon7 = '7';
short key_weapon8 = '8';
short key_prevweapon = 0;
short key_nextweapon = 0;

// Map control keys:

short key_map_north     = KEY_UPARROW;
short key_map_south     = KEY_DOWNARROW;
short key_map_east      = KEY_RIGHTARROW;
short key_map_west      = KEY_LEFTARROW;
short key_map_zoomin    = '=';
short key_map_zoomout   = '-';
short key_map_toggle    = KEY_TAB;
short key_map_maxzoom   = '0';
short key_map_follow    = 'f';
short key_map_grid      = 'g';
short key_map_mark      = 'm';
short key_map_clearmark = 'c';

// menu keys:

short key_menu_activate  = KEY_ESCAPE;
short key_menu_up        = KEY_UPARROW;
short key_menu_down      = KEY_DOWNARROW;
short key_menu_left      = KEY_LEFTARROW;
short key_menu_right     = KEY_RIGHTARROW;
short key_menu_back      = KEY_BACKSPACE;
short key_menu_forward   = KEY_ENTER;
short key_menu_confirm   = 'y';
short key_menu_abort     = 'n';

short key_menu_help      = KEY_F1;
short key_menu_save      = KEY_F2;
short key_menu_load      = KEY_F3;
short key_menu_volume    = KEY_F4;
short key_menu_detail    = KEY_F5;
short key_menu_qsave     = KEY_F6;
short key_menu_endgame   = KEY_F7;
short key_menu_messages  = KEY_F8;
short key_menu_qload     = KEY_F9;
short key_menu_quit      = KEY_F10;
short key_menu_gamma     = KEY_F11;

short key_menu_incscreen = KEY_EQUALS;
short key_menu_decscreen = KEY_MINUS;
short key_menu_screenshot = 0;

//
// Joystick controls
//

short joybfire = 0;
short joybstrafe = 1;
short joybuse = 3;
short joybspeed = 2;

short joybstrafeleft = -1;
short joybstraferight = -1;

short joybjump = -1;

short joybprevweapon = -1;
short joybnextweapon = -1;

short joybmenu = -1;

// Control whether if a mouse button is double clicked, it acts like
// "use" has been pressed

short dclick_use = 1;

//
// Bind all of the common controls used by Doom and all other games.
//

void M_BindBaseControls(void)
{
    // M_BindVariable("key_right",          &key_right);
    // M_BindVariable("key_left",           &key_left);
    // M_BindVariable("key_up",             &key_up);
    // M_BindVariable("key_down",           &key_down);
    // M_BindVariable("key_strafeleft",     &key_strafeleft);
    // M_BindVariable("key_straferight",    &key_straferight);
    // M_BindVariable("key_fire",           &key_fire);
    // M_BindVariable("key_use",            &key_use);
    // M_BindVariable("key_strafe",         &key_strafe);
    // M_BindVariable("key_speed",          &key_speed);

    // M_BindVariable("mouseb_fire",        &mousebfire);
    // M_BindVariable("mouseb_strafe",      &mousebstrafe);
    // M_BindVariable("mouseb_forward",     &mousebforward);

    // M_BindVariable("joyb_fire",          &joybfire);
    // M_BindVariable("joyb_strafe",        &joybstrafe);
    // M_BindVariable("joyb_use",           &joybuse);
    // M_BindVariable("joyb_speed",         &joybspeed);

    // M_BindVariable("joyb_menu_activate", &joybmenu);

    // // Extra controls that are not in the Vanilla versions:

    // M_BindVariable("joyb_strafeleft",    &joybstrafeleft);
    // M_BindVariable("joyb_straferight",   &joybstraferight);
    // M_BindVariable("mouseb_strafeleft",  &mousebstrafeleft);
    // M_BindVariable("mouseb_straferight", &mousebstraferight);
    // M_BindVariable("mouseb_use",         &mousebuse);
    // M_BindVariable("mouseb_backward",    &mousebbackward);
    // M_BindVariable("dclick_use",         &dclick_use);
    // M_BindVariable("key_pause",          &key_pause);
    // M_BindVariable("key_message_refresh", &key_message_refresh);
}

void M_BindHereticControls(void)
{
    // M_BindVariable("key_flyup",          &key_flyup);
    // M_BindVariable("key_flydown",        &key_flydown);
    // M_BindVariable("key_flycenter",      &key_flycenter);

    // M_BindVariable("key_lookup",         &key_lookup);
    // M_BindVariable("key_lookdown",       &key_lookdown);
    // M_BindVariable("key_lookcenter",     &key_lookcenter);

    // M_BindVariable("key_invleft",        &key_invleft);
    // M_BindVariable("key_invright",       &key_invright);
    // M_BindVariable("key_useartifact",    &key_useartifact);
}

void M_BindHexenControls(void)
{
    // M_BindVariable("key_jump",           &key_jump);
    // M_BindVariable("mouseb_jump",        &mousebjump);
    // M_BindVariable("joyb_jump",          &joybjump);

    // M_BindVariable("key_arti_all",             &key_arti_all);
    // M_BindVariable("key_arti_health",          &key_arti_health);
    // M_BindVariable("key_arti_poisonbag",       &key_arti_poisonbag);
    // M_BindVariable("key_arti_blastradius",     &key_arti_blastradius);
    // M_BindVariable("key_arti_teleport",        &key_arti_teleport);
    // M_BindVariable("key_arti_teleportother",   &key_arti_teleportother);
    // M_BindVariable("key_arti_egg",             &key_arti_egg);
    // M_BindVariable("key_arti_invulnerability", &key_arti_invulnerability);
}

void M_BindStrifeControls(void)
{
    // // These are shared with all games, but have different defaults:
    // key_message_refresh = '/';

    // // These keys are shared with Heretic/Hexen but have different defaults:
    // key_jump     = 'a';
    // key_lookup   = KEY_PGUP;
    // key_lookdown = KEY_PGDN;
    // key_invleft  = KEY_INS;
    // key_invright = KEY_DEL;

    // M_BindVariable("key_jump",           &key_jump);
    // M_BindVariable("key_lookUp",         &key_lookup);
    // M_BindVariable("key_lookDown",       &key_lookdown);
    // M_BindVariable("key_invLeft",        &key_invleft);
    // M_BindVariable("key_invRight",       &key_invright);

    // // Custom Strife-only Keys:
    // M_BindVariable("key_useHealth",      &key_usehealth);
    // M_BindVariable("key_invquery",       &key_invquery);
    // M_BindVariable("key_mission",        &key_mission);
    // M_BindVariable("key_invPop",         &key_invpop);
    // M_BindVariable("key_invKey",         &key_invkey);
    // M_BindVariable("key_invHome",        &key_invhome);
    // M_BindVariable("key_invEnd",         &key_invend);
    // M_BindVariable("key_invUse",         &key_invuse);
    // M_BindVariable("key_invDrop",        &key_invdrop);

    // // Strife also supports jump on mouse and joystick, and in the exact same
    // // manner as Hexen!
    // M_BindVariable("mouseb_jump",        &mousebjump);
    // M_BindVariable("joyb_jump",          &joybjump);
}

void M_BindWeaponControls(void)
{
    // M_BindVariable("key_weapon1",        &key_weapon1);
    // M_BindVariable("key_weapon2",        &key_weapon2);
    // M_BindVariable("key_weapon3",        &key_weapon3);
    // M_BindVariable("key_weapon4",        &key_weapon4);
    // M_BindVariable("key_weapon5",        &key_weapon5);
    // M_BindVariable("key_weapon6",        &key_weapon6);
    // M_BindVariable("key_weapon7",        &key_weapon7);
    // M_BindVariable("key_weapon8",        &key_weapon8);

    // M_BindVariable("key_prevweapon",     &key_prevweapon);
    // M_BindVariable("key_nextweapon",     &key_nextweapon);

    // M_BindVariable("joyb_prevweapon",    &joybprevweapon);
    // M_BindVariable("joyb_nextweapon",    &joybnextweapon);

    // M_BindVariable("mouseb_prevweapon",  &mousebprevweapon);
    // M_BindVariable("mouseb_nextweapon",  &mousebnextweapon);
}

void M_BindMapControls(void)
{
    // M_BindVariable("key_map_north",      &key_map_north);
    // M_BindVariable("key_map_south",      &key_map_south);
    // M_BindVariable("key_map_east",       &key_map_east);
    // M_BindVariable("key_map_west",       &key_map_west);
    // M_BindVariable("key_map_zoomin",     &key_map_zoomin);
    // M_BindVariable("key_map_zoomout",    &key_map_zoomout);
    // M_BindVariable("key_map_toggle",     &key_map_toggle);
    // M_BindVariable("key_map_maxzoom",    &key_map_maxzoom);
    // M_BindVariable("key_map_follow",     &key_map_follow);
    // M_BindVariable("key_map_grid",       &key_map_grid);
    // M_BindVariable("key_map_mark",       &key_map_mark);
    // M_BindVariable("key_map_clearmark",  &key_map_clearmark);
}

void M_BindMenuControls(void)
{
    // M_BindVariable("key_menu_activate",  &key_menu_activate);
    // M_BindVariable("key_menu_up",        &key_menu_up);
    // M_BindVariable("key_menu_down",      &key_menu_down);
    // M_BindVariable("key_menu_left",      &key_menu_left);
    // M_BindVariable("key_menu_right",     &key_menu_right);
    // M_BindVariable("key_menu_back",      &key_menu_back);
    // M_BindVariable("key_menu_forward",   &key_menu_forward);
    // M_BindVariable("key_menu_confirm",   &key_menu_confirm);
    // M_BindVariable("key_menu_abort",     &key_menu_abort);

    // M_BindVariable("key_menu_help",      &key_menu_help);
    // M_BindVariable("key_menu_save",      &key_menu_save);
    // M_BindVariable("key_menu_load",      &key_menu_load);
    // M_BindVariable("key_menu_volume",    &key_menu_volume);
    // M_BindVariable("key_menu_detail",    &key_menu_detail);
    // M_BindVariable("key_menu_qsave",     &key_menu_qsave);
    // M_BindVariable("key_menu_endgame",   &key_menu_endgame);
    // M_BindVariable("key_menu_messages",  &key_menu_messages);
    // M_BindVariable("key_menu_qload",     &key_menu_qload);
    // M_BindVariable("key_menu_quit",      &key_menu_quit);
    // M_BindVariable("key_menu_gamma",     &key_menu_gamma);

    // M_BindVariable("key_menu_incscreen", &key_menu_incscreen);
    // M_BindVariable("key_menu_decscreen", &key_menu_decscreen);
    // M_BindVariable("key_menu_screenshot",&key_menu_screenshot);
    // M_BindVariable("key_demo_quit",      &key_demo_quit);
    // M_BindVariable("key_spy",            &key_spy);
}

void M_BindChatControls(unsigned int num_players)
{
    // char name[32];  // haleyjd: 20 not large enough - Thank you, come again!
    // unsigned int i; // haleyjd: signedness conflict

    // M_BindVariable("key_multi_msg",     &key_multi_msg);

    // for (i=0; i<num_players; ++i)
    // {
    //     M_snprintf(name, sizeof(name), "key_multi_msgplayer%i", i + 1);
    //     M_BindVariable(name, &key_multi_msgplayer[i]);
    // }
}

//
// Apply custom patches to the default values depending on the
// platform we are running on.
//

void M_ApplyPlatformDefaults(void)
{
    // no-op. Add your platform-specific patches here.
}

