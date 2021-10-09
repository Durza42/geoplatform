

/*
 * init_lvl.c
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



/*
 *    Ce fichier initialise les niveaux (il place les obstacles aux bons endroits ou autres)
*/


   /* initialise le niveau 1 */
void lvl_1 (Var *var, Gal *gal) {

   int i = 0; // pour parcourir les boucles for
   int l = 0; // pour moins me fatiguer

      /* le sol */
   var -> p_lvl [l].Sol.x = 0; // le sol commence depuis tout à gauche de la fenetre
   var -> p_lvl [l].Sol.y = HAUT_WIND - 50; // hauteur du sol
   var -> p_lvl [l].Sol.w = LONG_WIND; // longueur du sol (celle de la fenetre)
   var -> p_lvl [l].Sol.h = 50; // hauteur du sol
   var -> p_lvl [l].couleur_sol.r = 25;
   var -> p_lvl [l].couleur_sol.g = 25;
   var -> p_lvl [l].couleur_sol.b = 25;

   for (i = 0 ; i < NB_SOLSEC ; i += 1) {
         /* on enlève les sols secondaires de la fenetre */
      var -> p_lvl [l].sol_sec [i].x = -1;
      var -> p_lvl [l].sol_sec [i].y = 1000;
      var -> p_lvl [l].sol_sec [i].h = 0;
      var -> p_lvl [l].sol_sec [i].w = 0;
   }

      /* le perso */
   var -> perso.Rperso.y = var -> p_lvl [l].Sol.y - var -> perso.Rperso.h; // on place le perso à la bonne ordonnée
   var -> perso.Rperso.x = 0; // on place le perso à la bonne abscice

      /* on positionne l'arrivée */
   var -> arrivee.rect.x = LONG_WIND + 200; // on positionne le sprite arrivee en x
   var -> arrivee.rect.h = 125; // on lui donne sa hauteur en h
   var -> arrivee.rect.y = var -> p_lvl [l].Sol.y - 15 - var -> arrivee.rect.h; // on positionne le sprite arrivee en y
   var -> arrivee.rect.w = 130 / (180 / 125); // on lui donne sa longueur correspondante au h sans la déformer (en réalité, l'image fait 180 par 130p)

      /* on fait sortir tous les pics de la fenetre, on n'en a pas besoin */
   for (i = 0; i < NB_PICS; i += 1) {
      var -> p_lvl [l].pics [i].Rect.x = -1; // on place les pics en x
      var -> p_lvl [l].pics [i].Rect.y = -1; // on place les pics en ordonnées
      var -> p_lvl [l].pics [i].Rect.h = 0; // on redimensionne la hauteur des pics
      var -> p_lvl [l].pics [i].Rect.w = 0; // on redimensionne la longueur des pics

      var -> p_lvl [l].pics [i].rects_v.x = -1; // on place le rectangle apparent des pics en x
      var -> p_lvl [l].pics [i].rects_v.y = -1; // on place le rectangle apparent des pics en y
      var -> p_lvl [l].pics [i].rects_v.h = 0; // on redimensionne le rectangle apparent des pics en w
      var -> p_lvl [l].pics [i].rects_v.w = 0; // on redimensionne le rectangle apparent des pics en x

      var -> p_lvl [l].pics [i].rects_h.x = -1; // on place le rectangle apparent des pics en x
      var -> p_lvl [l].pics [i].rects_h.y = -1; // on place le rectangle apparent des pics en y
      var -> p_lvl [l].pics [i].rects_h.h = 0; // on redimensionne le rectangle apparent des pics en w
      var -> p_lvl [l].pics [i].rects_h.w = 0; // on redimensionne le rectangle apparent des pics en x
   }

   for (i = 0 ; i < NB_DEADZONES ; i += 1) {
         /* on enlève les zones de mort de la fenetre */
      var -> p_lvl [l].dead_zones [i].dead.x = -1;
      var -> p_lvl [l].dead_zones [i].dead.y = -1;
      var -> p_lvl [l].dead_zones [i].dead.h = 0;
      var -> p_lvl [l].dead_zones [i].dead.w = 0;

         /* couleur des zones mortelles */
      var -> p_lvl [l].dead_zones [i].col.r = 230; // composente rouge
      var -> p_lvl [l].dead_zones [i].col.g = 230; // composente verte
      var -> p_lvl [l].dead_zones [i].col.b = 230; // composente bleue
   }

   
}



   /* initialise le niveau 2 */
