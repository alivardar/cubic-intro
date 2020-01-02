/***************************************************************/
/*  M.Ali VARDAR 2004 Classic intro for win and linux sdl2 */
/***************************************************************/

//ggcc -IC:\MinGW\include -IC:\MinGW\include\SDL2 -LC:\MinGW\lib -static -o cubic-sdl cubic-sdl.c  -lm -lSDL2

#define W 640
#define H 400
#define FONT_HEIGHT  16
#define FONT_WIDTH   16
#define SDL_MAIN_HANDLED

#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

int i;
//yildizlar
int stx[50];
int sty[50];
int stax[50];
int stay[50];
int starx[50];
int stary[50];

int stfix[300];
int stfiy[300];

//kup
double a[8][3];
int q[12], p[12];
double dy, dx, en, boy;
int t;
int x, y, z, k, m, n, h, g;
int cubels=40;
int cubepos=1;
//yazi
int yatay=320;
int yatay2=0;
char scrol[]="*** - Classic intro - ***";

int satir=170;
unsigned char asagi=0;
int satirm=50;
unsigned char asagim=1;
const float FPS = 60;

SDL_Event event;
SDL_Renderer *renderer;
SDL_Renderer *rendererVirt;

SDL_Window *window;


void yildiz() {
    for (i=1;i<=50;i++)	{
	stx[i]=rand()%W;	sty[i]=rand()%H;
	stax[i]=rand()%W;	stay[i]=rand()%H;
	starx[i]=rand()%W;	stary[i]=rand()%H;
	}
}

void bkgr_star() {
    for (i=1;i<=100;i++)	{
	stfix[i]=rand()%W;	stfiy[i]=rand()%H;
	}
}


void bkrground() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
    for (i=1;i<=290;i++)	{
		SDL_RenderDrawPoint(renderer, stfix[i], stfiy[i]);
	}
}

void yildiz_kaydir() {
    for (i=1;i<=50;i++)	{
		
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
		stx[i]--; if (stx[i]<1) stx[i]=W;
		SDL_RenderDrawPoint(renderer, stx[i], sty[i]);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);

		stax[i]=stax[i]-2; if (stax[i]<2) stax[i]=W;
		SDL_RenderDrawPoint(renderer, stax[i],stay[i] );

		starx[i]=starx[i]-3;if (starx[i]<3) starx[i]=W;
		SDL_RenderDrawPoint(renderer, starx[i],stary[i]);
	}
}

void anaveri() {
  q[0] = 1;  p[0] = 2;  q[1] = 2;  p[1] = 3;
  q[2] = 3;  p[2] = 4;  q[3] = 4;  p[3] = 1;
  q[4] = 5;  p[4] = 6;  q[5] = 6;  p[5] = 7;
  q[6] = 7;  p[6] = 8;  q[7] = 8;  p[7] = 5;
  q[8] = 1;  p[8] = 5;  q[9] = 2;  p[9] = 6;
  q[10] = 3;  p[10] = 7;  q[11] = 4;  p[11] = 8;
}

void dikdortgen() {
  a[0][0] = 1.0;  a[0][1] = 1.0;  a[0][2] = 1.0;
  a[1][0] = -1.0;  a[1][1] = 1.0;  a[1][2] = 1.0;
  a[2][0] = -1.0;  a[2][1] = 1.0;  a[2][2] = -1.0;
  a[3][0] = 1.0;  a[3][1] = 1.0;  a[3][2] = -1.0;
  a[4][0] = 1.0;  a[4][1] = -1.0;  a[4][2] = 1.0;
  a[5][0] = -1.0;  a[5][1] = -1.0;  a[5][2] = 1.0;
  a[6][0] = -1.0;  a[6][1] = -1.0;  a[6][2] = -1.0;
  a[7][0] = 1.0;  a[7][1] = -1.0;  a[7][2] = -1.0;
}

void kup_ciz() {
    dikdortgen();
    if (cubels>100) cubepos=-1;
	if (cubels<50) cubepos=1;		
	
	cubels=cubels+cubepos;
	
    dy=22.0/7*en/180;
    dx=22.0/7*boy/180;

    for(t=1;t<=8;t++) {
      x=a[t-1][0];
      y=a[t-1][1];
      z=a[t-1][2];
      a[t-1][0]=x*cos(dy)+z*sin(dy);
      k=z*cos(dy)-x*sin(dy);
      a[t-1][1]=y*cos(dx)+k*sin(dx);
    }

    for (t=1;t<=12;t++) {
      m=300+a[q[t-1]-1][0]*cubels; n=200+a[q[t-1]-1][1]*cubels;
      g=300+a[p[t-1]-1][0]*cubels; h=200+a[p[t-1]-1][1]*cubels;
      SDL_RenderDrawLine(renderer, (int)m, (int)n, (int)g, (int)h);
	}
    
	en++;
	boy++;
}

void k_barciz() {
	//kirmizi bar ciz
	 for (i=1;i<36;i++){
		SDL_SetRenderDrawColor(renderer, 255, i+5, i+5+76, i+76);
		SDL_RenderDrawLine(renderer, 0, satir+i, W, satir+i);
	}
	 
	 if ( (satir<40) && (asagi==0) ) asagi=1;
	 if ( (satir>350) && (asagi==1) ) asagi=0;
	 if (asagi==1) satir++; else satir--;
}

void m_barciz() {
	//mavi bar ciz
	for (i=1;i<36;i++){
	    SDL_SetRenderDrawColor(renderer, i+5+186, i+5+126, i+5+76, i+76);
		SDL_RenderDrawLine(renderer, 0, satirm+i, W, satirm+i);
	}
 
	if ( (satirm<40) && (asagim==0) ) asagim=1;
	if ( (satirm>450) && (asagim==1) ) asagim=0;
	if (asagim==1) satirm++; else satirm--;
}

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(W, H, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
	
	for (i = 0; i < W; ++i)
		SDL_RenderDrawPoint(renderer, i, i);
    
	anaveri();
	yildiz();
	bkgr_star();
	
	SDL_RenderPresent(renderer);
    while (1) {		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		bkrground();
		yildiz_kaydir();
		k_barciz();
		m_barciz();
		kup_ciz();
		SDL_RenderPresent(renderer);
		SDL_Delay(50);
		
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyRenderer(rendererVirt);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}

