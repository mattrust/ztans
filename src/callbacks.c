/*
 * Copyright (C) 2017  Matthias Rustler
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "callbacks.h"
#include "interface.h"
#include "main.h"
#include "support.h"

void colselinit (int col);
void filselinit (int col);

#define FIGGC 2848


/******************************************************************
 ******************************************************************/
void
on_mainwindow_destroy                  (GtkObject       *object,
                                        gpointer         user_data)
{
  tanend();
}


void
on_mquit_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  gtk_widget_destroy(mainwindow);
}


#define ZOOMINCDEC 1.05

void
on_msizinc_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  tanrecentreout(figgrande.zoom, figgrande.zoom*ZOOMINCDEC);
  figgrande.zoom *=ZOOMINCDEC;
  tanclampgrandefig();
  tanredrawgrande();
}


void
on_msizdec_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  tanrecentreout(figgrande.zoom, figgrande.zoom/ZOOMINCDEC);
  figgrande.zoom /=ZOOMINCDEC;
  tanredrawgrande();
}


void
on_mclrstat_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  tanclearreussinr(figactualnr);
  if (figtabsize)
    figpetite.reussi = FALSE;
  tanredrawpetite();
  selpossible=TRUE;
}


void
on_mclrall_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  int i;

  for (i = 0; i<figtabsize; i++ )
    tanclearreussinr(i);
  if (figtabsize)
    figpetite.reussi = FALSE;
  tanredrawpetite();
  selpossible=TRUE;
}


void
on_maccuracy1_activate                 (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  if (GTK_CHECK_MENU_ITEM (menuitem)->active)
    accuracy = 0;
}


void
on_maccuracy2_activate                 (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  if (GTK_CHECK_MENU_ITEM (menuitem)->active)
    accuracy = 1;
}


void
on_maccuracy3_activate                 (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  if (GTK_CHECK_MENU_ITEM (menuitem)->active)
    accuracy = 2;
}


void
on_mrotcont_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  if (GTK_CHECK_MENU_ITEM (menuitem)->active)
    rotstepnbr = TOUR/256;
}


void
on_mrotstp_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  tanpiecepos *piecepos;
  int i;
  
  if (GTK_CHECK_MENU_ITEM (menuitem)->active)
    rotstepnbr = TOUR/32;
  
  piecepos = figgrande.piecepos;
  for (i = 0; i<PIECENBR; i++){
    piecepos->rot = (int)((piecepos->rot+rotstepnbr/2)/rotstepnbr)*rotstepnbr;
    piecepos++;
  }
  
  tanredrawgrande();

}


void
on_mtanscolor_activate                 (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  colselinit(GCPIECENOR);
}


void
on_mtanstexture_activate               (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  filselinit(GCPIECENOR);
}


void
on_mhighcolor_activate                 (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  colselinit(GCPIECEHI);
}


void
on_mhightexture_activate               (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  filselinit(GCPIECEHI);
}


void
on_mbgcolor_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  colselinit(GCPIECEBG);
}


void
on_mbgtexture_activate                 (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  filselinit(GCPIECEBG);
}


void
on_mhlpoutcolor_activate               (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  colselinit(GCPIECEHLP);
}


void
on_msilcolor_activate                  (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  colselinit(GCPETITEFG);
}


void
on_msilbgcolor_activate                (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  colselinit(GCPETITEBG);
}


void
on_msilbgcol2_activate                 (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  colselinit(GCPETITECHK);
}


void
on_mhlptancolor_activate               (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  colselinit(GCPETITEHLP);
}


void
on_mfigfile_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  filselinit(FIGGC);
}


void
on_msaveconf_activate                  (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  if (tansaveconfig())
    tanstatprov(_("User config file saved."));
  else
    tanstatprov(_("Can't save config file."));
}


void
on_mabout_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
//  tanstatpush(_("About gTans..."));
  create_aboutwindow();
}


