CC = g++
CFLAGS = -c -Wall -Wextra -Werror
LDLIBS = -lm
EXECUTABLE = mathLib.o
OBJECT = mathLib.cpp
DIRECTORY = ../ivs_makefile # toto sa zmeni potom ked sa to bude odovzdavat
ZIP = xlogin01_xlogin02_xlogin03_xlogin04.zip
FOLDERS = CMakeFiles html latex
SINGLE_FILE = cmake_install.cmake CMakeCache.txt Makefile runTests doc.doxygen

# prelozenie profilingu
# run - spustenie programu
# profile - spustenie profilingu

$(EXECUTABLE): $(OBJECT)
	$(CC) $(CFLAGS) $(OBJECT) $(LDLIBS)

all: $(EXECUTABLE)

pack:
	zip -r $(ZIP) $(DIRECTORY)

test: tests.cpp
	cmake CMakeLists.txt && make -f Makefile && ./runTests

doc: 
	doxygen -g doc.doxygen && doxygen doc.doxygen

clean:
	rm -f $(EXECUTABLE)
	rm -f $(SINGLE_FILE)
	rm -rf $(FOLDERS)
	rm -rf $(ZIP)
	