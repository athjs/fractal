# Variables de compilation
CXX = arch -x86_64 g++
CXXFLAGS = -std=c++17 -I/usr/local/Cellar/sfml/3.0.0/include/SFML
LDFLAGS = -L/usr/local/Cellar/sfml/3.0.0/lib -lsfml-graphics -lsfml-window -lsfml-system
SOURCES = test.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXEC = prog

# Règle par défaut
all: $(EXEC)

# Création de l'exécutable
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC) $(LDFLAGS)

# Compilation des fichiers sources
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers générés
clean:
	rm -f $(OBJECTS) $(EXEC)

# Nettoyage complet
fclean: clean
	rm -f $(EXEC)

# Règle pour recompiler tout
re: fclean all
