CC = g++
CFLAGS = -c -Werror
LDLIBS = -lm
EXECUTABLE = mathLib.o
OBJECT = mathLib.cpp
DIRECTORY =  IVS---Fetylegg-calculator
ZIP = xbartl07_xsulga02_xtabim01_xpazde16.zip
FOLDERS = CMakeFiles html latex
SINGLE_FILE = cmake_install.cmake CMakeCache.txt Makefile runTests

# prelozenie profilingu
# run - spustenie programu
# profile - spustenie profilingu

$(EXECUTABLE): $(OBJECT)
	$(CC) $(CFLAGS) $(OBJECT) $(LDLIBS) -o $(EXECUTABLE)

all: $(EXECUTABLE)

pack:
	zip -r $(ZIP) $(DIRECTORY)

test: tests.cpp
	cmake CMakeLists.txt && make -f Makefile && ./runTests

doc: 
	doxygen documentation.doxygen

clean:
	rm -f $(EXECUTABLE)
	rm -f $(SINGLE_FILE)
	rm -rf $(FOLDERS)
	rm -rf $(ZIP)
	