void
on_mhelp_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  FILE *hlpfile;
  GtkWidget *helpwindow, *whltext;
  GtkTextBuffer *hlptext;
  GtkTextIter iter;
  char buffer[1024];
  int nchars;
  char helpfile[1024], *helpfile_ext;
  char helpfiledef[1024];
  char filext[4];

  helpwindow = create_helpwindow ();
  whltext = lookup_widget (GTK_WIDGET (helpwindow), "whltext");
  hlptext = gtk_text_buffer_new (NULL);
  gtk_text_buffer_get_end_iter (hlptext, &iter);

  if (! (helpfile_ext = g_getenv("LANG")))
    helpfile_ext = "";
   
  filext[2] = '\0';
  strncpy (filext, helpfile_ext, 2);
  snprintf (helpfile, 1023, HELPFILE_PATH, filext);
  snprintf (helpfiledef, 1023, HELPFILE_PATH, "");
   
  if ( (hlpfile=fopen(helpfile,"r"))!=NULL ||
       (hlpfile=fopen(helpfiledef,"r"))!=NULL ) {
    while (!feof(hlpfile)) {
      nchars = fread(buffer, 1, 1024, hlpfile);
      gtk_text_buffer_insert (hlptext, &iter, buffer, nchars);
    }
    fclose (hlpfile);
  }
  else {
    gtk_text_buffer_insert (hlptext, &iter, _("Can't read help file, Sorry."), -1);
  }
  
  tanstatpush(_("gTans help..."));
  gtk_text_view_set_buffer (GTK_TEXT_VIEW (whltext), hlptext);
  gtk_widget_show (helpwindow);
  
}


gboolean
on_wdrawareagrande_expose_event        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data)
{
  if (pixmapgrande1!=NULL)
    gdk_draw_drawable(widget->window,
		    widget->style->fg_gc[gtk_widget_get_state(widget)],
		    pixmapgrande1,
		    event->area.x, event->area.y,
		    event->area.x, event->area.y,
		    event->area.width, event->area.height);

  return FALSE;
}


gboolean
on_wdrawareagrande_configure_event     (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data)
{
  double izoom;
  tanpiecepos *piecepos;
  int i;

  widgetgrande=widget;
  if (!initcbgr)
    taninitcbgr();

  if (pixmapgrande1!=NULL){
    g_object_unref(pixmapgrande1);
    g_object_unref(pixmapgrande2);
  }

  pixmapgrande1 = gdk_pixmap_new(widget->window,
				 widget->allocation.width,
				 widget->allocation.height,
				 -1);
  pixmapgrande2 = gdk_pixmap_new(widget->window,
				 widget->allocation.width,
				 widget->allocation.height,
				 -1);
   
  if ( !editmode ){
    izoom=(widgetgrande->allocation.width*figgrande.zoom);
    piecepos=figgrande.piecepos;
    for (i=0; i<PIECENBR; i++){
      piecepos->posx=floor((piecepos->posx*izoom)+ARON)/izoom;
      piecepos->posy=floor((piecepos->posy*izoom)+ARON)/izoom;
      piecepos++;
    }
  }

  gdk_gc_set_line_attributes(tabgc[GCPIECEHLP],
			     widget->allocation.width>340 ? 2 : 1,
			     GDK_LINE_SOLID,
			     GDK_CAP_ROUND,
			     GDK_JOIN_ROUND);

  tanredrawgrande();

  return TRUE;
}


