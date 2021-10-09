/*
 * creer_fragms.c
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
 *    ici, on trouve le fonctionnement du jeu en arcade.
 */



void gen_new_fragm (Fragm *fragms, int id, int tmp) {

   switch (id) {
      case 0:
         define_fragm_1 (fragms);
     return;
      case 1:
         define_fragm_2 (fragms, tmp);
     return;
      case 2:
         define_fragm_3 (fragms);
     return;
      case 3:
         define_fragm_4 (fragms, tmp);
     return;
      case 4:
         define_fragm_5 (fragms, tmp);
     return;
      default:
     return;
   }
}




void basic_initialiser (Var *var) {

   var -> p_lvl [0].Sol.x = 0; // le sol commence depuis tout à gauche de la fenetre
   var -> p_lvl [0].Sol.y = HAUT_WIND - 50; // hauteur du sol
   var -> p_lvl [0].Sol.w = LONG_WIND; // longueur du sol (celle de la fenetre)
   var -> p_lvl [0].Sol.h = 50; // hauteur du sol
}



void enleve_sprites (Fragm *fragms) {

   /* correspond en réalité au niveau 3 debutant */

   int i = 0;

   for (i = 0 ; i < NB_SOLSEC_LOCAL ; i += 1) {
         /* on enlève les autres sols secondaires de la fenetre */
      fragms -> sol_sec [i].x = -1;
      fragms -> sol_sec [i].y = 1000;
      fragms -> sol_sec [i].h = 0;
      fragms -> sol_sec [i].w = 0;
   }

   /* les pics */

   for (i = 0; i < NB_PICS_LOCAL; i += 1) { // on fait ceci pour tous les autres pics
      fragms -> pics [i].Rect.x = -1; // on place les pics en x
      fragms -> pics [i].Rect.y = -1; // on place les pics en ordonnées
      fragms -> pics [i].Rect.h = 0; // on redimensionne la hauteur des pics
      fragms -> pics [i].Rect.w = 0; // on redimensionne la longueur des pics

      fragms -> pics [i].rects_v.x = -1; // on place le rectangle apparent des pics en x
      fragms -> pics [i].rects_v.y = -1; // on place le rectangle apparent des pics en y
      fragms -> pics [i].rects_v.h = 0; // on redimensionne le rectangle apparent des pics en w
      fragms -> pics [i].rects_v.w = 0; // on redimensionne le rectangle apparent des pics en x

      fragms -> pics [i].rects_h.x = -1; // on place le rectangle apparent des pics en x
      fragms -> pics [i].rects_h.y = -1; // on place le rectangle apparent des pics en y
      fragms -> pics [i].rects_h.h = 0; // on redimensionne le rectangle apparent des pics en w
      fragms -> pics [i].rects_h.w = 0; // on redimensionne le rectangle apparent des pics en x
   }

   for (i = 0 ; i < NB_CANNONS_LOCAL ; i += 1) {
      fragms -> cannons [i].surf.x = 0;
      fragms -> cannons [i].surf.y = 0;
      fragms -> cannons [i].surf.w = 0;
      fragms -> cannons [i].surf.h = 0;

      fragms -> cannons [i].Rcannon.x = 0;
      fragms -> cannons [i].Rcannon.y = 0;
      fragms -> cannons [i].Rcannon.w = 0;
      fragms -> cannons [i].Rcannon.h = 0;
   }

   for (i = 0 ; i < NB_DEADZONES_LOCAL ; i += 1) {
         /* on enlève les zones de mort de la fenetre */
      fragms -> dead_zones [i].dead.x = -1;
      fragms -> dead_zones [i].dead.y = -1;
      fragms -> dead_zones [i].dead.h = 0;
      fragms -> dead_zones [i].dead.w = 0;
   }
}


