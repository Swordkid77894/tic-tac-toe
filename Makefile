.PHONY: all clean

APP=game
CFLAGS=-Wall -Wextra -Werror -g

all: $(APP)

$(APP):
	gcc -o $(APP) $(CFLAGS) $(APP).c

clean:
	rm $(APP)
