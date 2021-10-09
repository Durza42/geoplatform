/*
 * types.c
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
 *    Ce fichier rassemble l'ensemble des structures utilisés dans geoplatform
 */



   /* données sur un pic */
typedef struct {
   SDL_Rect Rect, rects_v, rects_h; // rectangle global (tout le pic tient dedans, il sert à placer le pic), rectangles verticaux aucentre, pour tester les collisions quand le perso saute, rectangles horizontaux en bas pour quand le perso ne saute pas
   SDL_Texture *text_pic; // apparence du pic
} Pic;


typedef struct {
   SDL_Texture *texture; // image du sprite
   SDL_Rect rect; // emplacement du sprite
} Sprite;


typedef struct {
   float x;
   float y;
   float w;
   float h;
} Float_rect;


typedef struct {
   SDL_Rect dead; // une zone où le joueur n'a pas le droit d'aller
   SDL_Color col; // la couleur de la zone de mort
} Dead_zone;


typedef struct {
   SDL_Rect surf; // tout le rectangle
   SDL_Rect Rcannon; // le cannon en lui même (son emplacement à l'écran)
   SDL_Texture *Tcannon; // l'image du cannon
} Cannon;


typedef struct {
   int long_map; // longueur de la map

   SDL_Rect Sol; // le sol
   SDL_Color couleur_sol; // couleur du sol

   SDL_Rect sol_sec [NB_SOLSEC]; // sols secondaires (quand le sol monte)

   Pic pics [NB_PICS]; // coordonnées et taille des pics
   Dead_zone dead_zones [NB_DEADZONES]; // coordonnées et tailles des zones de mort

   Cannon cannons [NB_CANNONS]; // les cannons
}  Lvl;


typedef struct {
   SDL_Rect Rperso; // rectangle comprenant tout le perso
   SDL_Texture *perso; // image du perso
   int saute; // un nombre correspondant à l'heure de commendement du saut, 0 sinon
   bool perso_is_u; // oui ou non, selon si le perso choisit est le perso ultime
   SDL_Rect R_du_perso; // rectangle comprenant ma partie du perso qui sera affichée à l'écran
   int dir; // si le perso est ultime, indique si R_du_perso doit monter (0), descendre (1), aller à droite (2), ou à gauche (3)
} Perso;


   /* toutes les données de jeu (la fenetre, le niveau, le score, ...) */
typedef struct {
   SDL_Window *fenetre; // la fenetre
   SDL_Renderer *renderer; // le renderer ascocié
   SDL_Texture *render; // l'image d'arrière plan
   SDL_Rect Rrender; // la partie du fond qui est montré à la fenetre

   TTF_Font *police; // police utilisée pour afficher du texte à l'écran

   int lvl; // le niveau actuel, le monde actuel
   int lvl_max_atteint, monde_max_atteint; // le niveau maximum auquel le joueur est jamais allé
   int depl; // vitesse à laquelle le perso se déplace

   Perso perso; // image du perso actuel
   Sprite arrivee; // sprite de l'arrivée

   Lvl p_lvl [NB_LVLS_MAX * NB_MONDES]; // une donnée pour chaque niveau

   bool extr_datas; // si on prend les données d'une partie précédente ou pas
   bool vol; // si le perso est en train de voler

   SDL_Texture *params; // image indiquant qu'il faut appuiller sur <p> pour afficher les paramètres
   SDL_Rect Rparams; // emplacement de l'image des paramètres
   bool aff; // afficher la texture params ou pas

   int nb_skins, perso_act; // nombre de skins du joueur, skin séléctionné actuellement

   FILE *data_file; // fichier contenant les information sur la progresion du joueur

   int itt;
   bool is_paused;
} Var;


   /* rassemble toutes les images dont on aura besoin. On les stockes ici pour pouvoir y accéder plus facilement. */
typedef struct {
   SDL_Texture *ecran_titre, *mondes; // images de l'écran titre et des mondes

   SDL_Texture *arriere_plan [NB_LVLS_TOTAL]; // fonds des niveaux

   SDL_Texture *perso; // perso de départ

   SDL_Texture *pic, *pic_returned; // obstacle, obstacle retourné (de haut en bas)

   SDL_Texture *arrivee; // arrivée

   SDL_Texture *select, *select_carre; // sélecteur, selecteur carré

   SDL_Texture *cannon, *cannon_bas; // cannon qui tire vers le haut, vers le bas

   SDL_Texture *params; // image indiquant qu'il faut appuiller sur <p> pour afficher les paramètres

   SDL_Texture *skins [NB_SKINS_MAX];
   
   SDL_Texture *unknow; // un carré gris avec un point d'interrogation

   SDL_Texture *cadena, *cadena_ouvert;
} Gal;


typedef struct {
   short int volume;
   bool Bmusique [NB_LVLS_TOTAL];
   Mix_Music *Musique [NB_LVLS_TOTAL];
   Mix_Music *Musique_cutted [NB_LVLS_TOTAL]; // comme Musique, mais dont l'intro a été coupée
   int long_intro [NB_LVLS_TOTAL];
   bool deja_vu [NB_LVLS_TOTAL];
} Gal_mus;








