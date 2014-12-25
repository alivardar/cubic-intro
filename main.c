/*******************************************************/
/*  M.Ali VARDAR 2004 Classic intro for linux          */
/*  Kayan yildiz, kup dondurme, basit scroll yazi      */
/*  Font kullanimi, scroll bar, palet kullanimi        */
/*  Sadece svgalib kullanildi. mcedit ile yazildi.     */
/*  GPL Lisansi ile dagitilabilir.                     */
/*  1993-1995 yillarinda yazdigim basit pascal ve      */
/*  assembly introlarindan ceviridir.                  */
/* M.Ali VARDAR ali at linuxprogramlama.com 17/09/2004 */
/*******************************************************/

#define W 320
#define H 200
#define MODE G320x200x256
#define FONT_HEIGHT  8
#define FONT_WIDTH   8

#include <stdlib.h>
#include <vga.h>
#include <vgagl.h>
#include <vgakeyboard.h>

GraphicsContext *physicalscreen;
GraphicsContext *virtualscreen;

int i;
//yildizlar
int stx[30]={};
int sty[30]={};
int stax[30]={};
int stay[30]={};
int starx[30]={};
int stary[30]={};
//kup
double a[8][3];
int q[12], p[12];
double dy, dx, en, boy;
int t;
double x, y, z, k, m, n, h, g;
//yazi
int yatay=320;
int yatay2=0;
char scrol[]="*** - Classic intro - ***";

int satir=170;
unsigned char asagi=0;
int satirm=30;
unsigned char asagim=1;


/******************************************/
/*
unsigned char font_yeni[2048] =
{
	124,130,186,162,186,130,124,0,
	126,129,165,129,165,153,129,126,
	126,129,165,129,153,165,129,126,108,246,246,254,124,56,16,0,
	16,56,124,254,124,56,16,0,16,56,84,254,84,16,56,0,
	56,124,254,254,108,16,56,0,16,24,20,20,48,112,96,0,
	254,254,254,238,254,254,254,0,236,138,138,170,170,170,236,0,
	142,136,136,140,136,136,232,0,174,170,170,234,170,170,174,0,
	238,136,136,204,136,136,136,0,238,138,138,142,140,138,234,0,
	62,34,62,34,102,238,204,0,16,84,40,198,40,84,16,0,
	240,248,252,254,252,248,240,0,30,62,126,254,126,62,30,0,
	16,56,124,16,124,56,16,0,238,238,238,238,238,0,238,0,
	254,68,68,68,68,68,68,0,126,128,188,198,122,2,252,0,
	0,0,0,0,255,255,0,0,16,56,124,16,124,56,16,254,
	16,56,124,254,56,56,56,0,56,56,56,254,124,56,16,0,
	16,24,252,254,252,24,16,0,16,48,126,254,126,48,16,0,
	144,72,36,18,36,72,144,0,18,36,72,144,72,36,18,0,
	16,40,68,146,40,68,130,0,130,68,40,146,68,40,16,0,
	0,0,0,0,0,0,0,0,16,16,16,16,16,0,16,0,
	40,40,40,0,0,0,0,0,68,254,68,68,68,254,68,0,
	16,126,144,124,18,252,16,0,66,164,72,16,36,74,132,0,
	56,68,56,112,138,132,122,0,16,16,32,0,0,0,0,0,
	8,16,16,16,16,16,8,0,32,16,16,16,16,16,32,0,
	16,84,56,254,56,84,16,0,16,16,16,254,16,16,16,0,
	0,0,0,0,0,16,16,32,0,0,0,254,0,0,0,0,
	0,0,0,0,0,0,16,0,2,4,8,16,32,64,128,0,
	124,130,130,130,130,130,124,0,240,16,16,16,16,16,254,0,
	252,2,2,124,128,128,254,0,252,2,2,28,2,2,252,0,
	130,130,130,126,2,2,2,0,254,128,252,2,2,2,252,0,
	126,128,252,130,130,130,124,0,252,2,2,2,2,2,2,0,
	124,130,130,124,130,130,124,0,126,130,130,126,2,2,252,0,
	0,0,0,16,0,0,16,0,0,0,0,16,0,0,16,32,
	8,16,32,64,32,16,8,0,0,0,0,254,0,254,0,0,
	64,32,16,8,16,32,64,0,56,68,4,8,16,0,16,0,
	60,66,154,170,156,64,62,0,124,130,130,254,130,130,130,0,
	252,130,130,252,130,130,252,0,124,130,128,128,128,130,124,0,
	252,130,130,130,130,130,252,0,254,128,128,240,128,128,254,0,
	254,128,128,240,128,128,128,0,124,130,128,142,130,130,124,0,
	130,130,130,254,130,130,130,0,254,16,16,16,16,16,254,0,
	62,2,2,2,130,130,124,0,130,132,136,240,136,132,130,0,
	128,128,128,128,128,128,254,0,252,146,146,146,146,146,146,0,
	130,194,162,146,138,134,130,0,124,130,130,130,130,130,124,0,
	252,130,130,252,128,128,128,0,124,130,130,130,138,134,126,0,
	252,130,130,252,130,130,130,0,126,128,128,124,2,2,252,0,
	254,16,16,16,16,16,16,0,130,130,130,130,130,130,124,0,
	130,130,68,68,40,40,16,0,130,130,130,146,146,146,108,0,
	130,68,40,16,40,68,130,0,130,130,130,126,2,2,252,0,
	254,4,8,16,32,64,254,0,56,32,32,32,32,32,56,0,
	128,64,32,16,8,4,2,0,56,8,8,8,8,8,56,0,
	16,40,68,130,0,0,0,0,0,0,0,0,0,0,0,255,
	32,32,16,0,0,0,0,0,0,0,56,68,124,68,68,0,
	0,0,120,68,120,68,120,0,0,0,60,64,64,64,60,0,
	0,0,120,68,68,68,120,0,0,0,124,64,112,64,124,0,
	0,0,124,64,112,64,64,0,0,0,60,64,76,68,60,0,
	0,0,68,68,124,68,68,0,0,0,124,16,16,16,124,0,
	0,0,28,4,4,68,56,0,0,0,68,72,112,72,68,0,
	0,0,64,64,64,64,124,0,0,0,120,84,84,84,84,0,
	0,0,120,68,68,68,68,0,0,0,56,68,68,68,56,0,
	0,0,120,68,120,64,64,0,0,0,56,68,68,76,54,0,
	0,0,120,68,120,68,68,0,0,0,60,64,56,4,120,0,
	0,0,124,16,16,16,16,0,0,0,68,68,68,68,56,0,
	0,0,68,68,40,40,16,0,0,0,68,68,84,108,68,0,
	0,0,68,40,16,40,68,0,0,0,68,68,60,4,120,0,
	0,0,124,8,16,32,124,0,8,16,16,32,16,16,8,0,
	16,16,16,0,16,16,16,0,32,16,16,8,16,16,32,0,
	80,40,0,0,0,0,0,0,0,16,40,68,130,130,254,0,
	254,254,254,254,254,254,254,0,0,0,0,0,0,254,254,0,
	0,0,124,124,124,124,124,0,0,0,0,0,0,0,124,0,
	128,128,128,128,128,128,128,0,0,64,64,64,64,64,64,0,
	16,24,28,30,28,24,16,0,16,48,112,240,112,48,16,0,
	62,30,30,62,114,224,64,0,4,14,156,248,240,240,248,0,
	64,224,114,62,30,30,62,0,248,240,240,248,156,14,4,0,
	56,68,130,130,130,68,56,0,56,124,254,254,254,124,56,0,
	0,124,68,68,68,124,0,0,0,124,124,124,124,124,0,0,
	0,60,110,126,112,126,60,0,0,60,118,126,14,126,60,0,
	0,60,126,106,126,126,106,0,0,60,126,86,126,126,86,0,
	0,0,0,24,24,0,0,0,0,0,24,60,60,24,0,0,
	0,12,52,36,36,108,72,0,0,0,0,0,0,0,0,0,
	60,126,198,231,255,224,126,60,60,126,227,231,255,7,126,60,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,52,118,118,94,126,60,0,0,60,110,126,112,126,60,0,
	0,60,126,122,110,110,44,0,0,60,126,14,126,118,60,0,
	0,0,0,0,0,0,0,0,126,126,126,126,60,0,0,0,
	0,15,31,31,31,31,15,0,126,127,127,127,127,127,63,0,
	0,0,0,60,126,126,126,126,126,126,126,126,126,126,126,126,
	0,63,127,127,127,127,127,126,126,127,127,127,127,127,127,126,
	0,240,248,248,248,248,240,0,126,254,254,254,254,254,252,0,
	0,255,255,255,255,255,255,0,126,255,255,255,255,255,255,0,
	0,252,254,254,254,254,254,126,126,254,254,254,254,254,254,126,
	0,255,255,255,255,255,255,126,126,255,255,255,255,255,255,126,
	0,0,63,63,48,55,52,52,0,0,255,255,0,255,0,0,
	0,0,248,248,24,216,88,88,88,88,88,88,88,88,88,88,
	88,216,24,248,248,0,0,0,0,255,0,255,255,0,0,0,
	52,55,48,63,63,0,0,0,52,52,52,52,52,52,52,52,
	0,0,0,31,24,24,24,24,0,0,0,255,0,0,0,0,
	0,0,0,240,48,48,48,48,48,48,48,48,48,48,48,48,
	48,48,48,240,0,0,0,0,0,0,0,255,0,0,0,0,
	24,24,24,31,0,0,0,0,24,24,24,24,24,24,24,24,
	136,34,136,34,136,34,136,34,85,170,85,170,85,170,85,170,
	68,170,68,170,68,170,68,170,51,102,204,153,51,102,204,153,
	204,102,51,153,204,102,51,153,199,143,31,62,124,248,241,227,
	227,241,248,124,62,31,143,199,174,128,186,2,234,8,171,32,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
*/
/*****************************************************/
void yildiz()
{
    for (i=1;i<=30;i++)	{
	stx[i]=random()%200;	sty[i]=random()%320;
	stax[i]=random()%200;	stay[i]=random()%320;
	starx[i]=random()%200;	stary[i]=random()%320;
	}
}

