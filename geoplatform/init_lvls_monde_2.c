
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

   var -> vol = false; // le perso ne vole pas au début

   int i = 0; // pour parcouror les boucles for
   int l = 4; // pour moins me fatiguer

      /* le sol (on ne l'utilisera pas ce niveau) */
   var -> p_lvl [l].Sol.x = -1; // le sol commence depuis tout à gauche de la fenetre
   var -> p_lvl [l].Sol.y = 1569325056; // hauteur du sol
   var -> p_lvl [l].Sol.w = 1; // longueur du sol (celle de la fenetre)
   var -> p_lvl [l].Sol.h = 1; // hauteur du sol

   var -> p_lvl [l].couleur_sol.r = 0;
   var -> p_lvl [l].couleur_sol.g = 100;
   var -> p_lvl [l].couleur_sol.b = 0;

         /* le perso */
   var -> perso.Rperso.w = 40; // on place le perso à la bonne ordonnée
   var -> perso.Rperso.h = 40; // on place le perso à la bonne abscice
   var -> perso.Rperso.y = HAUT_WIND - 50 - var -> perso.Rperso.h - 1; // on place le perso à la bonne ordonnée
   var -> perso.Rperso.x = 0; // on place le perso à la bonne abscice

   var -> p_lvl [l].sol_sec [0].x = 0;
   var -> p_lvl [l].sol_sec [0].y = HAUT_WIND - 50;
   var -> p_lvl [l].sol_sec [0].h = 50;
   var -> p_lvl [l].sol_sec [0].w = 3900;

   var -> p_lvl [l].sol_sec [1].x = 3900;
   var -> p_lvl [l].sol_sec [1].y = HAUT_WIND + 1000;
   var -> p_lvl [l].sol_sec [1].h = 500;
   var -> p_lvl [l].sol_sec [1].w = 3650;

   for (i = 2 ; i < NB_SOLSEC ; i += 1) {
         /* on enlève les sols secondaires de la fenetre */
      var -> p_lvl [l].sol_sec [i].x = -1;
      var -> p_lvl [l].sol_sec [i].y = 1000;
      var -> p_lvl [l].sol_sec [i].h = 0;
      var -> p_lvl [l].sol_sec [i].w = 0;
   }


         /* le 1er */
   var -> p_lvl [l].pics [0].Rect.x = LONG_WIND + 1348; // on place le premier pic en x
   var -> p_lvl [l].pics [0].Rect.y = var -> p_lvl [l].sol_sec [0].y - HAUT_PICS_NORM; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [0].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [0].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [0]); // on place correctement chacun des rects du pic
   var -> p_lvl [l].pics [0].text_pic = gal -> pic; // on reinitialise l'image du pic

         /* le 2eme */
   var -> p_lvl [l].pics [1].Rect.x = LONG_WIND + 1499; // on place le premier pic en x
   var -> p_lvl [l].pics [1].Rect.y = var -> p_lvl [l].sol_sec [0].y - HAUT_PICS_NORM; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [1].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [1].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [1]); // on place correctement chacun des rects du pic
   var -> p_lvl [l].pics [1].text_pic = gal -> pic; // on reinitialise l'image du pic

         /* le 3eme */
   var -> p_lvl [l].pics [2].Rect.x = LONG_WIND + 3240 - HAUT_PICS_NORM / CORR_PIC_H_W; // on place le premier pic en x
   var -> p_lvl [l].pics [2].Rect.y = var -> p_lvl [l].sol_sec [0].y - HAUT_PICS_NORM; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [2].Rect.h = HAUT_PICS_NORM; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [2].Rect.w = HAUT_PICS_NORM / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [2]); // on place correctement chacun des rects du pic
   var -> p_lvl [l].pics [2].text_pic = gal -> pic; // on reinitialise l'image du pic


         /* dents de scie */
   var -> p_lvl [l].pics [3].Rect.x = LONG_WIND + 11275; // on place le premier pic en x
   var -> p_lvl [l].pics [3].Rect.y = 1725 - HAUT_PICS_NORM * 4; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [3].Rect.h = HAUT_PICS_NORM * 4; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [3].Rect.w = HAUT_PICS_NORM * 4 / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [3]); // on place correctement chacun des rects du pic
   var -> p_lvl [l].pics [3].text_pic = gal -> pic; // on reinitialise l'image du pic

   var -> p_lvl [l].pics [4].Rect.x = LONG_WIND + 11625; // on place le premier pic en x
   var -> p_lvl [l].pics [4].Rect.y = 1325; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [4].Rect.h = HAUT_PICS_NORM * 4; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [4].Rect.w = HAUT_PICS_NORM * 4 / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic_returned (&var -> p_lvl [l].pics [4]); // on place correctement chacun des rects du pic
   var -> p_lvl [l].pics [4].text_pic = gal -> pic_returned; // on reinitialise l'image du pic

   var -> p_lvl [l].pics [5].Rect.x = LONG_WIND + 11975; // on place le premier pic en x
   var -> p_lvl [l].pics [5].Rect.y = 1725 - HAUT_PICS_NORM * 4; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [5].Rect.h = HAUT_PICS_NORM * 4; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [5].Rect.w = HAUT_PICS_NORM * 4 / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [5]); // on place correctement chacun des rects du pic
   var -> p_lvl [l].pics [5].text_pic = gal -> pic; // on reinitialise l'image du pic

   var -> p_lvl [l].pics [6].Rect.x = LONG_WIND + 12325; // on place le premier pic en x
   var -> p_lvl [l].pics [6].Rect.y = 1325; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [6].Rect.h = HAUT_PICS_NORM * 4; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [6].Rect.w = HAUT_PICS_NORM * 4 / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic_returned (&var -> p_lvl [l].pics [6]); // on place correctement chacun des rects du pic
   var -> p_lvl [l].pics [6].text_pic = gal -> pic_returned; // on reinitialise l'image du pic

   var -> p_lvl [l].pics [7].Rect.x = LONG_WIND + 12675; // on place le premier pic en x
   var -> p_lvl [l].pics [7].Rect.y = 1725 - HAUT_PICS_NORM * 4; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [7].Rect.h = HAUT_PICS_NORM * 4; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [7].Rect.w = HAUT_PICS_NORM * 4 / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic (&var -> p_lvl [l].pics [7]); // on place correctement chacun des rects du pic
   var -> p_lvl [l].pics [7].text_pic = gal -> pic; // on reinitialise l'image du pic

   var -> p_lvl [l].pics [8].Rect.x = LONG_WIND + 13025; // on place le premier pic en x
   var -> p_lvl [l].pics [8].Rect.y = 1325; // on place le premier pic en ordonnées
   var -> p_lvl [l].pics [8].Rect.h = HAUT_PICS_NORM * 4; // on redimensionne la hauteur pic
   var -> p_lvl [l].pics [8].Rect.w = HAUT_PICS_NORM * 4 / CORR_PIC_H_W; // on redimensionne la longueur premier pic
   placer_rects_pic_returned (&var -> p_lvl [l].pics [8]); // on place correctement chacun des rects du pic
   var -> p_lvl [l].pics [8].text_pic = gal -> pic_returned; // on reinitialise l'image du pic

   for (i = 9; i < NB_PICS; i += 1) { // on fait ceci pour tous les autres pics
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

   var -> p_lvl [l].dead_zones [0].dead.x = LONG_WIND + 7050;
   var -> p_lvl [l].dead_zones [0].dead.y = 1000 + HAUT_WIND;
   var -> p_lvl [l].dead_zones [0].dead.h = 50;
   var -> p_lvl [l].dead_zones [0].dead.w = 100;

   var -> p_lvl [l].dead_zones [1].dead.x = LONG_WIND + 6900;
   var -> p_lvl [l].dead_zones [1].dead.y = 1000;
   var -> p_lvl [l].dead_zones [1].dead.h = 200;
   var -> p_lvl [l].dead_zones [1].dead.w = 1350;

   var -> p_lvl [l].dead_zones [2].dead.x = LONG_WIND + 6900;
   var -> p_lvl [l].dead_zones [2].dead.y = 3000;
   var -> p_lvl [l].dead_zones [2].dead.h = 50;
   var -> p_lvl [l].dead_zones [2].dead.w = 1000;

   var -> p_lvl [l].dead_zones [3].dead.x = LONG_WIND + 6900;
   var -> p_lvl [l].dead_zones [3].dead.y = 1400;
   var -> p_lvl [l].dead_zones [3].dead.h = 200;
   var -> p_lvl [l].dead_zones [3].dead.w = 1350;

   var -> p_lvl [l].dead_zones [4].dead.x = LONG_WIND + 8450;
   var -> p_lvl [l].dead_zones [4].dead.y = 575;
   var -> p_lvl [l].dead_zones [4].dead.h = 525;
   var -> p_lvl [l].dead_zones [4].dead.w = 50;

   var -> p_lvl [l].dead_zones [5].dead.x = LONG_WIND + 8450;
   var -> p_lvl [l].dead_zones [5].dead.y = 1225;
   var -> p_lvl [l].dead_zones [5].dead.h = 10000;
   var -> p_lvl [l].dead_zones [5].dead.w = 50;

   var -> p_lvl [l].dead_zones [6].dead.x = LONG_WIND + 9200;
   var -> p_lvl [l].dead_zones [6].dead.y = 550;
   var -> p_lvl [l].dead_zones [6].dead.h = 775;
   var -> p_lvl [l].dead_zones [6].dead.w = 50;

   var -> p_lvl [l].dead_zones [7].dead.x = LONG_WIND + 9200;
   var -> p_lvl [l].dead_zones [7].dead.y = 1450;
   var -> p_lvl [l].dead_zones [7].dead.h = 10000;
   var -> p_lvl [l].dead_zones [7].dead.w = 50;

   var -> p_lvl [l].dead_zones [8].dead.x = LONG_WIND + 9800;
   var -> p_lvl [l].dead_zones [8].dead.y = 500;
   var -> p_lvl [l].dead_zones [8].dead.h = 700;
   var -> p_lvl [l].dead_zones [8].dead.w = 50;

   var -> p_lvl [l].dead_zones [9].dead.x = LONG_WIND + 9800;
   var -> p_lvl [l].dead_zones [9].dead.y = 1400;
   var -> p_lvl [l].dead_zones [9].dead.h = 10000;
   var -> p_lvl [l].dead_zones [9].dead.w = 50;

   var -> p_lvl [l].dead_zones [10].dead.x = LONG_WIND + 10650;
   var -> p_lvl [l].dead_zones [10].dead.y = 500;
   var -> p_lvl [l].dead_zones [10].dead.h = 1000;
   var -> p_lvl [l].dead_zones [10].dead.w = 50;

   var -> p_lvl [l].dead_zones [11].dead.x = LONG_WIND + 10650;
   var -> p_lvl [l].dead_zones [11].dead.y = 1650;
   var -> p_lvl [l].dead_zones [11].dead.h = 10000;
   var -> p_lvl [l].dead_zones [11].dead.w = 50;

   // délimitations

   // haut
   var -> p_lvl [l].dead_zones [12].dead.x = LONG_WIND + 10700;
   var -> p_lvl [l].dead_zones [12].dead.y = 1275;
   var -> p_lvl [l].dead_zones [12].dead.h = 50;
   var -> p_lvl [l].dead_zones [12].dead.w = 3500;

   // bas
   var -> p_lvl [l].dead_zones [13].dead.x = LONG_WIND + 10700;
   var -> p_lvl [l].dead_zones [13].dead.y = 1725;
   var -> p_lvl [l].dead_zones [13].dead.h = 50;
   var -> p_lvl [l].dead_zones [13].dead.w = 3000;

   // descente

   // haut
   var -> p_lvl [l].dead_zones [14].dead.x = LONG_WIND + 14200;
   var -> p_lvl [l].dead_zones [14].dead.y = 1400;
   var -> p_lvl [l].dead_zones [14].dead.h = 50;
   var -> p_lvl [l].dead_zones [14].dead.w = 1000;

   // bas
   var -> p_lvl [l].dead_zones [15].dead.x = LONG_WIND + 13700;
   var -> p_lvl [l].dead_zones [15].dead.y = 1825;
   var -> p_lvl [l].dead_zones [15].dead.h = 50;
   var -> p_lvl [l].dead_zones [15].dead.w = 1000;

   // bords

   // haut
   var -> p_lvl [l].dead_zones [16].dead.x = LONG_WIND + 14200;
   var -> p_lvl [l].dead_zones [16].dead.y = 1275;
   var -> p_lvl [l].dead_zones [16].dead.h = 150;
   var -> p_lvl [l].dead_zones [16].dead.w = 50;

   // bas
   var -> p_lvl [l].dead_zones [17].dead.x = LONG_WIND + 13700;
   var -> p_lvl [l].dead_zones [17].dead.y = 1725;
   var -> p_lvl [l].dead_zones [17].dead.h = 150;
   var -> p_lvl [l].dead_zones [17].dead.w = 50;

   // descente 2

   // haut
   var -> p_lvl [l].dead_zones [18].dead.x = LONG_WIND + 15200;
   var -> p_lvl [l].dead_zones [18].dead.y = 1525;
   var -> p_lvl [l].dead_zones [18].dead.h = 50;
   var -> p_lvl [l].dead_zones [18].dead.w = 500;

   // bas
   var -> p_lvl [l].dead_zones [19].dead.x = LONG_WIND + 14700;
   var -> p_lvl [l].dead_zones [19].dead.y = 1925;
   var -> p_lvl [l].dead_zones [19].dead.h = 50;
   var -> p_lvl [l].dead_zones [19].dead.w = 1000;

   // bords

   // haut
   var -> p_lvl [l].dead_zones [20].dead.x = LONG_WIND + 15200;
   var -> p_lvl [l].dead_zones [20].dead.y = 1400;
   var -> p_lvl [l].dead_zones [20].dead.h = 150;
   var -> p_lvl [l].dead_zones [20].dead.w = 50;

   // bas
   var -> p_lvl [l].dead_zones [21].dead.x = LONG_WIND + 14700;
   var -> p_lvl [l].dead_zones [21].dead.y = 1825;
   var -> p_lvl [l].dead_zones [21].dead.h = 150;
   var -> p_lvl [l].dead_zones [21].dead.w = 50;

   // flappy bird

   var -> p_lvl [l].dead_zones [22].dead.x = LONG_WIND + 16150;
   var -> p_lvl [l].dead_zones [22].dead.y = 0;
   var -> p_lvl [l].dead_zones [22].dead.h = 1400;
   var -> p_lvl [l].dead_zones [22].dead.w = 50;

   var -> p_lvl [l].dead_zones [23].dead.x = LONG_WIND + 16150;
   var -> p_lvl [l].dead_zones [23].dead.y = 1550;
   var -> p_lvl [l].dead_zones [23].dead.h = 1150;
   var -> p_lvl [l].dead_zones [23].dead.w = 50;


   var -> p_lvl [l].dead_zones [24].dead.x = LONG_WIND + 16700;
   var -> p_lvl [l].dead_zones [24].dead.y = 0;
   var -> p_lvl [l].dead_zones [24].dead.h = 1600;
   var -> p_lvl [l].dead_zones [24].dead.w = 50;

   var -> p_lvl [l].dead_zones [25].dead.x = LONG_WIND + 16700;
   var -> p_lvl [l].dead_zones [25].dead.y = 1750;
   var -> p_lvl [l].dead_zones [25].dead.h = 1150;
   var -> p_lvl [l].dead_zones [25].dead.w = 50;


   var -> p_lvl [l].dead_zones [26].dead.x = LONG_WIND + 17400;
   var -> p_lvl [l].dead_zones [26].dead.y = 0;
   var -> p_lvl [l].dead_zones [26].dead.h = 1500;
   var -> p_lvl [l].dead_zones [26].dead.w = 50;

   var -> p_lvl [l].dead_zones [27].dead.x = LONG_WIND + 17400;
   var -> p_lvl [l].dead_zones [27].dead.y = 1650;
   var -> p_lvl [l].dead_zones [27].dead.h = 1150;
   var -> p_lvl [l].dead_zones [27].dead.w = 50;


   var -> p_lvl [l].dead_zones [28].dead.x = LONG_WIND + 18000;
   var -> p_lvl [l].dead_zones [28].dead.y = 0;
   var -> p_lvl [l].dead_zones [28].dead.h = 1750;
   var -> p_lvl [l].dead_zones [28].dead.w = 50;

   var -> p_lvl [l].dead_zones [29].dead.x = LONG_WIND + 18000;
   var -> p_lvl [l].dead_zones [29].dead.y = 1900;
   var -> p_lvl [l].dead_zones [29].dead.h = 1150;
   var -> p_lvl [l].dead_zones [29].dead.w = 50;

   var -> p_lvl [l].dead_zones [30].dead.x = LONG_WIND + 18850;
   var -> p_lvl [l].dead_zones [30].dead.y = 1450;
   var -> p_lvl [l].dead_zones [30].dead.h = 150;
   var -> p_lvl [l].dead_zones [30].dead.w = 50;

   var -> p_lvl [l].dead_zones [31].dead.x = LONG_WIND + 18850;
   var -> p_lvl [l].dead_zones [31].dead.y = 1800;
   var -> p_lvl [l].dead_zones [31].dead.h = 150;
   var -> p_lvl [l].dead_zones [31].dead.w = 50;

   var -> p_lvl [l].dead_zones [32].dead.x = LONG_WIND + 18850;
   var -> p_lvl [l].dead_zones [32].dead.y = 1400;
   var -> p_lvl [l].dead_zones [32].dead.h = 50;
   var -> p_lvl [l].dead_zones [32].dead.w = 2000;

   var -> p_lvl [l].dead_zones [33].dead.x = LONG_WIND + 18850;
   var -> p_lvl [l].dead_zones [33].dead.y = 1950;
   var -> p_lvl [l].dead_zones [33].dead.h = 50;
   var -> p_lvl [l].dead_zones [33].dead.w = 2000;

   var -> p_lvl [l].dead_zones [34].dead.x = LONG_WIND + 19400;
   var -> p_lvl [l].dead_zones [34].dead.y = 1475;
   var -> p_lvl [l].dead_zones [34].dead.h = 150;
   var -> p_lvl [l].dead_zones [34].dead.w = 50;

   var -> p_lvl [l].dead_zones [35].dead.x = LONG_WIND + 19400;
   var -> p_lvl [l].dead_zones [35].dead.y = 1775;
   var -> p_lvl [l].dead_zones [35].dead.h = 150;
   var -> p_lvl [l].dead_zones [35].dead.w = 50;

   var -> p_lvl [l].dead_zones [36].dead.x = LONG_WIND + 19950;
   var -> p_lvl [l].dead_zones [36].dead.y = 1575;
   var -> p_lvl [l].dead_zones [36].dead.h = 150;
   var -> p_lvl [l].dead_zones [36].dead.w = 50;

   var -> p_lvl [l].dead_zones [37].dead.x = LONG_WIND + 19950;
   var -> p_lvl [l].dead_zones [37].dead.y = 1725;
   var -> p_lvl [l].dead_zones [37].dead.h = 100;
   var -> p_lvl [l].dead_zones [37].dead.w = 50;

   //       ~_~

   var -> p_lvl [l].dead_zones [38].dead.x = LONG_WIND + 20850;
   var -> p_lvl [l].dead_zones [38].dead.y = 1400;
   var -> p_lvl [l].dead_zones [38].dead.h = 150;
   var -> p_lvl [l].dead_zones [38].dead.w = 50;

   var -> p_lvl [l].dead_zones [39].dead.x = LONG_WIND + 20850;
   var -> p_lvl [l].dead_zones [39].dead.y = 1850;
   var -> p_lvl [l].dead_zones [39].dead.h = 150;
   var -> p_lvl [l].dead_zones [39].dead.w = 50;

   var -> p_lvl [l].dead_zones [40].dead.x = LONG_WIND + 20900;
   var -> p_lvl [l].dead_zones [40].dead.y = 1400;
   var -> p_lvl [l].dead_zones [40].dead.h = 175;
   var -> p_lvl [l].dead_zones [40].dead.w = 50;

   var -> p_lvl [l].dead_zones [41].dead.x = LONG_WIND + 20900;
   var -> p_lvl [l].dead_zones [41].dead.y = 1875;
   var -> p_lvl [l].dead_zones [41].dead.h = 150;
   var -> p_lvl [l].dead_zones [41].dead.w = 50;

   var -> p_lvl [l].dead_zones [42].dead.x = LONG_WIND + 20950;
   var -> p_lvl [l].dead_zones [42].dead.y = 1400;
   var -> p_lvl [l].dead_zones [42].dead.h = 150;
   var -> p_lvl [l].dead_zones [42].dead.w = 50;

   var -> p_lvl [l].dead_zones [43].dead.x = LONG_WIND + 20950;
   var -> p_lvl [l].dead_zones [43].dead.y = 1850;
   var -> p_lvl [l].dead_zones [43].dead.h = 150;
   var -> p_lvl [l].dead_zones [43].dead.w = 50;

   for (i = 44  ; i < NB_DEADZONES ; i += 1) {
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

      /* cannon envoyeur */
   var -> p_lvl [l].cannons [0].surf.x = LONG_WIND + 6900;
   var -> p_lvl [l].cannons [0].surf.y = 0;
   var -> p_lvl [l].cannons [0].surf.w = 100;
   var -> p_lvl [l].cannons [0].surf.h = HAUT_WIND + 1000;
   var -> p_lvl [l].cannons [0].Rcannon.x = LONG_WIND + 7015;
   var -> p_lvl [l].cannons [0].Rcannon.y = HAUT_WIND + 1000 + (HAUT_WIND / 2 - 40);
   var -> p_lvl [l].cannons [0].Rcannon.w = 70;
   var -> p_lvl [l].cannons [0].Rcannon.h = 80;
   var -> p_lvl [l].cannons [0].Tcannon = gal -> cannon;

      /* cannon receveur */
   var -> p_lvl [l].cannons [1].surf.x = LONG_WIND + 55000;
   var -> p_lvl [l].cannons [1].surf.y = 1000;
   var -> p_lvl [l].cannons [1].surf.w = 100;
   var -> p_lvl [l].cannons [1].surf.h = HAUT_WIND + 1000;
   var -> p_lvl [l].cannons [1].Rcannon.x = LONG_WIND + 55015;
   var -> p_lvl [l].cannons [1].Rcannon.y = 1000 + (HAUT_WIND / 2 - 40);
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
   var -> arrivee.rect.x = LONG_WIND + 40000; // on positionne le sprite arrivee en x
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
   var -> arrivee.rect.x = LONG_WIND + 81000; // on positionne le sprite arrivee en x
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