void lvl_2 (Var *var, Gal *gal) {

   int i = 0; // pour parcouror les boucles for
   int l = 1; // pour moins me fatiguer

      /* le sol */
   var -> p_lvl [l].Sol.x = 0; // le sol commence depuis tout à gauche de la fenetre
   var -> p_lvl [l].Sol.y = HAUT_WIND - 50; // hauteur du sol
   var -> p_lvl [l].Sol.w = LONG_WIND; // longueur du sol (celle de la fenetre)
   var -> p_lvl [l].Sol.h = 50; // hauteur du sol
   var -> p_lvl [l].couleur_sol.r = 25;
   var -> p_lvl [l].couleur_sol.g = 75;
   var -> p_lvl [l].couleur_sol.b = 25;

   for (i = 0 ; i < NB_SOLSEC ; i += 1) {
         /* on enlève les sols secondaires de la fenetre */
      var -> p_lvl [l].sol_sec [i].x = -1;
      var -> p_lvl [l].sol_sec [i].y = 1000;
      var -> p_lvl [l].sol_sec [i].h = 0;
      var -> p_lvl [l].sol_sec [i].w = 0;
   }

      /* le perso */
   var -> perso.Rperso.y = var -> p_lvl [l].Sol.y - var -> perso.Rperso.h; // on place le perso à la bonne ordonnée
   var -> perso.Rperso.x = 0; // on place le perso à la bonne abscice

      /* les pics */
         /* le 1er */
   var -> p_lvl [l].pics [0].Rect.x = LONG_WIND + 100; // on place le premier pic en x
   var -> p_lvl [l].pics [0].Rect.y = var -> p_lvl [l].Sol.y - HAUT_PICS_NORM; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [0].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [0].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [0]); // on place correctement chacun des rects du pic

      /* on positionne l'arrivée */
   var -> arrivee.rect.x = LONG_WIND + 500; // on positionne le sprite arrivee en x
   var -> arrivee.rect.h = 125; // on lui donne sa hauteur en h
   var -> arrivee.rect.y = var -> p_lvl [l].Sol.y - 15 - var -> arrivee.rect.h; // on positionne le sprite arrivee en y
   var -> arrivee.rect.w = 130 / (180 / 125); // on lui donne sa longueur correspondante au h sans la déformer (en réalité, l'image fait 180 par 130p)

   for (i = 1; i < NB_PICS; i += 1) { // on fait ceci pour tous les autres pics
      var -> p_lvl [l].pics [i].Rect.x = -1; // on place les pics en x
      var -> p_lvl [l].pics [i].Rect.y = -1; // on place les pics en ordonnées
      var -> p_lvl [l].pics [i].Rect.h = 0; // on redimensionne la hauteur des pics
      var -> p_lvl [l].pics [i].Rect.w = 0; // on redimensionne la longueur des pics

      var -> p_lvl [l].pics [i].rects_v.x = -1; // on place le rectangle apparent des pics en x
      var -> p_lvl [l].pics [i].rects_v.y = -1; // on place le rectangle apparent des pics en y
      var -> p_lvl [l].pics [i].rects_v.h = 0; // on redimensionne le rectangle apparent des pics en w
      var -> p_lvl [l].pics [i].rects_v.w = 0; // on redimensionne le rectangle apparent des pics en x

      var -> p_lvl [l].pics [i].rects_h.x = -1; // on place le rectangle apparent des pics en x
      var -> p_lvl [l].pics [i].rects_h.y = -1; // on place le rectangle apparent des pics en y
      var -> p_lvl [l].pics [i].rects_h.h = 0; // on redimensionne le rectangle apparent des pics en w
      var -> p_lvl [l].pics [i].rects_h.w = 0; // on redimensionne le rectangle apparent des pics en x
   }

   for (i = 0 ; i < NB_DEADZONES ; i += 1) {
         /* on enlève les zones de mort de la fenetre */
      var -> p_lvl [l].dead_zones [i].dead.x = -1;
      var -> p_lvl [l].dead_zones [i].dead.y = -1;
      var -> p_lvl [l].dead_zones [i].dead.h = 0;
      var -> p_lvl [l].dead_zones [i].dead.w = 0;

         /* couleur des zones mortelles */
      var -> p_lvl [l].dead_zones [i].col.r = 230; // composente rouge
      var -> p_lvl [l].dead_zones [i].col.g = 255 - 75; // composente verte
      var -> p_lvl [l].dead_zones [i].col.b = 230; // composente bleue
   }
}




   /* initialise le niveau 3 */
