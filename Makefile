CXX = $(shell wx-config --cxx)

PROGRAM = organizer

OBJECTS = gui/MyProjectBase.o src/$(PROGRAM).o

# implementation

.SUFFIXES:      .o .cpp

.cpp.o :
	$(CXX) -c `wx-config --cxxflags` -o $@ $<

all:    $(PROGRAM)

$(PROGRAM):     $(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS) `wx-config --libs` `pkg-config nlohmann_json --cflags`

clean:
	rm -f src/*.o $(PROGRAM)
	rm -f gui/*.o
