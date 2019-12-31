/***************************************************************/
/*  M.Ali VARDAR 2004 Classic intro for win and linux sdl2 */
/***************************************************************/

//ggcc -IC:\MinGW\include -IC:\MinGW\include\SDL2 -LC:\MinGW\lib -static -o cubic-sdl cubic-sdl.c  -lm -lSDL2

#define W 320
#define H 200
#define FONT_HEIGHT  8
#define FONT_WIDTH   8

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
//kup
double a[8][3];
int q[12], p[12];
double dy, dx, en, boy;
int t;
int x, y, z, k, m, n, h, g;
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


#define WINDOW_WIDTH 600

void yildiz()
{
    for (i=1;i<=50;i++)	{
	stx[i]=rand()%600;	sty[i]=rand()%600;
	stax[i]=rand()%600;	stay[i]=rand()%600;
	starx[i]=rand()%600;	stary[i]=rand()%600;
	}
}

void yildiz_kaydir()
{
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (i=1;i<=50;i++)	{
		
		stx[i]--; if (stx[i]<1) stx[i]=600;
		SDL_RenderDrawPoint(renderer, stx[i], sty[i]);
	
		stax[i]=stax[i]-2; if (stax[i]<2) stax[i]=600;
		SDL_RenderDrawPoint(renderer, stax[i],stay[i] );

		
		starx[i]=starx[i]-3;if (starx[i]<3) starx[i]=600;
		SDL_RenderDrawPoint(renderer, starx[i],stary[i]);
		
	}
}
/*-------------------------------------------------------*/
void anaveri()
{
  q[0] = 1;  p[0] = 2;  q[1] = 2;  p[1] = 3;
  q[2] = 3;  p[2] = 4;  q[3] = 4;  p[3] = 1;
  q[4] = 5;  p[4] = 6;  q[5] = 6;  p[5] = 7;
  q[6] = 7;  p[6] = 8;  q[7] = 8;  p[7] = 5;
  q[8] = 1;  p[8] = 5;  q[9] = 2;  p[9] = 6;
  q[10] = 3;  p[10] = 7;  q[11] = 4;  p[11] = 8;
}

void dikdortgen()
{
  a[0][0] = 40.0;  a[0][1] = 40.0;  a[0][2] = 40.0;
  a[1][0] = -40.0;  a[1][1] = 40.0;  a[1][2] = 40.0;
  a[2][0] = -40.0;  a[2][1] = 40.0;  a[2][2] = -40.0;
  a[3][0] = 40.0;  a[3][1] = 40.0;  a[3][2] = -40.0;
  a[4][0] = 40.0;  a[4][1] = -40.0;  a[4][2] = 40.0;
  a[5][0] = -40.0;  a[5][1] = -40.0;  a[5][2] = 40.0;
  a[6][0] = -40.0;  a[6][1] = -40.0;  a[6][2] = -40.0;
  a[7][0] = 40.0;  a[7][1] = -40.0;  a[7][2] = -40.0;
}

void kup_ciz()
{
    dikdortgen();
    
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

    //vga_setcolor(150);    
    for (t=1;t<=12;t++) {
      m=150+a[q[t-1]-1][0]; n=100+a[q[t-1]-1][1];
      g=150+a[p[t-1]-1][0]; h=100+a[p[t-1]-1][1];
      //vga_drawline((int)m, (int)n, (int)g, (int)h);
	  //al_draw_line((int)m, (int)n, (int)g, (int)h, al_map_rgb(255,0,0), 5);
	}
    en++; boy++;
}
/*-------------------------------------------------------*/

void init_colormap() {
	int r=64;  int g=64;  int b=64;
	//kirmizi barrenkleri hazir
	//for (i=64;i<76;i++) { vga_setpalette (i, r>>2, 0, 0); r=r+8; }
	//mavi barrenkleri hazir
	//for (i=76;i<88;i++) { vga_setpalette (i, 0, 0, b>>2); b=b+8; }  
	//yesil barrenkleri hazir
	//for (i=88;i<100;i++) { vga_setpalette (i, 0, g>>2, 0); g=g+8; }  
}

/*-------------------------------------------------------*/

void k_barciz() {
	//kirmizi bar ciz
	 for (i=1;i<12;i++){
		//vga_setcolor(i+63); 
		//vga_drawline( 0, satir+i, 319, satir+i); 
		//al_draw_line( 0, satir+i, 319, satir+i, al_map_rgb(255,255,0), 1);
	}
	 
	 if ( (satir<40) && (asagi==0) ) asagi=1;
	 if ( (satir>150) && (asagi==1) ) asagi=0;
	 if (asagi==1) satir++; else satir--;
}

void m_barciz() {
	//mavi bar ciz
	for (i=1;i<12;i++){
		//vga_setcolor(i+76); 
		//vga_drawline( 0, satirm+i, 319, satirm+i); 
		//al_draw_line(  0, satirm+i, 319, satirm+i, al_map_rgb(255,255,0), 2);
	}
 
	if ( (satirm<40) && (asagim==0) ) asagim=1;
	if ( (satirm>150) && (asagim==1) ) asagim=0;
	if (asagim==1) satirm++; else satirm--;
}


int main(int argc, char *argv[])
{

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    
	for (i = 0; i < WINDOW_WIDTH; ++i)
        SDL_RenderDrawPoint(renderer, i, i);
    
	yildiz();
	
	SDL_RenderPresent(renderer);
    while (1) {
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		 SDL_RenderClear(renderer);

		yildiz_kaydir();
		SDL_RenderPresent(renderer);
		
		SDL_Delay(100);
		
		
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyRenderer(rendererVirt);

    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;

}

