all:
	gcc -g mem_segments.c -o ms -I ../lib/ -L ../lib/ -lluspm
	gcc -g necho.c -o ne -I ../lib/ -L ../lib/ -lluspm
	gcc -g display_env.c -o de -I ../lib/ -L ../lib/ -lluspm
	gcc -g modify_env.c -o me -I ../lib/ -L ../lib/ -lluspm
	gcc -g longjmp.c -o l -I ../lib/ -L ../lib/ -lluspm
	gcc -g setjmp_vars.c -o sv -I ../lib/ -L ../lib/ -lluspm

clean:
	rm -f ms ne de me l sv
