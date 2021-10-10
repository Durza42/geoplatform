#ifndef IMGS_C
#define IMGS_C

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>
#include "prot.h"

#ifndef CPP

SDL_Texture* load_img (const char path[], SDL_Renderer *renderer) {

   SDL_Surface *tmp = NULL;
   SDL_Texture *tex = NULL;

   tmp = SDL_LoadBMP(path);

   if (tmp == NULL) {
      printf("Erreur SDL_LoadBMP : %s\n", SDL_GetError());
      return NULL;
   }

   SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB (tmp -> format, 255, 255, 255));

   tex = SDL_CreateTextureFromSurface(renderer, tmp);

   SDL_FreeSurface(tmp);

   if (tex == NULL) {
      printf ("Erreur SDL_CreateTextureFromSurface : %s\n", SDL_GetError());
      return NULL;
   }

   return tex;
}


SDL_Surface* load_img_surface (const char path[]) {

   SDL_Surface *tmp = NULL;

   tmp = SDL_LoadBMP(path);

   if (tmp == NULL) {
      printf("Erreur SDL_LoadBMP : %s\n", SDL_GetError());
      return NULL;
   }

   SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB (tmp -> format, 255, 255, 255));

   return tmp;
}

   /*chargement d'une image + test*/
bool ld_img (SDL_Texture **text, SDL_Renderer *rend, char img []) {
   
   *text = load_img (img, rend);//chargement de l'image

   if (text == NULL) {//echec
      printf ("erreur à l'image %s : %s \n", img, SDL_GetError ());//message d'erreur

      return false;//retour d'erreur
   }
   else//réussite
      return true;//retour de succes.

   return true;
}

   /*print directement sur la texture, en solide*/
bool ttf_print_so (const char str [], SDL_Texture **T, SDL_Renderer *R, TTF_Font *pol, SDL_Color C) {

   if (pol == NULL) {
      printf ("erreur : ptr \"pol\" null. \n");
      return false;
   }

   SDL_Surface *texte = NULL;
   texte = TTF_RenderText_Solid (pol, str, C);

   *T = SDL_CreateTextureFromSurface (R, texte);
   SDL_FreeSurface (texte);

   return true;
}


   /*print directement sur la texture, en shaded*/
bool ttf_print_sh (const char str [], SDL_Texture **T, SDL_Renderer *R, TTF_Font *pol, SDL_Color C, SDL_Color F) {

   if (pol == NULL) {
      printf ("erreur : ptr \"pol\" null. \n");
      return false;
   }

   SDL_Surface *texte = NULL;
   texte = TTF_RenderText_Shaded (pol, str, C, F);

   *T = SDL_CreateTextureFromSurface (R, texte);
   SDL_FreeSurface (texte);

   return true;
}


   /*print directement sur la texture, en Blended*/
bool ttf_print_B (const char str [], SDL_Texture **T, SDL_Renderer *R, TTF_Font *pol, SDL_Color C) {

   if (pol == NULL) {
      printf ("erreur : ptr \"pol\" null. \n");
      return false;
   }

   SDL_Surface *texte = NULL;
   texte = TTF_RenderText_Blended (pol, str, C);

   *T = SDL_CreateTextureFromSurface (R, texte);
   SDL_FreeSurface (texte);

   return true;
}


   /*print sur un rect de la texture, en solide*/
bool ttf_print_R_so (const char str [], SDL_Texture **T, SDL_Rect rect, SDL_Renderer *R, TTF_Font *pol, SDL_Color C) {

   if (pol == NULL) {
      printf ("erreur : ptr \"pol\" null. \n");
      return false;
   }

   SDL_Surface *S_texte = NULL;
   S_texte = TTF_RenderText_Solid (pol, str, C);

   SDL_SetColorKey(S_texte, SDL_TRUE, SDL_MapRGB (S_texte -> format, 255, 255, 255));

   SDL_Texture *texte = SDL_CreateTextureFromSurface (R, S_texte);

   SDL_SetRenderTarget (R, *T);
   SDL_RenderCopy (R, texte, NULL, &rect);
   SDL_SetRenderTarget (R, NULL);

   SDL_DestroyTexture (texte);
   SDL_FreeSurface (S_texte);

   return true;
}


   /*print directement sur la fenetre, en shaded*/
bool ttf_print_R_sh (const char str [], SDL_Texture **T, SDL_Rect rect, SDL_Renderer *R, TTF_Font *pol, SDL_Color C, SDL_Color F) {

   if (pol == NULL) {
      printf ("erreur : ptr \"pol\" null. \n");
      return false;
   }

   SDL_Surface *S_texte = NULL;
   S_texte = TTF_RenderText_Shaded (pol, str, C, F);

   SDL_SetColorKey(S_texte, SDL_TRUE, SDL_MapRGB (S_texte -> format, 255, 255, 255));

   *T = SDL_CreateTextureFromSurface (R, S_texte);

   SDL_FreeSurface (S_texte);

   return true;
}


   /*print directement sur la fenetre, en Blended*/
bool ttf_print_R_B (const char str [], SDL_Texture **T, SDL_Rect rect, SDL_Renderer *R, TTF_Font *pol, SDL_Color C) {

   if (pol == NULL) {
      printf ("erreur : ptr \"pol\" null. \n");
      return false;
   }

   SDL_Surface *S_texte = NULL;
   S_texte = TTF_RenderText_Blended (pol, str, C);

   SDL_SetColorKey(S_texte, SDL_TRUE, SDL_MapRGB (S_texte -> format, 255, 255, 255));

   SDL_Texture *texte = SDL_CreateTextureFromSurface (R, S_texte);

   SDL_SetRenderTarget (R, *T);
   SDL_RenderCopy (R, texte, NULL, &rect);
   SDL_SetRenderTarget (R, NULL);

   SDL_DestroyTexture (texte);
   SDL_FreeSurface (S_texte);

   return true;
}



