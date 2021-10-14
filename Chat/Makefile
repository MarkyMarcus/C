CC		= clang
LD		= ld
RM		= rm
HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
WFLAGS	= -Wall
SYSROOT = $(shell xcrun --show-sdk-path --sdk macosx)
VERSION	= $(shell xcrun --show-sdk-version --sdk macosx)
CFLAGS	+= -arch x86_64 -mmacosx-version-min=$(VERSION) -isysroot $(SYSROOT) -g
LDFLAGS += -macosx_version_min $(VERSION) -syslibroot $(SYSROOT) -lSystem

all: client server

%.o: %.c $(HEADERS)
	@echo "  CC\t$@"
	$(CC) -c $(CFLAGS) -o $@ $<

client: client.o caesarcipher.o $(HEADERS)
	@echo "  LINK\t$@"
	$(LD) $(LDFLAGS) -o $@ client.o caesarcipher.o

server: server.o $(HEADERS)
	@echo "  LINK\t$@"
	$(LD) $(LDFLAGS) -o $@ server.o

.PHONY: clean

clean:
	@echo "  CLEAN"
	$(RM) -f client server $(OBJECTS)

print-%:
	@echo $*=$($*)

$(V).SILENT:
