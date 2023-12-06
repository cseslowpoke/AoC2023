# Makefile for Aoc2023 project using C++

# Compiler settings
# Detect the operating system
ifeq ($(OS),Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell uname -s)
endif

# Set the CXX variable according to the operating system
ifeq ($(detected_OS),Windows)
    CXX := g++
else ifeq ($(detected_OS),Darwin)  # Darwin is the name for macOS in uname
    CXX := g++-13
else
    CXX := g++
endif
CXXFLAGS = -Wall -g -DLOCAL -std=c++20

# Function to compile and run a day's problem with input redirection
define compile_and_run_day
day$(1)p1: Source/Day$(1)/p1.cpp
	$(CXX) $(CXXFLAGS) -o Day$(1)p1.out Source/Day$(1)/p1.cpp
	@./Day$(1)p1.out < Source/Day$(1)/in

day$(1)p2: Source/Day$(1)/p2.cpp
	$(CXX) $(CXXFLAGS) -o Day$(1)p2.out Source/Day$(1)/p2.cpp
	@./Day$(1)p2.out < Source/Day$(1)/in
endef

# Days to compile (e.g., 1, 2, 3, ...)
DAYS = 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

# Generate rules for each day
$(foreach day,$(DAYS),$(eval $(call compile_and_run_day,$(day))))

# Clean Target
clean:
	@rm -f $(foreach day,$(DAYS),Day$(day)p1.out Day$(day)p2.out)
	@rm -rf $(foreach day,$(DAYS),Day$(day)p1.out.dSYM Day$(day)p2.out.dSYM)

# Phony Targets
.PHONY: clean $(foreach day,$(DAYS),day$(day)p1 day$(day)p2)