void define_fragm_1 (Fragm *fragms) {

   /* correspond en réalité au niveau 2 debutant */

   fragms -> score_plus = 2;

   int i = 0;

   fragms -> them.r = 125;
   fragms -> them.g = 125;
   fragms -> them.b = 125;

   fragms -> sol_sec [0].x = LONG_WIND + 400; // sol secondaire, abscices
   fragms -> sol_sec [0].y = HAUT_WIND - 100; // sol secondaire, abscices
   fragms -> sol_sec [0].h = 50; // sol secondaire, hauteur
   fragms -> sol_sec [0].w = 450; // sol secondaire, longueur

   fragms -> dead_zones [0].dead.x = fragms -> sol_sec [0].x + 1; // zone de mort qui correspond au début du sol secondaire #1, abscices
   fragms -> dead_zones [0].dead.y = fragms -> sol_sec [0].y + 2; // zone de mort qui correspond au début du sol secondaire #1, ordonnées
   fragms -> dead_zones [0].dead.h = fragms -> sol_sec [0].h - 2; // zone de mort qui correspond au début du sol secondaire #1, hauteur
   fragms -> dead_zones [0].dead.w = 10; // zone de mort qui correspond au début du sol secondaire #1, longueur

   fragms -> dead_zones [0].col.r = 2; // composente rouge
   fragms -> dead_zones [0].col.g = 230; // composente verte
   fragms -> dead_zones [0].col.b = 230; // composente bleue

   for (i = 1 ; i < NB_SOLSEC_LOCAL ; i += 1) {
         /* on enlève les autres sols secondaires de la fenetre */
      fragms -> sol_sec [i].x = -1;
      fragms -> sol_sec [i].y = 1000;
      fragms -> sol_sec [i].h = 0;
      fragms -> sol_sec [i].w = 0;
   }


   /* les pics */

         /* le 1er */
   fragms -> pics [0].Rect.x = LONG_WIND + 100; // on place le premier pic en x
   fragms -> pics [0].Rect.y = HAUT_WIND - 50 - HAUT_PICS_NORM; // on place le premier pic en ordonnées
   fragms -> pics [0].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
   fragms -> pics [0].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&fragms -> pics [0]); // on place correctement chacun des rects du pic

         /*le 2em*/
   fragms -> pics [1].Rect.x = LONG_WIND + 650; // on place le premier pic en x
   fragms -> pics [1].Rect.y = fragms -> sol_sec [0].y - HAUT_PICS_NORM; // on place le premier pic en ordonnées
   fragms -> pics [1].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
   fragms -> pics [1].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&fragms -> pics [1]); // on place correctement chacun des rects du pic

   for (i = 2; i < NB_PICS_LOCAL; i += 1) { // on fait ceci pour tous les autres pics
      fragms -> pics [i].Rect.x = -1; // on place les pics en x
      fragms -> pics [i].Rect.y = -1; // on place les pics en ordonnées
      fragms -> pics [i].Rect.h = 0; // on redimensionne la hauteur des pics
      fragms -> pics [i].Rect.w = 0; // on redimensionne la longueur des pics

      fragms -> pics [i].rects_v.x = -1; // on place le rectangle apparent des pics en x
      fragms -> pics [i].rects_v.y = -1; // on place le rectangle apparent des pics en y
      fragms -> pics [i].rects_v.h = 0; // on redimensionne le rectangle apparent des pics en w
      fragms -> pics [i].rects_v.w = 0; // on redimensionne le rectangle apparent des pics en x

      fragms -> pics [i].rects_h.x = -1; // on place le rectangle apparent des pics en x
      fragms -> pics [i].rects_h.y = -1; // on place le rectangle apparent des pics en y
      fragms -> pics [i].rects_h.h = 0; // on redimensionne le rectangle apparent des pics en w
      fragms -> pics [i].rects_h.w = 0; // on redimensionne le rectangle apparent des pics en x
   }

   fragms -> fin_x = 900;
}




