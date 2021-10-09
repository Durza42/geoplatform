/*
 * arcade.h
 * This file is part of geoplatform
 *
 * Copyright (C) 2020 - malo.montillaud-ubuntu
 *
 * geoplatform is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * geoplatform is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with geoplatform. If not, see <http://www.gnu.org/licenses/>.
 */

/*
 *    ici sont enregistrées les fragments de jeu pour le mode arcade
 */



#define NB_PICS_LOCAL      5 // nombre de pics maximal des fragments de jeu
#define NB_CANNONS_LOCAL   1 // nombre de cannons maximal des fragments de jeu
#define NB_SOLSEC_LOCAL    10 // nombre de sols secondaires maximal des fragments de jeu
#define NB_DEADZONES_LOCAL 10 // nombre de zones de mort maximal des fragments de jeu

#define NB_FRAGMS_JEU 5 // nombre de fragments de jeu construits

typedef struct {
   Pic pics [NB_PICS_LOCAL];
   Cannon cannons [NB_CANNONS_LOCAL];
   SDL_Rect sol_sec [NB_SOLSEC_LOCAL];
   Dead_zone dead_zones [NB_DEADZONES_LOCAL];

   SDL_Color them;

   int fin_x;

   int score_plus;
} Fragm;


typedef struct {
   int temps;
   char C_temps [18];
   SDL_Texture *text_temps;
   SDL_Rect Rtemps;
   int scores;
   char C_scores [18];
   SDL_Texture *text_score;
   SDL_Rect Rscore;
} Datas;


void define_fragm_1 (Fragm *fragms);
void define_fragm_2 (Fragm *fragms, int tmp);
void define_fragm_3 (Fragm *fragms);
void define_fragm_4 (Fragm *fragms, int tmp);
void define_fragm_5 (Fragm *fragms, int tmp);
void gen_new_fragm (Fragm *fragms, int id, int tmp);
void refresh_arcade_mode (Var *var, Gal *gal, Fragm *fragm, Datas *datas);
void basic_initialiser (Var *var);
void decaler_sprites_arcade (Var *var, Gal *gal, int itt, Fragm *fragms);
bool test_game_over_arcade (Fragm *fragms, Var *var, Gal *gal, Datas *datas);
bool coll_perso_pic_arcade (Var *var, Fragm *fragms);
bool coll_perso_deadzones_arcade (Var *var, Fragm *fragms);
void print_message (Var *var, Gal *gal, char *mess);
void print_message_arcade (Var *var, Gal *gal, char *mess, Fragm *fragm, Datas *datas);
int saut_arcade (Var *var, Fragm *fragms);
void action_event_arcade (Var *var, int space, Fragm *fragms);
int fait_tomber_perso_arcade (Var *var, Fragm *fragms);
bool test_perso_tombe_arcade (Var *var, Fragm *fragms);
bool non_doit_voler_arcade (Var *var, Fragm *fragms);
bool doit_voler_arcade (Var *var, Fragm *fragms);
void mettre_datas_a_jour (Datas *datas, SDL_Renderer *R, TTF_Font *pol, SDL_Color C);
void enleve_sprites (Fragm *fragms);











