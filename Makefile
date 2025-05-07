FILC_CC = ../llvm-project-deluge/build/bin/clang
CC = gcc
CFLAGS = -g
SANITIZER_FLAG = -fsanitize=address

# List of source files
SOURCES = 0-out-of-bounds-access \
          1-overflowing-out-of-bounds \
          2-out-of-bounds-access \
          3-out-of-bounds-in-bounds \
          4-bad-syscall \
          5-type-confusion \
          6-use-after-free \
          7-pointer-races \
          8-data-races

all:
	@echo "usage: make [filc | sanitizer]"
filc:
	@echo "Building executables for filc target..."
	@mkdir -p output-filc
	@for src in $(SOURCES); do \
		exe=output-filc/$$src; \
		echo "Compiling $$src -> $$exe with sanitizer"; \
		$(FILC_CC) $(CFLAGS) $$src.c -o $$exe; \
	done

sanitizer:
	@echo "Building executables with sanitizer..."
	@mkdir -p output-sanitizer
	@for src in $(SOURCES); do \
		exe=output-sanitizer/$$src; \
		echo "Compiling $$src -> $$exe with sanitizer"; \
		$(CC) $(CFLAGS) $(SANITIZER_FLAG) $$src.c -o $$exe; \
	done

clean:
	@echo "Cleaning output directories..."
	@rm -rf output-filc output-sanitizer
