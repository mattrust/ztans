
# when launched from gtans-x.x/makefile PREFIX and DESTDIR are overriden
LINGUAS=es fr ru uk pl cs tr
INSTALL=install
PREFIX=/usr
LOCALEDIR=$(PREFIX)/share/locale
DESTDIR=

po:
	for i in $(LINGUAS); do \
		msgfmt -o gtans.mo-$$i gtans.po-$$i; \
	done;
clean:
	rm gtans.mo-*

install:
	for i in $(LINGUAS); do \
		mkdir -p $(DESTDIR)$(LOCALEDIR)/$$i/LC_MESSAGES; \
		$(INSTALL) -m 0644 gtans.mo-$$i $(DESTDIR)$(LOCALEDIR)/$$i/LC_MESSAGES/gtans.mo; \
	done;
