##
# LZ77
#
# @file
# @version 0.1
OPTIONS = -O3 -DNDEBUG
all: build/compressor
all: build/decompressor

debug: OPTIONS = -O0 -g -Wall -Wextra -fsantize=address -fno-omit-frame-pointer
debug: all

build/compress.o: src/compress.cpp
	g++ ${OPTIONS} src/compress.cpp -o build/compress.o -c
build/decompress.o: src/decompress.cpp
	g++ ${OPTIONS} src/decompress.cpp -o build/decompress.o -c
build/compressor: tools/compressor.cpp include/lz77.hpp build/compress.o
	g++ ${OPTIONS} tools/compressor.cpp build/compress.o -o build/compressor -I include/
build/decompressor: tools/decompressor.cpp include/lz77.hpp build/decompress.o
	g++ ${OPTIONS} tools/decompressor.cpp build/decompress.o -o build/decompressor -I include/
clean:
	rm build/*

# end