void yildiz_kaydir()
{
    for (i=1;i<=30;i++)	{
    	vga_setcolor(100); 
	stx[i]--; if (stx[i]<1) stx[i]=320;
	vga_drawpixel(stx[i], sty[i]);
	stax[i]=stax[i]-2; if (stax[i]<2) stax[i]=320;
	vga_drawpixel(stax[i],stay[i]);
	starx[i]=starx[i]-3;if (starx[i]<3) starx[i]=320;
	vga_drawpixel(starx[i],stary[i]);
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

    vga_setcolor(150);    
    for (t=1;t<=12;t++) {
      m=150+a[q[t-1]-1][0]; n=100+a[q[t-1]-1][1];
      g=150+a[p[t-1]-1][0]; h=100+a[p[t-1]-1][1];
      vga_drawline((int)m, (int)n, (int)g, (int)h);
    }
    en++; boy++;
}
/*-------------------------------------------------------*/

void prepare_font(void)  {
   void *font = malloc(256 * FONT_WIDTH * FONT_HEIGHT * BYTESPERPIXEL);
   gl_expandfont(FONT_WIDTH, FONT_HEIGHT, 15/*buasi renk*/, gl_font8x8, font);   
   gl_setfont(FONT_WIDTH, FONT_HEIGHT, font);
   //gl_expandfont(FONT_WIDTH, FONT_HEIGHT, color, font_yeni, font);
   //kendi fontunuzu bu sekilde ekleyebilrisniz
}
/*-------------------------------------------------------*/
void init_colormap() {
  int r=64;  int g=64;  int b=64;
//kirmizi barrenkleri hazir
  for (i=64;i<76;i++) { vga_setpalette (i, r>>2, 0, 0); r=r+8; }
//mavi barrenkleri hazir
  for (i=76;i<88;i++) { vga_setpalette (i, 0, 0, b>>2); b=b+8; }  
//yesil barrenkleri hazir
  for (i=88;i<100;i++) { vga_setpalette (i, 0, g>>2, 0); g=g+8; }  
}
/*-------------------------------------------------------*/
void k_barciz() {
//kirmizi bar ciz
 for (i=1;i<12;i++){vga_setcolor(i+63); vga_drawline( 0, satir+i, 319, satir+i); }
 if ( (satir<40) && (asagi==0) ) asagi=1;
 if ( (satir>150) && (asagi==1) ) asagi=0;
 if (asagi==1) satir++; else satir--;
}

void m_barciz() {
//mavi bar ciz
 for (i=1;i<12;i++){vga_setcolor(i+76); vga_drawline( 0, satirm+i, 319, satirm+i); }
 if ( (satirm<40) && (asagim==0) ) asagim=1;
 if ( (satirm>150) && (asagim==1) ) asagim=0;
 if (asagim==1) satirm++; else satirm--;
}

/*-------------------------------------------------------*/
int main () {
  vga_init();
  vga_setmode(MODE);
  gl_setcontextvga(MODE);
  prepare_font();

  physicalscreen = gl_allocatecontext();
  gl_getcontext(physicalscreen);
  gl_setcontextvgavirtual(MODE);

  virtualscreen = gl_allocatecontext();
  gl_getcontext(virtualscreen);
  gl_setcontext(virtualscreen);

  init_colormap();
  anaveri();
  yildiz();
 
for (;;){   
    switch (vga_getkey()) { case 27:  vga_setmode(TEXT); exit(0); }

    yildiz_kaydir();
    k_barciz();
    kup_ciz();
    vga_setcolor(96);
    gl_write(yatay--, 100, scrol);
    gl_write(290, 190, "mav");
    m_barciz();
    vga_waitretrace();
    vga_waitretrace ();      
    gl_copyscreen(physicalscreen);
    }
}
/*-------------------------------------------------------*/
