#include "eventedcookiejar.h"

EventedCookieJar::EventedCookieJar() : QNetworkCookieJar() 
{
}

bool EventedCookieJar::setCookiesFromUrl(const QList<QNetworkCookie> & cookieList, const QUrl & url)
{

    setCookies(url.host());

    return true;
}

QList<QNetworkCookie> EventedCookieJar::cookiesForUrl (const QUrl & url) const
{

    QList<QNetworkCookie> cookieList;

    return cookieList;
}

void EventedCookieJar::setCookies(const QString & url)
{

    emit cookiesSet(url);
}
