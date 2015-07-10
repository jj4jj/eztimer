eztest: test.cpp eztimer.cpp
	gcc -g -o $@ $^
clean:
	rm -f *.o eztest
run:
	./eztest
	
