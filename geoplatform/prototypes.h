
/*
 * prototypes.h
 * This file is part of geoplatform
 *
 * Copyright (C) 2020 - malo.montillaud-ubuntu
 *
 * geoplatform is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * geoplatform is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with geoplatform. If not, see <http://www.gnu.org/licenses/>.
 */


bool Inits (Var *var, Gal *gal, Gal_mus *gal_mus); /* initialisation de l'ensemble des variables */
bool init_gal (Gal *gal, SDL_Renderer *renderer); /* bool init_gal (Gal *gal, SDL_Renderer *renderer) */
bool init_gal_mus (Gal_mus *gal_mus, SDL_Renderer *renderer); /* initialisation des musiques */
void init_lvls (Var *var, Gal *gal); /* gestion des initialisations de niveau */
void exit_geoplatform (Var *var, Gal *gal); /* on demande à quiter geoplatform */

int select_lvl (Var *var, Gal *gal, int monde); /* écran de départ (selection de niveau, assignation des touches, vitesse, etc.) */
int select_monde (Var *var, Gal *gal); /* on choisit un monde */
void save_datas (FILE *data_file, Var *var); /* sauvegarde les données du joueur dans un fichier */
FILE* recup_datas (Var *var, Gal *gal); /* récupèrera les données demandées */

int boucle_principale (Var *var, Gal *gal, Gal_mus *gal_mus); /* traite les evenement */
int fait_tomber_perso (Var *var); /* vérifie si le perso doit tomber ou pas et agit en conséquence */
bool test_perso_tombe (Var *var); /* teste si le perso peut tomber ou pas */
void refresh (Var *var, Gal *gal); /* met la fenetre à jour */
Uint32 thread (Uint32 intervalle, void *data); /* thread qui se charge d'appeler à interval régulier la fonction qui décale les sprites vers la gauche */
void decaler_sprites (Var *var, int itt); /* décale tous les sprites vers la gauche */
void monte_sprites (Var *var); /* décale tous les sprites vers le haut */
void descend_sprites (Var *var); /* décale tous les sprites vers le bas */
void anim_perso_u (Var *var); /* anime le perso ultime */
bool coll_perso_pic (Var *var); /* définie si le perso touche un des pic */
bool coll_perso_deadzones (Var *var); /* définie si le perso touche une des zones de mort */
bool doit_voler (Var *var); /* vérifie si le perso doit commencer à voler */
bool non_doit_voler (Var *var); /* vérifie si le perso doit s'aretter de voler */

void lvl_1_1 (Var *var, Gal *gal); /* initialise le niveau 1 du monde 1 */
void lvl_2_1 (Var *var, Gal *gal); /* initialise le niveau 2 du monde 1 */
void lvl_3_1 (Var *var, Gal *gal); /* initialise le niveau 3 du monde 1 */
void lvl_4_1 (Var *var, Gal *gal); /* initialise le niveau 4 du monde 1 */
void placer_rects_pic (Pic *pics); /* place chacun des rectangles servants aux collisions des pics, par rapport à ces pics */
void placer_rects_pic_returned (Pic *pics); /* place chacun des rectangles servants aux collisions des pics, par rapport à ces pics, mais retournés */
bool params (Var *var, Gal *gal); /* affiche les paramètres */
int get_touche (SDL_Window *fenetre, SDL_Renderer *renderer, TTF_Font *pol); /* renvoie la touche appuillé */
int choose_skin (Var *var, Gal *gal); /* le joueur choisit un skin */
void defis (Var *var, Gal *gal); /* choit du défi */

void action_event (Var *var, int space); /* appele les fonctions correspondantes aux actions demandées */
int pause (); /* on met le programme en pause */
int saut (Var *var); /* le perso saute */

bool test_game_over (Var *var, Gal *gal, Gal_mus *gal_mus); /* regarde si le joueur a perdu, et agit en concéquance */
bool test_win (Var *var, Gal *gal); /* regarde si le joueur a gagné, et agit en concéquance */
void print_message (Var *var, Gal *gal, char *mess); /* on affiche un message à l'écran */

bool defi_1 (Var *var, Gal *gal); /* défi #1. renvoie true si réussit, false sinon */
int boucle_principale_no_dead (Var *var, Gal *gal); /* traite les evenement. retourne false si il faut quitter, true si le jouer veut continuer. le tout, sans mourir...*/

int boucle_arcade (Var *var, Gal *gal);

void redirect_intro_musique (Var *var, Gal_mus *gal_mus, Gal *gal);
void intro (char *title, char *compositeur, char *tire_de, int long_intro, Var *var, Gal *gal);









