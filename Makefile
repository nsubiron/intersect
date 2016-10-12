CXX=g++
CFLAGS=-Wall -Wextra -std=c++11
LFLAGS=-Wall -Wextra

SOURCES=Distance.cpp Intersector.cpp Shapes.cpp Vector2D.cpp main.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

intersect: $(OBJECTS)
	$(CXX) $(LFLAGS) -o intersect $(OBJECTS)

clean:
	rm -f $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $<
