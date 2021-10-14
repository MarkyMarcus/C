NAME	= helloworld
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

.PHONY: clean preprocess

$(NAME).preprocess: $(SOURCES) $(HEADERS)
	@echo "  PREPROCESS\t$@"
	$(CC) -E $(CFLAGS) -o $@ $(SOURCES)

$(NAME).assemble: $(SOURCES) $(HEADERS)
	@echo "  ASSEMBLE\t$@"
	$(CC) -S $(CFLAGS) -o $@ $(SOURCES)

$(NAME).compile: $(SOURCES) $(HEADERS)
	@echo "  COMPILE\t$@"
	$(CC) -c $(CFLAGS) -o $@ $(SOURCES)

$(NAME).link: $(NAME)
	cp $(NAME) $(NAME).link

clean:
	@echo "  CLEAN"
	$(RM) -f $(NAME) $(OBJECTS) $(NAME).preprocess $(NAME).assemble $(NAME).compile $(NAME).link

print-%:
	@echo $*=$($*)

$(V).SILENT:
