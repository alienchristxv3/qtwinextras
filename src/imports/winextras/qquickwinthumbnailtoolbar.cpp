/****************************************************************************
 **
 ** Copyright (C) 2013 Ivan Vizir <define-true-false@yandex.com>
 ** Contact: http://www.qt-project.org/legal
 **
 ** This file is part of QtWinExtras in the Qt Toolkit.
 **
 ** $QT_BEGIN_LICENSE:LGPL$
 ** Commercial License Usage
 ** Licensees holding valid commercial Qt licenses may use this file in
 ** accordance with the commercial license agreement provided with the
 ** Software or, alternatively, in accordance with the terms contained in
 ** a written agreement between you and Digia.  For licensing terms and
 ** conditions see http://qt.digia.com/licensing.  For further information
 ** use the contact form at http://qt.digia.com/contact-us.
 **
 ** GNU Lesser General Public License Usage
 ** Alternatively, this file may be used under the terms of the GNU Lesser
 ** General Public License version 2.1 as published by the Free Software
 ** Foundation and appearing in the file LICENSE.LGPL included in the
 ** packaging of this file.  Please review the following information to
 ** ensure the GNU Lesser General Public License version 2.1 requirements
 ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
 **
 ** In addition, as a special exception, Digia gives you certain additional
 ** rights.  These rights are described in the Digia Qt LGPL Exception
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
 **
 ** $QT_END_LICENSE$
 **
 ****************************************************************************/

#include "qquickwinthumbnailtoolbar.h"
#include "qquickwinthumbnailtoolbutton.h"

#include <QQuickWindow>
#include <QQmlEngine>

QT_BEGIN_NAMESPACE

/*!
    \qmltype ThumbnailToolBar
    \instantiates QQuickWinThumbnailToolBar
    \inqmlmodule QtWinExtras

    \brief Allows manipulating the window's thumbnail toolbar.

    This class allows an application to embed a toolbar in the thumbnail of a window,
    which is shown when hovering over its taskbar icon. It provides quick access to
    the window's commands without requiring the user to restore or activate the window.

    \image thumbbar.png Media player thumbnail toolbar

    \section3 Example
    \snippet code/thumbbar.qml thumbbar_qml
    \since QtWinExtras 1.0
 */

QQuickWinThumbnailToolBar::QQuickWinThumbnailToolBar(QQuickItem *parent) :
    QQuickItem(parent)
{
}

QQuickWinThumbnailToolBar::~QQuickWinThumbnailToolBar()
{
}

QQmlListProperty<QObject> QQuickWinThumbnailToolBar::data()
{
    return QQmlListProperty<QObject>(this, this, &QQuickWinThumbnailToolBar::addData, 0, 0, 0);
}

void QQuickWinThumbnailToolBar::itemChange(QQuickItem::ItemChange change, const QQuickItem::ItemChangeData &data)
{
    if (change == ItemSceneChange)
        m_toolbar.setWindow(data.window);
    QQuickItem::itemChange(change, data);
}

void QQuickWinThumbnailToolBar::addData(QQmlListProperty<QObject> *property, QObject *object)
{
    if (const QQuickWinThumbnailToolButton *button = qobject_cast<QQuickWinThumbnailToolButton *>(object)) {
        QQuickWinThumbnailToolBar *quickThumbbar = static_cast<QQuickWinThumbnailToolBar *>(property->data);
        quickThumbbar->m_toolbar.addButton(button->m_button);
    }
}

QT_END_NAMESPACE
