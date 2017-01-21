
# uninstall try to delete only files belonging to gTans but you
# probably should avoid using existing directories

DESTDIR = 
PREFIX	=	/usr
HOMEDIR	=	$(PREFIX)/share/gtans/
FIGDIR	=	$(HOMEDIR)/figures/
XPMDIR	=	$(HOMEDIR)/pixmaps/
EXECDIR	=	$(PREFIX)/bin/

PROG	=	gtans
CC	=	gcc
INSTALL =	install

CFLG	=	-O2 -Wall 
LDFLG	=	-lm

#comment this line if you DON'T want to use gettext
#you should also comment the commands which build and install the catalogs
#(see below) (I don't know if conditionnal make is portable)
CFLG	+=	-DTGTXT

CFLG	+=	-DXPMDIR=\"$(XPMDIR)\" -DFIGDIR=\"$(FIGDIR)\" \
		-DHOMEDIR=\"$(HOMEDIR)\"
OBJ	=	main.o support.o interface.o callbacks.o

$(PROG): $(OBJ)
	$(CC) $(OBJ) $(LDFLG) `gtk-config --libs ` -o $(PROG)

#comment this line if you DON'T want to use gettext
	cd po; make


callbacks.o: callbacks.c callbacks.h 
	$(CC) $(CFLG) -c callbacks.c `gtk-config --cflags `


interface.o: interface.c interface.h
	$(CC) $(CFLG) -c interface.c `gtk-config --cflags `


main.o: main.c main.h
	$(CC) $(CFLG) -c main.c `gtk-config --cflags `


support.o: support.c support.h
	$(CC) $(CFLG) -c support.c `gtk-config --cflags `


clean: 
	rm -f *.o $(PROG)


install: $(PROG)
	$(INSTALL) -d -m 0755 $(DESTDIR)$(HOMEDIR)
	$(INSTALL) -d -m 0755 $(DESTDIR)$(EXECDIR)
	$(INSTALL) -d -m 0755 $(DESTDIR)$(FIGDIR)
	$(INSTALL) -d -m 0755 $(DESTDIR)$(XPMDIR)
	$(INSTALL) -s $(PROG) $(DESTDIR)$(EXECDIR)$(PROG)
	$(INSTALL) -m 0644 gtanshelp*.txt $(DESTDIR)$(HOMEDIR)
	$(INSTALL) -m 0644 figures/* $(DESTDIR)$(FIGDIR)
	$(INSTALL) -m 0644 pixmaps/* $(DESTDIR)$(XPMDIR)
	sed -e s@FIGDIR@$(FIGDIR)@ -e s@XPMDIR@$(XPMDIR)@ gtansrc.def\
	    >$(DESTDIR)$(HOMEDIR)gtansrc
	chmod 644 $(DESTDIR)$(HOMEDIR)gtansrc

#comment this line if you DON'T want to use gettext
	cd po; make DESTDIR=$(DESTDIR) PREFIX=$(PREFIX) install
	cd misc; make DESTDIR=$(DESTDIR) PREFIX=$(PREFIX) install


uninstall:
	rm $(DESTDIR)$(EXECDIR)$(PROG)
	rm $(DESTDIR)$(HOMEDIR)gtansrc
	rm $(DESTDIR)$(HOMEDIR)gtanshelp*.txt
	rm $(DESTDIR)$(FIGDIR)*.figures
	rm $(DESTDIR)$(XPMDIR)gtans*.xpm
	-rmdir $(DESTDIR)$(FIGDIR)
	-rmdir $(DESTDIR)$(XPMDIR)
	-rmdir $(DESTDIR)$(HOMEDIR)


uninstallold:
	-rm /usr/local/bin/gtans
	-rm -r /usr/local/lib/gtans


