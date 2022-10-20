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

#ifndef __M_CONTROLS_H__
#define __M_CONTROLS_H__
 
extern short key_right;
extern short key_left;

extern short key_up;
extern short key_down;
extern short key_strafeleft;
extern short key_straferight;
extern short key_fire;
extern short key_use;
extern short key_strafe;
extern short key_speed;

extern short key_jump;
 
extern short key_flyup;
extern short key_flydown;
extern short key_flycenter;
extern short key_lookup;
extern short key_lookdown;
extern short key_lookcenter;
extern short key_invleft;
extern short key_invright;
extern short key_useartifact;

// villsa [STRIFE] strife keys
extern short key_usehealth;
extern short key_invquery;
extern short key_mission;
extern short key_invpop;
extern short key_invkey;
extern short key_invhome;
extern short key_invend;
extern short key_invuse;
extern short key_invdrop;

extern short key_message_refresh;
extern short key_pause;

extern short key_multi_msg;
extern short key_multi_msgplayer[8];

extern short key_weapon1;
extern short key_weapon2;
extern short key_weapon3;
extern short key_weapon4;
extern short key_weapon5;
extern short key_weapon6;
extern short key_weapon7;
extern short key_weapon8;

extern short key_arti_all;
extern short key_arti_health;
extern short key_arti_poisonbag;
extern short key_arti_blastradius;
extern short key_arti_teleport;
extern short key_arti_teleportother;
extern short key_arti_egg;
extern short key_arti_invulnerability;

extern short key_demo_quit;
extern short key_spy;
extern short key_prevweapon;
extern short key_nextweapon;

extern short key_map_north;
extern short key_map_south;
extern short key_map_east;
extern short key_map_west;
extern short key_map_zoomin;
extern short key_map_zoomout;
extern short key_map_toggle;
extern short key_map_maxzoom;
extern short key_map_follow;
extern short key_map_grid;
extern short key_map_mark;
extern short key_map_clearmark;

// menu keys:

extern short key_menu_activate;
extern short key_menu_up;
extern short key_menu_down;
extern short key_menu_left;
extern short key_menu_right;
extern short key_menu_back;
extern short key_menu_forward;
extern short key_menu_confirm;
extern short key_menu_abort;

extern short key_menu_help;
extern short key_menu_save;
extern short key_menu_load;
extern short key_menu_volume;
extern short key_menu_detail;
extern short key_menu_qsave;
extern short key_menu_endgame;
extern short key_menu_messages;
extern short key_menu_qload;
extern short key_menu_quit;
extern short key_menu_gamma;

extern short key_menu_incscreen;
extern short key_menu_decscreen;
extern short key_menu_screenshot;

extern short mousebfire;
extern short mousebstrafe;
extern short mousebforward;

extern short mousebjump;

extern short mousebstrafeleft;
extern short mousebstraferight;
extern short mousebbackward;
extern short mousebuse;

extern short mousebprevweapon;
extern short mousebnextweapon;

extern short joybfire;
extern short joybstrafe;
extern short joybuse;
extern short joybspeed;

extern short joybjump;

extern short joybstrafeleft;
extern short joybstraferight;

extern short joybprevweapon;
extern short joybnextweapon;

extern short joybmenu;

extern short dclick_use;

void M_BindBaseControls(void);
void M_BindHereticControls(void);
void M_BindHexenControls(void);
void M_BindStrifeControls(void);
void M_BindWeaponControls(void);
void M_BindMapControls(void);
void M_BindMenuControls(void);
void M_BindChatControls(unsigned int num_players);

void M_ApplyPlatformDefaults(void);

#endif /* #ifndef __M_CONTROLS_H__ */

