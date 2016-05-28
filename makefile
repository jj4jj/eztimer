eztest: test.cpp eztimer.cpp
	gcc -g -o $@ $^ -lrt -Wall --std=c++11
clean:
	rm -f *.o eztest
run:
	./eztest
	