void lvl_3 (Var *var, Gal *gal) {

   int i = 0; //  pour parcourir les boucles for
   int l = 2; // pour mois de fatigue pour moi

      /* les sol */
   var -> p_lvl [l].Sol.x = 0; // le sol commence depuis tout à gauche de la fenetre
   var -> p_lvl [l].Sol.y = HAUT_WIND - 50; // hauteur du sol
   var -> p_lvl [l].Sol.w = LONG_WIND; // longueur du sol (celle de la fenetre)
   var -> p_lvl [l].Sol.h = 50; // hauteur du sol
   var -> p_lvl [l].couleur_sol.r = 15; // composente rouge de la couleur du sol
   var -> p_lvl [l].couleur_sol.g = 50; // composente verte de la couleur du sol
   var -> p_lvl [l].couleur_sol.b = 15; // composente bleue de la couleur du sol

   var -> p_lvl [l].sol_sec [0].x = LONG_WIND + 750; // sol secondaire, abscices
   var -> p_lvl [l].sol_sec [0].y = var -> p_lvl [l].Sol.y - 50; // sol secondaire, ordonnées
   var -> p_lvl [l].sol_sec [0].h = 50; // sol secondaire, hauteur
   var -> p_lvl [l].sol_sec [0].w = 450; // sol secondaire, longueur

   var -> p_lvl [l].dead_zones [0].dead.x = var -> p_lvl [l].sol_sec [0].x + 1; // zone de mort qui correspond au début du sol secondaire #1, abscices
   var -> p_lvl [l].dead_zones [0].dead.y = var -> p_lvl [l].sol_sec [0].y + 2; // zone de mort qui correspond au début du sol secondaire #1, ordonnées
   var -> p_lvl [l].dead_zones [0].dead.h = var -> p_lvl [l].sol_sec [0].h - 2; // zone de mort qui correspond au début du sol secondaire #1, hauteur
   var -> p_lvl [l].dead_zones [0].dead.w = 10; // zone de mort qui correspond au début du sol secondaire #1, longueur

   var -> p_lvl [l].dead_zones [0].col.r = 2; // composente rouge
   var -> p_lvl [l].dead_zones [0].col.g = 230; // composente verte
   var -> p_lvl [l].dead_zones [0].col.b = 230; // composente bleue

   for (i = 1 ; i < NB_SOLSEC ; i += 1) {
         /* on enlève les autres sols secondaires de la fenetre */
      var -> p_lvl [l].sol_sec [i].x = -1;
      var -> p_lvl [l].sol_sec [i].y = 1000;
      var -> p_lvl [l].sol_sec [i].h = 0;
      var -> p_lvl [l].sol_sec [i].w = 0;
   }


      /* le perso */
   var -> perso.Rperso.y = var -> p_lvl [l].Sol.y - var -> perso.Rperso.h; // on place le perso à la bonne ordonnée
   var -> perso.Rperso.x = 0; // on place le perso à la bonne abscice


      /* les pics */

         /* le 1er */
   var -> p_lvl [l].pics [0].Rect.x = LONG_WIND + 100; // on place le premier pic en x
   var -> p_lvl [l].pics [0].Rect.y = var -> p_lvl [l].Sol.y - HAUT_PICS_NORM; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [0].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [0].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [0]); // on place correctement chacun des rects du pic


         /*le 2em*/
   var -> p_lvl [l].pics [1].Rect.x = LONG_WIND + 1000; // on place le premier pic en x
   var -> p_lvl [l].pics [1].Rect.y = var -> p_lvl [l].sol_sec [0].y - HAUT_PICS_NORM; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [1].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [1].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [1]); // on place correctement chacun des rects du pic

   for (i = 2; i < NB_PICS; i += 1) { // on fait ceci pour tous les autres pics
      var -> p_lvl [l].pics [i].Rect.x = -1; // on place les pics en x
      var -> p_lvl [l].pics [i].Rect.y = -1; // on place les pics en ordonnées
      var -> p_lvl [l].pics [i].Rect.h = 0; // on redimensionne la hauteur des pics
      var -> p_lvl [l].pics [i].Rect.w = 0; // on redimensionne la longueur des pics

      var -> p_lvl [l].pics [i].rects_v.x = -1; // on place le rectangle apparent des pics en x
      var -> p_lvl [l].pics [i].rects_v.y = -1; // on place le rectangle apparent des pics en y
      var -> p_lvl [l].pics [i].rects_v.h = 0; // on redimensionne le rectangle apparent des pics en w
      var -> p_lvl [l].pics [i].rects_v.w = 0; // on redimensionne le rectangle apparent des pics en x

      var -> p_lvl [l].pics [i].rects_h.x = -1; // on place le rectangle apparent des pics en x
      var -> p_lvl [l].pics [i].rects_h.y = -1; // on place le rectangle apparent des pics en y
      var -> p_lvl [l].pics [i].rects_h.h = 0; // on redimensionne le rectangle apparent des pics en w
      var -> p_lvl [l].pics [i].rects_h.w = 0; // on redimensionne le rectangle apparent des pics en x
   }

   for (i = 1 ; i < NB_DEADZONES ; i += 1) {
         /* on enlève les zones de mort de la fenetre */
      var -> p_lvl [l].dead_zones [i].dead.x = -1;
      var -> p_lvl [l].dead_zones [i].dead.y = -1;
      var -> p_lvl [l].dead_zones [i].dead.h = 0;
      var -> p_lvl [l].dead_zones [i].dead.w = 0;

         /* couleur des zones mortelles */
      var -> p_lvl [l].dead_zones [i].col.r = 240; // composente rouge
      var -> p_lvl [l].dead_zones [i].col.g = 205; // composente verte
      var -> p_lvl [l].dead_zones [i].col.b = 240; // composente bleue
   }


      /* on positionne l'arrivée */
   var -> arrivee.rect.x = LONG_WIND + 1500; // on positionne le sprite arrivee en x
   var -> arrivee.rect.h = 125; // on lui donne sa hauteur en h
   var -> arrivee.rect.y = var -> p_lvl [l].Sol.y - 15 - var -> arrivee.rect.h; // on positionne le sprite arrivee en y
   var -> arrivee.rect.w = 130 / (180 / 125); // on lui donne sa longueur correspondante au h sans la déformer (en réalité, l'image fait 180 par 130p)

}



   /* initialise le niveau 4 */
