
all:     cubic

cubic:	main.c
	gcc -w -Wall -o cubic main.c -I/usr/local/include -I/usr/include -L/usr/local/lib/ -L/usr/lib -lvga -lvgagl

main.o:		main.c

clean:		
	rm -rf cubic
	rm -rf cubic.o
	

final: cubic
	gzip --best -f cubic
	cat unpack.header cubic.gz > Cubic
	rm cubic.gz
	chmod a+rx Cubic
	ls -l Cubic