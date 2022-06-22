#--------------------------------------------------------
SOURCE   = main.cpp car.cpp terrain.cpp
CMP      = clang
OBJ      = $(SOURCE:.cpp=.o)
LIBS     = -lSOIL -framework Foundation -framework OpenGL -framework GLUT
CXXINCS  = -I.
BIN      = car_scene
OPTIM		 = -O2 -Wall
CXXFLAGS = $(CXXINCS) $(OPTIM)
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

%.o: %.cpp
	$(CMP) $(CXXFLAGS) -c -o $@ $<

all:	all-before $(BIN) all-after

$(BIN): $(OBJ)
	#$(SOURCE)
	$(CMP) -o $(BIN) $(OBJ) $(LIBS)

clean: clean-custom
	$(RM) $(OBJ) $(BIN)
#--------------------------------------------------------
