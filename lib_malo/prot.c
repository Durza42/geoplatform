
   /*chargement des images*/
bool ld_img (SDL_Texture **text, SDL_Renderer *rend, char img []);
SDL_Texture* load_img (const char path[], SDL_Renderer *renderer);

   /*écriture dans la fenetre*/
bool ttf_print_so (const char str [], SDL_Texture **T, SDL_Renderer *R, TTF_Font *pol, SDL_Color C);
bool ttf_print_sh (const char str [], SDL_Texture **T, SDL_Renderer *R, TTF_Font *pol, SDL_Color C, SDL_Color F);
bool ttf_print_B (const char str [], SDL_Texture **T, SDL_Renderer *R, TTF_Font *pol, SDL_Color C);

   /*acceil*/
void aide (SDL_Renderer *renderer, SDL_Rect Raide, SDL_Texture *T);

   /*qqs effets sur des surfaces*/
SDL_Surface* inverserCouleurs (SDL_Surface *depart);
SDL_Surface* luminosite (SDL_Surface *depart);
SDL_Surface* nuancesDeGris (SDL_Surface *depart);
   /*pareil, qui renvoie des textures*/

   /*renvoie une Surface à partir d'une texture*/
SDL_Surface *createSurfaceFromTexture (SDL_Texture *texture);

   /*colore une pixel d'une coordonnée donnée d'une couleur donnée*/
void setPixel(SDL_Surface *surface, Uint8 r, Uint8 g, Uint8 b, Uint8 a, size_t x, size_t y);

   /*attendre pendant X temps, tout en restant à l'affut d'une eventuelle demande de fermeture de la fenetre*/
void att_nn_blqte (const int delay, SDL_Window *wind, bool Pw);

   /*menu à deux issues, mess_1 ou mess_2*/
int menu_2poss (char *mess_1, char *mess_2, SDL_Texture *select, SDL_Window *fenetre, SDL_Renderer *renderer, TTF_Font *police);
   /*menu à trois issues, mess_1, mess_2 ou mess_3*/
int menu_3poss (char *mess_1, char *mess_2, char *mess_3, SDL_Texture *select, SDL_Window *fenetre, SDL_Renderer *renderer, TTF_Font *police);
   /*menu à 3 issues et un message en plus*/
int menu_2poss_message (char *mess_1, char *mess_2, char *mess, SDL_Texture *select, SDL_Window *fenetre, SDL_Renderer *renderer, TTF_Font *police);
   /*menu à 2 issues et un message en plus*/
int menu_3poss_message (char *mess_1, char *mess_2, char *mess_3, char *mess, SDL_Texture *select, SDL_Window *fenetre, SDL_Renderer *renderer, TTF_Font *police);

void afficher_message (char *str, const int size_str, SDL_Window *fenetre, SDL_Renderer *renderer, TTF_Font *font);
