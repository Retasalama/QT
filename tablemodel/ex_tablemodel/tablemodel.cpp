/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/
#include <QWidget>
#include <QApplication>
#include <QtWidgets>
#include <QtSql>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connection.h"

void getValuesFromModel(QSqlTableModel *model)
{
    model->setTable("person");

    //model->setFilter("firstname = 'Lars'");

    model->select();

    QString id = model->data(model->index(0,0)).toString();
    QString etu = model->data(model->index(0,1)).toString();
    QString suku = model->data(model->index(0,2)).toString();

    qDebug() <<id;
    qDebug() <<etu;
    qDebug() <<suku;

    //TEHTÄVÄ osa 1
    //yllä löydettiin haluttu rekordi

    //TEHTÄVÄ osa 2, mutta miten navigoisit läpi koko
    //person-taulun tulosjoukon tulostaen ne näytölle (qDebug)
    //Kommentoi ensin yllä filtteri, jotta saat kaikki rivit tulostumaan, sitten
    //käytä QSqlTableModel::record() -käskyä (kts. QSqlTableModel.pdf) alla for-loopissa


    // TEHTÄVÄ osa 3 (TODO) --------------
    //Lisää yksi rivi (record) tietokantatauluun insertRow() -käskyllä, joka luo
    //tyhjän rivin (record), sitten jokaiseen kenttään (column) rivillä asetetaan arvo setData() käskyllä.
	//kts. QSqlTableModel.pdf

    //TEHTÄVÄ osa 3
    int row = 5;
    model->insertRows(row, 1);
    model->setData(model->index(row,0), 106);
    model->setData(model->index(row,1), "Hop");
    model->setData(model->index(row,2), "Laa");

    //asetuksien jälkeen submitAll() käsky vasta toteuttaa rivin.
    model->submitAll();
    // ------------------------------------

    //TEHTÄVÄ osa 2
    for (int i = 0; i < model->rowCount(); ++i) {
        qDebug() << model->record(i); //tärkeä!!
    }

    //--------------------------------------
    // TEHTÄVÄ osa 3
    // Tarkista edellä tehty tulos poistamalla kommentit createView:n osalta.
    // Rivejä tulisi olla siis 6 kpltta graafisessa esityksessä näytöllä.

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));
}
//TEHTÄVÄ osa 3--------------------
QTableView *createView(QSqlTableModel *model, const QString &title = "")
{
    QTableView *view = new QTableView;
    view->setModel(model);
    view->setWindowTitle(title);
    return view;
}
//-----------------------------------
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    if (!createConnection())
        return 1;

    QSqlTableModel model;

    getValuesFromModel(&model);
//TEHTÄVÄ osa 3-------------------------------
    QTableView *view1 = createView(&model, QObject::tr("Table Model (View 1)"));
    QTableView *view2 = createView(&model, QObject::tr("Table Model (View 2)"));

    view1->show();
    view2->move(view1->x() + view1->width() + 20, view1->y());
    view2->show();
//----------------------------------------------
    return app.exec();
}