void define_fragm_2 (Fragm *fragms, int tmp) {

   /* correspond en réalité au niveau 3 debutant */

   fragms -> score_plus = 5;

   int i = 0;

   fragms -> them.r = 125;
   fragms -> them.g = 125;
   fragms -> them.b = 125;

   for (i = 0 ; i < NB_SOLSEC_LOCAL ; i += 1) {
         /* on enlève les autres sols secondaires de la fenetre */
      fragms -> sol_sec [i].x = -1;
      fragms -> sol_sec [i].y = 1000;
      fragms -> sol_sec [i].h = 0;
      fragms -> sol_sec [i].w = 0;
   }

   /* les pics */

         /* le 1er */
   fragms -> pics [0].Rect.x = LONG_WIND; // on place le premier pic en x
   fragms -> pics [0].Rect.y = HAUT_WIND - 50 - HAUT_PICS_NORM; // on place le premier pic en ordonnées
   fragms -> pics [0].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
   fragms -> pics [0].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&fragms -> pics [0]); // on place correctement chacun des rects du pic

         /*le 2em*/
   fragms -> pics [1].Rect.x = LONG_WIND + 180; // on place le premier pic en x
   fragms -> pics [1].Rect.y = HAUT_WIND - 50 - HAUT_PICS_NORM; // on place le premier pic en ordonnées
   fragms -> pics [1].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
   fragms -> pics [1].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&fragms -> pics [1]); // on place correctement chacun des rects du pic

         /*le 3em*/
   fragms -> pics [2].Rect.x = LONG_WIND + 400; // on place le premier pic en x
   fragms -> pics [2].Rect.y = HAUT_WIND - 50 - HAUT_PICS_NORM; // on place le premier pic en ordonnées
   fragms -> pics [2].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
   fragms -> pics [2].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&fragms -> pics [2]); // on place correctement chacun des rects du pic

         /*le 2em*/
   if (tmp < 60) {
      fragms -> pics [3].Rect.x = LONG_WIND + 425; // on place le premier pic en x
      fragms -> pics [3].Rect.y = HAUT_WIND - 50 - HAUT_PICS_NORM; // on place le premier pic en ordonnées
      fragms -> pics [3].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
      fragms -> pics [3].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
      placer_rects_pic (&fragms -> pics [3]); // on place correctement chacun des rects du pic
   }
   else {
      fragms -> pics [3].Rect.x = LONG_WIND + 450; // on place le premier pic en x
      fragms -> pics [3].Rect.y = HAUT_WIND - 50 - HAUT_PICS_NORM; // on place le premier pic en ordonnées
      fragms -> pics [3].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
      fragms -> pics [3].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
      placer_rects_pic (&fragms -> pics [3]); // on place correctement chacun des rects du pic
   }

   for (i = 4; i < NB_PICS_LOCAL; i += 1) { // on fait ceci pour tous les autres pics
      fragms -> pics [i].Rect.x = -1; // on place les pics en x
      fragms -> pics [i].Rect.y = -1; // on place les pics en ordonnées
      fragms -> pics [i].Rect.h = 0; // on redimensionne la hauteur des pics
      fragms -> pics [i].Rect.w = 0; // on redimensionne la longueur des pics

      fragms -> pics [i].rects_v.x = -1; // on place le rectangle apparent des pics en x
      fragms -> pics [i].rects_v.y = -1; // on place le rectangle apparent des pics en y
      fragms -> pics [i].rects_v.h = 0; // on redimensionne le rectangle apparent des pics en w
      fragms -> pics [i].rects_v.w = 0; // on redimensionne le rectangle apparent des pics en x

      fragms -> pics [i].rects_h.x = -1; // on place le rectangle apparent des pics en x
      fragms -> pics [i].rects_h.y = -1; // on place le rectangle apparent des pics en y
      fragms -> pics [i].rects_h.h = 0; // on redimensionne le rectangle apparent des pics en w
      fragms -> pics [i].rects_h.w = 0; // on redimensionne le rectangle apparent des pics en x
   }

   fragms -> fin_x = 500;
}


