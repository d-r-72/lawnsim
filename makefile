program_NAME := Lawnsim
program_C_SRCS := $(wildcard projects/lawn_sim_rewrite/src/*.c)
program_CXX_SRCS := $(wildcard projects/lawn_sim_rewrite/src/*.cpp)
program_C_OBJS := ${program_C_SRCS:.c=.o}
program_CXX_OBJS := ${program_CXX_SRCS:.cpp=.o}
program_OBJS := $(program_C_OBJS) $(program_CXX_OBJS)
program_INCLUDE_DIRS :=
program_LIBRARY_DIRS :=
program_LIBRARIES :=
program_TEST_SRC := $(wildcard projects/lawn_sim_rewrite/tests/*.cpp)

CC := g++
test_NAME := Test

CPPFLAGS += $(foreach includedir,$(program_INCLUDE_DIRS),-I$(includedir))
LDFLAGS += $(foreach librarydir,$(program_LIBRARY_DIRS),-L$(librarydir))
LDFLAGS += $(foreach library,$(program_LIBRARIES),-l$(library))
CPPFLAGS += -std=c++11

.PHONY: all clean distclean

all: $(program_NAME)

test:
	$(CC) -std=c++11 $(program_TEST_SRC) -o $(test_NAME)


$(program_NAME): $(program_OBJS)
	$(LINK.cc) $(program_OBJS) -o $(program_NAME)

clean:
	@- $(RM) $(program_NAME)
	@- $(RM) $(program_OBJS)

distclean: clean
