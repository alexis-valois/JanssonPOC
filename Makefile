CC        = gcc
CFLAGS    = -O3 -Wall -std=c99 `pkg-config --cflags --libs jansson`

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
	./$(BINDIR)/$(PROG)

$(PROG) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ./$(BINDIR)/$@

$(OBJS) : $(BINDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<
	@echo "Compiled "$<" successfully!"

$(TEST) : $(OBJS)
	$(CC) $(TESTDIR)/$(TESTSUITE) $(filter-out $(BINDIR)/$(PROG).o, $(OBJS)) $(CFLAGS) -o ./$(BINDIR)/$(TEST)
	./$(BINDIR)/$(TEST)

clean:
	rm -rf *~ $(BINDIR)/*