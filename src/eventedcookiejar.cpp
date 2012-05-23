#include "eventedcookiejar.h"

EventedCookieJar::EventedCookieJar() : QNetworkCookieJar() 
{
}

bool EventedCookieJar::setCookiesFromUrl(const QList<QNetworkCookie> & cookieList, const QUrl & url)
{

    setCookies();

    return true;
}

QList<QNetworkCookie> EventedCookieJar::cookiesForUrl (const QUrl & url) const
{

    QList<QNetworkCookie> cookieList;

    return cookieList;
}

void EventedCookieJar::setCookies()
{

    emit cookiesSet();
}
