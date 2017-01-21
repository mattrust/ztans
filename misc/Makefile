
# when launched from gtans-x.x/makefile PREFIX and DESTDIR are overriden

INSTALL=install
DESTDIR=
PREFIX=/usr

install:
	mkdir -p $(DESTDIR)$(PREFIX)/share/pixmaps
	mkdir -p $(DESTDIR)$(PREFIX)/share/gnome/apps/Games
	mkdir -p $(DESTDIR)$(PREFIX)/man/man6
	$(INSTALL) -m 0644 gtans_icon.png $(DESTDIR)$(PREFIX)/share/pixmaps/gtans_icon.png
	$(INSTALL) -m 0644 gtans.desktop $(DESTDIR)$(PREFIX)/share/gnome/apps/Games/gtans.desktop
	$(INSTALL) -m 0644 gtans-6x $(DESTDIR)$(PREFIX)/man/man6/gtans.6
