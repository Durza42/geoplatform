
/*
 * init_lvl_monde_2.c
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


   /* initialise le niveau 1 du monde 2 */
void lvl_1_2 (Var *var, Gal *gal) {

   printf ("oui...\n");

   int i = 0; // pour parcouror les boucles for
   int l = 4; // pour moins me fatiguer

      /* le sol */
   var -> p_lvl [l].Sol.x = 0; // le sol commence depuis tout à gauche de la fenetre
   var -> p_lvl [l].Sol.y = HAUT_WIND + 550; // hauteur du sol
   var -> p_lvl [l].Sol.w = LONG_WIND; // longueur du sol (celle de la fenetre)
   var -> p_lvl [l].Sol.h = 50; // hauteur du sol

   var -> p_lvl [l].couleur_sol.r = 125;
   var -> p_lvl [l].couleur_sol.g = 75;
   var -> p_lvl [l].couleur_sol.b = 25;

         /* le perso */
   var -> perso.Rperso.w = 40; // on place le perso à la bonne ordonnée
   var -> perso.Rperso.h = 40; // on place le perso à la bonne abscice
   var -> perso.Rperso.y = HAUT_WIND - 50 - var -> perso.Rperso.h - 1; // on place le perso à la bonne ordonnée
   var -> perso.Rperso.x = 0; // on place le perso à la bonne abscice

   var -> p_lvl [l].sol_sec [0].x = 0;
   var -> p_lvl [l].sol_sec [0].y = HAUT_WIND - 50;
   var -> p_lvl [l].sol_sec [0].h = 50;
   var -> p_lvl [l].sol_sec [0].w = 3850;

   for (i = 1 ; i < NB_SOLSEC ; i += 1) {
         /* on enlève les sols secondaires de la fenetre */
      var -> p_lvl [l].sol_sec [i].x = -1;
      var -> p_lvl [l].sol_sec [i].y = 1000;
      var -> p_lvl [l].sol_sec [i].h = 0;
      var -> p_lvl [l].sol_sec [i].w = 0;
   }


         /* le 1er */
   var -> p_lvl [l].pics [0].Rect.x = LONG_WIND + 1400; // on place le premier pic en x
   var -> p_lvl [l].pics [0].Rect.y = var -> p_lvl [l].sol_sec [0].y - HAUT_PICS_NORM; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [0].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [0].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [0]); // on place correctement chacun des rects du pic
   var -> p_lvl [l].pics [0].text_pic = gal -> pic; // on reinitialise l'image du pic

         /* le 2eme */
   var -> p_lvl [l].pics [1].Rect.x = LONG_WIND + 1550; // on place le premier pic en x
   var -> p_lvl [l].pics [1].Rect.y = var -> p_lvl [l].sol_sec [0].y - HAUT_PICS_NORM; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [1].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [1].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [1]); // on place correctement chacun des rects du pic
   var -> p_lvl [l].pics [1].text_pic = gal -> pic; // on reinitialise l'image du pic

         /* le 3eme */
   var -> p_lvl [l].pics [2].Rect.x = LONG_WIND + 3775; // on place le premier pic en x
   var -> p_lvl [l].pics [2].Rect.y = var -> p_lvl [l].sol_sec [0].y - HAUT_PICS_NORM; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [2].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [2].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [2]); // on place correctement chacun des rects du pic
   var -> p_lvl [l].pics [2].text_pic = gal -> pic; // on reinitialise l'image du pic

   for (i = 3; i < NB_PICS; i += 1) { // on fait ceci pour tous les autres pics
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

      /* on positionne l'arrivée */
   var -> arrivee.rect.x = LONG_WIND + 56000; // on positionne le sprite arrivee en x
   var -> arrivee.rect.h = 125; // on lui donne sa hauteur en h
   var -> arrivee.rect.y = var -> p_lvl [l].Sol.y - 15 - var -> arrivee.rect.h; // on positionne le sprite arrivee en y
   var -> arrivee.rect.w = 130 / (180 / 125); // on lui donne sa longueur correspondante au h sans la déformer (en réalité, l'image fait 180 par 130p)
}



   /* initialise le niveau 2 du monde 2 */
