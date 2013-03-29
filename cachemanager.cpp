#include "cachemanager.h"
#include <QtCore/QCryptographicHash>
#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtGui/QDesktopServices>
#include <QtNetwork/QNetworkReply>
#include "networkaccessmanager.h"

#include <QtCore/QDebug>

CacheManager::CacheManager(QObject *parent)
    : QObject(parent)
    , m_networkAccessManager(NetworkAccessManager::createN9NetworkAccessManager(this))
{
}

CacheManager::~CacheManager()
{
    foreach (QString path, m_cachedFiles) {
        QFile file (path);
        file.remove();
    }
}

bool CacheManager::contains(const QUrl &url)
{
    return m_cachedFiles.contains(url);
}

QString CacheManager::cachedFile(const QUrl &url)
{
    return m_cachedFiles.value(url);
}

void CacheManager::request(const QUrl &url)
{
    if (contains(url)) {
        emit requestFinished(url, cachedFile(url));
        return;
    }

    QNetworkReply *reply = m_networkAccessManager->get(QNetworkRequest(url));
    connect(reply, SIGNAL(finished()), this, SLOT(slotFinished()));
}

void CacheManager::slotFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if (!reply) {
        return;
    }

    QUrl url = reply->url();
    if (reply->error() != QNetworkReply::NoError) {
        emit requestFinished(url, QString());
        return;
    }

    QString cachePath = QDesktopServices::storageLocation(QDesktopServices::CacheLocation);
    if (!QDir::root().mkpath(cachePath)) {
        emit requestFinished(url, QString());
        return;
    }

    QString name = QCryptographicHash::hash(url.toString().toLocal8Bit(),
                                            QCryptographicHash::Md5).toHex();

    QDir cacheDir (cachePath);
    QString path = cacheDir.absoluteFilePath(name);

    QFile file (path);
    if (!file.open(QIODevice::WriteOnly)) {
        emit requestFinished(url, QString());
        return;
    }

    file.write(reply->readAll());
    file.close();

    m_cachedFiles.insert(url, path);
    emit requestFinished(url, path);
}