void define_fragm_3 (Fragm *fragms) {

   /* correspond en réalité au niveau 3 debutant */

   fragms -> score_plus = 6;

   int i = 0;

   fragms -> them.r = 125;
   fragms -> them.g = 125;
   fragms -> them.b = 125;

   fragms -> sol_sec [0].x = LONG_WIND + 0; // sol secondaire, abscices
   fragms -> sol_sec [0].y = HAUT_WIND - 50 - 50; // sol secondaire, ordonnées
   fragms -> sol_sec [0].h = 50; // sol secondaire, hauteur
   fragms -> sol_sec [0].w = 50; // sol secondaire, longueur

   fragms -> dead_zones [0].dead.x = LONG_WIND + 1; // zone de mort 
   fragms -> dead_zones [0].dead.y = HAUT_WIND - 50 - 50 + 2; // zone de mort
   fragms -> dead_zones [0].dead.h = 48; // zone de mort
   fragms -> dead_zones [0].dead.w = 2; // zone de mort

   fragms -> sol_sec [1].x = LONG_WIND + 60; // sol secondaire, abscices
   fragms -> sol_sec [1].y = HAUT_WIND - 50 - 25; // sol secondaire, ordonnées
   fragms -> sol_sec [1].h = 25; // sol secondaire, hauteur
   fragms -> sol_sec [1].w = 50; // sol secondaire, longueur

   fragms -> dead_zones [1].dead.x = LONG_WIND + 60 + 1; // zone de mort 
   fragms -> dead_zones [1].dead.y = HAUT_WIND - 50 - 25 + 2; // zone de mort
   fragms -> dead_zones [1].dead.h = 23; // zone de mort
   fragms -> dead_zones [1].dead.w = 2; // zone de mort

   fragms -> sol_sec [2].x = LONG_WIND + 120; // sol secondaire, abscices
   fragms -> sol_sec [2].y = HAUT_WIND - 50 - 100; // sol secondaire, ordonnées
   fragms -> sol_sec [2].h = 100; // sol secondaire, hauteur
   fragms -> sol_sec [2].w = 50; // sol secondaire, longueur

   fragms -> dead_zones [2].dead.x = LONG_WIND + 120 + 1; // zone de mort 
   fragms -> dead_zones [2].dead.y = HAUT_WIND - 50 - 100 + 2; // zone de mort
   fragms -> dead_zones [2].dead.h = 98; // zone de mort
   fragms -> dead_zones [2].dead.w = 2; // zone de mort

   fragms -> sol_sec [3].x = LONG_WIND + 175; // sol secondaire, abscices
   fragms -> sol_sec [3].y = HAUT_WIND - 50 - 50; // sol secondaire, ordonnées
   fragms -> sol_sec [3].h = 50; // sol secondaire, hauteur
   fragms -> sol_sec [3].w = 50; // sol secondaire, longueur

   fragms -> dead_zones [3].dead.x = LONG_WIND + 175 + 1; // zone de mort 
   fragms -> dead_zones [3].dead.y = HAUT_WIND - 50 - 50 + 2; // zone de mort
   fragms -> dead_zones [3].dead.h = 48; // zone de mort
   fragms -> dead_zones [3].dead.w = 2; // zone de mort

   fragms -> sol_sec [4].x = LONG_WIND + 230; // sol secondaire, abscices
   fragms -> sol_sec [4].y = HAUT_WIND - 50 - 100; // sol secondaire, ordonnées
   fragms -> sol_sec [4].h = 100; // sol secondaire, hauteur
   fragms -> sol_sec [4].w = 100; // sol secondaire, longueur

   fragms -> dead_zones [4].dead.x = LONG_WIND + 230 + 1; // zone de mort 
   fragms -> dead_zones [4].dead.y = HAUT_WIND - 50 - 100 + 2; // zone de mort
   fragms -> dead_zones [4].dead.h = 98; // zone de mort
   fragms -> dead_zones [4].dead.w = 2; // zone de mort

   for (i = 5 ; i < NB_SOLSEC_LOCAL ; i += 1) {
         /* on enlève les autres sols secondaires de la fenetre */
      fragms -> sol_sec [i].x = -1;
      fragms -> sol_sec [i].y = 1000;
      fragms -> sol_sec [i].h = 0;
      fragms -> sol_sec [i].w = 0;
   }

   for (i = 5 ; i < NB_DEADZONES_LOCAL ; i += 1) {
         /* on enlève les zones de mort de la fenetre */
      fragms -> dead_zones [i].dead.x = -1;
      fragms -> dead_zones [i].dead.y = -1;
      fragms -> dead_zones [i].dead.h = 0;
      fragms -> dead_zones [i].dead.w = 0;
   }

   for (i = 0; i < NB_PICS_LOCAL; i += 1) { // on fait ceci pour tous les autres pics
      fragms -> pics [i].Rect.x = -1; // on place les pics en x
      fragms -> pics [i].Rect.y = -1; // on place les pics en ordonnées
      fragms -> pics [i].Rect.h = 0; // on redimensionne la hauteur des pics
      fragms -> pics [i].Rect.w = 0; // on redimensionne la longueur des pics

      fragms -> pics [i].rects_v.x = -1; // on place le rectangle apparent des pics en x
      fragms -> pics [i].rects_v.y = -1; // on place le rectangle apparent des pics en y
      fragms -> pics [i].rects_v.h = 0; // on redimensionne le rectangle apparent des pics en w
      fragms -> pics [i].rects_v.w = 0; // on redimensionne le rectangle apparent des pics en x

      fragms -> pics [i].rects_h.x = -1; // on place le rectangle apparent des pics en x
      fragms -> pics [i].rects_h.y = -1; // on place le rectangle apparent des pics en y
      fragms -> pics [i].rects_h.h = 0; // on redimensionne le rectangle apparent des pics en w
      fragms -> pics [i].rects_h.w = 0; // on redimensionne le rectangle apparent des pics en x
   }

   fragms -> pics [0].Rect.x = LONG_WIND + 500; // on place le premier pic en x
   fragms -> pics [0].Rect.y = HAUT_WIND - 50 - HAUT_PICS_NORM; // on place le premier pic en ordonnées
   fragms -> pics [0].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
   fragms -> pics [0].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&fragms -> pics [0]); // on place correctement chacun des rects du pic

   for (i = 1; i < NB_PICS_LOCAL; i += 1) { // on fait ceci pour tous les autres pics
      fragms -> pics [i].Rect.x = -1; // on place les pics en x
      fragms -> pics [i].Rect.y = -1; // on place les pics en ordonnées
      fragms -> pics [i].Rect.h = 0; // on redimensionne la hauteur des pics
      fragms -> pics [i].Rect.w = 0; // on redimensionne la longueur des pics

      fragms -> pics [i].rects_v.x = -1; // on place le rectangle apparent des pics en x
      fragms -> pics [i].rects_v.y = -1; // on place le rectangle apparent des pics en y
      fragms -> pics [i].rects_v.h = 0; // on redimensionne le rectangle apparent des pics en w
      fragms -> pics [i].rects_v.w = 0; // on redimensionne le rectangle apparent des pics en x

      fragms -> pics [i].rects_h.x = -1; // on place le rectangle apparent des pics en x
      fragms -> pics [i].rects_h.y = -1; // on place le rectangle apparent des pics en y
      fragms -> pics [i].rects_h.h = 0; // on redimensionne le rectangle apparent des pics en w
      fragms -> pics [i].rects_h.w = 0; // on redimensionne le rectangle apparent des pics en x
   }

   fragms -> fin_x = 515;
}


