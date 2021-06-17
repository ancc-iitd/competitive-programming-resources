PEDANTIC_FLAGS =-DDEBUG -DLOCAL -O2 -std=c++17 -g -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector

NORMAL_FLAGS =-O2 -std=c++17 -DTIMING -DLOCAL

D ?= 0

ifeq ($(D), 1)
	CXXFLAGS = $(PEDANTIC_FLAGS)
else
	CXXFLAGS = $(NORMAL_FLAGS)
endif

clean:
	find . -maxdepth 1 -type f -executable -delete
