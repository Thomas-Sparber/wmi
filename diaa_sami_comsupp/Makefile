CXX=g++
CPPFLAGS=-c -O3
CPP_SOURCES= diaa_sami_comsupp.cpp
LDFLAGS=-loleaut32

OBJECTS=$(CPP_SOURCES:%.cpp=bin/%.o)
DEPS=$(OBJECTS:bin/%.o=bin/%.d)

all: bin diaa_sami_comsupp.dll

-include $(DEPS)

diaa_sami_comsupp.dll: $(OBJECTS)
	@echo "Linking" $@
	@$(CXX) -shared -o $@ $(OBJECTS) $(LDFLAGS)

bin/%.o: %.cpp
	@echo "Compiling" $<
	@$(CXX) -MD $(CFLAGS) $(CPPFLAGS) -o $@ $<

bin:
	mkdir bin

clean:
	@echo "Cleaning"
	@rm -rf bin/*.o bin/*.d diaa_sami_comsupp.dll
