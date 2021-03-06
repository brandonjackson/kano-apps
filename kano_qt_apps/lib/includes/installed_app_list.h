/**
 * installed_app_list.h
 *
 * Copyright (C) 2016-2017 Kano Computing Ltd.
 * License: http://www.gnu.org/licenses/gpl-2.0.txt GNU GPL v2
 *
 * Lists the apps intalled on the system
 */


#ifndef __INSTALLED_APP_LIST_H__
#define __INSTALLED_APP_LIST_H__


#include <QObject>
#include <QString>
#include <QList>
#include <QDir>
#include <QDebug>
#include <QThread>

#include "app.h"
#include "app_list.h"
#include "q_app_list.h"


class InstalledAppList : public QAppList
{
    Q_OBJECT

    public:
        InstalledAppList();
        ~InstalledAppList();

    protected:
        QDir apps_dir;
        QThread populate_thr;

    private slots:
        void update_list(QAppList apps);
        void clean_up();

    signals:
        Q_INVOKABLE void update();
};


#endif  // __INSTALLED_APP_LIST_H__