void define_fragm_4 (Fragm *fragms, int tmp) {

   /* correspond en réalité au niveau 3 debutant */

   fragms -> score_plus = 9;

   int i = 0;

   fragms -> them.r = 125;
   fragms -> them.g = 125;
   fragms -> them.b = 125;

   fragms -> sol_sec [0].x = LONG_WIND + 0; // sol secondaire, abscices
   fragms -> sol_sec [0].y = HAUT_WIND - 50 - 50; // sol secondaire, ordonnées
   fragms -> sol_sec [0].h = 20; // sol secondaire, hauteur
   fragms -> sol_sec [0].w = 100; // sol secondaire, longueur

   fragms -> dead_zones [0].dead.x = LONG_WIND + 1; // zone de mort 
   fragms -> dead_zones [0].dead.y = HAUT_WIND - 50 - 50 + 2; // zone de mort
   fragms -> dead_zones [0].dead.h = 18; // zone de mort
   fragms -> dead_zones [0].dead.w = 2; // zone de mort

   fragms -> sol_sec [1].x = LONG_WIND + 150; // sol secondaire, abscices
   fragms -> sol_sec [1].y = HAUT_WIND - 50 - 75; // sol secondaire, ordonnées
   fragms -> sol_sec [1].h = 20; // sol secondaire, hauteur
   fragms -> sol_sec [1].w = 250; // sol secondaire, longueur

   fragms -> dead_zones [1].dead.x = LONG_WIND + 150 + 1; // zone de mort 
   fragms -> dead_zones [1].dead.y = HAUT_WIND - 50 - 75 + 2; // zone de mort
   fragms -> dead_zones [1].dead.h = 18; // zone de mort
   fragms -> dead_zones [1].dead.w = 2; // zone de mort

   fragms -> dead_zones [2].dead.x = LONG_WIND + 140; // zone de mort 
   fragms -> dead_zones [2].dead.y = HAUT_WIND - 50 - 40; // zone de mort
   fragms -> dead_zones [2].dead.h = 35; // zone de mort
   fragms -> dead_zones [2].dead.w = 20; // zone de mort

   if (tmp < 300)
      fragms -> dead_zones [3].dead.x = LONG_WIND + 360; // zone de mort 
   else if (tmp < 600)
      fragms -> dead_zones [3].dead.x = LONG_WIND + 350; // zone de mort 
   else if (tmp < 1200)
      fragms -> dead_zones [3].dead.x = LONG_WIND + 345; // zone de mort 
   else
      fragms -> dead_zones [3].dead.x = LONG_WIND + 340; // zone de mort 
   fragms -> dead_zones [3].dead.y = HAUT_WIND - 50 - 75 - HAUT_PICS_NORM / 2 - 100; // zone de mort
   fragms -> dead_zones [3].dead.h = 25; // zone de mort
   fragms -> dead_zones [3].dead.w = 50; // zone de mort

   for (i = 2 ; i < NB_SOLSEC_LOCAL ; i += 1) {
         /* on enlève les autres sols secondaires de la fenetre */
      fragms -> sol_sec [i].x = -1;
      fragms -> sol_sec [i].y = 1000;
      fragms -> sol_sec [i].h = 0;
      fragms -> sol_sec [i].w = 0;
   }

   for (i = 4 ; i < NB_DEADZONES_LOCAL ; i += 1) {
         /* on enlève les zones de mort de la fenetre */
      fragms -> dead_zones [i].dead.x = -1;
      fragms -> dead_zones [i].dead.y = -1;
      fragms -> dead_zones [i].dead.h = 0;
      fragms -> dead_zones [i].dead.w = 0;
   }

   fragms -> pics [0].Rect.x = LONG_WIND + 300; // on place le premier pic en x
   fragms -> pics [0].Rect.y = HAUT_WIND - 50 - 75 - HAUT_PICS_NORM / 2; // on place le premier pic en ordonnées
   fragms -> pics [0].Rect.h = HAUT_PICS_NORM / 2; // on redimensionne la hauteur pic
   fragms -> pics [0].Rect.w = HAUT_PICS_NORM / 2 / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&fragms -> pics [0]); // on place correctement chacun des rects du pic

   for (i = 1; i < NB_PICS_LOCAL; i += 1) { // on fait ceci pour tous les autres pics
      fragms -> pics [i].Rect.x = -1; // on place les pics en x
      fragms -> pics [i].Rect.y = -1; // on place les pics en ordonnées
      fragms -> pics [i].Rect.h = 0; // on redimensionne la hauteur des pics
      fragms -> pics [i].Rect.w = 0; // on redimensionne la longueur des pics

      fragms -> pics [i].rects_v.x = -1; // on place le rectangle apparent des pics en x
      fragms -> pics [i].rects_v.y = -1; // on place le rectangle apparent des pics en y
      fragms -> pics [i].rects_v.h = 0; // on redimensionne le rectangle apparent des pics en w
      fragms -> pics [i].rects_v.w = 0; // on redimensionne le rectangle apparent des pics en x

      fragms -> pics [i].rects_h.x = -1; // on place le rectangle apparent des pics en x
      fragms -> pics [i].rects_h.y = -1; // on place le rectangle apparent des pics en y
      fragms -> pics [i].rects_h.h = 0; // on redimensionne le rectangle apparent des pics en w
      fragms -> pics [i].rects_h.w = 0; // on redimensionne le rectangle apparent des pics en x
   }

   fragms -> fin_x = 515;
}


