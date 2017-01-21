icon16dir = $(datadir)/icons/hicolor/16x16/apps
icon16_DATA = 16x16/gtans.png

icon22dir = $(datadir)/icons/hicolor/22x22/apps
icon22_DATA = 22x22/gtans.png

icon24dir = $(datadir)/icons/hicolor/24x24/apps
icon24_DATA = 24x24/gtans.png

icon32dir = $(datadir)/icons/hicolor/32x32/apps
icon32_DATA = 32x32/gtans.png

icon48dir = $(datadir)/icons/hicolor/48x48/apps
icon48_DATA = 48x48/gtans.png

svgicondir = $(datadir)/icons/hicolor/scalable/apps
svgicon_DATA = scalable/gtans.svg
	

install-data-hook: update-icon-cache
uninstall-hook: update-icon-cache
update-icon-cache:
	@-if test -z "$(DESTDIR)"; then \
		echo "Updating Gtk icon cache."; \
		$(GTK_UPDATE_ICON_CACHE) -f -t $(datadir)/icons/hicolor; \
	else \
		echo "*** Icon cache not updated. After (un)install, run this:"; \
		echo "*** gtk-update-icon-cache -f -t $(datadir)/icons/hicolor"; \
	fi


if MAINTAINER_MODE

$(icon16_DATA) $(icon22_DATA) $(icon24_DATA) $(icon32_DATA) $(icon48_DATA): $(svgicon_DATA)
	for size in 16 22 24 32 48; do \
		$(mkdir_p) $${size}x$${size}; \
		$(RSVG_CONVERT) -f png -h $$size -w $$size -o $${size}x$${size}/gtans.png $<; \
	done

endif


EXTRA_DIST = \
	$(icon16_DATA) \
	$(icon22_DATA) \
	$(icon24_DATA) \
	$(icon32_DATA) \
	$(icon48_DATA) \
	$(svgicon_DATA) 