void lvl_4 (Var *var, Gal *gal) {

   var -> vol= false; // le perso ne vole pas au début

   int i = 0; //  pour parcourir les boucles for
   int l = 3; // pour moins de fatigue pour moi

      /* les sol */
   var -> p_lvl [l].Sol.x = 0; // le sol commence depuis tout à gauche de la fenetre
   var -> p_lvl [l].Sol.y = HAUT_WIND - 50; // hauteur du sol
   var -> p_lvl [l].Sol.w = LONG_WIND; // longueur du sol (celle de la fenetre)
   var -> p_lvl [l].Sol.h = 50; // hauteur du sol
   var -> p_lvl [l].couleur_sol.r = 150; // composente rouge de la couleur du sol
   var -> p_lvl [l].couleur_sol.g = 15; // composente verte de la couleur du sol
   var -> p_lvl [l].couleur_sol.b = 15; // composente bleue de la couleur du sol

   var -> p_lvl [l].sol_sec [0].x = LONG_WIND + 750; // sol secondaire, abscices
   var -> p_lvl [l].sol_sec [0].y = var -> p_lvl [l].Sol.y - 50; // sol secondaire, ordonnées
   var -> p_lvl [l].sol_sec [0].h = 50; // sol secondaire, hauteur
   var -> p_lvl [l].sol_sec [0].w = 450; // sol secondaire, longueur

   var -> p_lvl [l].dead_zones [0].dead.x = var -> p_lvl [l].sol_sec [0].x + 1; // zone de mort qui correspond au début du sol secondaire #1, abscices
   var -> p_lvl [l].dead_zones [0].dead.y = var -> p_lvl [l].sol_sec [0].y + 2; // zone de mort qui correspond au début du sol secondaire #1, ordonnées
   var -> p_lvl [l].dead_zones [0].dead.h = var -> p_lvl [l].sol_sec [0].h - 2; // zone de mort qui correspond au début du sol secondaire #1, hauteur
   var -> p_lvl [l].dead_zones [0].dead.w = 10; // zone de mort qui correspond au début du sol secondaire #1, longueur

   var -> p_lvl [l].dead_zones [0].col.r = 2; // composente rouge
   var -> p_lvl [l].dead_zones [0].col.g = 230; // composente verte
   var -> p_lvl [l].dead_zones [0].col.b = 230; // composente bleue

   var -> p_lvl [l].sol_sec [1].x = LONG_WIND + 2000; // sol secondaire, abscices
   var -> p_lvl [l].sol_sec [1].y = var -> p_lvl [l].Sol.y - 50; // sol secondaire, ordonnées
   var -> p_lvl [l].sol_sec [1].h = 50; // sol secondaire, hauteur
   var -> p_lvl [l].sol_sec [1].w = 50; // sol secondaire, longueur

   var -> p_lvl [l].sol_sec [2].x = LONG_WIND + 2120; // sol secondaire, abscices
   var -> p_lvl [l].sol_sec [2].y = var -> p_lvl [l].Sol.y - 100; // sol secondaire, ordonnées
   var -> p_lvl [l].sol_sec [2].h = 100; // sol secondaire, hauteur
   var -> p_lvl [l].sol_sec [2].w = 50; // sol secondaire, longueur

   var -> p_lvl [l].sol_sec [3].x = LONG_WIND + 2230; // sol secondaire, abscices
   var -> p_lvl [l].sol_sec [3].y = var -> p_lvl [l].Sol.y - 100; // sol secondaire, ordonnées
   var -> p_lvl [l].sol_sec [3].h = 100; // sol secondaire, hauteur
   var -> p_lvl [l].sol_sec [3].w = 100; // sol secondaire, longueur


   var -> p_lvl [l].sol_sec [4].x = LONG_WIND + 2060; // sol secondaire, abscices
   var -> p_lvl [l].sol_sec [4].y = var -> p_lvl [l].Sol.y - 25; // sol secondaire, ordonnées
   var -> p_lvl [l].sol_sec [4].h = 25; // sol secondaire, hauteur
   var -> p_lvl [l].sol_sec [4].w = 50; // sol secondaire, longueur

   var -> p_lvl [l].sol_sec [5].x = LONG_WIND + 2175; // sol secondaire, abscices
   var -> p_lvl [l].sol_sec [5].y = var -> p_lvl [l].Sol.y - 50; // sol secondaire, ordonnées
   var -> p_lvl [l].sol_sec [5].h = 50; // sol secondaire, hauteur
   var -> p_lvl [l].sol_sec [5].w = 50; // sol secondaire, longueur

   var -> p_lvl [l].sol_sec [6].x = LONG_WIND + 2425; // sol secondaire, abscices
   var -> p_lvl [l].sol_sec [6].y = var -> p_lvl [l].Sol.y - 100; // sol secondaire, ordonnées
   var -> p_lvl [l].sol_sec [6].h = 100; // sol secondaire, hauteur
   var -> p_lvl [l].sol_sec [6].w = 50; // sol secondaire, longueur

   var -> p_lvl [l].sol_sec [7].x = LONG_WIND + 2600; // sol secondaire, abscices
   var -> p_lvl [l].sol_sec [7].y = var -> p_lvl [l].Sol.y - 80; // sol secondaire, ordonnées
   var -> p_lvl [l].sol_sec [7].h = 80; // sol secondaire, hauteur
   var -> p_lvl [l].sol_sec [7].w = 25; // sol secondaire, longueur

   var -> p_lvl [l].sol_sec [8].x = LONG_WIND + 3000; // sol secondaire, abscices
   var -> p_lvl [l].sol_sec [8].y = var -> p_lvl [l].Sol.y - 30; // sol secondaire, ordonnées
   var -> p_lvl [l].sol_sec [8].h = 30; // sol secondaire, hauteur
   var -> p_lvl [l].sol_sec [8].w = 3000; // sol secondaire, longueur

   var -> p_lvl [l].dead_zones [1].dead.x = LONG_WIND + 3002; // zone de mort qui correspond au début de la zone de vol
   var -> p_lvl [l].dead_zones [1].dead.y = var -> p_lvl [l].sol_sec [8].y + 2; // zone de mort qui correspond au début du sol secondaire #1, ordonnées
   var -> p_lvl [l].dead_zones [1].dead.h = 28; // zone de mort qui correspond au début du sol secondaire #1, hauteur
   var -> p_lvl [l].dead_zones [1].dead.w = 10; // zone de mort qui correspond au début du sol secondaire #1, longueur

   var -> p_lvl [l].dead_zones [1].col.r = 2; // composente rouge
   var -> p_lvl [l].dead_zones [1].col.g = 230; // composente verte
   var -> p_lvl [l].dead_zones [1].col.b = 230; // composente bleue

   var -> p_lvl [l].sol_sec [9].x = LONG_WIND + 3200; // sol secondaire, abscices
   var -> p_lvl [l].sol_sec [9].y = var -> p_lvl [l].Sol.y - 60; // sol secondaire, ordonnées
   var -> p_lvl [l].sol_sec [9].h = 60; // sol secondaire, hauteur
   var -> p_lvl [l].sol_sec [9].w = 2850; // sol secondaire, longueur

   var -> p_lvl [l].dead_zones [2].dead.x = LONG_WIND + 3202; // zone de mort qui correspond au début de la zone de vol
   var -> p_lvl [l].dead_zones [2].dead.y = var -> p_lvl [l].sol_sec [9].y + 2; // zone de mort qui correspond au début du sol secondaire #1, ordonnées
   var -> p_lvl [l].dead_zones [2].dead.h = 28; // zone de mort qui correspond au début du sol secondaire #1, hauteur
   var -> p_lvl [l].dead_zones [2].dead.w = 10; // zone de mort qui correspond au début du sol secondaire #1, longueur

   var -> p_lvl [l].dead_zones [2].col.r = 2; // composente rouge
   var -> p_lvl [l].dead_zones [2].col.g = 230; // composente verte
   var -> p_lvl [l].dead_zones [2].col.b = 230; // composente bleue

   var -> p_lvl [l].dead_zones [3].dead.x = LONG_WIND + 3350; // zone de mort qui correspond au début de la zone de vol
   var -> p_lvl [l].dead_zones [3].dead.y = var -> p_lvl [l].sol_sec [9].y; // zone de mort qui correspond au début début de la zone de vol
   var -> p_lvl [l].dead_zones [3].dead.h = var -> p_lvl [l].sol_sec [9].h; // zone de mort qui correspond au début début de la zone de vol
   var -> p_lvl [l].dead_zones [3].dead.w = 2700; // zone de mort qui correspond au début début de la zone de vol
      /* le couleur de la zone de mort */
   var -> p_lvl [l].dead_zones [3].col.r = 2; // composente rouge
   var -> p_lvl [l].dead_zones [3].col.g = 230; // composente verte
   var -> p_lvl [l].dead_zones [3].col.b = 230; // composente bleue

   var -> p_lvl [l].sol_sec [10].x = LONG_WIND + 3000; // sol secondaire, abscices
   var -> p_lvl [l].sol_sec [10].y = 0; // sol secondaire, ordonnées
   var -> p_lvl [l].sol_sec [10].h = 30; // sol secondaire, hauteur
   var -> p_lvl [l].sol_sec [10].w = 3000; // sol secondaire, longueur

   var -> p_lvl [l].dead_zones [4].dead.x = LONG_WIND + 3350; // zone de mort qui correspond au début de la zone de vol
   var -> p_lvl [l].dead_zones [4].dead.y = 0; // zone de mort qui correspond au début du sol secondaire #1, ordonnées
   var -> p_lvl [l].dead_zones [4].dead.h = var -> p_lvl [l].sol_sec [10].h; // zone de mort qui correspond au début du sol secondaire #1, hauteur
   var -> p_lvl [l].dead_zones [4].dead.w = 2700; // zone de mort qui correspond au début du sol secondaire #1, longueur

   var -> p_lvl [l].dead_zones [4].col.r = 2; // composente rouge
   var -> p_lvl [l].dead_zones [4].col.g = 230; // composente verte
   var -> p_lvl [l].dead_zones [4].col.b = 230; // composente bleue

   for (i = 11 ; i < NB_SOLSEC ; i += 1) {
         /* on enlève les autres sols secondaires de la fenetre */

      var -> p_lvl [l].sol_sec [i].x = -1;
      var -> p_lvl [l].sol_sec [i].y = 1000;
      var -> p_lvl [l].sol_sec [i].h = 0;
      var -> p_lvl [l].sol_sec [i].w = 0;
   }

      /* le perso */
   var -> perso.Rperso.y = var -> p_lvl [l].Sol.y - var -> perso.Rperso.h; // on place le perso à la bonne ordonnée
   var -> perso.Rperso.x = 0; // on place le perso à la bonne abscice


      /* les pics */

         /* le 1er */
   var -> p_lvl [l].pics [0].Rect.x = LONG_WIND + 100; // on place le premier pic en x
   var -> p_lvl [l].pics [0].Rect.y = var -> p_lvl [l].Sol.y - HAUT_PICS_NORM; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [0].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [0].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [0]); // on place correctement chacun des rects du pic

         /* le 2em */
   var -> p_lvl [l].pics [1].Rect.x = LONG_WIND + 1000; // on place le deuxieme pic en x
   var -> p_lvl [l].pics [1].Rect.y = var -> p_lvl [l].sol_sec [0].y - HAUT_PICS_NORM; // on place le deuxieme pic en ordonnées
   var -> p_lvl [l].pics [1].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [1].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur deuxieme pic
   placer_rects_pic (&var -> p_lvl [l].pics [1]); // on place correctement chacun des rects du pic

         /* le 3em */
   var -> p_lvl [l].pics [2].Rect.x = LONG_WIND + 1430; // on place le premier pic en x
   var -> p_lvl [l].pics [2].Rect.y = var -> p_lvl [l].Sol.y - HAUT_PICS_NORM; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [2].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [2].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [2]); // on place correctement chacun des rects du pic

         /* le 4em */
   var -> p_lvl [l].pics [3].Rect.x = LONG_WIND + 1960; // on place le premier pic en x
   var -> p_lvl [l].pics [3].Rect.y = var -> p_lvl [l].Sol.y - 40; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [3].Rect.h = 40; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [3].Rect.w = 40 / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [3]); // on place correctement chacun des rects du pic

         /* le 5em */
   var -> p_lvl [l].pics [4].Rect.x = LONG_WIND + 2065; // on place le premier pic en x
   var -> p_lvl [l].pics [4].Rect.y = var -> p_lvl [l].sol_sec [4].y - HAUT_PICS_NORM; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [4].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [4].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [4]); // on place correctement chacun des rects du pic

         /* le 6em */
   var -> p_lvl [l].pics [5].Rect.x = LONG_WIND + 2177; // on place le premier pic en x
   var -> p_lvl [l].pics [5].Rect.y = var -> p_lvl [l].sol_sec [5].y - 65; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [5].Rect.h = 65; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [5].Rect.w = 65 / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [5]); // on place correctement chacun des rects du pic

         /* le 7em */
   var -> p_lvl [l].pics [6].Rect.x = LONG_WIND + 2340; // on place le premier pic en x
   var -> p_lvl [l].pics [6].Rect.y = var -> p_lvl [l].Sol.y - 140; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [6].Rect.h = 140; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [6].Rect.w = 120 / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [6]); // on place correctement chacun des rects du pic

         /* le 8em */
   var -> p_lvl [l].pics [7].Rect.x = LONG_WIND + 2485; // on place le premier pic en x
   var -> p_lvl [l].pics [7].Rect.y = var -> p_lvl [l].Sol.y - 120; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [7].Rect.h = 120; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [7].Rect.w = 100 / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [7]); // on place correctement chacun des rects du pic

         /* le 9em */
   var -> p_lvl [l].pics [8].Rect.x = LONG_WIND + 2650; // on place le premier pic en x
   var -> p_lvl [l].pics [8].Rect.y = var -> p_lvl [l].Sol.y - 65; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [8].Rect.h = 65; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [8].Rect.w = 65 / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [8]); // on place correctement chacun des rects du pic

         /* le 10em */
   var -> p_lvl [l].pics [9].Rect.x = LONG_WIND + 3800; // on place le premier pic en x
   var -> p_lvl [l].pics [9].Rect.y = var -> p_lvl [l].sol_sec [9].y - HAUT_PICS_NORM * 2; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [9].Rect.h = HAUT_PICS_NORM * 2; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [9].Rect.w = HAUT_PICS_NORM * 2 / CORR_PIC_H_W; // on redimensionne la longueur pic
   placer_rects_pic (&var -> p_lvl [l].pics [9]); // on place correctement chacun des rects du pic

   for (i = 0; i < 10; i += 1) // on fait ceci pour tous les pics ci-dessus
      var -> p_lvl [l].pics [i].text_pic = gal -> pic; // on charge la bonne image du pic (pas la returned)

         /* le 11em */
   var -> p_lvl [l].pics [10].Rect.x = LONG_WIND + 4000; // on place le premier pic en x
   var -> p_lvl [l].pics [10].Rect.y = 30; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [10].Rect.h = HAUT_PICS_NORM * 2; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [10].Rect.w = HAUT_PICS_NORM * 2 / CORR_PIC_H_W; // on redimensionne la longueur pic
   placer_rects_pic_returned (&var -> p_lvl [l].pics [10]); // on place correctement chacun des rects du pic
   var -> p_lvl [l].pics [10].text_pic = gal -> pic_returned; // on redimensionne la longueur pic

         /* le 12em */
   var -> p_lvl [l].pics [11].Rect.x = LONG_WIND + 4550; // on place le premier pic en x
   var -> p_lvl [l].pics [11].Rect.y = 30; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [11].Rect.h = HAUT_PICS_NORM * 2; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [11].Rect.w = HAUT_PICS_NORM * 2 / CORR_PIC_H_W; // on redimensionne la longueur pic
   placer_rects_pic_returned (&var -> p_lvl [l].pics [11]); // on place correctement chacun des rects du pic
   var -> p_lvl [l].pics [11].text_pic = gal -> pic_returned; // on redimensionne la longueur pic

         /* le 13em */
   var -> p_lvl [l].pics [12].Rect.x = LONG_WIND + 5000; // on place le premier pic en x
   var -> p_lvl [l].pics [12].Rect.y = var -> p_lvl [l].sol_sec [9].y - HAUT_PICS_NORM * 2; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [12].Rect.h = HAUT_PICS_NORM * 2; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [12].Rect.w = HAUT_PICS_NORM * 2 / CORR_PIC_H_W; // on redimensionne la longueur pic
   placer_rects_pic_returned (&var -> p_lvl [l].pics [12]); // on place correctement chacun des rects du pic
   var -> p_lvl [l].pics [12].text_pic = gal -> pic; // on redimensionne la longueur pic

         /* le 14em */
   var -> p_lvl [l].pics [13].Rect.x = LONG_WIND + 5400; // on place le premier pic en x
   var -> p_lvl [l].pics [13].Rect.y = var -> p_lvl [l].sol_sec [9].y - HAUT_PICS_NORM * 2; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [13].Rect.h = HAUT_PICS_NORM * 2; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [13].Rect.w = HAUT_PICS_NORM * 2 / CORR_PIC_H_W; // on redimensionne la longueur pic
   placer_rects_pic_returned (&var -> p_lvl [l].pics [13]); // on place correctement chacun des rects du pic
   var -> p_lvl [l].pics [12].text_pic = gal -> pic; // on redimensionne la longueur pic

         /* le 14em */
   var -> p_lvl [l].pics [14].Rect.x = LONG_WIND + 5400; // on place le premier pic en x
   var -> p_lvl [l].pics [14].Rect.y = 30; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [14].Rect.h = HAUT_PICS_NORM * 2; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [14].Rect.w = HAUT_PICS_NORM * 2 / CORR_PIC_H_W; // on redimensionne la longueur pic
   placer_rects_pic_returned (&var -> p_lvl [l].pics [14]); // on place correctement chacun des rects du pic
   var -> p_lvl [l].pics [14].text_pic = gal -> pic_returned; // on redimensionne la longueur pic

   for (i = 15; i < NB_PICS; i += 1) { // on fait ceci pour tous les autres pics
      var -> p_lvl [l].pics [i].Rect.x = -1; // on place les pics en x
      var -> p_lvl [l].pics [i].Rect.y = -1; // on place les pics en ordonnées
      var -> p_lvl [l].pics [i].Rect.h = 0; // on redimensionne la hauteur des pics
      var -> p_lvl [l].pics [i].Rect.w = 0; // on redimensionne la longueur des pics

      var -> p_lvl [l].pics [i].rects_v.x = -1; // on place le rectangle apparent des pics en x
      var -> p_lvl [l].pics [i].rects_v.y = -1; // on place le rectangle apparent des pics en y
      var -> p_lvl [l].pics [i].rects_v.h = 0; // on redimensionne le rectangle apparent des pics en w
      var -> p_lvl [l].pics [i].rects_v.w = 0; // on redimensionne le rectangle apparent des pics en x

      var -> p_lvl [l].pics [i].rects_h.x = -1; // on place le rectangle apparent des pics en x
      var -> p_lvl [l].pics [i].rects_h.y = -1; // on place le rectangle apparent des pics en y
      var -> p_lvl [l].pics [i].rects_h.h = 0; // on redimensionne le rectangle apparent des pics en w
      var -> p_lvl [l].pics [i].rects_h.w = 0; // on redimensionne le rectangle apparent des pics en x
   }

   var -> p_lvl [l].dead_zones [5].dead.x = LONG_WIND + 4750; // zone de mort 
   var -> p_lvl [l].dead_zones [5].dead.y = HAUT_WIND / 2 - 50; // zone de mort
   var -> p_lvl [l].dead_zones [5].dead.h = 50; // zone de mort
   var -> p_lvl [l].dead_zones [5].dead.w = 100; // zone de mort

   var -> p_lvl [l].dead_zones [5].col.r = 2; // composente rouge
   var -> p_lvl [l].dead_zones [5].col.g = 230; // composente verte
   var -> p_lvl [l].dead_zones [5].col.b = 230; // composente bleue

   for (i = 6 ; i < NB_DEADZONES ; i += 1) {
         /* on enlève les zones de mort de la fenetre */
      var -> p_lvl [l].dead_zones [i].dead.x = -1;
      var -> p_lvl [l].dead_zones [i].dead.y = -1;
      var -> p_lvl [l].dead_zones [i].dead.h = 0;
      var -> p_lvl [l].dead_zones [i].dead.w = 0;
   }

      /* cannon lanceur */
   var -> p_lvl [l].cannons [0].surf.x = LONG_WIND + 3250;
   var -> p_lvl [l].cannons [0].surf.y = 0;
   var -> p_lvl [l].cannons [0].surf.w = 100;
   var -> p_lvl [l].cannons [0].surf.h = HAUT_WIND;
   var -> p_lvl [l].cannons [0].Rcannon.x = LONG_WIND + 3265;
   var -> p_lvl [l].cannons [0].Rcannon.y = HAUT_WIND / 2 - 40;
   var -> p_lvl [l].cannons [0].Rcannon.w = 70;
   var -> p_lvl [l].cannons [0].Rcannon.h = 80;

      /* cannon receveur */
   var -> p_lvl [l].cannons [1].surf.x = LONG_WIND + 6000;
   var -> p_lvl [l].cannons [1].surf.y = 0;
   var -> p_lvl [l].cannons [1].surf.w = 100;
   var -> p_lvl [l].cannons [1].surf.h = HAUT_WIND;
   var -> p_lvl [l].cannons [1].Rcannon.x = LONG_WIND + 6015;
   var -> p_lvl [l].cannons [1].Rcannon.y = HAUT_WIND / 2 - 40;
   var -> p_lvl [l].cannons [1].Rcannon.w = 70;
   var -> p_lvl [l].cannons [1].Rcannon.h = 80;
   var -> p_lvl [l].cannons [1].Tcannon = gal -> cannon_bas;

   for (i = 2 ; i < NB_CANNONS ; i += 1) {
      var -> p_lvl [l].cannons [i].surf.x = 0;
      var -> p_lvl [l].cannons [i].surf.y = 0;
      var -> p_lvl [l].cannons [i].surf.w = 0;
      var -> p_lvl [l].cannons [i].surf.h = 0;

      var -> p_lvl [l].cannons [i].Rcannon.x = 0;
      var -> p_lvl [l].cannons [i].Rcannon.y = 0;
      var -> p_lvl [l].cannons [i].Rcannon.w = 0;
      var -> p_lvl [l].cannons [i].Rcannon.h = 0;
   }

      /* on positionne l'arrivée */
   var -> arrivee.rect.x = LONG_WIND + 6500; // on positionne le sprite arrivee en x
   var -> arrivee.rect.h = 125; // on lui donne sa hauteur en h
   var -> arrivee.rect.y = var -> p_lvl [l].Sol.y - 15 - var -> arrivee.rect.h; // on positionne le sprite arrivee en y
   var -> arrivee.rect.w = 130 / (180 / 125); // on lui donne sa longueur correspondante au h sans la déformer (en réalité, l'image fait 180 par 130p)

}











   /* place chacun des rectangles servants aux collisions des pics, par rapport à ces pics */
