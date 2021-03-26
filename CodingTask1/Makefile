#the following statement uses wildcard function to get all cpp files and 
#replace .cpp with .o to create a space seperated list of object files.
#the object files are thus put as dependency that will be met by Make
#without further scripting to compile.
OBJECTS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

#CC = g++

CFLAGS=-fPIC

%.o: %.cpp 
	$(CXX) $(CFLAGS) -c -o $@ $<

all: LinuxCLISample 

clean:
	rm -Rf *.o
	rm -Rf LinuxCLISample 


LinuxCLISample: $(OBJECTS)
	$(CXX) *.o -o $@