void define_fragm_5 (Fragm *fragms, int tmp) {

   /* correspond en réalité au niveau 3 debutant */

   fragms -> score_plus = 6;

   int i = 0;

   fragms -> them.r = 125;
   fragms -> them.g = 125;
   fragms -> them.b = 125;

   fragms -> sol_sec [0].x = LONG_WIND; // sol secondaire, abscices
   fragms -> sol_sec [0].y = HAUT_WIND - 50 - 75; // sol secondaire, ordonnées
   fragms -> sol_sec [0].h = 75; // sol secondaire, hauteur
   fragms -> sol_sec [0].w = 150; // sol secondaire, longueur

   fragms -> dead_zones [0].dead.x = LONG_WIND; // zone de mort 
   fragms -> dead_zones [0].dead.y = HAUT_WIND - 50 - 75 + 2; // zone de mort
   fragms -> dead_zones [0].dead.h = 75; // zone de mort
   fragms -> dead_zones [0].dead.w = 2; // zone de mort

   if (tmp < 1200) {

      fragms -> sol_sec [1].x = LONG_WIND + 150; // sol secondaire, abscices
      fragms -> sol_sec [1].y = HAUT_WIND - 50 - 150; // sol secondaire, ordonnées
      fragms -> sol_sec [1].h = 150; // sol secondaire, hauteur
      fragms -> sol_sec [1].w = 250; // sol secondaire, longueur

      fragms -> dead_zones [1].dead.x = LONG_WIND + 150; // zone de mort 
      fragms -> dead_zones [1].dead.y = HAUT_WIND - 50 - 150 + 2; // zone de mort
      fragms -> dead_zones [1].dead.h = 150; // zone de mort
      fragms -> dead_zones [1].dead.w = 2; // zone de mort

      fragms -> sol_sec [2].x = LONG_WIND + 400; // sol secondaire, abscices
      fragms -> sol_sec [2].y = HAUT_WIND - 50 - 75; // sol secondaire, ordonnées
      fragms -> sol_sec [2].h = 75; // sol secondaire, hauteur
      fragms -> sol_sec [2].w = 150; // sol secondaire, longueur

      fragms -> dead_zones [2].dead.x = LONG_WIND + 400; // zone de mort 
      fragms -> dead_zones [2].dead.y = HAUT_WIND - 50 - 75 + 2; // zone de mort
      fragms -> dead_zones [2].dead.h = 75; // zone de mort
      fragms -> dead_zones [2].dead.w = 2; // zone de mort

      fragms -> sol_sec [3].x = LONG_WIND + 700; // sol secondaire, abscices
      fragms -> sol_sec [3].y = HAUT_WIND - 50 - 75; // sol secondaire, ordonnées
      fragms -> sol_sec [3].h = 75; // sol secondaire, hauteur
      fragms -> sol_sec [3].w = 150; // sol secondaire, longueur

      fragms -> dead_zones [3].dead.x = LONG_WIND + 700; // zone de mort 
      fragms -> dead_zones [3].dead.y = HAUT_WIND - 50 - 75 + 2; // zone de mort
      fragms -> dead_zones [3].dead.h = 75; // zone de mort
      fragms -> dead_zones [3].dead.w = 2; // zone de mort

      fragms -> sol_sec [4].x = LONG_WIND + 850; // sol secondaire, abscices
      fragms -> sol_sec [4].y = HAUT_WIND - 50 - 150; // sol secondaire, ordonnées
      fragms -> sol_sec [4].h = 150; // sol secondaire, hauteur
      fragms -> sol_sec [4].w = 250; // sol secondaire, longueur

      fragms -> dead_zones [4].dead.x = LONG_WIND + 850; // zone de mort 
      fragms -> dead_zones [4].dead.y = HAUT_WIND - 50 - 150 + 2; // zone de mort
      fragms -> dead_zones [4].dead.h = 150; // zone de mort
      fragms -> dead_zones [4].dead.w = 2; // zone de mort

      fragms -> sol_sec [5].x = LONG_WIND + 1100; // sol secondaire, abscices
      fragms -> sol_sec [5].y = HAUT_WIND - 50 - 75; // sol secondaire, ordonnées
      fragms -> sol_sec [5].h = 75; // sol secondaire, hauteur
      fragms -> sol_sec [5].w = 150; // sol secondaire, longueur

      fragms -> dead_zones [5].dead.x = LONG_WIND + 1100; // zone de mort 
      fragms -> dead_zones [5].dead.y = HAUT_WIND - 50 - 75 + 2; // zone de mort
      fragms -> dead_zones [5].dead.h = 75; // zone de mort
      fragms -> dead_zones [5].dead.w = 2; // zone de mort
   }
   else {

      fragms -> sol_sec [1].x = LONG_WIND + 150; // sol secondaire, abscices
      fragms -> sol_sec [1].y = HAUT_WIND - 50 - 150; // sol secondaire, ordonnées
      fragms -> sol_sec [1].h = 150; // sol secondaire, hauteur
      fragms -> sol_sec [1].w = 350; // sol secondaire, longueur

      fragms -> dead_zones [1].dead.x = LONG_WIND + 150; // zone de mort 
      fragms -> dead_zones [1].dead.y = HAUT_WIND - 50 - 150 + 2; // zone de mort
      fragms -> dead_zones [1].dead.h = 150; // zone de mort
      fragms -> dead_zones [1].dead.w = 2; // zone de mort

      fragms -> sol_sec [2].x = LONG_WIND + 500; // sol secondaire, abscices
      fragms -> sol_sec [2].y = HAUT_WIND - 50 - 75; // sol secondaire, ordonnées
      fragms -> sol_sec [2].h = 75; // sol secondaire, hauteur
      fragms -> sol_sec [2].w = 150; // sol secondaire, longueur

      fragms -> dead_zones [2].dead.x = LONG_WIND + 500; // zone de mort 
      fragms -> dead_zones [2].dead.y = HAUT_WIND - 50 - 75 + 2; // zone de mort
      fragms -> dead_zones [2].dead.h = 75; // zone de mort
      fragms -> dead_zones [2].dead.w = 2; // zone de mort

      fragms -> sol_sec [3].x = LONG_WIND + 800; // sol secondaire, abscices
      fragms -> sol_sec [3].y = HAUT_WIND - 50 - 75; // sol secondaire, ordonnées
      fragms -> sol_sec [3].h = 75; // sol secondaire, hauteur
      fragms -> sol_sec [3].w = 150; // sol secondaire, longueur

      fragms -> dead_zones [3].dead.x = LONG_WIND + 800; // zone de mort 
      fragms -> dead_zones [3].dead.y = HAUT_WIND - 50 - 75 + 2; // zone de mort
      fragms -> dead_zones [3].dead.h = 75; // zone de mort
      fragms -> dead_zones [3].dead.w = 2; // zone de mort

      fragms -> sol_sec [4].x = LONG_WIND + 950; // sol secondaire, abscices
      fragms -> sol_sec [4].y = HAUT_WIND - 50 - 150; // sol secondaire, ordonnées
      fragms -> sol_sec [4].h = 150; // sol secondaire, hauteur
      fragms -> sol_sec [4].w = 350; // sol secondaire, longueur

      fragms -> dead_zones [4].dead.x = LONG_WIND + 950; // zone de mort 
      fragms -> dead_zones [4].dead.y = HAUT_WIND - 50 - 150 + 2; // zone de mort
      fragms -> dead_zones [4].dead.h = 150; // zone de mort
      fragms -> dead_zones [4].dead.w = 2; // zone de mort

      fragms -> sol_sec [5].x = LONG_WIND + 1300; // sol secondaire, abscices
      fragms -> sol_sec [5].y = HAUT_WIND - 50 - 75; // sol secondaire, ordonnées
      fragms -> sol_sec [5].h = 75; // sol secondaire, hauteur
      fragms -> sol_sec [5].w = 150; // sol secondaire, longueur

      fragms -> dead_zones [5].dead.x = LONG_WIND + 1300; // zone de mort 
      fragms -> dead_zones [5].dead.y = HAUT_WIND - 50 - 75 + 2; // zone de mort
      fragms -> dead_zones [5].dead.h = 75; // zone de mort
      fragms -> dead_zones [5].dead.w = 2; // zone de mort
   }

/*
   fragms -> dead_zones [2].dead.x = LONG_WIND + 140; // zone de mort 
   fragms -> dead_zones [2].dead.y = HAUT_WIND - 50 - 40; // zone de mort
   fragms -> dead_zones [2].dead.h = 35; // zone de mort
   fragms -> dead_zones [2].dead.w = 20; // zone de mort

   if (tmp < 300)
      fragms -> dead_zones [3].dead.x = LONG_WIND + 360; // zone de mort 
   else if (tmp < 600)
      fragms -> dead_zones [3].dead.x = LONG_WIND + 350; // zone de mort 
   else if (tmp < 1200)
      fragms -> dead_zones [3].dead.x = LONG_WIND + 345; // zone de mort 
   else
      fragms -> dead_zones [3].dead.x = LONG_WIND + 340; // zone de mort 
   fragms -> dead_zones [3].dead.y = HAUT_WIND - 50 - 75 - HAUT_PICS_NORM / 2 - 100; // zone de mort
   fragms -> dead_zones [3].dead.h = 25; // zone de mort
   fragms -> dead_zones [3].dead.w = 50; // zone de mort
*/
   for (i = 6 ; i < NB_SOLSEC_LOCAL ; i += 1) {
         /* on enlève les autres sols secondaires de la fenetre */
      fragms -> sol_sec [i].x = -1;
      fragms -> sol_sec [i].y = 1000;
      fragms -> sol_sec [i].h = 0;
      fragms -> sol_sec [i].w = 0;
   }

   for (i = 6 ; i < NB_DEADZONES_LOCAL ; i += 1) {
         /* on enlève les zones de mort de la fenetre */
      fragms -> dead_zones [i].dead.x = -1;
      fragms -> dead_zones [i].dead.y = -1;
      fragms -> dead_zones [i].dead.h = 0;
      fragms -> dead_zones [i].dead.w = 0;
   }
/*
   fragms -> pics [0].Rect.x = LONG_WIND + 300; // on place le premier pic en x
   fragms -> pics [0].Rect.y = HAUT_WIND - 50 - 75 - HAUT_PICS_NORM / 2; // on place le premier pic en ordonnées
   fragms -> pics [0].Rect.h = HAUT_PICS_NORM / 2; // on redimensionne la hauteur pic
   fragms -> pics [0].Rect.w = HAUT_PICS_NORM / 2 / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&fragms -> pics [0]); // on place correctement chacun des rects du pic
*/
   for (i = 1; i < NB_PICS_LOCAL; i += 1) { // on fait ceci pour tous les autres pics
      fragms -> pics [i].Rect.x = -1; // on place les pics en x
      fragms -> pics [i].Rect.y = -1; // on place les pics en ordonnées
      fragms -> pics [i].Rect.h = 0; // on redimensionne la hauteur des pics
      fragms -> pics [i].Rect.w = 0; // on redimensionne la longueur des pics

      fragms -> pics [i].rects_v.x = -1; // on place le rectangle apparent des pics en x
      fragms -> pics [i].rects_v.y = -1; // on place le rectangle apparent des pics en y
      fragms -> pics [i].rects_v.h = 0; // on redimensionne le rectangle apparent des pics en w
      fragms -> pics [i].rects_v.w = 0; // on redimensionne le rectangle apparent des pics en x

      fragms -> pics [i].rects_h.x = -1; // on place le rectangle apparent des pics en x
      fragms -> pics [i].rects_h.y = -1; // on place le rectangle apparent des pics en y
      fragms -> pics [i].rects_h.h = 0; // on redimensionne le rectangle apparent des pics en w
      fragms -> pics [i].rects_h.w = 0; // on redimensionne le rectangle apparent des pics en x
   }

   fragms -> fin_x = 900;
}















