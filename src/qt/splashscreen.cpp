// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "splashscreen.h"
#include "clientversion.h"
#include "util.h"

#include <QPainter>
#undef loop /* ugh, remove this when the #define loop is gone from util.h */
#include <QApplication>

SplashScreen::SplashScreen(const QPixmap &pixmap, Qt::WindowFlags f) :
    QSplashScreen(pixmap, f)
{
    // Load the approved TaoCoin artwork, then add maintained-release stamps at runtime.
    QPixmap newPixmap;
    if(GetBoolArg("-testnet")) {
        newPixmap = QPixmap(":/images/splash_testnet");
    }
    else {
        newPixmap = QPixmap(":/images/splash");
    }

    const int w = newPixmap.width();
    const int h = newPixmap.height();

    int stampFontSize = w / 34;
    if(stampFontSize < 8)
        stampFontSize = 8;

    int infoFontSize = w / 48;
    if(infoFontSize < 7)
        infoFontSize = 7;

    QPainter pixPaint(&newPixmap);
    pixPaint.setRenderHint(QPainter::Antialiasing, true);

    QRect stampRect((w * 59) / 100, (h * 4) / 100, (w * 36) / 100, (h * 9) / 100);
    pixPaint.fillRect(stampRect, QColor(190, 145, 45, 220));
    pixPaint.setPen(QColor(20, 20, 20));
    pixPaint.setFont(QFont("Arial", stampFontSize, QFont::Bold));
    pixPaint.drawText(stampRect, Qt::AlignCenter,
                      tr("MAINTAINED %1").arg(MAINTENANCE_YEAR));

    QRect infoRect(0, (h * 82) / 100, w, (h * 18) / 100);
    pixPaint.fillRect(infoRect, QColor(0, 0, 0, 175));
    pixPaint.setPen(QColor(245, 245, 245));
    pixPaint.setFont(QFont("Arial", infoFontSize, QFont::Bold));
    pixPaint.drawText(QRect(0, (h * 83) / 100, w, (h * 5) / 100),
                      Qt::AlignCenter,
                      tr("TaoCoin — Original 2017 Legacy Chain"));
    pixPaint.setFont(QFont("Arial", infoFontSize));
    pixPaint.drawText(QRect(0, (h * 88) / 100, w, (h * 4) / 100),
                      Qt::AlignCenter,
                      tr("Maintained by the Xnuva Blockchain Project"));
    pixPaint.drawText(QRect(0, (h * 92) / 100, w, (h * 3) / 100),
                      Qt::AlignCenter,
                      QString("europazeus.org"));
    pixPaint.drawText(QRect(0, (h * 95) / 100, w, (h * 4) / 100),
                      Qt::AlignCenter,
                      QString("Version %1").arg(QString::fromStdString(FormatFullVersion())));

    pixPaint.end();

    this->setPixmap(newPixmap);
}
