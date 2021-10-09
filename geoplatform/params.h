/*
 * params.c
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

#define LONG_WIND 650 // longueur de la fenetre
#define HAUT_WIND 500 // hauteur de la fenetre

#define CORR_PIC_H_W 1.5 // diviseur pour passer de la hauteur à la longueur d'un pic en gardant les proportions

#define NB_PICS 15 // nombre de pics
#define NB_DEADZONES 45 // nombre de zones de mort
#define NB_SOLSEC 12 // le nombre de sols secondaires
#define NB_CANNONS 2 // nombre de cannons

#define NB_MONDES 2 // nombre de mondes
#define NB_LVLS_MAX 4 // nombre maximum de niveaux
#define NB_LVLS_TOTAL NB_LVLS_MAX * NB_MONDES // nombre de niveaux au total
const int NB_LVLS [NB_MONDES] = {4, 0};  // nombre de niveaux du monde 1 (malheureusement, pas de define []...)

#define HAUT_PICS_NORM 60 // hauteur normalle d'un pic normal

   /* ce seraient des constantes si elles ne risquaient pas de se faire modifier par le joueur */
int SAUTER = SDLK_SPACE; // la touche <espace> permetra par défaut de sauter
int PAUSE = SDLK_p; // la touche <p> permettra par défaut de mettre en pause
int REGLAGES = SDLK_r; // la touche <r>permettre par défaut d'accéder aux réglages

#define NB_SKINS_MAX 20 // nombre de skins quel'on peut avoir au maximum





