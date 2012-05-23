#ifndef EVENTEDCOOKIEJAR_H
#define EVENTEDCOOKIEJAR_H

#include <QNetworkCookieJar>
#include <QVariantMap>

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
    void setCookies(const QString & url, const QVariantMap & cookies);

signals:
    void cookiesSet(const QString & url, const QVariantMap & cookies);
};

#endif // EVENTEDCOOKIEJAR_H
