NAME	= leapyear
CC		= clang
LD		= ld
RM		= rm
HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
WFLAGS	= -Wall
SYSROOT = $(shell xcrun --show-sdk-path --sdk macosx)
VERSION	= $(shell xcrun --show-sdk-version --sdk macosx)
CFLAGS	+= -arch x86_64 -mmacosx-version-min=$(VERSION) -isysroot $(SYSROOT)
LDFLAGS += -macosx_version_min $(VERSION) -syslibroot $(SYSROOT) -lSystem

%.o: %.c $(HEADERS)
	@echo "  CC\t$@"
	$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): $(OBJECTS) $(HEADERS)
	@echo "  LINK\t$@"
	$(LD) $(LDFLAGS) -o $@ $(OBJECTS)

.PHONY: clean

clean:
	@echo "  CLEAN"
	$(RM) -f $(NAME) $(OBJECTS)

print-%:
	@echo $*=$($*)

$(V).SILENT:
