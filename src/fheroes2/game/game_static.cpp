/***************************************************************************
 *   Copyright (C) 2011 by Andrey Afletdinov <fheroes2@gmail.com>          *
 *                                                                         *
 *   Part of the Free Heroes2 Engine:                                      *
 *   http://sourceforge.net/projects/fheroes2                              *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <array>

#include "game.h"
#include "game_static.h"
#include "mp2.h"
#include "race.h"
#include "resource.h"
#include "save_format_version.h"
#include "serialize.h"
#include "skill.h"
#include "skill_static.h"

namespace Skill
{
    stats_t _stats[] = { { "knight",
                           { 1, 1, 1, 1 },
                           { 2, 2, 1, 1 },
                           0,
                           0,
                           { 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
                           10,
                           { 35, 45, 10, 10 },
                           { 25, 25, 25, 25 },
                           { 2, 4, 3, 1, 3, 5, 3, 1, 1, 2, 0, 3, 2, 2 } },
                         { "barbarian",
                           { 1, 1, 1, 1 },
                           { 3, 1, 1, 1 },
                           0,
                           0,
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0 },
                           10,
                           { 55, 35, 5, 5 },
                           { 30, 30, 20, 20 },
                           { 3, 3, 2, 1, 2, 3, 3, 2, 1, 3, 0, 4, 4, 1 } },
                         { "sorceress",
                           { 0, 0, 2, 2 },
                           { 0, 0, 2, 3 },
                           1,
                           15,
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1 },
                           10,
                           { 10, 10, 30, 50 },
                           { 20, 20, 30, 30 },
                           { 3, 3, 2, 2, 2, 1, 2, 3, 3, 4, 0, 2, 1, 4 } },
                         { "warlock",
                           { 0, 0, 2, 2 },
                           { 0, 0, 3, 2 },
                           1,
                           19,
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1 },
                           10,
                           { 10, 10, 50, 30 },
                           { 20, 20, 30, 30 },
                           { 1, 3, 2, 3, 2, 1, 2, 1, 3, 2, 1, 2, 4, 5 } },
                         { "wizard",
                           { 0, 0, 2, 2 },
                           { 0, 1, 2, 2 },
                           1,
                           17,
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
                           10,
                           { 10, 10, 40, 40 },
                           { 20, 20, 30, 30 },
                           { 1, 3, 2, 3, 2, 2, 2, 2, 4, 2, 0, 2, 2, 5 } },
                         { "necromancer",
                           { 0, 0, 2, 2 },
                           { 1, 0, 2, 2 },
                           1,
                           10,
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1 },
                           10,
                           { 15, 15, 35, 35 },
                           { 25, 25, 25, 25 },
                           { 1, 3, 2, 3, 2, 0, 2, 1, 3, 2, 5, 3, 1, 4 } },
                         { nullptr,
                           { 0, 0, 0, 0 },
                           { 0, 0, 0, 0 },
                           0,
                           0,
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                           10,
                           { 0, 0, 0, 0 },
                           { 0, 0, 0, 0 },
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } } };

    values_t _values[] = {
        { "pathfinding", { 25, 50, 100 } }, { "archery", { 10, 25, 50 } },     { "logistics", { 10, 20, 30 } }, { "scouting", { 1, 2, 3 } },
        { "diplomacy", { 25, 50, 100 } },   { "navigation", { 33, 66, 100 } }, { "leadership", { 1, 2, 3 } },   { "wisdom", { 3, 4, 5 } },
        { "mysticism", { 2, 3, 4 } },       { "luck", { 1, 2, 3 } },           { "ballistics", { 0, 0, 0 } },   { "eagleeye", { 20, 30, 40 } },
        { "necromancy", { 10, 20, 30 } },   { "estates", { 100, 250, 500 } },  { nullptr, { 0, 0, 0 } },
    };

    secondary_t _from_witchs_hut = {
        /* archery */ 1,   /* ballistics */ 1, /* diplomacy */ 1, /* eagleeye */ 1,
        /* estates */ 1,   /* leadership */ 0, /* logistics */ 1, /* luck */ 1,
        /* mysticism */ 1, /* navigation */ 1, /* necromancy*/ 0, /* pathfinding */ 1,
        /* scouting */ 1,  /* wisdom */ 1};

    StreamBase & operator<<( StreamBase & msg, const level_t & obj )
    {
        return msg << obj.basic << obj.advanced << obj.expert;
    }

    StreamBase & operator>>( StreamBase & msg, level_t & obj )
    {
        return msg >> obj.basic >> obj.advanced >> obj.expert;
    }

    StreamBase & operator<<( StreamBase & msg, const primary_t & obj )
    {
        return msg << obj.attack << obj.defense << obj.power << obj.knowledge;
    }

    StreamBase & operator>>( StreamBase & msg, primary_t & obj )
    {
        return msg >> obj.attack >> obj.defense >> obj.power >> obj.knowledge;
    }

    StreamBase & operator<<( StreamBase & msg, const secondary_t & obj )
    {
        return msg << obj.archery << obj.ballistics << obj.diplomacy << obj.eagleeye << obj.estates << obj.leadership << obj.logistics << obj.luck << obj.mysticism
                   << obj.navigation << obj.necromancy << obj.pathfinding << obj.scouting << obj.wisdom;
    }

    StreamBase & operator>>( StreamBase & msg, secondary_t & obj )
    {
        return msg >> obj.archery >> obj.ballistics >> obj.diplomacy >> obj.eagleeye >> obj.estates >> obj.leadership >> obj.logistics >> obj.luck >> obj.mysticism
               >> obj.navigation >> obj.necromancy >> obj.pathfinding >> obj.scouting >> obj.wisdom;
    }

    StreamBase & operator<<( StreamBase & msg, const stats_t & obj )
    {
        return msg << obj.captain_primary << obj.initial_primary << obj.initial_book << obj.initial_spell << obj.initial_secondary << obj.over_level
                   << obj.mature_primary_under << obj.mature_primary_over << obj.mature_secondary;
    }

    StreamBase & operator>>( StreamBase & msg, stats_t & obj )
    {
        return msg >> obj.captain_primary >> obj.initial_primary >> obj.initial_book >> obj.initial_spell >> obj.initial_secondary >> obj.over_level
               >> obj.mature_primary_under >> obj.mature_primary_over >> obj.mature_secondary;
    }

    StreamBase & operator<<( StreamBase & msg, const values_t & obj )
    {
        return msg << obj.values;
    }

    StreamBase & operator>>( StreamBase & msg, values_t & obj )
    {
        return msg >> obj.values;
    }
}

