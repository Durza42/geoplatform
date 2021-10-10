#ifndef MALO_H
#define MALO_H


/*
 * malo.h
 * This file is part of malo
 *
 * Copyright (C) 2020 - malo_mont
 *
 * malo is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * malo is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with malo. If not, see <http://www.gnu.org/licenses/>.
 */

 #ifndef CPP

      /*Ce code est écrit en français.*/

   /*bibliothèque graphique en elle même*/
  #include <SDL2/SDL.h>
   /*sert à écrire dans la fenetre*/
  #include <SDL2/SDL_ttf.h>
   /*sert à jouer de la musique*/
  #include <SDL2/SDL_mixer.h>
   /*booléens*/
  #include <stdbool.h>
   /*io*/
  #include <stdio.h>
   /*lib*/
  #include <stdlib.h>
   /*time*/
  #include <time.h>
   /*strings*/
  #include <ctype.h>

 #endif
 #ifdef CPP
 
    /* prototypes de toutes les fontions, donc en premier */
  #include "prot_cpp.h"
 #endif
 #ifndef CPP

   /*tout le chargement d'image, leur utilisation*/
 #include "imgs.c"

   /*l'acceil, le menu*/
  #include "menu.c"

   /*différentes structures globales à tous programe*/
  #include "struct.c"

   /*le reste*/
  #include "autres.c"

   /*.............................*/

 #endif
#endif