gboolean
on_wdrawareagrande_button_press_event  (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{
  int x,y;
  int piece;
  int oldselgr=selectedgrande;

  if (!selpossible || event->type!=GDK_BUTTON_PRESS)     /* double-click ou deja trouve */
    return TRUE;
  
  if (actiongrande != AN_none)      /* le button release event a ete avale */
    tanreleaseifrot();

  x=event->x;
  y=event->y;

  if ( event->button!=3){
    if ( (piece=tanwichisselect(x,y))>=0 ){
      taninitselect(piece, FALSE);
      selectedgrande=TRUE;
      actiongrande=AN_move;
      xold=x;
      yold=y;
      tandrawselect(0,0,0);
    }
    else{
      if (selectedgrande){
	actiongrande=AN_rot;
	xact=(gint16)(ARON+figgrande.piecepos[PIECENBR-1].posx*
		      widgetgrande->allocation.width*figgrande.zoom);
	yact=(gint16)(ARON+figgrande.piecepos[PIECENBR-1].posy*
		      widgetgrande->allocation.width*figgrande.zoom);
	xoth=xold=x;
	yoth=yold=y;
	rotact=tanangle((double)(xact-x),(double)(y-yact));
	rotold=0;
	
	invx2=x;
	invy2=y;
	gdk_draw_line (widgetgrande->window,
		       invertgc,
		       xact,yact,invx2,invy2);
	
      }
    }
  }
  
  if (event->button==3 && selectedgrande==TRUE){
    if (figgrande.piecepos[PIECENBR-1].type==3)
      figgrande.piecepos[PIECENBR-1].flipped^=1;
    else
      figgrande.piecepos[PIECENBR-1].rot=(figgrande.piecepos[PIECENBR-1].rot+TOUR/2)%TOUR;
    tandrawselect(0,0,0);
  }

  if (selectedgrande && !oldselgr)
    tanstatpush(_("Click into to move, around to rotate. Right-click to flip."));

  return TRUE;
}


gboolean
on_wdrawareagrande_button_release_event (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{
  tanreleaseifrot();

  /* actiongrande=AN_none; dans releaseifrot */

  if ( selpossible && figtabsize ){
    tanmaketinytabnotr(&figgrande,tinytabgr);
    tantranstinytab(tinytabgr);
    if (tantinytabcompare(tinytabgr, tinytabpe, accuracy)){
      tanunselect();
      selpossible=FALSE;
      tanstatpop();
      tanstatpush(_("Well done. Try another one ?"));
      tansetreussiactual();
      tanredrawpetite();
    }
  }

  return TRUE;
}


gboolean
on_wdrawareagrande_motion_notify_event (GtkWidget       *widget,
                                        GdkEventMotion  *event,
                                        gpointer         user_data)
{
  int x,y;
  GdkModifierType state;
  int rot;

  if (event->is_hint)
    gdk_window_get_pointer (event->window, &x, &y, &state);
  else{
    x=event->x;
    y=event->y;
    state=event->state;
  }

  if (actiongrande==AN_move){
    tandrawselect(x-xold,y-yold,0);
    xold=x;
    yold=y;
  }

  if (actiongrande==AN_rot){
    gdk_draw_line (widgetgrande->window,
		   invertgc,
		   xact,yact,invx2,invy2);

    rot=(rotact-tanangle((double)(xact-x),(double)(y-yact))+rotstepnbr/2+TOUR*3)%TOUR;
    rot=(int)(rot/rotstepnbr)*rotstepnbr;
    if (rot!=rotold){
      rotold=rot;
      tandrawselect(0,0,rot);
    }

    invx2=x;
    invy2=y;
    gdk_draw_line (widgetgrande->window,
		   invertgc,
		   xact,yact,invx2,invy2);

  }

  return TRUE;
}


gboolean
on_wdrawareapetite_configure_event     (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data)
{
  widgetpetite=widget;
  if (!initcbpe)
    taninitcbpe();

  if (pixmappetite!=NULL)
    g_object_unref(pixmappetite);
  
  pixmappetite = gdk_pixmap_new(widget->window,
				widget->allocation.width,
				widget->allocation.height,
				-1);

  tanredrawpetite();

  return TRUE;
}


gboolean
on_wdrawareapetite_expose_event        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data)
{
  if (pixmappetite!=NULL)
    gdk_draw_drawable(widget->window,
		    widget->style->fg_gc[gtk_widget_get_state(widget)],
		    pixmappetite,
		    event->area.x, event->area.y,
		    event->area.x, event->area.y,
		    event->area.width, event->area.height);

  return FALSE;
}


void
on_bfignr_changed                      (GtkEditable     *editable,
                                        gpointer         user_data)
{
  tansetnewfigurepart1(gtk_spin_button_get_value_as_int (spinner));
  tansetnewfigurepart2();
}


void
on_bunsel_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
  tanunselect();
}


void
on_badjust_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  tancolle(&figgrande, (accuracy+1)*0.05);
  spesavefig();
  tanredrawgrande();
}


void
on_bhlptan_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  helptanset = (helptanset+1)%PIECENBR;
  tanredrawpetite();

}