namespace GameStatic
{
    u8 whirlpool_lost_percent = 50;

    /* town, castle, heroes, artifact_telescope, object_observation_tower, object_magi_eyes */
    std::array<uint8_t, 6> overview_distance = { 4, 5, 4, 1, 20, 9 };

    u8 gameover_lost_days = 7;

    // kingdom
    u8 kingdom_max_heroes = 8;
    cost_t kingdom_starting_resource[] = {{10000, 30, 10, 30, 10, 10, 10},
                                          {7500, 20, 5, 20, 5, 5, 5},
                                          {5000, 10, 2, 10, 2, 2, 2},
                                          {2500, 5, 0, 5, 0, 0, 0},
                                          {0, 0, 0, 0, 0, 0, 0},
                                          // ai resource
                                          {10000, 30, 10, 30, 10, 10, 10}};

    // castle
    u8 castle_grown_well = 2;
    u8 castle_grown_wel2 = 8;
    u8 castle_grown_week_of = 5;
    u8 castle_grown_month_of = 100;

    u8 mageguild_restore_spell_points_day[] = {20, 40, 60, 80, 100};

    // heroes
    u8 heroes_spell_points_day = 1;

    // spells
    u16 spell_dd_distance = 0;
    u16 spell_dd_sp = 0;
    u16 spell_dd_hp = 0;

    // monsters
    float monsterUpgradeRatio = 1.0f;

    // visit objects mod: OBJ_BUOY, OBJ_OASIS, OBJ_WATERINGHOLE, OBJ_TEMPLE, OBJ_GRAVEYARD, OBJ_DERELICTSHIP,
    // OBJ_SHIPWRECK, OBJ_MERMAID, OBJ_FAERIERING, OBJ_FOUNTAIN, OBJ_IDOL, OBJ_PYRAMID
    int8_t objects_mod[] = {1, 1, 1, 2, -1, -1, -1, 1, 1, 1, 1, -2};

    // world
    u32 uniq = 0;
}

StreamBase & GameStatic::operator<<( StreamBase & msg, const Data & /*obj*/ )
{
    static_assert( LAST_SUPPORTED_FORMAT_VERSION < FORMAT_VERSION_SECOND_PRE_095_RELEASE, "Remove this method and its calls." );
    return msg;
}

StreamBase & GameStatic::operator>>( StreamBase & msg, const Data & /*obj*/ )
{
    static_assert( LAST_SUPPORTED_FORMAT_VERSION < FORMAT_VERSION_SECOND_PRE_095_RELEASE, "Remove this method and its calls." );
    if ( Game::GetLoadVersion() >= FORMAT_VERSION_SECOND_PRE_095_RELEASE ) {
        return msg;
    }

    msg >> whirlpool_lost_percent >> kingdom_max_heroes >> castle_grown_well >> castle_grown_wel2 >> castle_grown_week_of >> castle_grown_month_of
        >> heroes_spell_points_day >> gameover_lost_days >> spell_dd_distance >> spell_dd_sp >> spell_dd_hp;

    u8 array_size = 0;

    msg >> array_size;
    for ( u32 ii = 0; ii < array_size; ++ii )
        msg >> overview_distance[ii];

    msg >> array_size;
    for ( u32 ii = 0; ii < array_size; ++ii )
        msg >> kingdom_starting_resource[ii];

    msg >> array_size;
    for ( u32 ii = 0; ii < array_size; ++ii )
        msg >> mageguild_restore_spell_points_day[ii];

    msg >> array_size;
    for ( u32 ii = 0; ii < array_size; ++ii )
        msg >> objects_mod[ii];

    msg >> monsterUpgradeRatio >> uniq;
    if ( monsterUpgradeRatio < 0 ) {
        monsterUpgradeRatio = 1.0f;
    }

    msg >> array_size;
    for ( u32 ii = 0; ii < array_size; ++ii )
        msg >> Skill::_stats[ii];

    msg >> array_size;
    for ( u32 ii = 0; ii < array_size; ++ii )
        msg >> Skill::_values[ii];

    msg >> Skill::_from_witchs_hut;

    return msg;
}

