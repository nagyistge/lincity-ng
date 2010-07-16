/* ---------------------------------------------------------------------- *
 * lintypes.h
 * This file is part of lincity.
 * Lincity is copyright (c) I J Peters 1995-1997, (c) Greg Sharp 1997-2001.
 * ---------------------------------------------------------------------- */
#ifndef __lintypes_h__
#define __lintypes_h__

#define WORLD_SIDE_LEN 100      /* Minimap size is hardcoded 200 pixel => some job to do ... */

#define OLD_MAX_NUMOF_SUBSTATIONS 100
#define MAX_NUMOF_SUBSTATIONS 512

#define NUMOF_COAL_RESERVES 100
#define NUM_OF_TYPES    404
#define NUM_OF_GROUPS    50

#define OLD_MAX_NUMOF_MARKETS 100
#define MAX_NUMOF_MARKETS 512

#define NUMOF_DAYS_IN_MONTH 100
#define NUMOF_DAYS_IN_YEAR (NUMOF_DAYS_IN_MONTH*12)

#define NUMOF_DISCOUNT_TRIGGERS 6

int get_group_of_type(short selected_type);
void set_map_groups(void);
int get_type_cost(short type);
int get_group_cost(short group);
void get_type_name(short type, char *s);

/********** Data structures ***************/

struct GROUP {
    const char *name;           /* name of group */
    unsigned short no_credit;   /* TRUE if need credit to build */
    unsigned short group;       /* This is redundant: it must match
                                   the index into the table */
    unsigned short size;
    int colour;                 /* summary map colour */
    int cost_mul;               /* group cost multiplier */
    int bul_cost;               /* group bulldoze cost */
    int fire_chance;            /* probability of fire */
    int cost;                   /* group cost */
    int tech;                   /* group cost */
};

struct TYPE {
    int group;                  /* What group does this type belong to? */
    char *graphic;              /* Bitmap of the graphic */
};

struct map_point_info_struct {
    int population;
    int flags;
    unsigned short coal_reserve;
    unsigned short ore_reserve;
    int int_1;
    int int_2;
    int int_3;
    int int_4;
    int int_5;
    int int_6;
    int int_7;
};

/* GCS -- One of these days I will get this right. */
struct map_struct {
    short type[WORLD_SIDE_LEN][WORLD_SIDE_LEN];
    short group[WORLD_SIDE_LEN][WORLD_SIDE_LEN];
    int pollution[WORLD_SIDE_LEN][WORLD_SIDE_LEN];
    map_point_info_struct info[WORLD_SIDE_LEN][WORLD_SIDE_LEN];
    int date[WORLD_SIDE_LEN][WORLD_SIDE_LEN];
    int tech[WORLD_SIDE_LEN][WORLD_SIDE_LEN];
    int anim[WORLD_SIDE_LEN][WORLD_SIDE_LEN];
    int im_index[WORLD_SIDE_LEN][WORLD_SIDE_LEN];
    int activity[WORLD_SIDE_LEN][WORLD_SIDE_LEN];
};

#define MP_TYPE(x,y)   map.type[x][y]
#define MP_GROUP(x,y)  map.group[x][y]
#define MP_POL(x,y)    map.pollution[x][y]
#define MP_INFO(x,y)   map.info[x][y]
#define MP_DATE(x,y)   map.date[x][y] // date of built
#define MP_TECH(x,y)   map.tech[x][y] // Tech at build time
#define MP_ANIM(x,y)   map.anim[x][y] // real_time for next anim    //does not need to be saved

#define MP_SIZE(x,y)   main_groups[MP_GROUP(x,y)].size
#define MP_COLOR(x,y)  main_groups[MP_GROUP(x,y)].colour
#define MP_GROUP_IS_RESIDENCE(x,y)  (GROUP_IS_RESIDENCE(MP_GROUP(x,y)))
#define HAS_UGWATER(x,y) (MP_INFO(x,y).flags & FLAG_HAS_UNDERGROUND_WATER)

struct ground_struct {
    int altitude;       //surface of ground. unused currently
    int ecotable;       //done at init time: pointer to the table for vegetation
    int wastes;         //wastes underground
    int pollution;      //pollution underground
    int water_alt;      //altitude of water (needed to know drainage basin)
    int water_pol;      //pollution of water
    int water_wast;     //wastes in water
    int water_next;     //next tile(s) where the water will go from here
    int int1;           //reserved for future (?) use
    int int2;
    int int3;
    int int4;           //used as tmp in setup_ground  //FIXME : this is too ugly
};
#define ALT(x,y) ground[x][y].altitude


#endif /* __lintypes_h__ */

/** @file lincity/lintypes.h */

