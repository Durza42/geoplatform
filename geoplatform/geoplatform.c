/*
 * geoplatform.h
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
 *    ce fichier fait le lien entre chacun des fichiers
 */


#include "../lib_malo/malo.h" // ma librairie. inclut : La SDL2, d'autres fontions

#include "params.h" // ensemble des defines, constantes et autres utilisés dans geoplatform
#include "types.h" // ensemble des structures utilisés dans geoplatform
#include "prototypes.h" // ensemble des prototypes

#include "accueil.c" // relatif au lencemant du jeu

#include "defis.c" // défis

#include "reponces_events.c" // réponces aux évennements

#include "test_game_over.c" // en lien avec les fin de niveau (game-over / win)

#include "boucle.c" // traitement des evenements

#include "init_lvls_monde_1.c" // initialisation des niveaux
#include "init_lvls_monde_2.c" // initialisation des niveaux

#include "intros_musiques.c" // contient les intros des musiques

#include "arcade.h" // mode arcade, header
#include "arcade.c" // mode arcade
#include "creer_fragms.c" // création des fragments de jeu

#include "main.c" // commencement (main) et initialisations













