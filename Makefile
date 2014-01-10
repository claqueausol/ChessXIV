CC	:= gcc
CFLAGS	:= -ansi -Wall

MODULES   := Model Control View
SRC_DIR   := $(addprefix src/,$(MODULES))

INCLUDES  := $(addprefix -I,$(SRC_DIR))

VPATH = $(SRC_DIR) src

.PHONY: all clean

all: StructuredLibraryTest

clean:
	rm build/*

test:
	@echo "SRC_DIR = " $(SRC_DIR)

build/%.o: %.c
	$(CC) $< -o $@ $(CFLAGS) $(INCLUDES) -c

build/lib%.a: %.o
	ar rc $@ $<
	ranlib $@

StructuredLibraryTest: build/StructuredLibraryTest.o build/libModel.a build/libControl.a build/libView.a
	$(CC) build/StructuredLibraryTest.o -Lbuild -lModel -lControl -lView -o build/$@ $(CFLAGS)

ViewUnitTest: build/ViewUnitTest.o build/libModel.a build/libView.a
	$(CC) build/ViewUnitTest.o -Lbuild -lModel -lView -o build/$@ $(CFLAGS)

ControlUnitTest: build/ControlUnitTest.o build/libControl.a
	$(CC) build/ControlUnitTest.o -Lbuild -lControl -o build/$@ $(CFLAGS)
