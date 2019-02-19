all: forks.c 
	gcc forks.c -o fork 

run: 
	./fork

clean: 
	rm fork
