eztest: test.cpp eztimer.cpp
	gcc -g -o $@ $^ -lrt
clean:
	rm -f *.o eztest
run:
	./eztest
	
