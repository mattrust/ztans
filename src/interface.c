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

#include <libraries/mui.h>
#include <proto/muimaster.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#include "compatibility.h"
#include "callbacks.h"
#include "interface.h"
#include "main.h"
#include "support.h"

GtkWidget*
create_mainwindow (void)
{
#if 0
  GtkWidget *mainwindow;
  GtkWidget *vbox1;
  GtkWidget *menubar1;
  GtkWidget *mgame;
  GtkWidget *mgame_menu;
  GtkAccelGroup *mgame_menu_accels;
  GtkWidget *mquit;
  GtkWidget *mprefs;
  GtkWidget *mprefs_menu;
  GtkAccelGroup *mprefs_menu_accels;
  GtkWidget *mtans;
  GtkWidget *mtans_menu;
  GtkAccelGroup *mtans_menu_accels;
  GtkWidget *mtanscolor;
  GtkWidget *mtanstexture;
  GtkWidget *mhitan;
  GtkWidget *mhitan_menu;
  GtkAccelGroup *mhitan_menu_accels;
  GtkWidget *mhighcolor;
  GtkWidget *mhightexture;
  GtkWidget *mbg;
  GtkWidget *mbg_menu;
  GtkAccelGroup *mbg_menu_accels;
  GtkWidget *mbgcolor;
  GtkWidget *mbgtexture;
  GtkWidget *mhlpoutcolor;
  GtkWidget *s_parateur1;
  GtkWidget *msilcolor;
  GtkWidget *msilbgcolor;
  GtkWidget *msilbgcol2;
  GtkWidget *mhlptancolor;
  GtkWidget *s_parateur2;
  GtkWidget *imsize;
  GtkWidget *imsize_menu;
  GtkAccelGroup *imsize_menu_accels;
  GtkWidget *msizinc;
  GtkWidget *msizdec;
  GtkWidget *maccuracy;
  GtkWidget *maccuracy_menu;
  GtkAccelGroup *maccuracy_menu_accels;
  GSList *accgrp_group = NULL;
  GtkWidget *maccuracy1;
  GtkWidget *maccuracy2;
  GtkWidget *maccuracy3;
  GtkWidget *rotstp;
  GtkWidget *rotstp_menu;
  GtkAccelGroup *rotstp_menu_accels;
  GSList *rotgrp_group = NULL;
  GtkWidget *mrotcont;
  GtkWidget *mrotstp;
  GtkWidget *separator1;
  GtkWidget *mfigfile;
  GtkWidget *s_parateur3;
  GtkWidget *msaveconf;
  GtkWidget *mmisc;
  GtkWidget *mmisc_menu;
  GtkAccelGroup *mmisc_menu_accels;
  GtkWidget *mabout;
  GtkWidget *mhelp;
  GtkWidget *sep17;
  GtkWidget *mclrstat;
  GtkWidget *mclrall;
  GtkWidget *table1;
  GtkWidget *aspectframe1;
  GtkWidget *wdrawareagrande;
  GtkWidget *aspectframe2;
  GtkWidget *wdrawareapetite;
  GtkWidget *vbox2;
  GtkWidget *hbox1;
  GtkWidget *label2;
  GtkObject *bfignr_adj;
  GtkWidget *bfignr;
  GtkWidget *hseparator2;
  GtkWidget *bunsel;
  GtkWidget *hseparator1;
  GtkWidget *bhlptan;
  GtkWidget *bhlpout;
  GtkWidget *wstatusbar;

  mainwindow = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (mainwindow, "mainwindow");
  g_object_set_data (G_OBJECT (mainwindow), "mainwindow", mainwindow);
  gtk_window_set_icon_name (GTK_WINDOW (mainwindow), "gtans");
  gtk_window_set_title (GTK_WINDOW (mainwindow), _("gTans"));
  gtk_window_set_default_size (GTK_WINDOW (mainwindow), 500, 430);

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_set_name (vbox1, "vbox1");
  g_object_ref (vbox1);
  g_object_set_data_full (G_OBJECT (mainwindow), "vbox1", vbox1,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (mainwindow), vbox1);

  menubar1 = gtk_menu_bar_new ();
  gtk_widget_set_name (menubar1, "menubar1");
  g_object_ref (menubar1);
  g_object_set_data_full (G_OBJECT (mainwindow), "menubar1", menubar1,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (menubar1);
  gtk_box_pack_start (GTK_BOX (vbox1), menubar1, FALSE, FALSE, 0);

  mgame = gtk_menu_item_new_with_label (_("Game"));
  gtk_widget_set_name (mgame, "mgame");
  g_object_ref (mgame);
  g_object_set_data_full (G_OBJECT (mainwindow), "mgame", mgame,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mgame);
  gtk_container_add (GTK_CONTAINER (menubar1), mgame);

  mgame_menu = gtk_menu_new ();
  gtk_widget_set_name (mgame_menu, "mgame_menu");
  g_object_ref (mgame_menu);
  g_object_set_data_full (G_OBJECT (mainwindow), "mgame_menu", mgame_menu,
                            (GDestroyNotify) g_object_unref);
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (mgame), mgame_menu);
//  mgame_menu_accels = gtk_menu_ensure_uline_accel_group (GTK_MENU (mgame_menu));

  mquit = gtk_menu_item_new_with_label (_("Quit"));
  gtk_widget_set_name (mquit, "mquit");
  g_object_ref (mquit);
  g_object_set_data_full (G_OBJECT (mainwindow), "mquit", mquit,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mquit);
  gtk_container_add (GTK_CONTAINER (mgame_menu), mquit);

  mprefs = gtk_menu_item_new_with_label (_("Preferences"));
  gtk_widget_set_name (mprefs, "mprefs");
  g_object_ref (mprefs);
  g_object_set_data_full (G_OBJECT (mainwindow), "mprefs", mprefs,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mprefs);
  gtk_container_add (GTK_CONTAINER (menubar1), mprefs);

  mprefs_menu = gtk_menu_new ();
  gtk_widget_set_name (mprefs_menu, "mprefs_menu");
  g_object_ref (mprefs_menu);
  g_object_set_data_full (G_OBJECT (mainwindow), "mprefs_menu", mprefs_menu,
                            (GDestroyNotify) g_object_unref);
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (mprefs), mprefs_menu);
//  mprefs_menu_accels = gtk_menu_ensure_uline_accel_group (GTK_MENU (mprefs_menu));

  mtans = gtk_menu_item_new_with_label (_("Tans"));
  gtk_widget_set_name (mtans, "mtans");
  g_object_ref (mtans);
  g_object_set_data_full (G_OBJECT (mainwindow), "mtans", mtans,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mtans);
  gtk_container_add (GTK_CONTAINER (mprefs_menu), mtans);

  mtans_menu = gtk_menu_new ();
  gtk_widget_set_name (mtans_menu, "mtans_menu");
  g_object_ref (mtans_menu);
  g_object_set_data_full (G_OBJECT (mainwindow), "mtans_menu", mtans_menu,
                            (GDestroyNotify) g_object_unref);
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (mtans), mtans_menu);
//  mtans_menu_accels = gtk_menu_ensure_uline_accel_group (GTK_MENU (mtans_menu));

  mtanscolor = gtk_menu_item_new_with_label (_("Color..."));
  gtk_widget_set_name (mtanscolor, "mtanscolor");
  g_object_ref (mtanscolor);
  g_object_set_data_full (G_OBJECT (mainwindow), "mtanscolor", mtanscolor,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mtanscolor);
  gtk_container_add (GTK_CONTAINER (mtans_menu), mtanscolor);

  mtanstexture = gtk_menu_item_new_with_label (_("Texture..."));
  gtk_widget_set_name (mtanstexture, "mtanstexture");
  g_object_ref (mtanstexture);
  g_object_set_data_full (G_OBJECT (mainwindow), "mtanstexture", mtanstexture,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mtanstexture);
  gtk_container_add (GTK_CONTAINER (mtans_menu), mtanstexture);

  mhitan = gtk_menu_item_new_with_label (_("Hilighted tan"));
  gtk_widget_set_name (mhitan, "mhitan");
  g_object_ref (mhitan);
  g_object_set_data_full (G_OBJECT (mainwindow), "mhitan", mhitan,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mhitan);
  gtk_container_add (GTK_CONTAINER (mprefs_menu), mhitan);

  mhitan_menu = gtk_menu_new ();
  gtk_widget_set_name (mhitan_menu, "mhitan_menu");
  g_object_ref (mhitan_menu);
  g_object_set_data_full (G_OBJECT (mainwindow), "mhitan_menu", mhitan_menu,
                            (GDestroyNotify) g_object_unref);
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (mhitan), mhitan_menu);
//  mhitan_menu_accels = gtk_menu_ensure_uline_accel_group (GTK_MENU (mhitan_menu));

  mhighcolor = gtk_menu_item_new_with_label (_("Color..."));
  gtk_widget_set_name (mhighcolor, "mhighcolor");
  g_object_ref (mhighcolor);
  g_object_set_data_full (G_OBJECT (mainwindow), "mhighcolor", mhighcolor,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mhighcolor);
  gtk_container_add (GTK_CONTAINER (mhitan_menu), mhighcolor);

  mhightexture = gtk_menu_item_new_with_label (_("Texture..."));
  gtk_widget_set_name (mhightexture, "mhightexture");
  g_object_ref (mhightexture);
  g_object_set_data_full (G_OBJECT (mainwindow), "mhightexture", mhightexture,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mhightexture);
  gtk_container_add (GTK_CONTAINER (mhitan_menu), mhightexture);

  mbg = gtk_menu_item_new_with_label (_("Background"));
  gtk_widget_set_name (mbg, "mbg");
  g_object_ref (mbg);
  g_object_set_data_full (G_OBJECT (mainwindow), "mbg", mbg,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mbg);
  gtk_container_add (GTK_CONTAINER (mprefs_menu), mbg);

  mbg_menu = gtk_menu_new ();
  gtk_widget_set_name (mbg_menu, "mbg_menu");
  g_object_ref (mbg_menu);
  g_object_set_data_full (G_OBJECT (mainwindow), "mbg_menu", mbg_menu,
                            (GDestroyNotify) g_object_unref);
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (mbg), mbg_menu);
//  mbg_menu_accels = gtk_menu_ensure_uline_accel_group (GTK_MENU (mbg_menu));

  mbgcolor = gtk_menu_item_new_with_label (_("Color..."));
  gtk_widget_set_name (mbgcolor, "mbgcolor");
  g_object_ref (mbgcolor);
  g_object_set_data_full (G_OBJECT (mainwindow), "mbgcolor", mbgcolor,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mbgcolor);
  gtk_container_add (GTK_CONTAINER (mbg_menu), mbgcolor);

  mbgtexture = gtk_menu_item_new_with_label (_("Texture..."));
  gtk_widget_set_name (mbgtexture, "mbgtexture");
  g_object_ref (mbgtexture);
  g_object_set_data_full (G_OBJECT (mainwindow), "mbgtexture", mbgtexture,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mbgtexture);
  gtk_container_add (GTK_CONTAINER (mbg_menu), mbgtexture);

  mhlpoutcolor = gtk_menu_item_new_with_label (_("Outline help color..."));
  gtk_widget_set_name (mhlpoutcolor, "mhlpoutcolor");
  g_object_ref (mhlpoutcolor);
  g_object_set_data_full (G_OBJECT (mainwindow), "mhlpoutcolor", mhlpoutcolor,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mhlpoutcolor);
  gtk_container_add (GTK_CONTAINER (mprefs_menu), mhlpoutcolor);

  s_parateur1 = gtk_menu_item_new ();
  gtk_widget_set_name (s_parateur1, "s_parateur1");
  g_object_ref (s_parateur1);
  g_object_set_data_full (G_OBJECT (mainwindow), "s_parateur1", s_parateur1,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (s_parateur1);
  gtk_container_add (GTK_CONTAINER (mprefs_menu), s_parateur1);
  gtk_widget_set_sensitive (s_parateur1, FALSE);

  msilcolor = gtk_menu_item_new_with_label (_("Silhouette color..."));
  gtk_widget_set_name (msilcolor, "msilcolor");
  g_object_ref (msilcolor);
  g_object_set_data_full (G_OBJECT (mainwindow), "msilcolor", msilcolor,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (msilcolor);
  gtk_container_add (GTK_CONTAINER (mprefs_menu), msilcolor);

  msilbgcolor = gtk_menu_item_new_with_label (_("Silhouette background..."));
  gtk_widget_set_name (msilbgcolor, "msilbgcolor");
  g_object_ref (msilbgcolor);
  g_object_set_data_full (G_OBJECT (mainwindow), "msilbgcolor", msilbgcolor,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (msilbgcolor);
  gtk_container_add (GTK_CONTAINER (mprefs_menu), msilbgcolor);

  msilbgcol2 = gtk_menu_item_new_with_label (_("Solved figure bg..."));
  gtk_widget_set_name (msilbgcol2, "msilbgcol2");
  g_object_ref (msilbgcol2);
  g_object_set_data_full (G_OBJECT (mainwindow), "msilbgcol2", msilbgcol2,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (msilbgcol2);
  gtk_container_add (GTK_CONTAINER (mprefs_menu), msilbgcol2);

  mhlptancolor = gtk_menu_item_new_with_label (_("Help tan color..."));
  gtk_widget_set_name (mhlptancolor, "mhlptancolor");
  g_object_ref (mhlptancolor);
  g_object_set_data_full (G_OBJECT (mainwindow), "mhlptancolor", mhlptancolor,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mhlptancolor);
  gtk_container_add (GTK_CONTAINER (mprefs_menu), mhlptancolor);

  s_parateur2 = gtk_menu_item_new ();
  gtk_widget_set_name (s_parateur2, "s_parateur2");
  g_object_ref (s_parateur2);
  g_object_set_data_full (G_OBJECT (mainwindow), "s_parateur2", s_parateur2,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (s_parateur2);
  gtk_container_add (GTK_CONTAINER (mprefs_menu), s_parateur2);
  gtk_widget_set_sensitive (s_parateur2, FALSE);

  imsize = gtk_menu_item_new_with_label (_("Tans size"));
  gtk_widget_set_name (imsize, "imsize");
  g_object_ref (imsize);
  g_object_set_data_full (G_OBJECT (mainwindow), "imsize", imsize,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (imsize);
  gtk_container_add (GTK_CONTAINER (mprefs_menu), imsize);

  imsize_menu = gtk_menu_new ();
  gtk_widget_set_name (imsize_menu, "imsize_menu");
  g_object_ref (imsize_menu);
  g_object_set_data_full (G_OBJECT (mainwindow), "imsize_menu", imsize_menu,
                            (GDestroyNotify) g_object_unref);
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (imsize), imsize_menu);
//  imsize_menu_accels = gtk_menu_ensure_uline_accel_group (GTK_MENU (imsize_menu));

  msizinc = gtk_menu_item_new_with_label (_("Increase"));
  gtk_widget_set_name (msizinc, "msizinc");
  g_object_ref (msizinc);
  g_object_set_data_full (G_OBJECT (mainwindow), "msizinc", msizinc,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (msizinc);
  gtk_container_add (GTK_CONTAINER (imsize_menu), msizinc);

  msizdec = gtk_menu_item_new_with_label (_("Decrease"));
  gtk_widget_set_name (msizdec, "msizdec");
  g_object_ref (msizdec);
  g_object_set_data_full (G_OBJECT (mainwindow), "msizdec", msizdec,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (msizdec);
  gtk_container_add (GTK_CONTAINER (imsize_menu), msizdec);

  maccuracy = gtk_menu_item_new_with_label (_("Accuracy"));
  gtk_widget_set_name (maccuracy, "maccuracy");
  g_object_ref (maccuracy);
  g_object_set_data_full (G_OBJECT (mainwindow), "maccuracy", maccuracy,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (maccuracy);
  gtk_container_add (GTK_CONTAINER (mprefs_menu), maccuracy);

  maccuracy_menu = gtk_menu_new ();
  gtk_widget_set_name (maccuracy_menu, "maccuracy_menu");
  g_object_ref (maccuracy_menu);
  g_object_set_data_full (G_OBJECT (mainwindow), "maccuracy_menu", maccuracy_menu,
                            (GDestroyNotify) g_object_unref);
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (maccuracy), maccuracy_menu);
//  maccuracy_menu_accels = gtk_menu_ensure_uline_accel_group (GTK_MENU (maccuracy_menu));

  maccuracy1 = gtk_radio_menu_item_new_with_label (accgrp_group, _("High"));
  accgrp_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (maccuracy1));
  gtk_widget_set_name (maccuracy1, "maccuracy1");
  g_object_ref (maccuracy1);
  g_object_set_data_full (G_OBJECT (mainwindow), "maccuracy1", maccuracy1,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (maccuracy1);
  gtk_container_add (GTK_CONTAINER (maccuracy_menu), maccuracy1);

  maccuracy2 = gtk_radio_menu_item_new_with_label (accgrp_group, _("Medium"));
  accgrp_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (maccuracy2));
  gtk_widget_set_name (maccuracy2, "maccuracy2");
  g_object_ref (maccuracy2);
  g_object_set_data_full (G_OBJECT (mainwindow), "maccuracy2", maccuracy2,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (maccuracy2);
  gtk_container_add (GTK_CONTAINER (maccuracy_menu), maccuracy2);

  maccuracy3 = gtk_radio_menu_item_new_with_label (accgrp_group, _("Low"));
  accgrp_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (maccuracy3));
  gtk_widget_set_name (maccuracy3, "maccuracy3");
  g_object_ref (maccuracy3);
  g_object_set_data_full (G_OBJECT (mainwindow), "maccuracy3", maccuracy3,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (maccuracy3);
  gtk_container_add (GTK_CONTAINER (maccuracy_menu), maccuracy3);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (maccuracy3), TRUE);

  rotstp = gtk_menu_item_new_with_label (_("Rotation"));
  gtk_widget_set_name (rotstp, "rotstp");
  g_object_ref (rotstp);
  g_object_set_data_full (G_OBJECT (mainwindow), "rotstp", rotstp,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (rotstp);
  gtk_container_add (GTK_CONTAINER (mprefs_menu), rotstp);

  rotstp_menu = gtk_menu_new ();
  gtk_widget_set_name (rotstp_menu, "rotstp_menu");
  g_object_ref (rotstp_menu);
  g_object_set_data_full (G_OBJECT (mainwindow), "rotstp_menu", rotstp_menu,
                            (GDestroyNotify) g_object_unref);
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (rotstp), rotstp_menu);
//  rotstp_menu_accels = gtk_menu_ensure_uline_accel_group (GTK_MENU (rotstp_menu));

  mrotcont = gtk_radio_menu_item_new_with_label (rotgrp_group, _("Continuous"));
  rotgrp_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (mrotcont));
  gtk_widget_set_name (mrotcont, "mrotcont");
  g_object_ref (mrotcont);
  g_object_set_data_full (G_OBJECT (mainwindow), "mrotcont", mrotcont,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mrotcont);
  gtk_container_add (GTK_CONTAINER (rotstp_menu), mrotcont);

  mrotstp = gtk_radio_menu_item_new_with_label (rotgrp_group, _("Step by step"));
  rotgrp_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (mrotstp));
  gtk_widget_set_name (mrotstp, "mrotstp");
  g_object_ref (mrotstp);
  g_object_set_data_full (G_OBJECT (mainwindow), "mrotstp", mrotstp,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mrotstp);
  gtk_container_add (GTK_CONTAINER (rotstp_menu), mrotstp);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (mrotstp), TRUE);

  separator1 = gtk_menu_item_new ();
  gtk_widget_set_name (separator1, "separator1");
  g_object_ref (separator1);
  g_object_set_data_full (G_OBJECT (mainwindow), "separator1", separator1,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (separator1);
  gtk_container_add (GTK_CONTAINER (mprefs_menu), separator1);
  gtk_widget_set_sensitive (separator1, FALSE);

  mfigfile = gtk_menu_item_new_with_label (_("Figures file..."));
  gtk_widget_set_name (mfigfile, "mfigfile");
  g_object_ref (mfigfile);
  g_object_set_data_full (G_OBJECT (mainwindow), "mfigfile", mfigfile,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mfigfile);
  gtk_container_add (GTK_CONTAINER (mprefs_menu), mfigfile);

  s_parateur3 = gtk_menu_item_new ();
  gtk_widget_set_name (s_parateur3, "s_parateur3");
  g_object_ref (s_parateur3);
  g_object_set_data_full (G_OBJECT (mainwindow), "s_parateur3", s_parateur3,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (s_parateur3);
  gtk_container_add (GTK_CONTAINER (mprefs_menu), s_parateur3);
  gtk_widget_set_sensitive (s_parateur3, FALSE);

  msaveconf = gtk_menu_item_new_with_label (_("Save config"));
  gtk_widget_set_name (msaveconf, "msaveconf");
  g_object_ref (msaveconf);
  g_object_set_data_full (G_OBJECT (mainwindow), "msaveconf", msaveconf,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (msaveconf);
  gtk_container_add (GTK_CONTAINER (mprefs_menu), msaveconf);

  mmisc = gtk_menu_item_new_with_label (_("Misc."));
  gtk_widget_set_name (mmisc, "mmisc");
  g_object_ref (mmisc);
  g_object_set_data_full (G_OBJECT (mainwindow), "mmisc", mmisc,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mmisc);
  gtk_container_add (GTK_CONTAINER (menubar1), mmisc);

  mmisc_menu = gtk_menu_new ();
  gtk_widget_set_name (mmisc_menu, "mmisc_menu");
  g_object_ref (mmisc_menu);
  g_object_set_data_full (G_OBJECT (mainwindow), "mmisc_menu", mmisc_menu,
                            (GDestroyNotify) g_object_unref);
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (mmisc), mmisc_menu);
//  mmisc_menu_accels = gtk_menu_ensure_uline_accel_group (GTK_MENU (mmisc_menu));

  mabout = gtk_menu_item_new_with_label (_("About..."));
  gtk_widget_set_name (mabout, "mabout");
  g_object_ref (mabout);
  g_object_set_data_full (G_OBJECT (mainwindow), "mabout", mabout,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mabout);
  gtk_container_add (GTK_CONTAINER (mmisc_menu), mabout);

  mhelp = gtk_menu_item_new_with_label (_("Help..."));
  gtk_widget_set_name (mhelp, "mhelp");
  g_object_ref (mhelp);
  g_object_set_data_full (G_OBJECT (mainwindow), "mhelp", mhelp,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mhelp);
  gtk_container_add (GTK_CONTAINER (mmisc_menu), mhelp);

  sep17 = gtk_menu_item_new ();
  gtk_widget_set_name (sep17, "sep17");
  g_object_ref (sep17);
  g_object_set_data_full (G_OBJECT (mainwindow), "sep17", sep17,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (sep17);
  gtk_container_add (GTK_CONTAINER (mmisc_menu), sep17);
  gtk_widget_set_sensitive (sep17, FALSE);

  mclrstat = gtk_menu_item_new_with_label (_("Clear figure status"));
  gtk_widget_set_name (mclrstat, "mclrstat");
  g_object_ref (mclrstat);
  g_object_set_data_full (G_OBJECT (mainwindow), "mclrstat", mclrstat,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mclrstat);
  gtk_container_add (GTK_CONTAINER (mmisc_menu), mclrstat);

  mclrall = gtk_menu_item_new_with_label (_("Clear all figures status"));
  gtk_widget_set_name (mclrall, "mclrall");
  g_object_ref (mclrall);
  g_object_set_data_full (G_OBJECT (mainwindow), "mclrall", mclrall,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (mclrall);
  gtk_container_add (GTK_CONTAINER (mmisc_menu), mclrall);

  table1 = gtk_table_new (3, 4, TRUE);
  gtk_widget_set_name (table1, "table1");
  g_object_ref (table1);
  g_object_set_data_full (G_OBJECT (mainwindow), "table1", table1,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (table1);
  gtk_box_pack_start (GTK_BOX (vbox1), table1, TRUE, TRUE, 0);

  aspectframe1 = gtk_aspect_frame_new (NULL, 0.5, 0.5, 1, FALSE);
  gtk_widget_set_name (aspectframe1, "aspectframe1");
  g_object_ref (aspectframe1);
  g_object_set_data_full (G_OBJECT (mainwindow), "aspectframe1", aspectframe1,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (aspectframe1);
  gtk_table_attach (GTK_TABLE (table1), aspectframe1, 0, 3, 0, 3,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);

  wdrawareagrande = gtk_drawing_area_new ();
  gtk_widget_set_name (wdrawareagrande, "wdrawareagrande");
  g_object_ref (wdrawareagrande);
  g_object_set_data_full (G_OBJECT (mainwindow), "wdrawareagrande", wdrawareagrande,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (wdrawareagrande);
  gtk_container_add (GTK_CONTAINER (aspectframe1), wdrawareagrande);
  gtk_widget_set_events (wdrawareagrande, GDK_EXPOSURE_MASK | GDK_POINTER_MOTION_HINT_MASK | GDK_BUTTON_MOTION_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK | GDK_STRUCTURE_MASK);

  aspectframe2 = gtk_aspect_frame_new (NULL, 0.5, 0.5, 1, TRUE);
  gtk_widget_set_name (aspectframe2, "aspectframe2");
  g_object_ref (aspectframe2);
  g_object_set_data_full (G_OBJECT (mainwindow), "aspectframe2", aspectframe2,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (aspectframe2);
  gtk_table_attach (GTK_TABLE (table1), aspectframe2, 3, 4, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);

  wdrawareapetite = gtk_drawing_area_new ();
  gtk_widget_set_name (wdrawareapetite, "wdrawareapetite");
  g_object_ref (wdrawareapetite);
  g_object_set_data_full (G_OBJECT (mainwindow), "wdrawareapetite", wdrawareapetite,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (wdrawareapetite);
  gtk_container_add (GTK_CONTAINER (aspectframe2), wdrawareapetite);
  gtk_widget_set_events (wdrawareapetite, GDK_EXPOSURE_MASK | GDK_STRUCTURE_MASK);

  vbox2 = gtk_vbox_new (FALSE, 3);
  gtk_widget_set_name (vbox2, "vbox2");
  g_object_ref (vbox2);
  g_object_set_data_full (G_OBJECT (mainwindow), "vbox2", vbox2,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (vbox2);
  gtk_table_attach (GTK_TABLE (table1), vbox2, 3, 4, 1, 3,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (vbox2), 3);

  hbox1 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox1, "hbox1");
  g_object_ref (hbox1);
  g_object_set_data_full (G_OBJECT (mainwindow), "hbox1", hbox1,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (hbox1);
  gtk_box_pack_start (GTK_BOX (vbox2), hbox1, FALSE, FALSE, 0);

  label2 = gtk_label_new (_("Figure "));
  gtk_widget_set_name (label2, "label2");
  g_object_ref (label2);
  g_object_set_data_full (G_OBJECT (mainwindow), "label2", label2,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (label2);
  gtk_box_pack_start (GTK_BOX (hbox1), label2, TRUE, TRUE, 0);

  bfignr_adj = gtk_adjustment_new (1000, 0, 1000, 1, 10, 0);
  bfignr = gtk_spin_button_new (GTK_ADJUSTMENT (bfignr_adj), 1, 0);
  gtk_widget_set_name (bfignr, "bfignr");
  g_object_ref (bfignr);
  g_object_set_data_full (G_OBJECT (mainwindow), "bfignr", bfignr,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (bfignr);
  gtk_box_pack_start (GTK_BOX (hbox1), bfignr, TRUE, TRUE, 0);
  gtk_spin_button_set_numeric (GTK_SPIN_BUTTON (bfignr), TRUE);
  gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (bfignr), TRUE);

  hseparator2 = gtk_hseparator_new ();
  gtk_widget_set_name (hseparator2, "hseparator2");
  g_object_ref (hseparator2);
  g_object_set_data_full (G_OBJECT (mainwindow), "hseparator2", hseparator2,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (hseparator2);
  gtk_box_pack_start (GTK_BOX (vbox2), hseparator2, FALSE, FALSE, 0);

  bunsel = gtk_button_new_with_label (_("Unselect tan"));
  gtk_widget_set_name (bunsel, "bunsel");
  g_object_ref (bunsel);
  g_object_set_data_full (G_OBJECT (mainwindow), "bunsel", bunsel,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (bunsel);
  gtk_box_pack_start (GTK_BOX (vbox2), bunsel, FALSE, FALSE, 0);
  gtk_widget_set_can_focus (bunsel, FALSE);

  hseparator1 = gtk_hseparator_new ();
  gtk_widget_set_name (hseparator1, "hseparator1");
  g_object_ref (hseparator1);
  g_object_set_data_full (G_OBJECT (mainwindow), "hseparator1", hseparator1,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (hseparator1);
  gtk_box_pack_start (GTK_BOX (vbox2), hseparator1, FALSE, FALSE, 0);

  bhlptan = gtk_button_new_with_label (_("Show a tan"));
  gtk_widget_set_name (bhlptan, "bhlptan");
  g_object_ref (bhlptan);
  g_object_set_data_full (G_OBJECT (mainwindow), "bhlptan", bhlptan,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (bhlptan);
  gtk_box_pack_start (GTK_BOX (vbox2), bhlptan, FALSE, FALSE, 0);
  gtk_widget_set_can_focus (bhlptan, FALSE);

  bhlpout = gtk_button_new_with_label (_("Show outline"));
  gtk_widget_set_name (bhlpout, "bhlpout");
  g_object_ref (bhlpout);
  g_object_set_data_full (G_OBJECT (mainwindow), "bhlpout", bhlpout,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (bhlpout);
  gtk_box_pack_start (GTK_BOX (vbox2), bhlpout, FALSE, FALSE, 0);
  gtk_widget_set_can_focus (bhlpout, FALSE);

  wstatusbar = gtk_statusbar_new ();
  gtk_widget_set_name (wstatusbar, "wstatusbar");
  g_object_ref (wstatusbar);
  g_object_set_data_full (G_OBJECT (mainwindow), "wstatusbar", wstatusbar,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (wstatusbar);
  gtk_box_pack_start (GTK_BOX (vbox1), wstatusbar, FALSE, FALSE, 0);

  g_signal_connect (G_OBJECT (mainwindow), "destroy",
                    G_CALLBACK (on_mainwindow_destroy),
                    NULL);
  g_signal_connect (G_OBJECT (mquit), "activate",
                    G_CALLBACK (on_mquit_activate),
                    NULL);
  g_signal_connect (G_OBJECT (mtanscolor), "activate",
                    G_CALLBACK (on_mtanscolor_activate),
                    NULL);
  g_signal_connect (G_OBJECT (mtanstexture), "activate",
                    G_CALLBACK (on_mtanstexture_activate),
                    NULL);
  g_signal_connect (G_OBJECT (mhighcolor), "activate",
                    G_CALLBACK (on_mhighcolor_activate),
                    NULL);
  g_signal_connect (G_OBJECT (mhightexture), "activate",
                    G_CALLBACK (on_mhightexture_activate),
                    NULL);
  g_signal_connect (G_OBJECT (mbgcolor), "activate",
                    G_CALLBACK (on_mbgcolor_activate),
                    NULL);
  g_signal_connect (G_OBJECT (mbgtexture), "activate",
                    G_CALLBACK (on_mbgtexture_activate),
                    NULL);
  g_signal_connect (G_OBJECT (mhlpoutcolor), "activate",
                    G_CALLBACK (on_mhlpoutcolor_activate),
                    NULL);
  g_signal_connect (G_OBJECT (msilcolor), "activate",
                    G_CALLBACK (on_msilcolor_activate),
                    NULL);
  g_signal_connect (G_OBJECT (msilbgcolor), "activate",
                    G_CALLBACK (on_msilbgcolor_activate),
                    NULL);
  g_signal_connect (G_OBJECT (msilbgcol2), "activate",
                    G_CALLBACK (on_msilbgcol2_activate),
                    NULL);
  g_signal_connect (G_OBJECT (mhlptancolor), "activate",
                    G_CALLBACK (on_mhlptancolor_activate),
                    NULL);
  g_signal_connect (G_OBJECT (msizinc), "activate",
                    G_CALLBACK (on_msizinc_activate),
                    NULL);
  g_signal_connect (G_OBJECT (msizdec), "activate",
                    G_CALLBACK (on_msizdec_activate),
                    NULL);
  g_signal_connect (G_OBJECT (maccuracy1), "activate",
                    G_CALLBACK (on_maccuracy1_activate),
                    NULL);
  g_signal_connect (G_OBJECT (maccuracy2), "activate",
                    G_CALLBACK (on_maccuracy2_activate),
                    NULL);
  g_signal_connect (G_OBJECT (maccuracy3), "activate",
                    G_CALLBACK (on_maccuracy3_activate),
                    NULL);
  g_signal_connect (G_OBJECT (mrotcont), "activate",
                    G_CALLBACK (on_mrotcont_activate),
                    NULL);
  g_signal_connect (G_OBJECT (mrotstp), "activate",
                    G_CALLBACK (on_mrotstp_activate),
                    NULL);
  g_signal_connect (G_OBJECT (mfigfile), "activate",
                    G_CALLBACK (on_mfigfile_activate),
                    NULL);
  g_signal_connect (G_OBJECT (msaveconf), "activate",
                    G_CALLBACK (on_msaveconf_activate),
                    NULL);
  g_signal_connect (G_OBJECT (mabout), "activate",
                    G_CALLBACK (on_mabout_activate),
                    NULL);
  g_signal_connect (G_OBJECT (mhelp), "activate",
                    G_CALLBACK (on_mhelp_activate),
                    NULL);
  g_signal_connect (G_OBJECT (mclrstat), "activate",
                    G_CALLBACK (on_mclrstat_activate),
                    NULL);
  g_signal_connect (G_OBJECT (mclrall), "activate",
                    G_CALLBACK (on_mclrall_activate),
                    NULL);
  g_signal_connect (G_OBJECT (wdrawareagrande), "expose_event",
                    G_CALLBACK (on_wdrawareagrande_expose_event),
                    NULL);
  g_signal_connect (G_OBJECT (wdrawareagrande), "configure_event",
                    G_CALLBACK (on_wdrawareagrande_configure_event),
                    NULL);
  g_signal_connect (G_OBJECT (wdrawareagrande), "button_press_event",
                    G_CALLBACK (on_wdrawareagrande_button_press_event),
                    NULL);
  g_signal_connect (G_OBJECT (wdrawareagrande), "button_release_event",
                    G_CALLBACK (on_wdrawareagrande_button_release_event),
                    NULL);
  g_signal_connect (G_OBJECT (wdrawareagrande), "motion_notify_event",
                    G_CALLBACK (on_wdrawareagrande_motion_notify_event),
                    NULL);
  g_signal_connect (G_OBJECT (wdrawareapetite), "configure_event",
                    G_CALLBACK (on_wdrawareapetite_configure_event),
                    NULL);
  g_signal_connect (G_OBJECT (wdrawareapetite), "expose_event",
                    G_CALLBACK (on_wdrawareapetite_expose_event),
                    NULL);
  g_signal_connect (G_OBJECT (bfignr), "changed",
                    G_CALLBACK (on_bfignr_changed),
                    NULL);
  g_signal_connect (G_OBJECT (bunsel), "clicked",
                    G_CALLBACK (on_bunsel_clicked),
                    NULL);
  g_signal_connect (G_OBJECT (bhlptan), "clicked",
                    G_CALLBACK (on_bhlptan_clicked),
                    NULL);
  g_signal_connect (G_OBJECT (bhlpout), "clicked",
                    G_CALLBACK (on_bhlpout_clicked),
                    NULL);

  return mainwindow;
#endif
}

GtkWidget*
create_fileselectwindow (void)
{
#if 0
  GtkWidget *fileselectwindow;

  fileselectwindow = gtk_file_chooser_dialog_new (_("Select a file"),
                                      GTK_WINDOW(mainwindow),
                                      GTK_FILE_CHOOSER_ACTION_OPEN,
                                      GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                      GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
                                      NULL);
  gtk_widget_set_name (fileselectwindow, "fileselectwindow");
  g_object_set_data (G_OBJECT (fileselectwindow), "fileselectwindow", fileselectwindow);
  gtk_container_set_border_width (GTK_CONTAINER (fileselectwindow), 10);
  gtk_window_set_modal (GTK_WINDOW (fileselectwindow), TRUE);

  g_signal_connect (G_OBJECT (fileselectwindow), "delete_event",
                    G_CALLBACK (on_fileselectwindow_delete_event),
                    NULL);

  g_signal_connect (G_OBJECT (fileselectwindow), "response",
                    G_CALLBACK (on_bfsok_clicked),
                    NULL);

  return fileselectwindow;
#endif
}

GtkWidget*
create_colorselectwindow (void)
{
#if 0
  GtkWidget *colorselectwindow;
  GtkWidget *bcsok;
  GtkWidget *bcscancel;
  GtkWidget *help_button1;

  colorselectwindow = gtk_color_selection_dialog_new (_("Select color"));
  gtk_widget_set_name (colorselectwindow, "colorselectwindow");
  g_object_set_data (G_OBJECT (colorselectwindow), "colorselectwindow", colorselectwindow);
  gtk_container_set_border_width (GTK_CONTAINER (colorselectwindow), 10);
  gtk_window_set_modal (GTK_WINDOW (colorselectwindow), TRUE);

  bcsok = GTK_COLOR_SELECTION_DIALOG (colorselectwindow)->ok_button;
  gtk_widget_set_name (bcsok, "bcsok");
  g_object_set_data (G_OBJECT (colorselectwindow), "bcsok", bcsok);
  gtk_widget_show (bcsok);
  gtk_widget_set_can_default (bcsok, TRUE);

  bcscancel = GTK_COLOR_SELECTION_DIALOG (colorselectwindow)->cancel_button;
  gtk_widget_set_name (bcscancel, "bcscancel");
  g_object_set_data (G_OBJECT (colorselectwindow), "bcscancel", bcscancel);
  gtk_widget_show (bcscancel);
  gtk_widget_set_can_default (bcscancel, TRUE);

  help_button1 = GTK_COLOR_SELECTION_DIALOG (colorselectwindow)->help_button;
  gtk_widget_set_name (help_button1, "help_button1");
  g_object_set_data (G_OBJECT (colorselectwindow), "help_button1", help_button1);
  gtk_widget_show (help_button1);
  gtk_widget_set_can_default (help_button1, TRUE);

  g_signal_connect (G_OBJECT (colorselectwindow), "delete_event",
                    G_CALLBACK (on_colorselectwindow_delete_event),
                    NULL);
  g_signal_connect (G_OBJECT (bcsok), "clicked",
                    G_CALLBACK (on_bcsok_clicked),
                    NULL);
  g_signal_connect (G_OBJECT (bcscancel), "clicked",
                    G_CALLBACK (on_bcscancel_clicked),
                    NULL);

  return colorselectwindow;
#endif
}

void
create_aboutwindow (void)
{
#if 0
  const gchar *authors[] = {
    "Philippe Banwarth <bwt@altern.org>",
    "Yaakov Selkowitz <yselkowitz@users.sourceforge.net>",
     NULL};

  static const gchar license_text[] = \
    N_("This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.\n\n"
       "This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.\n\n"
       "You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.");

  gtk_show_about_dialog (GTK_WINDOW(mainwindow),
                "authors", authors,
                "comments", _("Chinese Tangram puzzle game."),
                "copyright", "\xc2\xa9 2000-2003 Philippe Banwarth\n\xc2\xa9 2009 Yaakov Selkowitz",
                "license", license_text,
                "logo-icon-name", "gtans",
#if GTK_CHECK_VERSION(2, 11, 0)
                "program-name", _("gTans"),
#else
                "name", _("gTans"),
#endif
                "title", _("About gTans"),
                "translator-credits", _("translator-credits"),
                "version", VERSION,
                "website", "http://gtans.sourceforge.net/",
#if GTK_CHECK_VERSION(2, 7, 2)
                "wrap-license", TRUE,
#endif
                 NULL);
#endif
}

GtkWidget*
create_helpwindow (void)
{
#if 0
  GtkWidget *helpwindow;
  GtkWidget *dialog_vbox2;
  GtkWidget *scrolledwindow1;
  GtkWidget *whltext;
  GtkWidget *dialog_action_area2;
  GtkWidget *bhlclose;

  helpwindow = gtk_dialog_new ();
  gtk_widget_set_name (helpwindow, "helpwindow");
  g_object_set_data (G_OBJECT (helpwindow), "helpwindow", helpwindow);
  gtk_window_set_title (GTK_WINDOW (helpwindow), _("gTans help"));
  gtk_window_set_modal (GTK_WINDOW (helpwindow), TRUE);
  gtk_window_set_default_size (GTK_WINDOW (helpwindow), 470, 400);

  dialog_vbox2 = GTK_DIALOG (helpwindow)->vbox;
  gtk_widget_set_name (dialog_vbox2, "dialog_vbox2");
  g_object_set_data (G_OBJECT (helpwindow), "dialog_vbox2", dialog_vbox2);
  gtk_widget_show (dialog_vbox2);

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_set_name (scrolledwindow1, "scrolledwindow1");
  g_object_ref (scrolledwindow1);
  g_object_set_data_full (G_OBJECT (helpwindow), "scrolledwindow1", scrolledwindow1,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (scrolledwindow1);
  gtk_box_pack_start (GTK_BOX (dialog_vbox2), scrolledwindow1, TRUE, TRUE, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow1), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

  whltext = gtk_text_view_new ();
  gtk_widget_set_name (whltext, "whltext");
  g_object_ref (whltext);
  g_object_set_data_full (G_OBJECT (helpwindow), "whltext", whltext,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (whltext);
  gtk_container_add (GTK_CONTAINER (scrolledwindow1), whltext);

  dialog_action_area2 = GTK_DIALOG (helpwindow)->action_area;
  gtk_widget_set_name (dialog_action_area2, "dialog_action_area2");
  g_object_set_data (G_OBJECT (helpwindow), "dialog_action_area2", dialog_action_area2);
  gtk_widget_show (dialog_action_area2);
  gtk_container_set_border_width (GTK_CONTAINER (dialog_action_area2), 10);

  bhlclose = gtk_button_new_with_label (_("Close"));
  gtk_widget_set_name (bhlclose, "bhlclose");
  g_object_ref (bhlclose);
  g_object_set_data_full (G_OBJECT (helpwindow), "bhlclose", bhlclose,
                            (GDestroyNotify) g_object_unref);
  gtk_widget_show (bhlclose);
  gtk_box_pack_start (GTK_BOX (dialog_action_area2), bhlclose, FALSE, TRUE, 0);

  g_signal_connect (G_OBJECT (helpwindow), "destroy",
                    G_CALLBACK (on_helpwindow_destroy),
                    NULL);
  g_signal_connect (G_OBJECT (bhlclose), "clicked",
                    G_CALLBACK (on_bhlclose_clicked),
                    NULL);

  return helpwindow;
#endif
}

