#include <QVariantMap>
#include <QDateTime>
#include "eventedcookiejar.h"

EventedCookieJar::EventedCookieJar() : QNetworkCookieJar() 
{
}

bool EventedCookieJar::setCookiesFromUrl(const QList<QNetworkCookie> & cookieList, const QUrl & url)
{

    QVariantMap cookies;

    for (QList<QNetworkCookie>::const_iterator i = cookieList.begin(); i != cookieList.end(); i++) {

        QDateTime expires = (*i).expirationDate();
        QVariantMap details;

        details["value"] = QString((*i).value());
        details["expires"] = expires.toString();

        cookies[QString((*i).name())] = details;
        //cookies[QString((*i).name())] = QString((*i).value());
    }

    setCookies(url.host(), cookies);

    return true;
}

QList<QNetworkCookie> EventedCookieJar::cookiesForUrl (const QUrl & url) const
{

    QList<QNetworkCookie> cookieList;

    return cookieList;
}

void EventedCookieJar::setCookies(const QString & url, const QVariantMap & cookies)
{

    emit cookiesSet(url, cookies);
}
