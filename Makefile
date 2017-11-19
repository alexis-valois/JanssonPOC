CC        = gcc
CFLAGS    = -O3 -Wall -std=c11
LFLAGS	  = -ljansson

PROG      = main
TEST      = test

SRCDIR    = ./src
BINDIR    = ./bin
TESTDIR   = ./tests

SRCS      = $(wildcard $(SRCDIR)/*.c)
TESTSUITE = testSuite.c
OBJS      = $(SRCS:$(SRCDIR)/%.c=$(BINDIR)/%.o)

all : $(PROG)

launch:
	./$(BINDIR)/$(PROG) < ./files/params.json

$(PROG) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ./$(BINDIR)/$@ $(LFLAGS)

$(OBJS) : $(BINDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<
	@echo "Compiled "$<" successfully!"

$(TEST) : $(OBJS)
	$(CC) $(TESTDIR)/$(TESTSUITE) $(filter-out $(BINDIR)/$(PROG).o, $(OBJS)) $(CFLAGS) -o ./$(BINDIR)/$(TEST)
	./$(BINDIR)/$(TEST)

clean:
	rm -rf *~ $(BINDIR)/*