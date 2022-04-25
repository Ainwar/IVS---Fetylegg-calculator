CC = g++
CFLAGS = -c -Wall -Wextra -Werror
LDLIBS = -lm
EXECUTABLE = mathLib.o
OBJECT = mathLib.cpp
DIRECTORY = ../ivs_makefile # toto sa zmeni potom ked sa to bude odovzdavat
ZIP = xbartl07_xsulga02_xtabim01_xpazde16.zip
FOLDERS = CMakeFiles html latex
SINGLE_FILE = cmake_install.cmake CMakeCache.txt Makefile runTests Doxyfile.doxygen

# prelozenie GUI
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
	doxygen Doxyfile.doxygen

clean:
	rm -f $(EXECUTABLE)
	rm -f $(SINGLE_FILE)
	rm -rf $(FOLDERS)
	rm -rf $(ZIP)
	
