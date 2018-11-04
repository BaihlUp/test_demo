src = $(wildcard *.c)
obj = $(patsubst %.c, %, $(src))

ALL:$(obj)

$(obj):%:%.c
	gcc $< -o $@ -Wall -g

clean:
	-rm -f $(obj) 

.PHONY: clean ALL