void lvl_2_2 (Var *var, Gal *gal) {

   int i = 0; // pour parcourir les boucles for
   int l = 5; // pour moins me fatiguer

      /* le sol */
   var -> p_lvl [l].Sol.x = 0; // le sol commence depuis tout à gauche de la fenetre
   var -> p_lvl [l].Sol.y = HAUT_WIND - 50; // hauteur du sol
   var -> p_lvl [l].Sol.w = LONG_WIND; // longueur du sol (celle de la fenetre)
   var -> p_lvl [l].Sol.h = 50; // hauteur du sol

   var -> p_lvl [l].couleur_sol.r = 125;
   var -> p_lvl [l].couleur_sol.g = 175;
   var -> p_lvl [l].couleur_sol.b = 125;

         /* le perso */
   var -> perso.Rperso.w = 40; // on place le perso à la bonne ordonnée
   var -> perso.Rperso.h = 40; // on place le perso à la bonne abscice
   var -> perso.Rperso.y = HAUT_WIND - 50 - var -> perso.Rperso.h; // on place le perso à la bonne ordonnée
   var -> perso.Rperso.x = 0; // on place le perso à la bonne abscice

   for (i = 0 ; i < NB_SOLSEC ; i += 1) {
         /* on enlève les sols secondaires de la fenetre */
      var -> p_lvl [l].sol_sec [i].x = -1;
      var -> p_lvl [l].sol_sec [i].y = 1000;
      var -> p_lvl [l].sol_sec [i].h = 0;
      var -> p_lvl [l].sol_sec [i].w = 0;
   }

   for (i = 0; i < NB_PICS; i += 1) { // on fait ceci pour tous les autres pics
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

      /* on positionne l'arrivée */
   var -> arrivee.rect.x = LONG_WIND + 18000; // on positionne le sprite arrivee en x
   var -> arrivee.rect.h = 125; // on lui donne sa hauteur en h
   var -> arrivee.rect.y = var -> p_lvl [l].Sol.y - 15 - var -> arrivee.rect.h; // on positionne le sprite arrivee en y
   var -> arrivee.rect.w = 130 / (180 / 125); // on lui donne sa longueur correspondante au h sans la déformer (en réalité, l'image fait 180 par 130p)
}


   /* initialise le niveau 3 du monde 2 */
void lvl_3_2 (Var *var, Gal *gal) {

   int i = 0; // pour parcourir les boucles for
   int l = 6; // pour moins me fatiguer

      /* le sol */
   var -> p_lvl [l].Sol.x = 0; // le sol commence depuis tout à gauche de la fenetre
   var -> p_lvl [l].Sol.y = HAUT_WIND - 50; // hauteur du sol
   var -> p_lvl [l].Sol.w = LONG_WIND; // longueur du sol (celle de la fenetre)
   var -> p_lvl [l].Sol.h = 50; // hauteur du sol

   var -> p_lvl [l].couleur_sol.r = 125;
   var -> p_lvl [l].couleur_sol.g = 175;
   var -> p_lvl [l].couleur_sol.b = 125;

         /* le perso */
   var -> perso.Rperso.w = 40; // on place le perso à la bonne ordonnée
   var -> perso.Rperso.h = 40; // on place le perso à la bonne abscice
   var -> perso.Rperso.y = HAUT_WIND - 50 - var -> perso.Rperso.h; // on place le perso à la bonne ordonnée
   var -> perso.Rperso.x = 0; // on place le perso à la bonne abscice

   for (i = 0 ; i < NB_SOLSEC ; i += 1) {
         /* on enlève les sols secondaires de la fenetre */
      var -> p_lvl [l].sol_sec [i].x = -1;
      var -> p_lvl [l].sol_sec [i].y = 1000;
      var -> p_lvl [l].sol_sec [i].h = 0;
      var -> p_lvl [l].sol_sec [i].w = 0;
   }

   for (i = 0; i < NB_PICS; i += 1) { // on fait ceci pour tous les autres pics
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

      /* on positionne l'arrivée */


      /* temps : ?? */
   var -> arrivee.rect.x = LONG_WIND + 80000; // on positionne le sprite arrivee en x
   var -> arrivee.rect.h = 125; // on lui donne sa hauteur en h
   var -> arrivee.rect.y = var -> p_lvl [l].Sol.y - 15 - var -> arrivee.rect.h; // on positionne le sprite arrivee en y
   var -> arrivee.rect.w = 130 / (180 / 125); // on lui donne sa longueur correspondante au h sans la déformer (en réalité, l'image fait 180 par 130p)
}




   /* initialise le niveau 4 du monde 2 */
void lvl_4_2 (Var *var, Gal *gal) {

   int i = 0; // pour parcourir les boucles for
   int l = 7; // pour moins me fatiguer

      /* le sol */
   var -> p_lvl [l].Sol.x = 0; // le sol commence depuis tout à gauche de la fenetre
   var -> p_lvl [l].Sol.y = HAUT_WIND - 50; // hauteur du sol
   var -> p_lvl [l].Sol.w = LONG_WIND; // longueur du sol (celle de la fenetre)
   var -> p_lvl [l].Sol.h = 50; // hauteur du sol

   var -> p_lvl [l].couleur_sol.r = 125;
   var -> p_lvl [l].couleur_sol.g = 175;
   var -> p_lvl [l].couleur_sol.b = 125;

         /* le perso */
   var -> perso.Rperso.w = 40; // on place le perso à la bonne ordonnée
   var -> perso.Rperso.h = 40; // on place le perso à la bonne abscice
   var -> perso.Rperso.y = HAUT_WIND - 50 - var -> perso.Rperso.h; // on place le perso à la bonne ordonnée
   var -> perso.Rperso.x = 0; // on place le perso à la bonne abscice

   for (i = 0 ; i < NB_SOLSEC ; i += 1) {
         /* on enlève les sols secondaires de la fenetre */
      var -> p_lvl [l].sol_sec [i].x = -1;
      var -> p_lvl [l].sol_sec [i].y = 1000;
      var -> p_lvl [l].sol_sec [i].h = 0;
      var -> p_lvl [l].sol_sec [i].w = 0;
   }

   for (i = 0; i < NB_PICS; i += 1) { // on fait ceci pour tous les autres pics
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

      /* on positionne l'arrivée */
   var -> arrivee.rect.x = LONG_WIND + 49500; // on positionne le sprite arrivee en x
   var -> arrivee.rect.h = 125; // on lui donne sa hauteur en h
   var -> arrivee.rect.y = var -> p_lvl [l].Sol.y - 15 - var -> arrivee.rect.h; // on positionne le sprite arrivee en y
   var -> arrivee.rect.w = 130 / (180 / 125); // on lui donne sa longueur correspondante au h sans la déformer (en réalité, l'image fait 180 par 130p)
}






