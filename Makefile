
all:	cubic-svgalib cubic-allegro

cubic-svgalib:	cubic-svgalib.c
	gcc -w -Wall -o cubic-svgalib cubic-svgalib.c -lm -lvga -lvgagl

cubic-svgalib.o:		cubic-svgalib.c

cubic-allegro: cubic-allegro.c 
	gcc -w -Wall -o cubic-allegro cubic-allegro.c -lm -lallegro


clean:		
	rm -rf cubic-allegro cubic-svgalib
	rm -rf cubic-allegro.o cubic-svgalib.o
	
final: cubic-svgalib
	gzip --best -f cubic-svgalib
	cat unpack.header cubicsvgalib.gz > Cubic
	rm cubic.gz
	chmod a+rx Cubic
	ls -l Cubic