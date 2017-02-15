all:
	gcc -g copy.c -o copy -I ../lib -L ../lib -lluspm
	gcc -g seek_io.c -o seek_io -I ../lib -L ../lib -lluspm
	gcc -g large_file.c -o large_file -I ../lib -L ../lib -lluspm

clean:
	rm -f copy seek_io large_file