SDL_Surface* inverserCouleurs (SDL_Surface *depart) {
   
   SDL_Surface *retour;
   Uint32 *pixels;//deviendra un tableau de pixels

   size_t i = 0, j = 0, w = (size_t) depart -> w, h = (size_t) depart -> h ;//pour les boucles

   SDL_LockSurface(depart);//on bloque la surface pour travailler en toute securite

   pixels = depart -> pixels;//on recupere les pixels de la surface dans un tableau

   for(i = 0; i < h; i++) {
      for(j = 0; j < w; j++) {

         SDL_Color* color;

         color = malloc (sizeof(SDL_Color));

         SDL_GetRGB (pixels[i * w + j], depart -> format, &color -> r, &color -> g, &color -> b);
         SDL_Color inverse = {255 - color -> r, 255 - color -> g, 255 - color -> b};
         pixels[i * w + j] = SDL_MapRGB(depart -> format, inverse.r, inverse.g, inverse.b);

         free (color);
      }
   }

   retour = SDL_CreateRGBSurfaceWithFormatFrom(pixels, depart -> w, depart -> h, 32, depart -> pitch, depart -> format -> format);

   SDL_UnlockSurface (depart);//on debloque la surface
   return retour;//on retourne la surface en couleurs inversees
}



SDL_Surface* luminosite (SDL_Surface *depart) {
   
   SDL_Surface *retour;//sera retourne
   Uint32 *pixels;//deviendra un tableau de pixels

   size_t i = 0, j = 0, w = (size_t) depart -> w, h = (size_t) depart -> h ;//pour les boucles

   SDL_LockSurface(depart);//on bloque la surface pour travailler en toute securite

   pixels = depart -> pixels;//on recupere les pixels de la surface dans un tableau


   for(i = 0; i < h; i++) {
      for(j = 0; j < w; j++) {

         SDL_Color* color;

         color = malloc (sizeof(SDL_Color));

         SDL_GetRGB(pixels[i * w + j], depart -> format, &color -> r, &color -> g, &color -> b);
      
         SDL_Color lum = {255 * SDL_pow((double) color -> r / 255, 0.5), 255 * SDL_pow((double) color -> g / 255, 0.5), 255 * SDL_pow((double) color -> b / 255, 0.5)};

         pixels[i * w + j] = SDL_MapRGB(depart -> format, lum.r, lum.g, lum.b);

         free (color);
      }
   }

   retour = SDL_CreateRGBSurfaceWithFormatFrom(pixels, depart -> w, depart -> h, 32, depart -> pitch, depart -> format -> format);

   SDL_UnlockSurface (depart);//on debloque la surface

   return retour;//on retourne la surface, mais moin lumineuse
}

/*

SDL_Surface* _luminosite (SDL_Surface *depart) {
   
   SDL_Surface *retour;//sera retourne
   Uint32 *pixels;

   pixels = depart -> pixels;

   size_t i = 0, j = 0, w = (size_t) depart -> w, h = (size_t) depart -> h ;//pour les boucles

   SDL_LockSurface(depart);//on bloque la surface pour travailler en toute securite

   SDL_Color C = {0};

   for(i = 0; i < h; i++) {
      for(j = 0; j < w; j++) {

         SDL_GetRGBA (pixels [i * w + j], SDL_AllocFormat (SDL_PIXELFORMAT_RGBA8888), &C.r, &C.g, &C.b, &C.a);

         C.r -= 10;
         C.g -= 10;
         C.b -= 10;

         setPixel (depart, C.r, C.g, C.b, 255, i, j);

         C.r = 0;
         C.g = 0;
         C.b = 0;
      }
   }

   retour = SDL_CreateRGBSurfaceWithFormatFrom (pixels, depart -> w, depart -> h, 32, depart -> pitch, depart -> format -> format);

   SDL_UnlockSurface (depart);//on debloque la surface

   return retour;//on retourne la surface, mais moin lumineuse
}

*/


SDL_Surface* nuancesDeGris (SDL_Surface *depart) {
   
   SDL_Surface *retour;
   Uint32 *pixels;//deviendra un tableau de pixels

   size_t i = 0, j = 0, w = (size_t) depart -> w, h = (size_t) depart -> h ;//pour les boucles

   SDL_LockSurface(depart);//on bloque la surface pour travailler en toute securite

   pixels = depart -> pixels;//on recupere les pixels de la surface dans un tableau


   for(i = 0; i < h; i++) {
      for(j = 0; j < w; j++) {

         SDL_Color* color;

         color = malloc (sizeof(SDL_Color));

         SDL_GetRGB(pixels[i * w + j], depart -> format, &color -> r, &color -> g, &color -> b);
         Uint8 gris = (color -> r + color -> g + color -> b) / 3;
         pixels[i * w + j] = SDL_MapRGB(depart -> format, gris, gris, gris);

         free (color);
      }
   }

   retour = SDL_CreateRGBSurfaceWithFormatFrom(pixels, depart -> w, depart -> h, 32, depart -> pitch, depart -> format -> format);

   SDL_UnlockSurface (depart);//on debloque la surface
   return retour;//on retourne la surface en nuances de gris
}

#endif

#endif
