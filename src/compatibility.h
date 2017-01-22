#ifndef COMPATIBILITY_H
#define COMPATIBILITY_H

typedef BOOL gboolean;
typedef char gchar;
typedef int gint;
typedef unsigned int guint;
typedef unsigned short gushort;
typedef WORD gint16;
typedef double gdouble;
typedef void *gpointer;

typedef struct {int width; int height;} Allocation;
typedef struct {void *white_gc; int *fg_gc;} Style;

typedef Object *GtkObject;
typedef Object *GtkMenuItem;
typedef struct {void *window; Style *style; Allocation allocation;} GtkWidget;
typedef Object *GtkStatusbar;
typedef Object *GtkSpinButton;
typedef Object *GtkAdjustment;
typedef Object *GtkButton;
typedef Object *GtkAccelGroup;
typedef Object *GtkEditable;

typedef Object *GdkEventExpose;
typedef Object *GdkEventConfigure;
typedef Object *GdkEventButton;
typedef Object *GdkEventMotion;
typedef Object *GdkEvent;
typedef struct {int x; int y; int width; int height;} GdkRectangle;
typedef Object GdkPixmap;
typedef Object GdkGC;
typedef struct {int red; int green; int blue;} GdkColor;
typedef Object GdkColormap;
typedef struct {int x; int y;} GdkPoint;

#define G_DIR_SEPARATOR_S "/"
#define GDK_INVERT 1
#define GDK_TILED 2
#define GDK_SOLID 3
#define GTK_FILE_CHOOSER_ACTION_OPEN
#define GTK_STOCK_CANCEL
#define GTK_RESPONSE_CANCEL
#define GTK_STOCK_OPEN
#define GTK_RESPONSE_ACCEPT

#define PKGDATADIR "PROGDIR:data"
#define SYSCONFDIR "PROGDIR:data"

#define ABS(a) ((a) > 0 ? (a) : -(a)) 

#endif
