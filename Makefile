# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iinclude -Wall -std=c++11

# MySQL library
LDFLAGS = -lmysqlclient

# Source files
SRCS = main.cpp src/classe.cpp src/database.cpp src/etudiant.cpp src/login.cpp src/matiere.cpp src/note.cpp src/personne.cpp src/professeur.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = student_manager

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
