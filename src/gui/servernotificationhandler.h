/*
 * Copyright (C) by Klaas Freitag <freitag@owncloud.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */

#ifndef SERVERNOTIFICATIONHANDLER_H
#define SERVERNOTIFICATIONHANDLER_H

#include <QtCore>

#include "activitywidget.h"

class QJsonDocument;

namespace OCC {

class ServerNotificationHandler : public QObject
{
    Q_OBJECT
public:
    explicit ServerNotificationHandler(QObject *parent = nullptr);

signals:
    void newNotificationList(ActivityList);

public slots:
    void slotFetchNotifications(AccountStatePtr ptr);

private slots:
    void slotNotificationsReceived(const QJsonDocument &json, int statusCode);

private:
    QPointer<JsonApiJob> _notificationJob;
};
}

#endif // SERVERNOTIFICATIONHANDLER_H
