/* This file is (c) 2008-2012 Konstantin Isakov <ikm@goldendict.org>
 * Part of TDNDict. Licensed under GPLv3 or later, see the LICENSE file */

#ifndef __INITIALIZING_HH_INCLUDED__
#define __INITIALIZING_HH_INCLUDED__

#include <QDialog>
#include "ui_initializing.h"

class Initializing: public QDialog
{
  Q_OBJECT

public:

  Initializing( QWidget * parent, bool showOnStartup );
#if ( QT_VERSION >= QT_VERSION_CHECK( 5, 0, 0 ) ) && defined( Q_OS_WIN32 )
  ~Initializing();
#endif

public slots:

  void indexing( QString const & dictionaryName );

private:

  virtual void closeEvent( QCloseEvent * );
  virtual void reject();
#if ( QT_VERSION >= QT_VERSION_CHECK( 5, 0, 0 ) ) && defined( Q_OS_WIN32 )
  QStyle * barStyle, * oldBarStyle;
#endif

  Ui::Initializing ui;
};

#endif