void
on_bhlpout_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  if(!helpoutset){
    helpoutset = TRUE;
    tanredrawgrande();
  }
}


/******************************************************************
 ******************************************************************/
static int filselnr;


void filselinit (int col)
{
  gchar *filename,*statext;
  

  if (col==FIGGC){
    filename = figfilename;
    statext = _("Select a figures file...");
  }
  else{
    filename = tabpxnam[col];
    statext = _("Select a texture (xpm file)...");
  }
  
  if (filselwin==NULL)
    filselwin = create_fileselectwindow();
  
  gtk_file_chooser_set_filename (GTK_FILE_CHOOSER(filselwin),filename);
  
  gtk_widget_show (filselwin);
  gdk_window_raise (filselwin->window);
  
  tanstatpush(statext);
  filselnr=col;
  
}


gboolean
on_fileselectwindow_delete_event       (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
  gtk_widget_hide (gtk_widget_get_toplevel (GTK_WIDGET (widget)));
  tanstatpop();
  return TRUE;
}


void
on_bfsok_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
  gchar *filename;


  tanstatpop();
  filename=gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (filselwin));
  
  if (filselnr==FIGGC){
    if (tanloadfigtab(filename)){
      gchar *str;
      str = g_strdup_printf(_("%d figures loaded."),figtabsize);
      tanstatprov(str);
      g_free(str);
    }
    else{
      tanstatprov(_("Can't load figure file."));
    }
  }
  else{  
    tansetpixmapmode(widgetgrande, filename, filselnr);
    if (filselnr<=GCPIECELAST)
      tanredrawgrande();
    else
      tanredrawpetite();
  }
  gtk_widget_hide (gtk_widget_get_toplevel (GTK_WIDGET (button)));
}


void
on_bfscancel_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_widget_hide (gtk_widget_get_toplevel (GTK_WIDGET (button)));
  tanstatpop();
}


/******************************************************************
 ******************************************************************/

static GtkWidget *clrsel;
static GdkColor colselcolor;
static int colselnr;

void color_changed_cb (GtkWidget *widget, GtkColorSelection *colorsel)
{
  gtk_color_selection_get_current_color (colorsel,&colselcolor);
}


void colselinit (int col)
{
  if (colselwin==NULL){
    colselwin = create_colorselectwindow();
    clrsel = GTK_COLOR_SELECTION_DIALOG(colselwin)->colorsel;
    g_signal_connect(G_OBJECT(clrsel),"color_changed",
		       (GCallback)color_changed_cb, (gpointer)clrsel);
  }
  
  colselcolor = colortab[col];
  gtk_color_selection_set_current_color(GTK_COLOR_SELECTION(clrsel),&colselcolor);
  gtk_widget_show (colselwin);
  gdk_window_raise (colselwin->window);
  
  tanstatpush(_("Select a color..."));
  colselnr=col;
}


gboolean
on_colorselectwindow_delete_event      (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
  gtk_widget_hide (gtk_widget_get_toplevel (GTK_WIDGET (widget)));
  tanstatpop();
  return TRUE;
}


void
on_bcsok_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
  tansetcolormode(&colselcolor,colselnr);
  if (colselnr<=GCPIECELAST)
    tanredrawgrande();
  else
    tanredrawpetite();
  gtk_widget_hide (gtk_widget_get_toplevel (GTK_WIDGET (button)));
  tanstatpop();
}


void
on_bcscancel_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_widget_hide (gtk_widget_get_toplevel (GTK_WIDGET (button)));
  tanstatpop();
}


/******************************************************************
 ******************************************************************/
void
on_babclose_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_widget_destroy (gtk_widget_get_toplevel (GTK_WIDGET (button)));
}


void
on_aboutwindow_destroy                 (GtkObject       *object,
                                        gpointer         user_data)
{
  tanstatpop();
}


/******************************************************************
 ******************************************************************/
void
on_bhlclose_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_widget_destroy (gtk_widget_get_toplevel (GTK_WIDGET (button)));
}


void
on_helpwindow_destroy                  (GtkObject       *object,
                                        gpointer         user_data)
{
  tanstatpop();
}
