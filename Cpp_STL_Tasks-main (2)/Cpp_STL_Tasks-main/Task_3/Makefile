all: all.out
all.out : test.o collection_test.o point.o collection.o 
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
collection_test.o: collection_test.cc collection.h point.h 
	g++ $< -c
test.o : test.cc collection.h point.h 
	g++ $< -c
collection.o : collection.cc collection.h point.h  
	g++ $< -c   
point.o : point.cc collection.h point.h 
	g++ $< -c
clean:
	rm -rf *.o *.out
