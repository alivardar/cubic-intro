/***************************************************************/
/*  M.Ali VARDAR 2004 Classic intro for win and linux sdl2 */
/***************************************************************/

//ggcc -IC:\MinGW\include -IC:\MinGW\include\SDL2 -LC:\MinGW\lib -static -o cubic-sdl cubic-sdl.c  -lm -lSDL2

#define W 320
#define H 200
#define FONT_HEIGHT  8
#define FONT_WIDTH   8


#include <stdio.h>
#include  <stdlib.h>
#include  <time.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>


int i;
//yildizlar
float stx[30]={};
float sty[30]={};
float stax[30]={};
float stay[30]={};
float starx[30]={};
float stary[30]={};
//kup
double a[8][3];
int q[12], p[12];
double dy, dx, en, boy;
int t;
float x, y, z, k, m, n, h, g;
//yazi
int yatay=320;
int yatay2=0;
char scrol[]="*** - Classic intro - ***";

int satir=170;
unsigned char asagi=0;
int satirm=30;
unsigned char asagim=1;


const float FPS = 60;



void yildiz()
{
    for (i=1;i<=30;i++)	{
	stx[i]=rand()%200;	sty[i]=rand()%320;
	stax[i]=rand()%200;	stay[i]=rand()%320;
	starx[i]=rand()%200;	stary[i]=rand()%320;
	}
}

void yildiz_kaydir()
{
    for (i=1;i<=30;i++)	{
		//vga_setcolor(100); 
		stx[i]--; if (stx[i]<1) stx[i]=320;
		//vga_drawpixel(stx[i], sty[i]);
		al_draw_pixel(stx[i], sty[i], al_color_name("antiquewhite") );
	
		stax[i]=stax[i]-2; if (stax[i]<2) stax[i]=320;
		//vga_drawpixel(stax[i],stay[i]);
		al_draw_pixel(stax[i], stay[i], al_color_name("antiquewhite"));
		
		starx[i]=starx[i]-3;if (starx[i]<3) starx[i]=320;
		//vga_drawpixel(starx[i],stary[i]);
		al_draw_pixel(starx[i], stary[i], al_color_name("antiquewhite"));
		
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
	  al_draw_line((int)m, (int)n, (int)g, (int)h, al_map_rgb(255,0,0), 5);
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
		al_draw_line( 0, satir+i, 319, satir+i, al_map_rgb(255,255,0), 1);
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
		al_draw_line(  0, satirm+i, 319, satirm+i, al_map_rgb(255,255,0), 2);
	}
 
	if ( (satirm<40) && (asagim==0) ) asagim=1;
	if ( (satirm>150) && (asagim==1) ) asagim=0;
	if (asagim==1) satirm++; else satirm--;
}


int main(int argc, char *argv[])
{
	ALLEGRO_DISPLAY *display = NULL;
	
	bool running = true;
	bool redraw = true;

	// Initialize allegro
	if (!al_init()) {
		fprintf(stderr, "Failed to initialize allegro.\n");
		return 1;
	}

	
	// Create the display
	display = al_create_display(320, 240);
	if (!display) {
		fprintf(stderr, "Failed to create display.\n");
		return 1;
	}

	// Display a black screen
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();

fprintf(stdout, "N1\n");

	// Game loop
	while (running) {

fprintf(stdout, "N2\n");

		al_clear_to_color(al_map_rgb(0,0,0));
		anaveri();
fprintf(stdout, "N3\n");
		kup_ciz();
fprintf(stdout, "N4\n");		
		k_barciz();
fprintf(stdout, "N5\n");


		yildiz();		
		al_flip_display();
		yildiz_kaydir();
		m_barciz();		
		
fprintf(stdout, "N4\n");		
		al_flip_display();
		al_rest(1.0);

		fprintf(stdout, "N1\n");
	
	} 

	fprintf(stdout, "Normal quit");

	// Clean up
	al_destroy_display(display);

	return 0;
}

