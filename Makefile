CXX=g++
CPPFLAGS=-c -O3 -std=c++11 -Wall -Wextra -Weffc++ -I../kernel_module/include -I./include -I./utils -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -Wdouble-promotion -Wuninitialized -fipa-pure-const -Wtrampolines -Wfloat-equal  -Wcast-qual -Wcast-align -Wconversion -Wlogical-op -Wredundant-decls -Wshadow -Wint-to-pointer-cast
CPP_SOURCES= \
	src/wmi.cpp \
	src/wmiresult.cpp

TEST_SOURCE= src/test.cpp

LDFLAGS=-lole32 -loleaut32 -lwbemuuid -L. -ldiaa_sami_comsupp

OBJECTS=$(CPP_SOURCES:src/%.cpp=bin/%.o)
TEST_OBJECT=$(TEST_SOURCE:src/%.cpp=bin/%.o)
DEPS=$(OBJECTS:bin/%.o=bin/%.d) $(TEST_OBJECT:bin/%.o=bin/%.d)

all: bin wmi.dll test.exe

-include $(DEPS)

wmi.dll: $(OBJECTS) diaa_sami_comsupp.dll
	@echo "Linking" $@
	@$(CXX) -shared -o $@ $(OBJECTS) $(LDFLAGS)

test.exe: wmi.dll $(TEST_OBJECT)
	@echo "Linking" $@
	@$(CXX) -o $@ $(TEST_OBJECT) -L. -lwmi

bin/%.o: src/%.cpp
	@echo "Compiling" $<
	@$(CXX) -MD $(CFLAGS) $(CPPFLAGS) -o $@ $<

bin:
	mkdir bin

diaa_sami_comsupp.dll:
	@make -C diaa_sami_comsupp
	@ln -s diaa_sami_comsupp/$@ .

clean:
	@echo "Cleaning"
	@make -C diaa_sami_comsupp clean
	@rm -rf bin/*.o bin/*.d wmi.dll diaa_sami_comsupp.dll test.exe
