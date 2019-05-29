CXX = g++

SRC_DIR=src
BINDIR=bin
INCLUDEDIR=include

SRC_DIR_ARCHI=$(SRC_DIR)/deeplearn/archi
SRC_DIR_TRAIN=$(SRC_DIR)/deeplearn/train
SRC_DIR_IHM=$(SRC_DIR)/ihm
SRC_DIR_PRETRAIT=$(SRC_DIR)/pretraitement

SRC= $(wildcard $(SRC_DIR)/*.cpp) \
$(wildcard $(SRC_DIR_IHM)/*.cpp) \
$(wildcard $(SRC_DIR_ARCHI)/*.cpp) \
$(wildcard $(SRC_DIR_TRAIN)/*.cpp) \
$(wildcard $(SRC_DIR_PRETRAIT)/*.cpp)

OBJ= $(SRC:.cpp=.o)

CXXFLAGS=-Wall -pedantic -I$(INCLUDEDIR)
LDFLAGS=
GTKMFLAG=`pkg-config gtkmm-3.0 --cflags --libs`
MAGICKFLAG=`Magick++-config --ldflags --libs`

EXEC=GestionRN

all : $(BINDIR)/$(EXEC)

$(BINDIR)/GestionRN : $(OBJ)
	$(CXX) -o $@ $^ $(GTKMFLAG) $(MAGICKFLAG)

$(SRC_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS) $(GTKMFLAG) $(MAGICKFLAG)

$(SRC_DIR_ARCHI)/%.o : $(SRC_DIR_ARCHI)/%.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

$(SRC_DIR_TRAIN)/%.o : $(SRC_DIR_TRAIN)/%.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

$(SRC_DIR_PRETRAIT)/%.o : $(SRC_DIR_PRETRAIT)/%.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS) $(MAGICKFLAG)

$(SRC_DIR_IHM)/%.o : $(SRC_DIR_IHM)/%.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS) $(GTKMFLAG)

clean :
	rm $(SRC_DIR_IHM)/*.o
	rm $(SRC_DIR_ARCHI)/*.o
	rm $(SRC_DIR_TRAIN)/*.o
	rm $(SRC_DIR_PRETRAIT)/*.o
	rm $(BINDIR)/*