u32 GameStatic::GetLostOnWhirlpoolPercent( void )
{
    return whirlpool_lost_percent;
}

u32 GameStatic::GetOverViewDistance( u32 d )
{
    return d >= overview_distance.size() ? 0 : overview_distance[d];
}

u32 GameStatic::GetGameOverLostDays( void )
{
    return gameover_lost_days;
}

u32 GameStatic::GetHeroesRestoreSpellPointsPerDay( void )
{
    return heroes_spell_points_day;
}

u32 GameStatic::GetMageGuildRestoreSpellPointsPercentDay( int level )
{
    return level && level < 6 ? mageguild_restore_spell_points_day[level - 1] : 0;
}

u32 GameStatic::GetKingdomMaxHeroes( void )
{
    return kingdom_max_heroes;
}

u32 GameStatic::GetCastleGrownWell( void )
{
    return castle_grown_well;
}

u32 GameStatic::GetCastleGrownWel2( void )
{
    return castle_grown_wel2;
}

u32 GameStatic::GetCastleGrownWeekOf( void )
{
    return castle_grown_week_of;
}

u32 GameStatic::GetCastleGrownMonthOf( void )
{
    return castle_grown_month_of;
}

s32 GameStatic::ObjectVisitedModifiers( const MP2::MapObjectType objectType )
{
    switch ( objectType ) {
    case MP2::OBJ_BUOY:
        return objects_mod[0];
    case MP2::OBJ_OASIS:
        return objects_mod[1];
    case MP2::OBJ_WATERINGHOLE:
        return objects_mod[2];
    case MP2::OBJ_TEMPLE:
        return objects_mod[3];
    case MP2::OBJ_GRAVEYARD:
        return objects_mod[4];
    case MP2::OBJ_DERELICTSHIP:
        return objects_mod[5];
    case MP2::OBJ_SHIPWRECK:
        return objects_mod[6];
    case MP2::OBJ_MERMAID:
        return objects_mod[7];
    case MP2::OBJ_FAERIERING:
        return objects_mod[8];
    case MP2::OBJ_FOUNTAIN:
        return objects_mod[9];
    case MP2::OBJ_IDOL:
        return objects_mod[10];
    case MP2::OBJ_PYRAMID:
        return objects_mod[11];
    default:
        break;
    }

    return 0;
}

const Skill::stats_t * GameStatic::GetSkillStats( int race )
{
    switch ( race ) {
    case Race::KNGT:
        return &Skill::_stats[0];
    case Race::BARB:
        return &Skill::_stats[1];
    case Race::SORC:
        return &Skill::_stats[2];
    case Race::WRLK:
        return &Skill::_stats[3];
    case Race::WZRD:
        return &Skill::_stats[4];
    case Race::NECR:
        return &Skill::_stats[5];
    default:
        break;
    }

    return nullptr;
}

const Skill::values_t * GameStatic::GetSkillValues( int type )
{
    switch ( type ) {
    case Skill::Secondary::PATHFINDING:
        return &Skill::_values[0];
    case Skill::Secondary::ARCHERY:
        return &Skill::_values[1];
    case Skill::Secondary::LOGISTICS:
        return &Skill::_values[2];
    case Skill::Secondary::SCOUTING:
        return &Skill::_values[3];
    case Skill::Secondary::DIPLOMACY:
        return &Skill::_values[4];
    case Skill::Secondary::NAVIGATION:
        return &Skill::_values[5];
    case Skill::Secondary::LEADERSHIP:
        return &Skill::_values[6];
    case Skill::Secondary::WISDOM:
        return &Skill::_values[7];
    case Skill::Secondary::MYSTICISM:
        return &Skill::_values[8];
    case Skill::Secondary::LUCK:
        return &Skill::_values[9];
    case Skill::Secondary::BALLISTICS:
        return &Skill::_values[10];
    case Skill::Secondary::EAGLEEYE:
        return &Skill::_values[11];
    case Skill::Secondary::NECROMANCY:
        return &Skill::_values[12];
    case Skill::Secondary::ESTATES:
        return &Skill::_values[13];
    default:
        break;
    }

    return nullptr;
}

const Skill::secondary_t * GameStatic::GetSkillForWitchsHut( void )
{
    return &Skill::_from_witchs_hut;
}

GameStatic::Data & GameStatic::Data::Get( void )
{
    static Data gds;
    return gds;
}

int GameStatic::GetBattleMoatReduceDefense( void )
{
    return 3;
}
