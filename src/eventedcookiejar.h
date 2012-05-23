#ifndef EVENTEDCOOKIEJAR_H
#define EVENTEDCOOKIEJAR_H

#include <QNetworkCookieJar>

class EventedCookieJar: public QNetworkCookieJar
{
    Q_OBJECT;
private:
    QString m_cookiesFile;

public:
    EventedCookieJar();

    bool setCookiesFromUrl(const QList<QNetworkCookie> & cookieList, const QUrl & url);
    QList<QNetworkCookie> cookiesForUrl (const QUrl & url) const;

public slots:
    void setCookies(const QString & url);

signals:
    void cookiesSet(const QString & url);
};

#endif // EVENTEDCOOKIEJAR_H
