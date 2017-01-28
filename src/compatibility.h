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
typedef Object *GdkBitmap;
typedef struct {int x; int y; int width; int height;} GdkRectangle;
typedef Object *GdkPixmap;
typedef Object *GdkDrawable;
typedef Object *GdkGC;
typedef Object *GdkFill;
typedef void (*GdkFunction)(void);
typedef struct {int red; int green; int blue;} GdkColor;
typedef Object *GdkColormap;
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
#define CLAMP(x, low, high)  (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))
#define _(a) (a)
#define g_malloc(a) malloc(a)
#define g_free(a) free(a)
#define g_strtod(a, b) strtod(a, b)

void
gdk_draw_line (GdkDrawable *drawable,
               GdkGC *gc,
               gint x1_,
               gint y1_,
               gint x2_,
               gint y2_);

void
gdk_draw_lines (GdkDrawable *drawable,
                GdkGC *gc,
                const GdkPoint *points,
                gint n_points);

void
gdk_draw_rectangle (GdkDrawable *drawable,
                    GdkGC *gc,
                    gboolean filled,
                    gint x,
                    gint y,
                    gint width,
                    gint height);

void
gdk_draw_drawable (GdkDrawable *drawable,
                   GdkGC *gc,
                   GdkDrawable *src,
                   gint xsrc,
                   gint ysrc,
                   gint xdest,
                   gint ydest,
                   gint width,
                   gint height);

GdkGC *
gdk_gc_new (GdkDrawable *drawable);

void
gdk_gc_set_fill (GdkGC *gc,
                 GdkFill fill);

void
gdk_gc_set_foreground (GdkGC *gc,
                       const GdkColor *color);

gboolean
gdk_colormap_alloc_color (GdkColormap *colormap,
                          GdkColor *color,
                          gboolean writeable,
                          gboolean best_match);

void
gdk_gc_set_function (GdkGC *gc,
                     GdkFunction function);

void
gdk_gc_set_tile (GdkGC *gc,
                 GdkPixmap *tile);

void
gdk_colormap_free_colors (GdkColormap *colormap,
                          const GdkColor *colors,
                          gint n_colors);

GdkColormap *
gdk_colormap_get_system (void);

void
gdk_gc_set_ts_origin (GdkGC *gc,
                      gint x,
                      gint y);

GdkPixmap *
gdk_pixmap_create_from_xpm (GdkDrawable *drawable,
                            GdkBitmap **mask,
                            const GdkColor *transparent_color,
                            const gchar *filename);

void
g_object_unref (gpointer object);

#endif
