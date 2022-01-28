CXX = g++
VERSION = --std=c++11

SEARCH = search.cpp
SEA = search

all: $(SEA)

search: $(SEARCH)
	@echo "generating search..."
	$(CXX) $(VERSION) $(SEARCH) -o $(SEA)


.PHONY: clean
clean:
	@echo "cleaning up......"
	rm search
    
