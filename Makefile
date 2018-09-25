OBJS=promisc.o
SRCS=promisc.c
EXEC=promisc
CfLAGS+=-O2
LDFLAGS+=-lpcap

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(LDFLAGS)

clean:
	-rm -f $(EXEC) $(OBJS) *~ *.core core *.BAK tags


