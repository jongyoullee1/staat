compile: info.o
	gcc -o info.out info.o

stat.o: info.c
	gcc -c info.c

run: info.out
	./info.out

clean:
	rm *.out
	rm *.o