void placer_rects_pic (Pic *pics) {
   pics -> rects_v.x = pics -> Rect.x + pics -> Rect.w / 2 - 1; // on place le rectangle apparent du premier pic en x
   pics -> rects_v.y = pics -> Rect.y; // on place le rectangle apparent du troisieme pic en y
   pics -> rects_v.h = pics -> Rect.h; //  // on redimensionne le rectangle apparent du troisieme pic en w
   pics -> rects_v.w = 2; // on redimensionne le rectangle apparent du troisieme pic en x

   pics -> rects_h.x = pics -> Rect.x; // on place le rectangle apparent du troisieme pic en x
   pics -> rects_h.y = pics -> Rect.y + pics -> Rect.h - 10; // on place le rectangle apparent du troisieme pic en y
   pics -> rects_h.h = 10; // on redimensionne le rectangle apparent du troisieme pic en w
   pics -> rects_h.w = pics -> Rect.w; // on redimensionne le rectangle apparent du troisieme pic en x
}



   /* place chacun des rectangles servants aux collisions des pics, par rapport à ces pics, mais retournés */
void placer_rects_pic_returned (Pic *pics) {
   pics -> rects_v.x = pics -> Rect.x + pics -> Rect.w / 2 - 1; // on place le rectangle apparent du premier pic en x
   pics -> rects_v.y = pics -> Rect.y; // on place le rectangle apparent du troisieme pic en y
   pics -> rects_v.h = pics -> Rect.h; //  // on redimensionne le rectangle apparent du troisieme pic en w
   pics -> rects_v.w = 2; // on redimensionne le rectangle apparent du troisieme pic en x

   pics -> rects_h.x = pics -> Rect.x; // on place le rectangle apparent du troisieme pic en x
   pics -> rects_h.y = pics -> Rect.y; // on place le rectangle apparent du troisieme pic en y
   pics -> rects_h.h = 10; // on redimensionne le rectangle apparent du troisieme pic en w
   pics -> rects_h.w = pics -> Rect.w; // on redimensionne le rectangle apparent du troisieme pic en x
}







