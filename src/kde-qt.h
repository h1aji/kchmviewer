/***************************************************************************
 *   Copyright (C) 2004-2005 by Georgy Yunaev, gyunaev@ulduzsoft.com       *
 *   Please do not use email address above for bug reports; see            *
 *   the README file                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef KDE_QT_H
#define KDE_QT_H

#include "config.h"

#if defined (USE_KDE)
	
	#define KQ_CLASSNAME(name)			K##name
	#define KQ_DECLARECLASS(name)		class KQ##name : public K##name

	#include <kapplication.h>
	#include <kmainwindow.h>
	#include <kstatusbar.h>
	#include <kmenubar.h>
	#include <kcmdlineargs.h>
	#include <klocale.h>
	#include <klistview.h>
	#include <kfiledialog.h>
	#include <khtml_part.h>
	#include <ktabwidget.h>
	#include <kpopupmenu.h>
	#include <kmessagebox.h>
	#include <kprogress.h>
	#include <krun.h>

#else /* !USE_KDE */

	#define KQ_CLASSNAME(name)			Q##name

	#include <qapplication.h>
	#include <qmainwindow.h>
	#include <qstring.h>
	#include <qstatusbar.h>
	#include <qlistview.h>
	#include <qfiledialog.h>
	#include <qmenubar.h>
	#include <qtabwidget.h>
	#include <qmessagebox.h>
	#include <qprogressdialog.h>

	#define i18n(A)		tr(A)

#endif /* USE_KDE */

/* common non-wrapped UI classes */
#include <qsplitter.h>
#include <qtoolbutton.h>
#include <qheader.h>
#include <qtextbrowser.h>
#include <qlayout.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qpushbutton.h>

/* common utility classes */
#include <qwhatsthis.h>
#include <qstring.h>
#include <qtextedit.h>
#include <qfile.h>
#include <qdir.h>
#include <qregexp.h>
#include <qtimer.h>
#include <qmap.h>
#include <qeventloop.h>

class KQMainWindow : public KQ_CLASSNAME(MainWindow)
{
public:
	KQMainWindow ( QWidget * parent, const char * name, WFlags f )
		: KQ_CLASSNAME(MainWindow) (parent, name, f) {};
};


class KQListView : public KQ_CLASSNAME(ListView)
{
public:
	KQListView(QWidget *parent = 0, const char *name = 0, int f = 0);
};


class KQProgressModalDialog : public KQ_CLASSNAME(ProgressDialog)
{
	public:
		KQProgressModalDialog ( const QString & captionText, const QString & labelText, const QString & cancelButtonText, int totalSteps, QWidget * creator = 0 );
		
		// Seems like people have fun making classes incompatible
#if defined (USE_KDE)		
		void   setTotalSteps( int totalSteps ) { progressBar ()->setTotalSteps( totalSteps ); }
		void   setProgress( int progress ) { progressBar ()->setProgress( progress ); }
#else
		bool   wasCancelled() { return wasCanceled(); }
#endif
};

class KQTabWidget : public KQ_CLASSNAME(TabWidget)
{
public:
	KQTabWidget (QWidget *parent = 0, const char *name = 0, int f = 0)
		: KQ_CLASSNAME(TabWidget) (parent, name, f) {};
};

class KQPopupMenu : public KQ_CLASSNAME(PopupMenu)
{
public:
	KQPopupMenu (QWidget *parent = 0 )
		: KQ_CLASSNAME(PopupMenu) (parent) {};
};

#include <qinputdialog.h>
#include <qcheckbox.h>
#include <qtextedit.h>
#include <qradiobutton.h>
#include <qspinbox.h>
#include <qgroupbox.h>
#include <qbuttongroup.h>
#include <qtooltip.h>

#endif /* KDE_QT_H */
