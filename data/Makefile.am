SUBDIRS = icons

sysconf_DATA = gtansrc
gtansrc: gtansrc.in
	$(AM_V_GEN)$(SED) -e "s!\@pkgdatadir\@!$(pkgdatadir)!" $< > $@

helpdir = $(pkgdatadir)
help_DATA = \
	gtanshelp.txt	\
	gtanshelpcs.txt	\
	gtanshelpes.txt	\
	gtanshelpfr.txt	\
	gtanshelppl.txt	\
	gtanshelpru.txt	\
	gtanshelpuk.txt

figuresdir = $(pkgdatadir)/figures
figures_DATA = \
	figures/alpha.figures	\
	figures/default.figures	\
	figures/misc.figures	\
	figures/similar.figures

pixmapsdir = $(pkgdatadir)/pixmaps
pixmaps_DATA = \
	pixmaps/gtans_brightburtwood.xpm	\
	pixmaps/gtans_brightwood.xpm		\
	pixmaps/gtans_burtwood.xpm			\
	pixmaps/gtans_paper.xpm				\
	pixmaps/gtans_puzzle.xpm			\
	pixmaps/gtans_recessed.xpm			\
	pixmaps/gtans_rope.xpm				\
	pixmaps/gtans_stones.xpm			\
	pixmaps/gtans_volcanic.xpm			\
	pixmaps/gtans_wood.xpm


CLEANFILES = $(sysconf_DATA)

EXTRA_DIST = \
	gtansrc.in		\
	$(help_DATA)	\
	$(figures_DATA)	\
	$(pixmaps_DATA)
